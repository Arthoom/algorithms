alias d='{ x=$(cat -); clang++ $x.cc -o $x -std=c++11 -Wall -Wextra -Wshadow -Wconversion -Wno-sign-conversion -Wno-unused-result -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -DDEBUG -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer -fno-optimize-sibling-calls; }<<<'
alias n='{ x=$(cat -); clang++ $x.cc -o $x -std=c++11 -static -m32 -O2; }<<<'
