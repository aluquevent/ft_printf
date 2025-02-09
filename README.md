# ft_printf

## 📌 Overview
`ft_printf` is a custom implementation of the standard C `printf` function. It replicates its functionality, handling various format specifiers, flags, width, precision, and different data types.

## 🚀 Features
- Supports format specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`
- Handles flags: `-`, `0`, `+`, ` ` (space), `#`
- Manages width and precision correctly
- Supports variable width and precision with `*`
- Properly handles `NULL` strings as `(null)`
- Follows the 42 Norms (max 25 lines per function, no for loops, no ternary operators)

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
| ` `  | Adds a space before positive numbers (ignored if `+` is used) |
| `#`  | Prints `0x` or `0X` for `%x/%X`, forces `0` for `%o` |

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

## 📌 Norm Compliance
- ✅ Functions must be **≤ 25 lines**
- ✅ No `for` loops
- ✅ No ternary operators (`? :`)
- ✅ Proper memory management (`free` used correctly)

## 🏆 Authors
- **Asier** - [GitHub Profile](https://github.com/aluquevent)

## 📜 License
This project is open-source and free to use. No restrictions apply!


