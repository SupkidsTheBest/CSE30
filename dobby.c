#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>


void dobbySpeak(int argc, char **argv){
	int i;
	int res1;
	int res2;
	int res3;
	int res4;
	int res5;
	int res6;
	int res7;
   for(i = 1; i < argc; ++i){
	   if(i < argc - 1){
		res1 = strcmp(argv[i], "I");
		res2 = strcmp(argv[i], "me");
		res3 = strcmp(argv[i+1], "have");
		res4 = strcmp(argv[i+1], "am");
		res5 = strcmp(argv[i+1],"do");
		res6 = strcmp(argv[i], "my");
		res7 = strcmp(argv[i], "mine");
		if(res2 == 0){
			printf("Dobby ");
	  	}
	  	else if((res6 == 0) || (res7 ==0)){
	  		printf("Dobby's ");
	  	}
	  	else if((res1 == 0) && (res3 == 0)){
			if(i != argc - 2){
	  	 		printf("Dobby has ");
			}
			else{
				printf("Dobby has.");
			}
			i++;
	  	}
		else if((res1 == 0) && (res4 == 0)){
			if(i != argc-2){
	  	 		printf("Dobby is ");
			}else
			{
				printf("Dobby is.");
			}
			i++;
			
	  	}
		else if((res1 == 0) && (res5 == 0)){
	  	 	if(i != argc - 2){
	  	 		printf("Dobby does ");
			}else
			{
				printf("Dobby does.");
			}
			i++;
	  	}
		else if(res1 == 0){
			if(i != argc - 2){
				printf("Dobby %ss ", argv[i+1]);
			}
			else{
				printf("Dobby %ss.", argv[i+1]);

			}
			i++;
		}
		else{
			printf("%s ", argv[i]);
		}
	}
	else{
		res1 = strcmp(argv[i], "I");
		res2 = strcmp(argv[i], "me");
		res6 = strcmp(argv[i], "my");
		res7 = strcmp(argv[i], "mine");
		if(res2 == 0 || res1 == 0){
			printf("Dobby.\n");
	  	}
		else if((res6 == 0) || (res7 ==0)){
	  	 	printf("Dobby's.\n");
	  	}
		else{
			printf("%s.\n", argv[argc - 1]);
		}
	}
    }
}


void dobbyHex(int value, char **argv){
	int val = atoi(argv[value]);
	printf("Dobby casts a hex! The value is 0x%x.\n", val);
}
void dobbyHelp(){
	printf("Usage:\n./dobby -h\n./dobby -x [number]\n./dobby [space-separated text]\n");
}

int main(int argc, char **argv){
	int hex_mode = 0;
	int opt;
	int val = 0;
	while((opt = getopt(argc, argv, "xh")) !=-1) {
		switch(opt) {
			case 'x':
				hex_mode = 1;
				dobbyHex(optind, argv);
				break;
			case 'h':
				hex_mode = 2;
				dobbyHelp();
					break;
			default:
				break;
		}
	}
	if(hex_mode == 0){ 
		dobbySpeak(argc, argv);
	}
}

