#include <stdio.h>
#include <stdbool.h>

Columna(char s){
	if (s=='+' || s=='-') return 0;
	if (s=='0'          ) return 1;
	if (s>='1' && s<='9') return 2;
	                      return 3;
}

int Automata(char *s, int MT [5][4]){
	int e = 0;
	int i = 0;
	int r = 0;
	bool signo = true;
	
	if (s[i] == '-') signo = false;
	if (s[i] == '+') signo = true;
			
	while (s[i] && e != 4){
		
		if (s[i] != '+' && s[i] != '-')
		r= r*10+(s[i] - '0');
		
		e = MT[e][Columna(s[i])];
		i++;
    }
    if(signo == false)
		r = -r;
	if(e == 1 || e==3){
		printf("\n\nla cadena tomada es valida y corresponde al numero: %i", r);
		return 1;
    }
    else{
    	printf("\n\nla cadena tomada es invalida!");
	return 0;
	}	
}


int main (){
	int MT[5][4] = {
		{2, 1, 3, 4},
		{4, 4, 4, 4},
		{4, 4, 3, 4},
		{4, 3, 3, 4},
		{4, 4, 4, 4}
	};
	
	char s[100];
	
	printf("Identificador de cadenas dentro de un automata finito.\n\nIngrese una cadena: ");
	scanf ("%s", s);
	Automata(s, MT);
}

