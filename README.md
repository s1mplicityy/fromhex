# fromhex
Extremely simple command line utility to convert hex strings into raw bytes.

# Usage
Compile main.c for your system:

`gcc -lm -O3 -o fromhex main.c`

After the build is completed, you can run it:

`./fromhex deadbeef`

or

`.\fromhex deadbeef` on Windows systems.

Fromhex supports inline mode that you can enable by passing "i" after your hex string.

For example, `./fromhex deadbeef i` would output raw de, ad, be, ef bytes instead of human-readable format. You can check that with hexdump -C.

To take input from stdin, pass - instead of the hexstring. For example, `echo dead00beef | fromhex - i` would output raw de, ad, 00, be, ef bytes. It ignores newlines by default, otherwise it would error out on line breaks.

Inline mode is useful for command chaining and scripts in general.

To avoid having to navigate to the binary's directory each time you need fromhex, you can do `sudo cp ./fromhex /usr/bin` or add `export PATH="$PATH:/path/to/fromhex"` to the end of your shell profile file (.bashrc, .zshrc, depends on the shell you got).
