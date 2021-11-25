gcc -Wfatal-errors \
-std=c99 \
./*.c \
-lmingw32 \
-lSDL2main \
-lSDL2 \
-o game.exe