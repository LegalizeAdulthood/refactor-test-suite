#!/bin/sh
echo '# All Cases' > AllCases.md
echo '' >> AllCases.md
grep '#TEST#' ../RefactorTest/* \
 | sed -e 's/[^#]*#TEST#: \([A-Z][A-Z]*\)\([0-9][0-9]*\).*$/\1 \2/' \
 | sort -k1,1d -k2,2n \
 | sed -e 's/ \([0-9]\)$/\1   | TBD/' \
       -e 's/ \([0-9][0-9]\)$/\1  | TBD/' \
       -e 's/ \([0-9][0-9][0-9]\)$/\1 | TBD/' \
       -e 's/^\(...[A-Z]..\) /\1/' \
       -e 's/^\(..[A-Z]..\) /\1/' \
       -e 's/^\(.[0-9]...\)/\1 /' \
       -e 's/^\(...[A-Z]. \)/\1 /' \
 >> AllCases.md
