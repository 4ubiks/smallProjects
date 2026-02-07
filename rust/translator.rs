use std::io;

fn main(){

    let mut input = String::new();
    println!("Enter the number to translate:");
    io::stdin()
        .read_line(&mut input)
        .expect("Make sure your input is one character and try again.");

   let val = to_binary(input);
   let asc = ascii(input);
   main_menu(input, val, asc);
}
fn main_menu(x: String, s: String, a: char){
    println!(" ");
    println!("global translator");
    println!("--------------------------");
    println!("you entered {x}");
    println!("--------------------------");
    println!("Binary: {s}");
    println!("ASCII: {a}");
    println!("Hexadecimal: ");
}

fn to_binary(x: i32) -> String{
    let mut modu = 0;
    let mut a = x;
    let mut binary: String = "".to_owned();
    let zero: String = "0".to_owned();
    let one: String = "1".to_owned();

    while a != 0 {
        modu = a % 2;
        if {modu} == 0{
            binary.push_str(&zero);
        }
        else if {modu} == 1{
            binary.push_str(&one);
        }
        a = a / 2;
    }

    let rB = reverse(binary);

    rB
}

fn ascii(x: i32) -> char{
    let integer = 65;
    let character = integer as u8 as char;

    character
}

fn reverse(s: String) -> String {
    s.chars().rev().collect()
}
