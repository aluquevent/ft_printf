# ft_printf

## 📌 Overview
`ft_printf` is a custom implementation of the standard C `printf` function. It replicates its functionality, handling various format specifiers, flags, width, precision, and different data types.

**Table of contents**
- [Features](#-features)
- [Installation](#-installation)
- [Usage](#-usage)
- [Format specifiers](#-format-specifiers)
- [Flags & behavior](#-flags--behavior)
- [Project structure](#-project-structure)

## 🚀 Features
- Supports format specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`
- Handles flags: `-`, `0`, `+`, ` ` (space), `#`
- Manages width and precision correctly
- Supports variable width and precision with `*`
- Properly handles `NULL` strings as `(null)`
- Returns the number of printed characters as a value or -1 when it fails.

## 📄 Allowed Functions
- `write`
- `malloc`
- `free`
- `va_start`, `va_arg`, `va_copy`, `va_end`

## 🔧 Installation
Clone the repository and compile it with your project:
```sh
make
```
Or compile manually:
```sh
gcc -Wall -Wextra -Werror -c *.c
ar rcs libftprintf.a *.o
```

## 🛠 Usage
Include the library in your project:
```c
#include "ft_printf.h"
```
Then use `ft_printf` like `printf`:
```c
ft_printf("Hello %s! You have %d new messages.\n", "User", 5);
```
### Example Outputs
```c
ft_printf("%%d: %d\n", 42);        // Output: "%d: 42"
ft_printf("%%x: %#x\n", 255);     // Output: "%x: 0xff"
ft_printf("%%10s: %10s\n", "Hi"); // Output: "       Hi"
```

## 📜 Format Specifiers
| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address |
| `%d` / `%i` | Prints a signed integer |
| `%u` | Prints an unsigned integer |
| `%x` / `%X` | Prints a hexadecimal number (lower/uppercase) |
| `%%` | Prints a `%` character |

## 🎯 Flags & Behavior
| Flag | Description |
|------|-------------|
| `-`  | Left-aligns the output (default is right-aligned) |
| `0`  | Pads numbers with zeros instead of spaces (ignored if `-` or precision is set) |
| `+`  | Forces a `+` sign for positive numbers |
| ` `(space)  | Adds a space before positive numbers (ignored if `+` is used) |
| `#`  | Prints `0x` or `0X` for `%x/%X`, forces `0` for `%o` |
| `width` | An optional decimal digit string (with nonzero first digit) specifying a minimun field `width`. If the converted value has fewer character than the field width, it will be padded with spaces on the left (or right, if left-adjustment flag is given). Insted of a decimal digit string one may write `*` to specify that the field width is given as an argument. |
| `.`| An optional `precision`, in the form of a period ('.') followed by an optional decimal digit string. Instead of a decimal string one may write `*` to specify that the precision is given in the next argument, which must be of type *int*. If the precision is given as just `.`, the precision is taken to be zero. |
### Additional behavior notes
| Flag | Notes |
|------|-------|
| `-`  | Applies to all format specifiers |
| `0`  | Applies to `%d`, `%i`, `%u`, `%x`, `%X` |
| `+`  | Applies to `%d`, `%i`. |
| ` `(space) | Applies to `%d`, `%i`. |
| `#`  | Applies to `%x`, `%X`. |
| `width` | Applies to all format specifiers. |
| `.`  | For **integers** (`%d`, `%i`, `%u`, `%x`, `%X`), it specifies the minimun width and pads with zeros if necessary, but **will not cut the number**. For **strings** (`%s`), limits the **maximun number of characters** to be printed. If the string is longer than the specified precision, it will be truncated to the specified length. | 
## 🏗 Project Structure
```
ft_printf/
│── ft_printf.c
│── check_format.c
│── parse_format.c
│── parse_flags.c
│── parse_width.c
│── parse_precision.c
│── handlers/
│   ├── handle_char.c
│   ├── handle_string.c
│   ├── handle_integer.c
│   ├── handle_unsigned.c
│   ├── handle_hex.c
│   ├── handle_pointer.c
│── utils/
│   ├── ft_itoa_base.c
│   ├── ft_strlen.c
│   ├── ft_strdup.c
│   ├── ft_strncpy.c
│── ft_printf.h
│── Makefile
```

## 🛠 Compilation & Testing
To test your `ft_printf`:
```sh
gcc main.c libftprintf.a -o test
./test
```

## 🏆 Authors
- **Asier** - [GitHub Profile](https://github.com/aluquevent)

## 📜 License
This project is open-source and free to use. No restrictions apply!

 <p style="text-align: right;">[back to top](#ft_prinft)</p>
