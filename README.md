# MiniProject1
This code can do both encryption and decryption for whatever it is given. So first you give the code a file and then if you want to encrypt the code,
you insert number 1 then the code changes the file extension to .crp. If you want to decrypt it changes the extension to .txt . Then, if it is encrypting,
it subtracts 16 from the each character's ascii value, then if the value is still less than 32 then subtract a value of 32 and add a value of 144 and then 
it turns it into a hex number and prints it into a new file. If it's decrypting, it manually prints the "'" ,"?" and "!.Then if the digit is 0 or any even number
it subtracts 48 from its ascii value and then multiply it by 16, then if the second digit is a letter it adds its value that is between 10 and 15. If the second value 
isn't a letter, it subtracts a value of 48 from its ascii value . Now, if the value is greater than 127 it subtracts a value of 144 and adds a value of 32,
then it prints the corresponding character. If it isn't greater it prints the corresponding value straight away.
