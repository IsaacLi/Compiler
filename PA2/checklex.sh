#! /bin/sh
./lexer $1 > tempa
reflexer $1 > tempb
diff tempa tempb
rm tempa
rm tempb