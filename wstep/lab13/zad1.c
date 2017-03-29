#include<stdio.h>
#include<string.h>

main()
{
	char c, im[30], nz[30];
	int i;

	FILE *fp=fopen("dane.txt","r");

	while(fscanf(fp,"%s %s %d",im,nz,&i)==3)
	{
		printf("%s %s %d\n",im,nz,i);
	}

	/*while((c=fgetc(fp))!=EOF)
	{
		printf("%c",c);
	}*/
	fclose(fp);

}
