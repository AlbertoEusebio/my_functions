/*
	Some usefull functions i often use
	@EusebioAlberto
*/

#include "my_functions.h"


int lenght(char *str){
/*	this function returns the lenght of a string of text */

	int lenght = 0;
	
	for(;;str++){
		if(*str != '\0'){
			lenght++;
		}
		else{
			break;
		}
		
		
	}
	return lenght;
	
} 

char* reverse(char *str, char buff[]){
/* This function reverses a string of text*/
	int i = lenght(str)-1;
	buff[i+1] = '\0';
	for(int c = i; c>=0; c--, str++){
		buff[c] = *str;
	}
	return buff;
	
}

void lower(char str[]){
/*This function sets all the characters in a string to the lower case*/	
	for(int i=0;i<lenght(str);i++){
		
		if(str[i] >= 65 && str[i] <= 90){
			str[i] += 32;
		}
		
	}
	
}

void upper(char str[]){
/*This function sets all the characters in a string to the upper case*/	
	for(int i=0;i<lenght(str);i++){
		
		if(str[i] >= 97 && str[i] <= 122){
			str[i] -= 32;
		}
		
	}
	
}

void clear_string(char *str){
/*This function clear an array of chars*/
//N.B. pass only char arrays as argument

	for(int i=0; i<lenght(str); i++){
		str[i] = '\0';
		
	}
}


void binary_code(int n, char str[]){
	
	/*This function takes a number and converts it in binary*/
	//N.B. the char str must be an array and it must be 40 bits large or more
	
	const int dim = 32;
	
	int bin[dim]; //evry int is 4 bytes long, so 8*4=32
	
	for(int i=0; i<dim ;i++){
		//I set all the characters to 0 to avoid errors
		bin[i] = 0;
	}
	
	/*This is the actual alghoritm*/
	int c = abs(n);
	
	for(int i = dim-1; i>=0; i--){ 
		if(c>1){
			bin[i] = c%2;
			if(c%2==0){
				c /= 2;
			}
			else{
				c--;
				c /= 2;
			}
		}
		else if(c==1){
			bin[i] = 1;
			break;
		}
		else{
			break;
		}
	}
	
	if(n<0){
		for(int i = dim-1; i>=0; i--){
			bin[i] = !bin[i];
		}
	}
	
	/*I convert all the numbers in chars and I reverse the array*/
	for(int i=0; i<dim; i++){
		if(bin[i] == 1){
			str[i] = '1';
		}
		else if(bin[i] == 0){
			
			str[i] = '0';
			
		}
	}
	str[dim] = '\0';
	
}


_Bool all_equals(int n[], int size){
	
/*This function returns True if all the elements of the arry are equals*/
	
	for(int i=0;i<size;i++){
		
		if(n[0] == n[i]){
			continue;
		}
		else{
			return 0;
		}
		
	}
	
	return 1;
	
}

void delay(clock_t mill){
/*This function is a delay function*/

	clock_t start = 0 , end = 0, diff = 0;
	clock_t CLOCKS_PER_MILLISECOND = CLOCKS_PER_SEC/1000;

	start = clock();
	for(;diff<mill;){
		end = clock();
		diff = (end - start)/CLOCKS_PER_MILLISECOND;
	}

}


char* i_to_str(long int n, char buff[], int b){
/*It converts an integer into a string of characters in a certain base and returns it*/
	long int var = n;
	int i = 0;
	
	while(var > 0){
		var /= (int) b;
		i++;
	}
	var = n;
	buff[i] = '\0';
	for(;i>0; i--){
		buff[i-1] = (var%b)+48;
		var /= (int) b;
	}
	
	return buff;
}

long int str_to_i(char* str, int b, int size){
	/*
	this program takes an input string of numbers and returns its contenent into a number. 
	Can also accept negative numbers but not string with spaces or letters, otherwise the behavior is unexpected
	*/

	signed long int number = 0;
	int zero = (int) '0';
	int i = 0;
	_Bool negative = 0;
	if(str[i] == '-'){
		negative = 1;
		i++;
	}
	for(; i<size; i++){
		number += (str[i]-zero)*((int)pow(b, size-i-1));
	}
	if(negative){
		number *= -1;
	}
	return number;
	
}
