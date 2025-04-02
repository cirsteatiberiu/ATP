//R_Points.dat

#include <stdio.h>
#include <conio.h>

typedef struct {
	int nrm;
	char nume[30];
	int grupa;
	char pp;
	char teme[10];
	char ex;
	char is;
}STUDENT;

void consultare_integrala() {
	FILE* f, * g;
	fopen_s(&f, "R_Points.dat", "rb");
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
	fprintf_s(g, "%-5s %-10s %-30s %-10s %-10s %-20s %-5s\n", "Crt.", "Nr. mat.", "Nume", "Grupa", "Pct. PP", "Pct. T", "Pct. E");
	fprintf_s(g, "=================================================================================================\n");
	while (fread(&s, sizeof(STUDENT), 1, f)) {
		if (s.is == 1) {
			fprintf_s(g, "%-5d %-10d %-30s %-10d %-10d ", ++crt, s.nrm, s.nume, s.grupa, s.pp);
			for (int i = 0; i < 10; i++)
				fprintf_s(g, "%-2d", s.teme[i]);
			fprintf_s(g, " %-5d\n", s.ex);
		}
	}
	fclose(f);
	fclose(g);
	printf_s("Consultarea integrala s-a realizat cu succes.\nRezultatul acesteia se afla in fisierul Lista_control.txt\n");

}

void main() {
	consultare_integrala();
}
