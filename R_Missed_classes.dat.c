//R_Missed_classes.dat

#include <stdio.h>
#include <conio.h>

typedef struct {
	char c;
	char s;
}ABSENTE;

typedef struct {
	char is;
	int nrmat;
	char nume[25];
	int grupa;
	char an;
	ABSENTE abs[15];
}STUDENT;

void consultare_integrala() {
	FILE* f, * g;
	fopen_s(&f, "R_Missed_classes.dat", "rb");
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
	fprintf_s(g, "%-5s %-10s %-30s %-10s %-5s ", "Crt.", "Nr. mat", "Nume", "Grupa", "An");
	for (int i = 0; i < 15; i++) {
		fprintf_s(g, "C%02d S%02d | ", i + 1, i + 1);
	}
	fprintf_s(g, "\n");
	fprintf_s(g, "======================================================================================================================================================================================================================\n");
	while (fread(&s, sizeof(STUDENT), 1, f)) {
		if (s.is == 1) {
			fprintf_s(g, "%-5d %-10d %-30s %-10d %-5d ", ++crt, s.nrmat, s.nume, s.grupa, s.an);
			for (int i = 0; i < 15; i++) {
				fprintf_s(g, "%-4d %-4d ", s.abs[i].c, s.abs[i].s);
			}
			fprintf_s(g, "\n");
		}
	}
	fclose(f);
	fclose(g);
	printf_s("Consultarea integrala s-a realizat cu succes.\nRezultatul acesteia se afla in fisierul Lista_control.txt\n");

}

void main() {
	consultare_integrala();
}
