use std::io::Write;
/*
	Colleen in Rust
*/

fn main() {
	/*
		main function
	*/
	if ft_creat().is_err() {
		std::process::exit(1);
	}
}

fn ft_creat() -> std::io::Result<()> {
	let mut file = std::fs::OpenOptions::new().write(true).create(true).truncate(true).open("tmp_Colleen")?;
	let content = format!("{}, {0:?}, {1:?});
	file.write_all(content.as_bytes())?;
	Ok(())
{1}
", "use std::io::Write;\n/*\n\tColleen in Rust\n*/\n\nfn main() {\n\t/*\n\t\tmain function\n\t*/\n\tif ft_creat().is_err() {\n\t\tstd::process::exit(1);\n\t}\n}\n\nfn ft_creat() -> std::io::Result<()> {\n\tlet mut file = std::fs::OpenOptions::new().write(true).create(true).truncate(true).open(\"tmp_Colleen\")?;\n\tlet content = format!(\"{}, {0:?}, {1:?});\n\tfile.write_all(content.as_bytes())?;\n\tOk(())\n{1}\n\"", "}");
	file.write_all(content.as_bytes())?;
	Ok(())
}
