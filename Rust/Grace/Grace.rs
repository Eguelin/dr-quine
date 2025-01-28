use std::io::Write;
/*
	Colleen in Rust
*/

macro_rules! main {
	($str1:expr, $str2:expr) => {
		fn main() -> Result<(), std::io::Error> {
			let mut file = std::fs::OpenOptions::new().write(true).create(true).truncate(true).open("Grace_kid.rs")?;
			let content = format!("{}{0:?}, {1:?}{1}", $str1, $str2);
			file.write_all(content.as_bytes())?;
			Ok(())
		}
	};
}

main!("use std::io::Write;\n/*\n\tColleen in Rust\n*/\n\nmacro_rules! main {\n\t($str1:expr, $str2:expr) => {\n\t\tfn main() -> Result<(), std::io::Error> {\n\t\t\tlet mut file = std::fs::OpenOptions::new().write(true).create(true).truncate(true).open(\"Grace_kid.rs\")?;\n\t\t\tlet content = format!(\"{}{0:?}, {1:?}{1}\", $str1, $str2);\n\t\t\tfile.write_all(content.as_bytes())?;\n\t\t\tOk(())\n\t\t}\n\t};\n}\n\nmain!(", ");\n");
