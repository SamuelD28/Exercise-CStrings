#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "UtilityHeader.h"

#define TEST1 "  ALLO   "
#define TEST2 " ALLO TLM "
#define TAILLE_LECTURE 50
#define TEST_ASSAINIR "A;B,CD####\\"
#define TEST_SAIN "ABCD"

int main()
{
	setlocale(LC_ALL, "");

	char chaine[TAILLE_LECTURE];
	char* mots[] = { "bleu", "blanc", "rouge", NULL };

	//Methode modifer avec Trimmer
	LireChaineNonVide("Entrer une chaine non-vide.", chaine, TAILLE_LECTURE);
	LireChaineTailleControlée("Entrer une chaine de taille controler.", chaine, TAILLE_LECTURE, 3, 6);

	assert(!isdangereux('A'));
	assert(isdangereux(';'));

	LireMotSelonEnsemble("Une des couleurs du tricolore : ", chaine, TAILLE_LECTURE, mots);
	assert(strcmp(chaine, "bleu") == 0 || strcmp(chaine, "blanc") == 0 || strcmp(chaine, "rouge") == 0);

	char chiffreFavori = LireCaractèreSelonFonction("Chiffre favori : ", isdigit);
	assert(isdigit(chiffreFavori));

	AfficherLigneSéparatrice(80, '-');

	char dest[1000] = "";

	strcpy(chaine, TEST1);

	// TESTS TRIM
	TrimmerEspaces(chaine, dest);
	if (strcmp(chaine, TEST1)) puts("Test1 : fail");
	if (strcmp(dest, "ALLO")) puts("Test2 : fail");

	strcpy(chaine, TEST2);
	TrimmerEspaces(chaine, dest);
	if (strcmp(chaine, TEST2)) puts("Test3 : fail");
	if (strcmp(dest, "ALLO TLM"))  puts("Test4 : fail");

	TrimmerEspacesSurPlace(chaine);
	if (strcmp(chaine, "ALLO TLM"))  puts("Test5 : fail");

	strcpy(chaine, TEST1);
	TrimmerEspacesSurPlace(chaine);
	if (strcmp(chaine, "ALLO"))  puts("Test6 : fail");


	strcpy(chaine, TEST_ASSAINIR);
	Assainir(chaine, dest);
	if (strcmp(chaine, TEST_ASSAINIR))  puts("Test6b : fail");
	if (strcmp(dest, TEST_SAIN)) puts("Test7 : ca dépend des caractères dangereux considérés");
	strcpy(chaine, TEST_ASSAINIR);
	AssainirSurPlaceSelonEnsemble(chaine, ";");
	if (strcmp(chaine, "AB,CD####\\")) puts("Test8 : fail");

	strcpy(chaine, TEST_ASSAINIR);
	AssainirSurPlaceSelonFonction(chaine, isdangereux);
	if (strcmp(chaine, TEST_SAIN)) puts("Test9 : ca dépend des caractères dangereux considérés");

	strcpy(chaine, TEST_ASSAINIR);
	AssainirSurPlaceSelonFonction(chaine, ispunct);
	if (strcmp(chaine, "ABCD")) puts("Test10 : fail");
}