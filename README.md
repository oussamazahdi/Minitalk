# minitalk

![42 Badge](https://img.shields.io/badge/42-minitalk-00babc)
![C Badge](https://img.shields.io/badge/Language-C-blue)

## 📚 Overview

Minitalk is a project at 42 School that involves creating a small client-server data exchange program using UNIX signals. The project focuses on implementing a communication system between two processes using only SIGUSR1 and SIGUSR2 signals.

## 🔍 Description

The goal is to create a communication program in the form of a client and a server:
- **Server**: Must be launched first and display its PID after launch. It should receive and display messages sent by clients.
- **Client**: Takes two parameters - the server PID and the string to send. It must communicate the string to the server using UNIX signals.

## 🛠️ Implementation

This implementation uses bitwise operations to convert characters into binary representations, which are then transmitted one bit at a time using UNIX signals:
- SIGUSR1 represents binary 0
- SIGUSR2 represents binary 1

The communication must be acknowledged by the server after receiving each message, and the bonus part handles Unicode characters.

## 🚀 How to Use

### Compilation

To compile both the server and client:

```bash
make
```

To compile only the server or client:

```bash
make server
make client
```

To clean the object files:

```bash
make clean
```

To clean everything (object files and executables):

```bash
make fclean
```

To recompile everything:

```bash
make re
```

### Running the Project

1. Start the server first:
```bash
./server
```
The server will display its PID (Process ID) upon startup.

2. In another terminal, run the client with the server's PID and the message you want to send:
```bash
./client [server_pid] [message]
```

Example:
```bash
./client 12345 "Hello, minitalk!"
```

### Bonus Features

This implementation includes:
- Server acknowledgment of message reception
- Support for Unicode characters
- Colorful output for better visibility

## 🧩 Project Structure

```
.
├── Makefile
├── minitalk.h
├── minitalk_bonus.h (if applicable)
├── server.c
├── client.c
├── utils.c (if needed)
├── server_bonus.c (if applicable)
├── client_bonus.c (if applicable)
└── README.md
```

## 🔬 Key Learning Objectives

- Understanding UNIX signals and their handling
- Process communication techniques
- Bitwise operations for data encoding and decoding
- Proper signal handling and error management
- Client-server architecture basics

## 📝 Technical Constraints

- Only SIGUSR1 and SIGUSR2 signals can be used for communication
- Global variables are forbidden
- All memory allocated with `malloc` must be properly freed
- The code must comply with the 42 Norm
- Error handling must be thorough to avoid unexpected behavior

## 👤 Author

- Oussama Zahdi (@oussamazahdi)

## 💬 Acknowledgements

- 42 School for providing this challenging project
- All fellow students who provided feedback and testing
