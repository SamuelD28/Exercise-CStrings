#include <memory.h>

#define REF
#define OUT

// On recoit un int et retourne un int parcequ'on veut avoir 
// la m�me signature que les fonctions de la librairie (ispunct, isalpha, isalnum, etc)
// et aussi car LireCaract�reSelonFonction veut une fonction 
// de type int Fct(int)
// Les caract�res dangereux sont : #@/%&*()|\,.;<>
int isdangereux(int c); // 1 ligne

// Cette fonction se fait en moins de 100 caract�res (une seule instruction)
// Pensez � r�utiliser LireMot() et vous inspirer de l�exemple � vecteur de cstrings �
// <param name="p_question">LA question � poser</param>
// <param name="mot">valeur de retour</param>
// <param name="tailleMot">taille du buffer mot</param>
// <param name="pMots">les choix de mots</param>
void LireMotSelonEnsemble(char p_question[], OUT char* mot, size_t tailleMot, char* pMots[]);
char LireCaract�reSelonFonction(char p_question[], int(*pFonction)(int)); // 4 lignes environ

// Les deux prochaines fonctions enl�vent les caract�res dangereux et se font en 1 ligne
void AssainirSurPlace(REF char* str);
// On assume que les chaines ne se chevauchent pas
void Assainir(const char* str, OUT char* strFinale);

// Pour les 4 prochaines fonctions, c�est possible que vous ayez � faire un peu de 
// copier-coller mais c�est possible de ne pas le faire en se d�finissant une fonction
// � isdansensemblecourant �
void AssainirSelonFonction(const char* strSource, OUT char* strFinale, int(*pFonction)(int));
void AssainirSelonEnsemble(const char* str, OUT char* strFinale, const char* ensemble);
void AssainirSurPlaceSelonEnsemble(char* str, char* ensemble);
void AssainirSurPlaceSelonFonction(char* str, int(*pFonction)(int));

void TrimmerEspacesSurPlace(REF char* str)
// On assume que les chaines ne se chevauchent pas
void TrimmerEspaces(const char* str, OUT char* strFinale);

// Maintenant valider avec TrimmerEspaces() avant de tester strlen>0
void LireChaineNonVide(char p_question[], char* chaine, size_t taille);
void LireChaineTailleControl�e(char p_question[], char* chaine, size_t taille, size_t p_lgMin, size_t p_lgMax);

// Cette fonction affiche le caract�re c n fois avec un \n � la fin.
// Codegolf : 29 char de code � battre, sans compter les espaces
void AfficherLigneS�paratrice(int n, char c);
