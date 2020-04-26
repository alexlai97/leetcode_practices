// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>
}

impl ListNode {
#[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val
        }
    }
}

fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut cur1 = &l1;
    let mut cur2 = &l2;
    let mut l3: Option<Box<ListNode>> = None;
    let mut cur3 = &mut l3;
    
    let mut carry = false;

    while cur1.is_some() || cur2.is_some() {
        let sum =
            if cur1.is_some() { cur1.as_ref().unwrap().val } else { 0 } +
            if cur2.is_some() { cur2.as_ref().unwrap().val } else { 0 } + 
            if carry { 1 } else { 0 };
        // carry = false;
        
        *cur3 = Some(Box::new(ListNode::new(sum % 10)));
        cur3 = &mut cur3.as_mut().unwrap().next;
        carry = sum >= 10;

        if cur1.is_some() { cur1 = &cur1.as_ref().unwrap().next; }
        if cur2.is_some() { cur2 = &cur2.as_ref().unwrap().next; }
    }

    if carry { *cur3 = Some(Box::new(ListNode::new(1))); }

    l3
}


fn main() {
    let l1 = Some(Box::new(ListNode {
        val: 2,
        next: Some(Box::new(ListNode {
            val: 4,
            next: Some(Box::new(ListNode {
                val: 3,
                next: None,
            })),
        })),
    }));
    let l2 = Some(Box::new(ListNode {
        val: 5,
        next: Some(Box::new(ListNode {
            val: 6,
            next: Some(Box::new(ListNode {
                val: 4,
                next: None,
            })),
        })),
    }));

    let l3 = add_two_numbers(l1,l2);
    dbg!(l3);
}
