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

## 🛠️ How We Built It

Minishell was a team effort! **I worked on lexing, parsing, and signals**, while my friend **handled execution and built-in commands**. Here’s how it works under the hood:

### 🔍 Lexing (Tokenization)
Before executing anything, the shell must first **break down** the input into individual tokens. Our lexer:
- Recognizes different elements like **commands, arguments, operators (`|`, `<`, `>`)**, and **environment variables (`$VAR`)**.
- Preserves text inside **quotes (`"` and `'`)** as a single unit.
- Strips out extra whitespace so that parsing is easier.

### 📌 Parsing
The parser ensures the **tokens follow the correct syntax**. It detects invalid commands and structures them into a meaningful format.

### 🚀 Execution
After parsing, commands get passed to **execution**, which:
- Recognizes built-in commands like `cd`, `echo`, and `export` and executes them **without forking a new process**.
- Uses `execve()` for external commands like `/bin/ls`, creating a child process with `fork()`.
- Manages **pipes and redirections** to properly send data between commands.

### 🔗 Pipes & Redirections
Handling pipes and redirections was one of the trickiest parts:
- We use **file descriptors (`dup2()`)** to redirect input and output streams.
- Commands connected by pipes (`ls | grep minishell`) communicate **through file descriptors** instead of writing to the terminal.

### 🎭 Signal Handling
To make the shell user-friendly, we implemented:
- **`Ctrl+C`**: Interrupts a running process.
- **`Ctrl+D`**: Signals the end of input.
- **`Ctrl+\`**: Can terminate running processes.

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

```bash
echo "Hello, World!"
pwd
cd ..
env | grep PATH
export TEST_VAR=42
echo $TEST_VAR
unset TEST_VAR
ls -l | grep minishell
cat input.txt | sort | uniq -c
echo "This is a test" > output.txt
cat < output.txt
ls > list.txt
echo "Appending this line" >> output.txt
```

---

## 📚 References & Learning Resources

- [Bash Beginner’s Guide](https://tldp.org/LDP/Bash-Beginners-Guide/html/index.html)
- [GNU Bash Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [Writing Your Own Shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
- [42 School Minishell Example](https://github.com/twagger/minishell)
- [Lexers & Parsers in Shells](https://trove.assistants.epita.fr/docs/42sh/lexer-parser)

---

## 🔥 Fun Facts

- **Why did we build this?** Because it was part of our curriculum at **42 Paris**!
- **Most frustrating bug?** Parsing unclosed quotes. `"Hello World` -> 😭
- **Proudest moment?** Getting pipes and redirections to work seamlessly!

---

## 🐝 License

This project is for educational purposes only.

---

🚀 **Happy Shell Scripting!**
