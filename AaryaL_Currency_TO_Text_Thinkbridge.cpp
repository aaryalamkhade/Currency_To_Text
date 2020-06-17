#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int number(int digits)       //Function for single digit number   eg.one,one thosand,one lakh,etc
{
	switch(digits)
	{   
		case 1:cout<<" One";
		       break;
		case 2:cout<<" Two";
		       break;
	    case 3:cout<<" Three";
		       break;	
	    case 4:cout<<" Four";
		       break;
	    case 5:cout<<" Five";
		       break;
		case 6:cout<<" Six";
		       break;
		case 7:cout<<" Seven";
		       break;
		case 8:cout<<" Eight";
		       break;
		case 9:cout<<" Nine";
		       break;
			   	   	   	   	   		    		   	          
	}
}

int doublenumber(int digit_copy,int digits)           //Function for double digit number   eg.Twenty,Twenty thosand,Twenty one lakh,etc
{ 
	switch(digit_copy)
	    {
	    	case 1:switch(digits)
	    	       {
	    	       	case 10:cout<<" Ten";
	    	       	        break;
	    	       	case 11:cout<<" Eleven";
	    	       	         break;
	    	       	case 12:cout<<" Twelve";
	    	       	        break;
	    	       	case 13:cout<<" Thirteen";
	    	       	        break;
	    	       	case 14:cout<<" Forteen";
	    	       	        break;
	    	       	case 15:cout<<" Fifteen";
	    	       	        break;
	    	       	case 16:cout<<" Sixteen";
	    	       	        break;
	    	       	case 17:cout<<" Seventeen";
	    	       	        break;
	    	       	case 18:cout<<" Eighteen";
	    	       	        break;
	    	       	case 19:cout<<" Nineteen";
	    	       	         break;
	    	       	}
	    	       	break;
	        case 2:cout<<" Twenty";
	               number(digits);
	                break;
	        case 3:cout<<" Thirty";
	               number(digits);
	              break;
	        case 4:cout<<" Forty";
	               number(digits);
	              break;
	        case 5:cout<<" Fifty";
	               number(digits);
	              break;
	        case 6:cout<<" Sixty";
	                number(digits);
	              break;
	        case 7:cout<<" Seventy";
	               number(digits);
	              break;
	        case 8:cout<<" Eighty";
	              number(digits);
	              break;
	        case 9:cout<<" Ninety";
	              number(digits);
	              break;
	       
		}
}
 
int word(double float_amount,int int_amount)              //why double bcaz after that 0.7584 ans comes
{     
	double decimalNo = fmod(float_amount, 1);           //fmod is modula function for double  eg.1.25 fmod gives the value 0.25
    stringstream s;                                    //Bcaz we cant give double value to string
	s<<decimalNo;                                     // s read a value from y
	string h;
	s>>h;                                            //s write its value to h
	int decimalNo_length=h.length()-2;              //length of the digits after point   eg 0.25 len=2
    int int_length = 0;
	int x1=int_amount;
    for(; x1 != 0; x1 /= 10, int_length++);        //length of int value eg 125 len=3
    int int_lenght1=int_length;
	if(int_lenght1>9)
	{
	   cout<<"Enter the number which  have 9 digits before decimal point";	
	}
	else
	{                             
	int decimalNo_pow=pow(10,int_length-1);              
	if(int_lenght1==0)
	{
		cout<<"zero";                             // for zero value
	}
	else
	{
	while(int_length>0)                         //spiltting digits from Number
	{  
	int p=int_amount/decimalNo_pow;            //Spilt the digit in the way they appear eg.123   1,2,3
	int	digits=p%10;  
		decimalNo_pow=decimalNo_pow/10;  
		int_length--;
		int digit_copy=digits;                            //bcaz 11,12 cant be in switchcase
		if(int_length==1 || int_length==4 || int_length==6 || int_length==8)              // for  2 digit numbers eg.10,20,30 
		{   
		   if(digits==1)                       //for 10-19 values
		   {
			 p=int_amount/decimalNo_pow; 
	      	 digits=digits*10+p%10;                //gives value 10,12,..,19
		     decimalNo_pow=decimalNo_pow/10;
		     int_length--;
		    }
		   else
		   {
		     p=int_amount/decimalNo_pow;          //for no other than 10-19
		     digits=p%10;  
		     decimalNo_pow=decimalNo_pow/10;
		     int_length--;
		     if(digits==0)
		     {
		   	  int_length=0;          //so that loop will break here after getting 0
		     }
		   }
		}
      	    
		   if(digit_copy==0)
		   {
		   	 int_lenght1=0;        //for 100,1000,10000
		   } 
    	switch(int_lenght1)
    	{   
    		case 1: 
				     number(digits); 
    		         int_lenght1--;
    		          break;
    		case 2:doublenumber(digit_copy,digits);
    		       int_lenght1--;
    		       int_lenght1--;
    		       break;
    	    case 3:number(digits);
    	           cout<<" Hundred";
    	           int_lenght1--;
    	           break;
    	    case 4:
			       number(digits);
    	           cout<<" Thousand";
    	           int_lenght1--;
    	           break;
    	    case 5:doublenumber(digit_copy,digits);
    	           cout<<" Thousand";
    	           int_lenght1--;
    	           int_lenght1--;
    	           break;
    	    case 6:number(digits);
    	           cout<<" Lakh";
    	           int_lenght1--;
    	           break;
    	    case 7:doublenumber(digit_copy,digits);
    	           cout<<" Lakh";
    	           int_lenght1--;
    	           int_lenght1--;
    	           break;
    	    case 8:number(digits);
    	           cout<<" Crore";
    	           int_lenght1--;
    	           break;
    	    case 9:doublenumber(digit_copy,digits);
    	         cout<<" Crore";
    	           int_lenght1--;
    	           int_lenght1--;
    	           break;
    	  	}
	}
	cout<<" ";
    if(decimalNo!=0)                         //if there is a complete integers
	{  
		 cout<<decimalNo*pow(10,decimalNo_length)<<"/"<<pow(10,decimalNo_length);    //numbrs after decimal point
	}
}	  
}
}
int main()                                    //main function
{       int loop_value;
		cout<<"...........Currency To Text...........";
		cout<<endl<<endl;
	do
	{
	   double float_amount;
	    int int_amount;
	    cout<<"Enter Currency Value: ";
	    cin>>float_amount;
	    int_amount=float_amount;
	    cout<<"In Words: ";
		word(float_amount,int_amount);
		cout<<endl<<endl;
		cout<<"If you want to convert currency to text again Press 1:";
	    cin>>loop_value;
	}while(loop_value==1);
}



