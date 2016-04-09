# Encryption Caesar Shift

This project will work as a demo expecting that there will be a file named `./plain.txt` with plain text to be encrypted.
It will then create a `./encrypted.txt` file with the caesar shift encoding.

You can also provide a custom shift value as part of your command line argument list. It looks a little something like this:
- $`caesar_shift.exe 10`
- $`caesar_shift.exe 20`

You can also specify a file but if you do you will need to specify a custom shift value like above. It will look something like this:
- $`caesar_shift.exe 10 ./some_message.txt`
- $`caesar_shift.exe 20 ./another_message.txt`

Currently this doesn't provide an decryption from command line.
