
#include "gd.h"


#include <stdio.h>
#define UNIT 2 // Đây là đơn vị của mỗi block

int main() {

  /* Declare the image */
  gdImagePtr im;
  /* Declare output files */
  FILE *pngout, *jpegout;
  /* Declare color indexes */
  int black;
  int white;

  /* Allocate the image: 64 pixels across by 64 pixels tall */
  im = gdImageCreate(300, 300);

	
  /* Allocate the color black (red, green and blue all minimum).
    Since this is the first color in a new image, it will
    be the background color. */
  black = gdImageColorAllocate(im, 0, 0, 0);

  /* Allocate the color white (red, green and blue all maximum). */
  white = gdImageColorAllocate(im, 255, 255, 255);
  int red = gdImageColorAllocate(im, 255, 0, 0);
  gdImageFill(im,0,0, white);
  
  // Mảng dưới tương ứng với 12345674
  char numbs[35] = {1,0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,0,0,1,1,1,0,1,0,0,0,0};
  //char numbs[1] = {1};
  int x1 =2, x2= 10;
  int start = 2;
  // Vẻ thử barcode với số 1001
  int i;
  for (i = 0; i < 35; i++) {
	  printf("i=%d\n",i);
	  if (numbs[i] == 1) {
			// Nếu là 1 thì màu đen chiếm 2/3, màu trắng chiếm 1/3
			x1 = start; x2 = x1 + UNIT * 2;
			gdImageFilledRectangle(im, x1,2, x2,50, black);
			x1 = x2; x2 = x1 + UNIT;
			gdImageFilledRectangle(im, x1,2, x2,50, white);
			start = x2;
	  } else {
			// Nếu là 1 thì màu đen chiếm 1/3, màu trắng chiếm 2/3
			x1 = start; x2 = x1 + UNIT;
			gdImageFilledRectangle(im, x1,2, x2,50, black);
			x1 = x2; x2 = x1 + UNIT * 2 ;
			gdImageFilledRectangle(im, x1,2, x2,50, white);
			start = x2;
	  }
	
  }
  
 
  /* Open a file for writing. "wb" means "write binary", important
    under MSDOS, harmless under Unix. */
  pngout = fopen("test.png", "wb");

  /* Do the same for a JPEG-format file. */
  //jpegout = fopen("test.jpg", "wb");

  /* Output the image to the disk file in PNG format. */
  gdImagePng(im, pngout);

  /* Output the same image in JPEG format, using the default
    JPEG quality setting. */
//  gdImageJpeg(im, jpegout, -1);

  /* Close the files. */
  fclose(pngout);
  //fclose(jpegout);

  /* Destroy the image in memory. */
  gdImageDestroy(im);
}
