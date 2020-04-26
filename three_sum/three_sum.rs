#[allow(dead_code)]
fn two_sum_sorted_array_with_target(sorted_array: &Vec<i32>, target: i32) -> Vec<(i32,i32)> {
    let mut results: Vec::<(i32,i32)> = Vec::new();
    let mut flags: Vec<bool> = vec![false; sorted_array.len()];
    for i in 0..sorted_array.len() {
        if flags[i] == true {
            continue;
        }

        match sorted_array.binary_search(&(target-sorted_array[i])) {
            Ok(index) => {
                if index == i {
                    // ignore 
                } else {
                    results.push((sorted_array[i], target-sorted_array[i]));
                    flags[i] = true;
                    flags[index] = true;
                }
            },
            Err(_) => (),
        } 
    }
    // dbg!(flags);
    results
}

// FIXME: not perfect, contains duplicates
#[allow(dead_code)]
fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut results: Vec<Vec<i32>> = Vec::new();
    let mut arr = nums.clone();
    arr.sort();

    for i in 0..arr.len() {
        let removed_array = {
            let mut new_arr = arr.clone();
            new_arr.remove(i);
            new_arr
        };
        let pairs = two_sum_sorted_array_with_target(&removed_array, -arr[i]);

        for p in pairs {
            results.push(vec![arr[i], p.0, p.1]);
        }
    }

    results
}

use std::collections::HashSet;
// FIXME: not perfect, contains duplicates
#[allow(dead_code)]
fn three_sum_hashset(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let length = nums.len();
    let mut results: Vec<Vec<i32>> = Vec::new();
    let mut nums_hashset = HashSet::new();
    for n in & nums {
        nums_hashset.insert(n);
    }
    
    for i in 0..length {
        for j in i..length {
            if nums_hashset.contains(&(-nums[i]-nums[j])) {
                results.push(vec![nums[i],nums[j],-nums[i]-nums[j]]);
            }
        }
    }
    
    results
}

fn three_sum_quadratic(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut results: Vec<Vec<i32>> = Vec::new();
    if nums.len() < 3 {return results;}
    let mut arr = nums.clone();
    arr.sort();
    // arr.dedup();

    let length = arr.len();

    for i in 0..=length-2 {
        let a = arr[i];
        let mut start = i+1;
        let mut end = length-1;
        while start < end {
            let b = arr[start];
            let c = arr[end];
            let sum = a + b + c;
            if sum == 0 {
                let answer = vec![a,b,c];
                if ! results.contains(&answer) {
                    results.push(answer);
                }
                start += 1;
                end -= 1;
            } else if sum > 0 {
                end -= 1;
            } else {
                start += 1;
            }
        }
    }

    results
}

fn main() {
   // let array: Vec<i32> = vec![1,2,3,4,5,6,7,8,9,10];

   // dbg!(two_sum_sorted_array_with_target(&array, 10));
   //
   let array2: Vec<i32> = vec![-1, 0, 1, 2, -1, -4];
   dbg!(three_sum_quadratic(array2));
}
