#include<stdio.h>
#include<string.h>

main()
{
	char c, im[30], nz[30];
	int i,zarobki;

	FILE *fp=fopen("dane.txt","r");
	FILE *fp2=fopen("wysokie-zarobki.txt","r");
	
	printf("Podaj zarobki\n");
	scanf("%d",&zarobki);

	while(fscanf(fp,"%s %s %d",im,nz,&i)==3)
	{
		if(i>=zarobki)
		printf("%s %s %d\n",im,nz,i);
	}
	fclose(fp);

}
