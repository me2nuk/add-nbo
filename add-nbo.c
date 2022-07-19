#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t ntohl(uint32_t n){
	
	uint32_t n1 = (n & 0xFF000000 ) >> 24;
	uint32_t n2 = (n & 0x00FF0000 ) >> 8;
	uint32_t n3 = (n & 0x0000FF00 ) << 8;
	uint32_t n4 = (n & 0x000000FF ) << 32;

	return n1 | n2 | n3 | n4;
}

int main(int argc, char *argv[]){

	/* number of arguments checking */
	if( argc < 3 ){
		printf("Invalid number of arguments.\nex ) ./add-nbo <FILE 1> <FILE 2>");
		exit(0);
	}

	/* FILE TYPE varaible */
	FILE *fp1;
	FILE *fp2;
	
	/* uint32_t TYPE fread variable */
	uint32_t f1;
	uint32_t f2;

	fp1 = fopen(argv[1], "rb");
	fp2 = fopen(argv[2], "rb");

	/* FILE READ Check */
	if( fp1 == NULL || fp2 == NULL ){
		printf("Invalid File.");
		exit(0);
	}

	/* file read */
	fread(&f1, sizeof(uint32_t), 1, fp1);
	fread(&f2, sizeof(uint32_t), 1,  fp2);

	/* call network to host long function */
	f1 = ntohl(f1);
	f2 = ntohl(f2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", f1, f1, f2, f2, f1 + f2, f1 + f2);

	/* file close */
	fclose(fp1);
	fclose(fp2);

	return 1;
}
