#/bin/sh
cd src
make config
cd ..

rm -f s++

SPRITE=`pwd`"/lib/libsprite.a -I"`pwd`"/include -I/usr/include/X11 -L/usr/lib/i386-linux-gnu -L/usr/X11R6/lib -lX11"

echo "#!/bin/sh" >> s++
echo "echo \"g++ \"  \$@  -Wall "$SPRITE >> s++
echo "g++ \$@ -Wall "$SPRITE >> s++
chmod +x s++

echo "To compile use: "`pwd`"/s++ filename.cpp"

