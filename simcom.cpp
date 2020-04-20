#include <stdio.h>
int main()
{
	int n=0 ,result=0;
	char c=0;
	scanf("%d",&n);
	result=n;
	while(c!='='){
		scanf("%c",&c);	
		if(c=='=')
		    break;
		scanf("%d",&n);
	 	switch(c)
	 	{
	 		case '+':
	 			result=result+n;
				 break;
	 		case '-':
	 			result=result-n;
				 break;
	 		case '*':
	 			result=result*n;
		 		break;
	 		case '/':
                if(n==0){
                    printf("ERROR");
                    return 0;
                }
                else
	 			    result=result/n;
		 		break;
			default:
				printf("ERROR\n");
				return 0;
	 	}		 	
	}
	printf("%d",result);
    return 0;
 } 
