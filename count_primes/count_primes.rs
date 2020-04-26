// O(n^1.5)
#[allow(dead_code)]
fn count_primes_1(n: i32) -> i32 {
    let mut count= 0;
    for i in 2..n {
        let up = (i as f64).sqrt().floor() as i32;
        // dbg!(i,up);
        // check i is a prime
        let mut prime = true;
        for j in 2..=up {
            // dbg!(j);
            if i % j == 0 {
                // dbg!(i);
                prime = false;
            }
        }
        if prime {
            count+= 1;
        }
    }
    count
}

fn count_primes_2(n: i32) -> i32 {
    if n <=1 { return 0; }
    let up = (n as f64).sqrt().floor() as i32;

    // https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    let mut table = vec![true;n as usize];
    table[0] = false;
    table[1] = false;

    for prime in 2..=up {
        // dbg!(prime);
        if !table[prime as usize] {
            continue;
        }

        for multiple in (prime*prime..n).step_by(prime as usize) {
            table[multiple as usize] = false;
        }
    }

    // dbg!(&table);
    table.iter().filter(|&flag| *flag == true).count() as i32
}

#[allow(dead_code)]
fn test_bunch(up: i32) {

    for n in 0..=up {
        let result1 = count_primes_1(n);
        let result2 = count_primes_2(n);
        if result1 != result2 {
            println!("n: {} | result1 v.s. result2: {},  {}",n, result1, result2);
        }
    }
}

fn main() {
    test_bunch(20);

    // let n = 5;
    // println!("count_primes_2({}): {}",n,count_primes_2(n));
}
