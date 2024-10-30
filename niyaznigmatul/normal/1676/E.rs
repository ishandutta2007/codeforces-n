extern crate core;

use crate::reader::Reader;

fn main() {
    let mut sc = Reader::new();
    let tests : u32 = sc.read_integer();
    for _ in 0..tests {
        solve(&mut sc);
    }
}

fn solve(sc: &mut Reader) {
    let n = sc.read_integer();
    let q = sc.read_integer();
    let mut a = vec![0; n];
    for i in 0..n {
        a[i] = sc.read_integer();
    }
    a.sort_by_key(|x| -x);
    for i in 1..n {
        a[i] += a[i - 1];
    }
    let mut ans = String::new();
    for _ in 0..q {
        let x = sc.read_integer();
        let mut left = 0;
        let mut right = n;
        while left != right - 1 {
            let mid = (left + right) >> 1;
            if a[mid] >= x {
                right = mid;
            } else {
                left = mid;
            }
        }
        if a[right - 1] >= x {
            right -= 1;
        }
        if right == n {
            ans.push_str("-1\n");
        } else {
            ans.push_str(&format!("{}\n", right + 1));
        }
    }
    print!("{}", ans);
}

mod reader {
    use std::fmt::Debug;
    use std::io;
    use std::io::{Read, Stdin};
    use std::iter::{Peekable, Iterator};
    use std::str::FromStr;
    use std::vec::IntoIter;

    pub struct Reader {
        input: Stdin,
        buf: Peekable<IntoIter<u8>>
    }

    impl Reader {
        pub fn new() -> Self {
            Self {
                input: io::stdin(),
                buf: Vec::new().into_iter().peekable()
            }
        }

        fn refill_buffer(&mut self) {
            while self.buf.peek().is_none() {
                let mut buf = vec![0; 65536];
                let read_bytes = self.input.read(&mut buf).unwrap();
                if read_bytes == 0 {
                    return
                }
                self.buf = buf.into_iter().peekable();
            }
        }

        fn peek(&mut self) -> Option<u8> {
            self.refill_buffer();
            self.buf.peek().map(|x| *x)
        }

        fn get(&mut self) -> Option<u8> {
            self.refill_buffer();
            self.buf.next()
        }

        fn read_line_safe(&mut self) -> Option<String> {
            let mut str = String::new();
            while let Some(ch) = self.get() {
                if ch == b'\n' {
                    break;
                }
                if ch == b'\r' {
                    if self.peek() == Some(b'\n') {
                        self.get();
                    }
                    break;
                }
                str.push(ch as char);
            }
            if str.is_empty() {
                None
            } else {
                Some(str)
            }
        }

        fn read_token_safe(&mut self) -> Option<String> {
            while (self.peek()? as char).is_whitespace() {
                self.get();
            }
            let mut str = String::new();
            while let Some(ch) = self.get() {
                if (ch as char).is_whitespace() {
                    break;
                }
                str.push(ch as char);
            }
            if str.is_empty() {
                None
            } else {
                Some(str)
            }
        }

        pub fn read_integer<T: FromStr>(&mut self) -> T
        where <T as FromStr>::Err : Debug,
        {
            self.read_token_safe().unwrap().parse::<T>().unwrap()
        }

        pub fn read_token(&mut self) -> String {
            self.read_token_safe().unwrap()
        }
    }
}