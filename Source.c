#include<stdio.h>

int min(int x,int y);

void main ()
{
  int amount,coins,index,i,j;
  int deno[20];
  int array[100]={0};
  int table[20][20];
  
  
  printf("Enter amount : ");
  scanf("%d",&amount);
  
  printf("Enter no of coins :");
  scanf("%d",&coins);
  
  printf("Enter denominations :\n ");
  for(i=1;i<=coins;i++)
	{
	  scanf("%d",&deno[i]);
	} 
  
  //Check if amount is invalid
  if (amount <= 0)
    {
      printf ("Invalid amount");
    }

  //initialization if amount = 0
  for (i = 0; i <= coins; i++)
    {
      table[i][0] = 0; 
    }

  // initialization if items = 0
  for (j = 0; j <= amount; j++)
    {
      table[0][j] = 0; 
    }
    
    
  for (j = 1; j <= amount; j++) {
      for (i = 1; i <= coins; i++)	{
        	    if(deno[i] <= amount) {
        	      	if(deno[i]==1) {
        			        table[i][j]=j;
        	        }
        	      	else {
        			      if(j-(j%deno[i])<=0){
        				      table[i][j] =table[i-1][j];
        		      	}			
        			      else{  // Using previously computed values to fill table
        			        table[i][j] = min(table[i-1][j], (1 + table[i][j-(deno[i])]));
        		      	}		
        	      	} 
            	}
        	    else {
        		    table[i][j] = table[i-1][j];  // if amount less than denomination
             	}	
        	
      }
	}
	
  for (i = 0; i <= coins; i++) { // Printing the table generated
      for (j = 0; j <= amount; j++)
    	{
    	  printf("%d\t",table[i][j]);
    	}
    	printf("\n");
    }


      i=coins;
      j=amount;
      index = 1;

      while(i>0)  // Backtracking to get the denominations 
      {
        if(table[i][j]!=table[i-1][j]) {
      		array[index] = deno[i];
      		index++;
      		j=j-deno[i];
      		
      	}
        else
           i--;
      }

      printf("The denominations in change are  ");
      for(i=1;i<index;i++)
      {
        if(i==1){ // Condition to check if its first denomination to avoid a comma
          printf(" %d",array[i]);
        }
        else
        printf(",%d",array[i]);
      }
}

int min(int x,int y) // Function to find minimum
{
if(x<=y)
return x;
else return y;
}


	
