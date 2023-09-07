# LibASM
1. **Project**: Library of standard C functions written in 64-bit ASM

2. **Main Function**: Project contains a `main` function that tests the functions and compiles with the library to demonstrate functionality.

3. **Functions to Rewrite**:
   - `ft_strlen` (Refer to `man 3 strlen` for details)
   - `ft_strcpy` (Refer to `man 3 strcpy` for details)
   - `ft_strcmp` (Refer to `man 3 strcmp` for details)
   - `ft_write` (Refer to `man 2 write` for details)
   - `ft_read` (Refer to `man 2 read` for details)
   - `ft_strdup` (Refer to `man 3 strdup`, and you may call `malloc`)

4. **Error Handling**: Errors are checked during syscalls and set properly when necessary. Code sets the `errno` variable correctly.
