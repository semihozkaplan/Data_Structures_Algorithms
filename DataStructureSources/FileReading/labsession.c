#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct note {

	float grd1;
	float grd2;
	float grd3;
	
};

struct student {

	char name[20];
	char surname[20];
	struct note grd;

};


int main(void) {

	struct student std[5];
	float ave[5];

	FILE* inpf;
	FILE* outf;

	inpf = fopen("inpf.txt", "r");
	outf = fopen("outf.txt", "w");

	int i = 0;
	int j = 0;
	
		
	fscanf(inpf, "%s %s %f %f %f ", std[0].name, std[0].surname, &std[0].grd.grd1, &std[0].grd.grd2, &std[0].grd.grd3);
	
	while (!feof(inpf)) {

		i++;
		fscanf(inpf, "%s %s %f %f %f", std[i].name, std[i].surname, &std[i].grd.grd1, &std[i].grd.grd2, &std[i].grd.grd3);
		ave[i] = ((std[i].grd.grd1) + (std[i].grd.grd2) + (std[i].grd.grd3)) / 3;
		printf("%.2f", ave[i]);
	}
		
	
	double avec = (ave[1] + ave[2] + ave[3] + ave[4] + ave[5]) / 5;


	for (int j = 0; j < 5; j++)
	{

		if (ave[j] < avec) fprintf(outf, "%s %s %f", std[j].name, std[j].surname, ave[j]);

	}
	
	fclose(inpf);
	fclose(outf);

	return 0;
}