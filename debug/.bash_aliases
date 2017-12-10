alias d='{ x=$(cat -); clang++ $x.cc -o $x -std=c++11 -Wall -Wextra -Wshadow -Wconversion -Wno-sign-conversion -Wno-unused-result -D_GLIBCXX_D$
alias n='{ x=$(cat -); clang++ $x.cc -o $x -std=c++11 -static -m32 -O2; }<<<'
