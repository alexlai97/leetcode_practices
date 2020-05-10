use std::char::from_digit;
fn count_and_say(n: i32) -> String {
    let mut result = vec!['1'];

    for _ in 1..n {
        let mut temp = Vec::new();
        let mut i = 0_usize;
        while i < result.len() {
            let mut j = i + 1;
            while j < result.len() && result[i] == result[j] {
                j += 1;
            }
            temp.push(from_digit((j-i) as u32, 10).unwrap());
            temp.push(result[i]);

            i = j;
        }

        result = temp;
    }
        
    result.iter().collect()
}

fn main() {
    // dbg!(count_and_say(4));
    for i in 1..10 {
        dbg!(count_and_say(i));
    }
}
