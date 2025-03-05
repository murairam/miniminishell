# 🐚 Welcome to Minishell!

Minishell is a **mini Unix shell** built as part of our **42 Paris** curriculum. It’s a lightweight version of Bash, handling commands, pipes, and redirections. Writing our own shell was both **challenging and rewarding**—we had to dig deep into **process management, file descriptors, and signal handling**. Now you can use our shell and see how it works! 😃

---

## 🎉 Features

- 🛠️ **Command Execution**: Run built-in and external commands like a real shell.
- 🔗 **Pipes (`|`)**: Chain multiple commands together seamlessly.
- 📂 **Redirections (`<`, `>`, `>>`, `<<`)**: Redirect input and output for files.
- 🌍 **Environment Variables (`$VAR`)**: Expand variables dynamically.
- 🎭 **Signal Handling**: No accidental shell crashes with `Ctrl+C`, `Ctrl+D`, or `Ctrl+\`.
- 🚀 **Custom Tokenizer & Parser**: Breaks down and processes user input **from scratch**.

⚠️ **Note**: This project only includes the mandatory requirements—no `&&`, `||`, `;`, or wildcards (`*`).

---

## 🔽 Getting Started

### 1️⃣ Clone the Repo
```bash
git clone https://github.com/murairam/miniminishell.git
cd miniminishell
```

### 2️⃣ Compile It
```bash
make
```

### 3️⃣ Start Your Shell
```bash
./minishell
```

### 4️⃣ Exit
```bash
exit
```

---

## 🚀 Try These Commands in Minishell

### 📢 Basic Commands

Print a simple message:
```bash
echo "Hello, World!"
```

Print the current working directory:
```bash
pwd
```

Change directory and confirm:
```bash
cd ..
pwd
```

List all environment variables:
```bash
env
```

### 🌍 Environment Variable Handling

Set and print an environment variable:
```bash
export TEST_VAR=42
echo $TEST_VAR
```

Unset an environment variable:
```bash
unset TEST_VAR
echo $TEST_VAR
```

### 🔗 Using Pipes

List files and filter output:
```bash
ls -l | grep minishell
```

Convert text to uppercase:
```bash
echo "Hello World" | tr '[:lower:]' '[:upper:]'
```

Count unique words from a file:
```bash
cat input.txt | sort | uniq -c
```

### 📂 Redirections

Write output to a file:
```bash
echo "This is a test" > output.txt
```

Read from a file:
```bash
cat < output.txt
```

Save `ls` output to a file:
```bash
ls > list.txt
```

Append output to a file:
```bash
echo "Appending this line" >> output.txt
```

### 🧪 Additional Test Cases

Count characters in a string:
```bash
echo "Test" | wc -c
```

Read first 5 lines from a file:
```bash
head -n 5 < input.txt
```

Search for a term in a file and save output:
```bash
grep "search_term" < input.txt > output.txt
```

Try to read a non-existing file (should display an error):
```bash
cat non_existent_file
```

Change to `/tmp` directory and check:
```bash
cd /tmp
pwd
```

Print last command's exit status:
```bash
echo $?
```

Execute `ls` using absolute path:
```bash
/bin/ls
```

Count files in a directory:
```bash
/bin/ls | wc -l
```

Write and read from a temporary file:
```bash
echo "Hello" > temp.txt
cat < temp.txt
```

Append multiple lines to a file and read:
```bash
echo "Line 1" > temp.txt
echo "Line 2" >> temp.txt
cat < temp.txt
```

### 🎭 Signal Handling

Interrupt a running process with `Ctrl+C`:
```bash
# Press Ctrl+C while a process is running
```

Exit the shell using `Ctrl+D`:
```bash
# Press Ctrl+D in an empty prompt
```

---

## 📚 References & Learning Resources

- [Bash Beginner’s Guide](https://tldp.org/LDP/Bash-Beginners-Guide/html/index.html)
- [GNU Bash Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [Writing Your Own Shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
- [42 School Minishell Example](https://github.com/twagger/minishell)
- [Lexers & Parsers in Shells](https://trove.assistants.epita.fr/docs/42sh/lexer-parser)
- [Parsing Expressions](https://eli.thegreenplace.net/2012/08/02/parsing-expressions-by-precedence-climbing)
- [Signals in Shells](https://github.com/mcombeau/minishell/blob/main/sources/signals/signal.c)
- [Minishell Bash HOWTO](https://tldp.org/HOWTO/Bash-Prog-Intro-HOWTO.html)
- [POSIX Shell Specification](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_10)
- [Developing a Linux Shell](https://www.geeksforgeeks.org/developing-linux-based-shell/)
- [Context Sensitivity in Grammar](https://eli.thegreenplace.net/2007/11/24/the-context-sensitivity-of-cs-grammar)
- [Dash Shell Parser](https://git.kernel.org/pub/scm/utils/dash/dash.git/tree/src/parser.c)
- [Oil Shell Insights](https://www.oilshell.org/blog/2019/02/07.html)
- [Recursive Descent Parsing](https://eli.thegreenplace.net/2009/03/20/a-recursive-descent-parser-with-an-infix-expression-evaluator)
- [Precedence Climbing Parsing](https://eli.thegreenplace.net/2012/08/02/parsing-expressions-by-precedence-climbing)
- [Shell Grammar Specification](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_10)

---

## 🔥 Fun Facts

- **Why did we build this?** Because it was part of our curriculum at **42 Paris**!
- **Most frustrating bug?** Parsing unclosed quotes. `"Hello World` -> 😭
- **Proudest moment?** Getting pipes and redirections to work seamlessly!

---

## 🐝 License

This project is for educational purposes only. Feel free to use it as a learning reference.

---

🚀 **Happy Shell Scripting!**
