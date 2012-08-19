#! /bin/sh
./myparser $1 > parsed.my
reflexer $1 | refparser $1 > parsed.ref
diff parsed.ref parsed.my
rm parsed.ref parsed.my