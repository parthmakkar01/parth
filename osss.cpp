#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
	int p,i,z=0,sum=0,sum1=0,e,r,s;
	printf("enter the number of processes:");
	scanf("%d",&p);
	int a[p],b[p]={0},c[p]={0},t[p]={0},w[p]={0};
	
	
	for(i=0;i<p;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<p;i++)
	{
		if(a[i]==0)
		{
			b[i]=2;
		}
		else
		{
			b[i]=2*a[i];
		}
	}
	for(int r=0;r<p-1;r++)
	{
		for(i=0;i<p-1-r;i++)
		{
			if(a[i]>a[i+1])
			{
				s=a[i];
				a[i]=a[i+1];
				a[i+1]=s;
			}
		}
		
	}
	
	
	for(int r=0;r<p-1;r++)
	{
		for(i=0;i<p-1-r;i++)
		{
			if(b[i]>b[i+1])
			{
				s=b[i];
				b[i]=b[i+1];
				b[i+1]=s;
			}
		}
		
	}
	
/*	for(i=0;i<p;i++)
	{
		cout<<"a["<<i<<"]:";
		cout<<a[i]<<endl;
	}
	
	
	for(i=0;i<p;i++)
	{
		cout<<"b["<<i<<"]:";
		cout<<b[i]<<endl;
	}*/
	
	
	
	
	
	
	
	
	
	
	
	int j=0,j1=0;
	for(i=0;i<p;i++)
	{
		z=z+b[i];
		if(a[0]==0)
		{
			
			if(j==0)
			{
				c[i]=c[i]+z;
				
				j=1;	
			}
			else
			{
				if(a[i]<=c[i-1])
				{
					c[i]=z;
				}
				else
				{
					c[i]=(z+a[i]-c[i-1]);
					z=z+a[i]-c[i-1];
				}
			}	
		}
		else
		{
			if(j1==0)
			{
				c[i]=z+(a[i]-0);
				z=z+(a[i]-0);
				j1=1;
			}
			else
			{
				if(a[i]<=c[i-1])
				{
					c[i]=z;
				}
				else
				{
					c[i]=(z+a[i]-c[i-1]);
				}
				
			}	
		}
	}
	
	for(i=0;i<p;i++)
	{
		t[i]=c[i]-a[i];
	}
	for(i=0;i<p;i++)
	{
		w[i]=t[i]-b[i];
	}
	
	for(i=0;i<p;i++)
	{
		sum=sum+t[i];
	
	}
	for(i=0;i<p;i++)
	{
		sum1=sum1+w[i];
	}
	
	
	printf("process_number \t arrival_time \t burst_time \t completion time \t turn_around_time \t waiting_time \n");
	for(i=0;i<p;i++)
	{
		printf("%d \t\t %d \t\t %d \t\t %d \t\t\t %d \t\t\t %d  \n",i,a[i],b[i],c[i],t[i],w[i]);
		
	}

	printf("\naverage turn_around_time for first come first serve is : %d\n",(sum/p));
	printf("average waiting_time for first come first serve is : %d ",(sum1/p));
	






	/// now for shortest job first  
	
	
	

	printf("\naverage turn_around_time for shortest job first is : %d\n",(sum/p));
	printf("average waiting_time for shortest job first is : %d ",(sum1/p));





}
