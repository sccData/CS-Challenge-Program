#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{
    FILE* fp=NULL;
    int   nfiles =--argc; /*ignore the name of the program itself*/
    int   argidx =1;      /*ignore the name of the program itself*/
    char* currfile="";
    char  c;
    enum state {INSIDE, OUTSIDE};
    enum state currstate = OUTSIDE;
    /*count of words,lines,characters*/
    unsigned long nw=0,nl=0,nc=0;

    if(nfiles==0) 
    {
        fp=stdin; /*standard input*/
        nfiles++; 
    }
    else /*set to first*/
    {
        currfile=argv[argidx++];
        fp=fopen(currfile,"r");
    }
    while(nfiles>0) /*files left >0*/
    {
       if(fp==NULL)
        {
            fprintf(stderr,"Unable to open input\n");
            exit(-1);
        }
        nc=nw=nl=0;
        while((c=getc(fp))!=EOF)
        {
		if(c == '\n') {
			nl++;
		} else if(c == ' ' || c == '\t') {
			currstate = OUTSIDE;
		} else {
			++nc;
			if(currstate == OUTSIDE) {
				currstate = INSIDE;
				++nw;
			}
			currstate = INSIDE;
		}
        }
        printf("%ld %ld %ld %s\n",nc, nw, nl, currfile);
        /*next file if exists*/
        nfiles--;
        if(nfiles>0)
        {
            currfile=argv[argidx++];
            fp     =fopen(currfile,"r");
        }
    }
	return 0;
}
