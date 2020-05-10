struct Solution;

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let n = n as usize;
        if n == 0 {
            0
        } else {
            let mut table = Vec::with_capacity(n);
            table.push(1);
            table.push(2);
            for i in 2..n {
                table.push(table[i-1]+table[i-2]);
            }
            table[n-1]
        }
    }
}

fn main() {
    println!("{}", Solution::climb_stairs(6));
    println!("{}", Solution::climb_stairs(5));
    println!("{}", Solution::climb_stairs(4));
    println!("{}", Solution::climb_stairs(3));
    println!("{}", Solution::climb_stairs(2));
    println!("{}", Solution::climb_stairs(1));
    println!("{}", Solution::climb_stairs(0));
}
