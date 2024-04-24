#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void split_yuv420p_I420(char *inputPath, int width, int height) {
    FILE *fp_yuv = fopen(inputPath, "rb+");
    FILE *fp_y = fopen("./out/output_420p_y.y", "wb+");
    FILE *fp_u = fopen("./out/output_420p_u.y", "wb+");
    FILE *fp_v = fopen("./out/output_420p_v.y", "wb+");
 
    unsigned char *data = (unsigned char *) malloc(width * height * 3 / 2);
    fread(data, 1, width * height * 3 / 2, fp_yuv);
    fwrite(data, 1, width * height, fp_y);  // Y
    fwrite(data + width * height, 1, width * height / 4, fp_u); // U
    fwrite(data + width * height * 5 / 4, 1, width * height / 4, fp_v); // V
 
    free(data);
    fclose(fp_yuv);
    fclose(fp_y);
    fclose(fp_u);
    fclose(fp_v);
}

void split_yuv422p_I422(char *inputPath, int width, int height) {
    FILE *fp_yuv = fopen(inputPath, "rb+");
    FILE *fp_y = fopen("./out/output_422p_y.y", "wb+");
    FILE *fp_u = fopen("./out/output_422p_u.y", "wb+");
    FILE *fp_v = fopen("./out/output_422p_v.y", "wb+");
 
    unsigned char *data = (unsigned char *) malloc(width * height * 2);
    fread(data, 1, width * height * 2, fp_yuv);
    fwrite(data, 1, width * height, fp_y); // Y
    fwrite(data + width * height, 1, width * height / 2, fp_u); // U
    fwrite(data + width * height * 3 / 2, 1, width * height / 2, fp_v); // V
    
    free(data);
    fclose(fp_yuv);
    fclose(fp_y);
    fclose(fp_u);
    fclose(fp_v);
}

void split_yuv444p_I444(char *inputPath, int width, int height) {
    FILE *fp_yuv = fopen(inputPath, "rb+");
    FILE *fp_y = fopen("./out/output_444p_y.y", "wb+");
    FILE *fp_u = fopen("./out/output_444p_u.y", "wb+");
    FILE *fp_v = fopen("./out/output_444p_v.y", "wb+");
 
    unsigned char *data = (unsigned char *) malloc(width * height * 3);
    fread(data, 1, width * height * 3, fp_yuv);
    fwrite(data, 1, width * height, fp_y); // Y
    fwrite(data + width * height, 1, width * height, fp_u); // U
    fwrite(data + width * height * 2, 1, width * height, fp_v); // V
    
    free(data);
    fclose(fp_yuv);
    fclose(fp_y);
    fclose(fp_u);
    fclose(fp_v);
}

int main(int argc, char *argv[]){
	struct stat st;
	if (stat("out", &st) != 0) {
		if (mkdir("./out", 0777) == -1) {
			return -1;
		}
	} 

	split_yuv420p_I420("./yuv420p.yuv", 480, 320);
	split_yuv422p_I422("./yuv422p.yuv", 480, 320);
	split_yuv444p_I444("./yuv444p.yuv", 480, 320);

	return 0;
}
