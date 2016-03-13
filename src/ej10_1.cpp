#include <iostream>
using namespace std;

int ContieneCString(const char cad[], const char subcad[]);

int main(){
	char cad[] = "HoHola mundo",
		subcad1[] = "mundo",
		subcad2[] = "Hola",
		subcad3[] = "",
		subcad4[] = "No";
	int r1,r2,r3,r4;
	r1 = ContieneCString(cad, subcad1);
	r2 = ContieneCString(cad, subcad2);
	r3 = ContieneCString(cad, subcad3);
	r4 = ContieneCString(cad, subcad4);
	
	cout << r1 << r2 << r3 << r4 << endl;
}

int ContieneCString(const char cad[], const char subcad[]){
	int pos = 0,
		inicio = 0;
	bool igual,
		done = subcad[pos]=='\0';
		
	for(int i=0; cad[i]!='\0' && !done ; i++){
		igual = cad[i] == subcad[pos];
		done = igual && subcad[pos+1] == '\0';
		if(igual){
			if(pos==0)
				inicio = i;
			pos++;
		}
		else if(!done)
			pos = 0;
		
		if(!igual && cad[i] == subcad[pos])
			i--;
	}	
	inicio = done?inicio:-1;
	return inicio;
}
