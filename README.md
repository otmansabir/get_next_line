# get_next_line

A minimal C utility to read a single line at a time from a file descriptor. This project is a classic 42 assignment focused on robust buffered I/O, static storage, and edge-case handling.

- Repository: https://github.com/otmansabir/get_next_line
- Language: C

## What it does

`get_next_line(int fd)` reads from `fd` and returns the next line, including the newline character if one is encountered before EOF. It maintains internal state between calls to continue from where it left off, making it suitable for iterating through a file (or stdin) line by line.

The bonus version adds support for handling multiple file descriptors at once.

## Repository structure

- get_next_line.c — Core implementation
- get_next_line.h — Public header and API
- get_next_line_utils.c — String/util helpers for the core
- get_next_line_bonus.c — Bonus implementation (multi-FD)
- get_next_line_bonus.h — Bonus header
- get_next_line_utils_bonus.c — Helpers used by the bonus build

## API

```c
char *get_next_line(int fd);
```

- Parameters
  - `fd`: A valid file descriptor (e.g., from `open`, `STDIN_FILENO`, or a socket).
- Returns
  - A heap-allocated C string containing the next line (including the trailing `\n` when present).
  - `NULL` on EOF with no remaining data or on error.

Caller is responsible for `free`ing the returned pointer when non-NULL.

## Buffer size

This project typically relies on a compile-time macro `BUFFER_SIZE` to control read chunk size.

- Define it at compile time:
  - `-D BUFFER_SIZE=42` (example)
- Choosing a reasonable value (e.g., 32, 42, 1024) balances syscall frequency and memory usage.

If `BUFFER_SIZE` is not provided, the implementation may use a default value defined in the header/source.

## Building

No build system is required; compile directly with your compiler.

- Regular (single-FD) version:
  ```sh
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
     -c get_next_line.c get_next_line_utils.c
  ```
  Link the resulting objects with your program:
  ```sh
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
     your_main.c get_next_line.o get_next_line_utils.o -o your_program
  ```

- Bonus (multi-FD) version:
  ```sh
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
     -c get_next_line_bonus.c get_next_line_utils_bonus.c
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
     your_main.c get_next_line_bonus.o get_next_line_utils_bonus.o -o your_program
  ```

Adjust flags and compiler as needed for your environment.

## Usage example

Read all lines from a file:

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int   fd = open("input.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return 1;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

Read from stdin:

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
    char *line;
    while ((line = get_next_line(STDIN_FILENO)) != NULL)
    {
        // process line...
        free(line);
    }
    return 0;
}
```

## Behavior and edge cases

- Includes the newline character `\n` in the returned string when a line break is encountered.
- On EOF:
  - If there is leftover buffered data without a trailing newline, returns that final chunk.
  - Subsequent calls return `NULL`.
- Returns `NULL` on error (e.g., invalid `fd`, read failure, memory allocation failure).
- The function uses internal static storage to keep unread fragments between calls.

## Bonus features

- Supports reading from multiple file descriptors in parallel (e.g., interleaving calls to `get_next_line(fd1)` and `get_next_line(fd2)`).
- Keeps independent internal buffers per `fd`.

Use `get_next_line_bonus.c/.h` and corresponding utils for this behavior.

## Integration tips

- Always `free` the returned pointer when non-NULL.
- Guard against infinite loops by breaking on `NULL`.
- Consider wrapping calls in a helper that ensures cleanup on errors.
- Choose a `BUFFER_SIZE` appropriate to your workload and platform.

## Compatibility

- Standard C on Unix-like systems.
- Uses `read(2)`; ensure the descriptor is readable and opened appropriately.

## Author

- otmansabir — https://github.com/otmansabir

## License

No license file is present in this repository at the time of writing.
