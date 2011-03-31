#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MARK6_MAX_NUM 49

void ball_machine_init(int remains[])
{
  int i=0;
	for (i=1;i<=MARK6_MAX_NUM;i++) remains[i]=i;
        remains[MARK6_MAX_NUM+1]=0;
        remains[0]=0;
}

int ball_machine_run(int n, int i, int results[], int remains[])
{
  int r=0;
  int rr=0;
  int j=0;
  int k=0;

	if(i>n) return 0;
	
	r=rand()%(MARK6_MAX_NUM-i+1) + 1;
	rr=remains[r];
	for(j=r;j<=MARK6_MAX_NUM;j++) remains[j]=remains[j+1];
	results[i]=rr;
	if (i>1) {
		for(j=i;j>1;j--) {
			if (rr>results[j-1]) {
				for (k=i;k>j;k--) results[k]=results[k-1];
				results[j]=rr;
				j=0;
			}	
		}
		if (rr<results[1]) {
        		for (k=i;k>1;k--) results[k]=results[k-1];
        		results[1]=rr;
        	}
	}
	return ball_machine_run(n,++i,results,remains);
}

int main(int argc, char* argv[])
{
  int i=0;
  int n=6;
  int r=1;
  int s=1;
  int all_balls[MARK6_MAX_NUM+2];
  int *results;


	if (argc>=2) n=atoi(argv[1]);
	if (n<6) n=6;	
	if (n>MARK6_MAX_NUM) n=MARK6_MAX_NUM;

	if (argc>=3) r=atoi(argv[2]);
	if (r<1) r=1;

        results = (int*) malloc((n+1) * sizeof (int));
	
	srand(time(NULL));
	for (s=1;s<=r; s++) {
		for (i=0;i<=n;i++) results[i]=0;
		ball_machine_init(all_balls);
		ball_machine_run(n, 1, results, all_balls);
		for(i=1;i<=n;i++) printf("%2d ",results[i]);
		printf("\n");
	}

	free(results);
	exit(0);
}
