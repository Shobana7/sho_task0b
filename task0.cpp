#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;
void shoba(vector<int> curtain_qty,vector<int> cus_query,int num,int query);
void kamal( vector<int>  curtain_qty,vector<int> cus_query,int num,int query);
void jasmine( vector<int> curtain_qty,vector<int>  cus_query,int num,int query);

int main()
{
    int n,q,i,j;
    
	cout<<"Enter the number of curtains \n";
	cin>>n ;
	
	vector<int> measurements(n);
	cout<<"Enter measurements \n";
    for (i=0; i<n; i++)
    cin>>measurements[i];
    
    cout<<"Enter the number of queries \n";
    cin>>q;
    
    vector<int> customer(q);
    cout<<"Enter the requirements \n";
    for(j=0;j<q;j++)
    cin>>customer[j];
    
    cout<<"SHOBA \n";shoba(measurements,customer,n,q);
    
    cout<<"KAMAL \n";kamal(measurements,customer,n,q);
    
    cout<<"JASMINE \n";jasmine(measurements,customer,n,q);

return 0;
}

void kamal( vector<int> curtain_qty,vector<int> cus_query,int num,int query)  
{ 
   int k,l,flag,p,t;

  for(k=0;k<query;k++)
  { 
     flag=0; 
     for(l=0;l<num;l++)                    /*finding the smallest no which is equal or greater than the req*/
	  {
	     if(curtain_qty[l]==cus_query[k])
	         {flag=1;
	         curtain_qty[l]=0;
	         break;
    	     }
    	
     }
     
     if(flag==1)
	     {
	       for(p=0;p<num;p++)
	       cout<<curtain_qty[p]<<" ";
	       cout<< "\n";
		 } 
	
	else if(flag==0)
	     { int s,d; 
		   int diff = abs(curtain_qty[0]-cus_query[k]);
		   for(s=0;s<num;s++)
		   {t=0;
		   d=curtain_qty[s]-cus_query[k];
		   	 if(d<=diff && d>0)
		      {t=1;
			  curtain_qty[s]-= cus_query[k];
		      break;}
		   }
        if(t==1)
	     {
	       for(s=0;s<num;s++)
	       cout<<curtain_qty[s]<<" ";
	       cout<< "\n";
		 } 
		 else 
		 cout<< "-1 \n";
         }       
     }
  }
		
void jasmine( vector<int> curtain_qty,vector<int> cus_query,int num,int query)
{
    int k,r,p,max,pos;
     
    for(k=0;k<query;k++)
      { 
         max=curtain_qty[0];
         for(r=1;r<num;r++)          /*finding the curtain of longest length*/
            {
	          if(curtain_qty[r]>max)
	          {
	             max=curtain_qty[r];
	             pos=r;
              }
	
            }
            
         if(curtain_qty[pos]>=cus_query[k])
	        {
	          curtain_qty[pos]-=cus_query[k];
	          for(p=0;p<num;p++)
              cout<<curtain_qty[p]<<" ";
	          cout<< "\n";
			} 
	     else 
	        cout<<"-1 \n";
      }   
}
  	
void shoba(vector<int> curtain_qty,vector<int> cus_query,int num,int query)
{ 
   int k,l,p,flag;
   
	for(l=0;l<query;l++)
	  {
	     for(k=num-1;k>=0;k--)                              /*the length that first fits */
	     { flag=0;
	       if(cus_query[l]==curtain_qty[k]||cus_query[l]<curtain_qty[k])
	         {
			 flag=1;
	         if(cus_query[l]==curtain_qty[k]) 
			 curtain_qty[k]=0;
	         else 
		     curtain_qty[k]-=cus_query[l];
	         break;}
         }  
   
   if(flag==1)
	{
	  for(p=0;p<num;p++)
	  cout<<curtain_qty[p]<<" ";
	  cout<< "\n";
	  } 
	else if(flag==0)
	  cout<<"-1 \n";
	
	  } 	
}

