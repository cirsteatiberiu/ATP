//S_Study.dat

#include <stdio.h>
#include <conio.h>
typedef struct
{
	int nrmat;
	char nume[30];
	char an;
	int grupa;
	char tip;
	struct
	{
		char zi;
		char luna;
		int an;
	}data;
	struct
	{
		char oraIntrare;
		char minIntrare;
	}intrare;
	struct
	{
		char oraIesire;
		char minIesire;
	}iesire;
}STUDENT;


void consultare_integrala() {
	FILE* f, * g;
	fopen_s(&f, "S_Study.dat", "rb");
	if (!f) {
		printf_s("Eroare la deschiderea fisierului binar.\n");
		return;
	}
	fopen_s(&g, "Lista_control.txt", "wt");
	if (!g) {
		printf_s("Eroare la deschiderea fisierului text.\n");
		fclose(f);
		return;
	}
	STUDENT s;
	int crt = 0;
	fprintf_s(g, "%-4s %-10s %-25s %-5s %-7s %-5s %-13s %-8s %-6s\n", "Crt.", "Nr. mat.", "Nume", "An", "Grupa", "B/L", "Data", "Ora intrare", "Ora iesire");
	fprintf_s(g, "==================================================================================================\n");
	while (fread(&s, sizeof(STUDENT), 1, f)) {
		fprintf_s(g, "%-4d %-10d %-25s %-5d %-7d %-5c %02d.%02d.%4d    %02d:%02d       %02d:%02d\n", ++crt, s.nrmat, s.nume, s.an, s.grupa, s.tip, s.data.zi, s.data.luna, s.data.an, s.intrare.oraIntrare, s.intrare.minIntrare, s.iesire.oraIesire, s.iesire.minIesire);
	}
	fclose(f);
	fclose(g);

	printf_s("Consultarea integrala s-a realizat cu succes.\nRezultatul acesteia se afla in fisierul Lista_control.txt\n");

}

void main() {
	
	consultare_integrala();

}
