#include <stdio.h>
#include <stdlib.h>
#define MIN 2
#define MAX 100
#define SOUBOR "cisla.txt"
#define SOUBOR1 "vysledky.txt"

int main(int argc, char *argv[]) {
	int c1;
	int c2;
	int i;
	int lmc;
	int gcd;
	int radky=1;
	FILE *fp;
	FILE *fp2;
	fp = fopen(SOUBOR, "r");
	if(fp == NULL){
		printf("Read/Open ERROR");
		return EXIT_FAILURE;		
	}
		fp2 = fopen(SOUBOR1, "w");
	if(fp2 == NULL){
		printf("Write/Open ERROR");
		return EXIT_FAILURE;		
	}
	
	
	printf("--------------------------------------\t|\nporadi \t cislo1 cislo2 \t nsn \t nsd\t|\n--------------------------------------\t|\n");
	
	while(fscanf(fp,"%d %d",&c1,&c2) == 2){
	 for(i=1;i<=c1&&i<=c2;i++){
	 	if(c1%i == 0 && c2%i == 0)
	 	gcd = i;
	 }
	 lmc = (c1*c2)/gcd;
	 printf("%d.\t %d\t %d\t %d\t %d\t|\n",radky,c1,c2,lmc,gcd);
	 if(gcd !=1)
	 fprintf(fp2,"%d.\t %d\t %d\t %d\t %d\t|\n",radky,c1,c2,lmc,gcd);
	 ++radky;
	}
	printf("--------------------------------------\t|\n");
	printf("v souboru %s je %d dvojic cisel",SOUBOR,radky-1);
	if(fclose(fp) == EOF)
	printf("Read/Close ERROR");
	if(fclose(fp2) == EOF)
	printf("Write/Close ERROR");
	
	return 0;
}
