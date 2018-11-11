#ifndef UTILITY_INCLUDED
#define UTILITY_INCLUDED

#include <stdbool.h>

int LireEntier32(char p_question[]);
int LireEntier32AvecMinimum(char p_question[], int p_min);
int LireEntier32DansIntervalle(char p_question[], int p_min, int p_max);
bool ConfirmerOuiOuNon(char p_question[]);
void LireChaine(char p_question[], char* chaine, size_t p_taille);
void LireChaineFormatée(char p_question[], char* format, char* chaine);
void LireChaineNonVide(char p_question[], char* chaine, size_t p_taille);
void LireChaineAlnum(char p_question[], char* chaine, size_t p_taille);
void AppendChar(char* s, char c);
int  isdangereux(int c);
void LireMotSelonEnsemble(char p_question[], char* mot, size_t tailleMot, char* pMots[]);
char LireCaractèreSelonFonction(char p_question[], int(*pFonction)(int));
void AfficherLigneSéparatrice(int n, char c);
void TrimmerEspaces(const char* str, char* strFinale);
void TrimmerEspacesSurPlace(char* str);
void Assainir(const char* str, char* strFinale);
void AssainirSelonEnsemble(const char* str, char* strFinale, const char* ensemble);
void AssainirSurPlaceSelonEnsemble(char* str, char* ensemble);
void AssainirSelonFonction(const char* str, char* strFinale, int(*pFonction)(int));
void AssainirSurPlaceSelonFonction(char* str, int(*pFonction)(int));
void AssainirSurPlace(char* str);
void LireChaineTailleControlée(char p_question[], char* chaine, size_t taille, size_t p_lgMin, size_t p_lgMax);
void ViderBuffer();

#endif UTILITY_INCLUDED