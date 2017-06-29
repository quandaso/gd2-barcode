How to build on Ubuntu
sudo apt-get -y install libgd2-xpm-dev build-essential
gcc test.c -static -lgd -lpng  -lz -ljpeg -lm -o test