# pipex

The purpose of this project is to learn the underlying mechanics of UNIX `pipe`.

### Discription of mandatory part
The program `pipex` will be executed as follows:
```bash
$> ./pipex file1 cmd1 cmd2 file2
```
and should behave the same as the following command in shell:
```bash
$> < file1 cmd1 | cmd2 > file2
```
All errors should be handled the same as the shell handles them
### Discription of bonus part
Program need handle multiple pipes
```bash
$> < file1 cmd1 | cmd2 | cmd3 | ... | cmdn > file2

$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
