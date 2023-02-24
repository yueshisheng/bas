// FrechetDist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <math.h>

typedef struct _sPoint
{
	float x;
	float y;
}sPoint;	

#define max(a,b) (((a)>(b))?(a):(b))

float dis(sPoint *p1, sPoint* p2, int i, int j)
{
	return sqrt(pow(p1[i].x-p2[j].x,2) + pow(p1[i].y-p2[j].y,2));
}

float min3(float f1, float f2, float f3)
{
	float minf = (f1 < f2)? f1 : f2;
	minf = (minf < f3)? minf : f3;
	return minf;
}


float Cal(sPoint* p1, sPoint *p2,float** ca, int i, int j)
{
	if(ca[i][j] > -1.0)
	{
		return ca[i][j];
	}
	else if(i == 0 && j == 0)
	{
		ca[i][j] = dis(p1,p2,0,0);
	}
	else if(i > 0 && j == 0)
	{
		ca[i][j] = max(Cal(p1,p2,ca,i-1,0),dis(p1,p2,i,0));
	}
	else if(i == 0 && j > 0)
	{
		ca[i][j] = max(Cal(p1,p2,ca,0,j-1),dis(p1,p2,0,j));
	}
	else if(i > 0 && j > 0)
	{
		ca[i][j] = max(min3( Cal(p1,p2,ca,i-1,j), Cal(p1,p2,ca,i-1,j-1), Cal(p1,p2,ca,i,j-1) ), dis(p1,p2,i,j));
	}
	else
	{
		ca[i][j] = 0xFFFFFFFF;
	}

	return ca[i][j];

}


float calcFrechet(sPoint *p1, int p, sPoint* p2, int q)
{
	// init ca[p][q]
	float **ca = new float*[p];
	for(int i = 0 ; i < p ; i++)
	{
		ca[i] = new float[q];
	}

	for(int i = 0 ; i < p ; i++)
	{
		for(int j = 0 ; j < q ; j++)
		{
			ca[i][j] = -1.0;
		}
	}

	float r=Cal(p1,p2,ca,p-1,q-1);


	for (int i=0; i<p; i++)
	{
		for (int j=0; j<q; j++)
		{
			printf("%f ",ca[i][j]);
		}
		printf("\n");
	}


	for(int i = 0 ; i < p ; i++)
		delete []ca[i];
	delete []ca;

	return r;

}


float calcFrechetBottomUp(sPoint *p1, int p, sPoint* p2, int q)
{
	float **ca = new float*[p];
	for(int i = 0 ; i < p ; i++)
	{
		ca[i] = new float[q];
	}

	for(int i = 0 ; i < p ; i++)
	{
		for(int j = 0 ; j < q ; j++)
		{
			ca[i][j] = -1.0;
		}
	}

	ca[0][0] = dis(p1,p2,0,0);
	for (int i=1; i<p; i++)
		ca[i][0] = max(ca[i-1][0],dis(p1,p2,i,0));

	for (int i=1; i<p; i++)
		ca[0][i] =max(ca[0][i-1],dis(p1,p2,0,i));

	for (int i=1; i<p; i++)
	{
		for (int j=1; j<q; j++)
		{
			ca[i][j] = max(min3( ca[i-1][j], ca[i-1][j-1], ca[i][j-1] ), dis(p1,p2,i,j));
		}
	}
	float r=ca[p-1][q-1];

	for(int i = 0 ; i < p ; i++)
		delete []ca[i];
	delete []ca;

	return r;
}


int main(int argc, _TCHAR* argv[])
{
	sPoint p1[5] = {{1.0,2.0},{2.0,3.0},{3.0,4.0},{4.0,5.0},{5.0,6.0}};
	sPoint p2[7] = {{1.0,-2.0},{2.0,-3.0},{3.0,-4.0},{4.0,-5.0},{5.0,-6.0},{6.0,-7.0},{7.0,-8.0}};

// 	sPoint p1[6] = {{1.0,2.0},{2.0,3.0},{3.0,4.0},{4.0,5.0},{5.0,6.0},{6.0,-7.0}};
// 	sPoint p2[6] = {{1.0,2.0},{2.0,3.0},{3.0,4.0},{4.0,5.0},{5.0,6.0},{6.0,-8.0}};

	float r=calcFrechet(p1,5,p2,7);

	//float r=calcFrechetBottomUp(p1,5,p2,7);


	printf("Frechet distance: %f   \n",r);

	return 0;
}

