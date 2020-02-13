#!/usr/bin/bash

# asymmetic encryption algorithm
# using 2048bit to generate the private key
/usr/local/bin/openssl genpkey -algorithm RSA -out private_key.pem -pkeyopt rsa_keygen_bits:2048

# to generate the public key
/usr/local/bin/openssl rsa -pubout -in private_key.pem -out public_key.pem

# to create a encrypted version of the file
/usr/local/bin/openssl rsautl -encrypt -inkey public_key.pem -pubin -in PlainTextFile.txt -out EncryptedData.txt


