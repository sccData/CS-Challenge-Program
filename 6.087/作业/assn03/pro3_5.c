#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 100
#define NUM     9

int main(int argc, char* argv[]) {
	FILE* fp1 = fopen("stateoutflow0708.txt", "r");

	if(fp1 == NULL) return 0;

	FILE* fp2 = fopen("record.txt", "w");

	if(fp2 == NULL) return 0;

	char stateCodeOrigin[STRSIZE];
	char countyCodeOrigin[STRSIZE];
	char stateCodeDest[STRSIZE];
	char countyCodeDest[STRSIZE];
	char stateAbbrv[STRSIZE];
	char stateName[STRSIZE];
	char returnNum[STRSIZE];
	char exmptNum[STRSIZE];
	int aggrAgi;

	char line1[STRSIZE * NUM];
	char line2[STRSIZE * NUM];

	fputs("STATE\tTOTAL\n", fp2);
	fputs("--------------\n", fp2);
	int total = 0;

	while(fgets(line1, STRSIZE * NUM, fp1)) {
		sscanf(line1, "%s %s %s %s %s %s %s %s %d", stateCodeOrigin, countyCodeOrigin, stateCodeDest, 
													countyCodeDest, stateAbbrv, stateName, returnNum, 
													exmptNum, &aggrAgi);
		if(strcmp(stateCodeOrigin, "\"25\"") == 0) {
			sprintf(line2, "%s\t%d\n", stateName, aggrAgi);
			total += aggrAgi;
			fputs(line2, fp2);
		}
	}

	fputs("--------------\n", fp2);
	sprintf(line2, "Total\t%d", total);
	fputs(line2, fp2);

	fclose(fp1);
	fclose(fp2);

	return 0;
}
