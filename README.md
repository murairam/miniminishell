# 🐚 Welcome to Minishell!

Minishell is a **mini Unix shell** built as part of our **42 Paris** curriculum. It’s a lightweight version of Bash, handling commands, pipes, and redirections. We had a lot of fun building it, and now you can have fun using it! 😃

---

## 🎉 Features

- 🛠️ **Run Commands**: Execute built-in and external commands with ease.
- 🔗 **Pipes (`|`)**: Chain multiple commands together.
- 📂 **Redirections (`<`, `>`, `>>`, `<<`)**: Redirect input and output like a pro.
- 🌍 **Environment Variables (`$VAR`)**: Expand variables dynamically.
- 🎭 **Signal Handling**: Handles `Ctrl+C`, `Ctrl+D`, and `Ctrl+\` properly.
- 🚀 **Custom Tokenizer & Parser**: Breaks down and processes user input.

⚠️ **Note**: This project only includes the mandatory requirements—no `&&`, `||`, `;`, or wildcards (`*`).

---

## 🛠️ How We Built It

Minishell was a team effort! **I worked on lexing, parsing, and signals**, while my friend **handled execution and built-in commands**. Here’s how it works under the hood:

1. **Lexing**: The input is broken into tokens (words, operators, etc.), while keeping quotes intact and expanding variables like `$HOME`.
2. **Parsing**: We check for syntax errors and organize the command structure.
3. **Execution**: Built-ins like `cd`, `echo`, and `export` are handled internally, while external commands are passed to `execve`.
4. **Pipes & Redirections**: Commands are linked with pipes, and I/O redirections are properly handled.
5. **Signal Handling**: Prevents unwanted crashes from `Ctrl+C`, `Ctrl+D`, etc.

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

```bash
echo "Hello, World!"
```

```bash
pwd
```

```bash
cd ..
pwd
```

```bash
env | grep PATH
```

### 🌍 Environment Variable Handling

```bash
export TEST_VAR=42
echo $TEST_VAR
```

```bash
unset TEST_VAR
echo $TEST_VAR
```

### 🔗 Using Pipes

```bash
ls -l | grep minishell
```

```bash
echo "Hello World" | tr '[:lower:]' '[:upper:]'
```

```bash
cat input.txt | sort | uniq -c
```

### 📂 Redirections

```bash
echo "This is a test" > output.txt
```

```bash
cat < output.txt
```

```bash
ls > list.txt
```

```bash
echo "Appending this line" >> output.txt
```

### 🧪 Additional Test Cases

```bash
echo "Test" | wc -c
```

```bash
head -n 5 < input.txt
```

```bash
grep "search_term" < input.txt > output.txt
```

```bash
cat non_existent_file
```

```bash
cd /tmp
pwd
```

```bash
echo $?
```

```bash
/bin/ls
```

```bash
/bin/ls | wc -l
```

```bash
echo "Hello" > temp.txt
cat < temp.txt
```

```bash
echo "Line 1" > temp.txt
echo "Line 2" >> temp.txt
cat < temp.txt
```

### 🎭 Signal Handling

```bash
# Press Ctrl+C to interrupt the current process
```

```bash
# Press Ctrl+D to exit the shell
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

---

## 🛠️ Development Workflow

### 🐞 Debugging With Valgrind
```bash
valgrind --leak-check=full ./minishell
```

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
