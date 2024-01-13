 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#define n 50
#define MAX 50

void gotoxy(int x,int y)
{
	COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}























char * convertirEnMajuscules(char mot[]) {
    int i = 0;

    while (mot[i] != '\0') {
        if (mot[i] >= 'a' && mot[i] <= 'z') {
            mot[i] = mot[i] - 'a' + 'A';
        }
        i++;
    }
    return mot;
}




                           // LES STRUCTURES
// ETUDIANT :
typedef struct Etudiant{
	char * cne;
	char nom_etd[n];
	char prenom_etd[n];
	char pass[n];
	struct Etudiant* suivant;
} Etudiant;


typedef struct Liste_Etudiant{
	int taille;
	Etudiant * tete;
	Etudiant *qeue;
}Liste_Etudiant;




//Note :
typedef struct Note {
	Etudiant * etudiant;
	char matiere[n];                      // liste des matieres est constantes, + Gestion des matiere n'est pas demandée
	float note;
	struct Note * suivant;
}Note;

typedef struct Liste_Note {
	int taille;
	Note * tete;
	Note *qeue;
}Liste_Note;


//Date :
typedef struct Date {
	int jour;
	int mois;
	int annee;
}Date;


Date saisir_date() {
    Date date;

    // Saisie du jour
    do {
    printf("Veuillez entrer le jour : ");
    scanf("%d", &date.jour);
    
    if(date.jour <1 || date.jour>31)
    {
    	printf("\nLe jour entre n est pas valide !!! ressayer svp.\n\n");
    	getchar();
	}
	}
	while (date.jour <1 || date.jour>31);
  
  

 do {
 	printf("Veuillez entrer le mois : ");
    scanf("%d", &date.mois);
    
        if(date.mois<1 || date.mois>12)
    {
    	printf("\nLe Mois entre n est pas valide !!! ressayer svp.\n\n");
    	getchar();
	}
    
 }while(date.mois<1 || date.mois>12);
   


    printf("Veuillez entrer l'année : ");
    scanf("%d", &date.annee);

    return date;
}


//presnece :
typedef struct Presence {
	Etudiant * etud;
	char matiere[n];
	int presence;
	Date date;
	struct Presence * suivant;
}Presence;

typedef struct Liste_presence {
	int taille;
	Presence * tete;
	Presence *qeue;
}Liste_presence;



                          //les fonctions

//etudiant
Etudiant * initialisation_etudiant(){

	Etudiant * etud = (Etudiant*)malloc(sizeof(Etudiant));
	etud->cne = NULL;
	etud->nom_etd[0] = '\0';
	etud->prenom_etd[0] = '\0';
	etud->pass[0] = '\0';
	etud->suivant = NULL;
return etud;
}

Liste_Etudiant * initialisation_liste_etudiant(){

	Liste_Etudiant * liste_etud = (Liste_Etudiant*)malloc(sizeof(Liste_Etudiant));
	liste_etud->taille = 0;
	liste_etud->tete = NULL;
	liste_etud->qeue = NULL;

	return liste_etud;
}

Liste_Etudiant * ajouter_Etudiant_entete(Liste_Etudiant * lst_etud){
	
   char cne[n], nom[n], prenom[n];

    printf("Veuillez entrer le CNE de l etudiant : ");   
    scanf("%s", cne);  

    printf("Veuillez entrer le Nom de l etudiant : ");
    scanf("%s", nom); 

    printf("Veuillez entrer le Prenom de l etudiant : ");
    scanf("%s", prenom); 

    

   
	Etudiant * nouveau_etd = initialisation_etudiant();

	nouveau_etd->cne = (char*)malloc(10 * sizeof(char));
	strcpy(nouveau_etd->cne,cne);

	strcpy(nouveau_etd->nom_etd,nom);
	strcpy(nouveau_etd->prenom_etd,prenom);
	strcpy(nouveau_etd->pass,cne);




	if(lst_etud->tete == NULL)
	{
			lst_etud->tete = nouveau_etd;
			lst_etud->qeue = nouveau_etd;
			
			
	}
	else
	{
		
		   nouveau_etd->suivant = lst_etud->tete;
		   lst_etud->tete = nouveau_etd;
		   
		 
	}
	lst_etud->taille++;

	return lst_etud;
}

void afficher_liste_etudiant(Liste_Etudiant * lst_etud)

{
	Etudiant * p = lst_etud->tete;
	while(p!=NULL)
	{
		printf("Le CNE est : %s \n",p->cne);
		printf("Le Nom est : %s \n",p->nom_etd);
		printf("Le prenom est : %s \n",p->prenom_etd);
	

		p = p->suivant;
		
	    printf("-----------------------------------------------------\n");
	}
}

Etudiant * chercherSuppEtudiantParCNE(Liste_Etudiant *liste, char cne[]) {
    Etudiant *courant = liste->tete;
 
    while (courant != NULL) {
    	
        if (strcmp(courant->cne, cne) == 0) {
        
		 return courant;   
        }
        courant = courant->suivant;
    }
    
    return NULL;
}






int nb_abs_etud(Liste_presence *listePresence, char *cne_entree) {
    int count = 0;


    Presence *currentPresence = listePresence->tete;

    while (currentPresence != NULL) {
    
  
        if (strcmp(currentPresence->etud->cne, cne_entree) == 0) {
        	
        	if(currentPresence->presence == 0)
        	{
        		  count++;
       
			}
          
        }


        currentPresence = currentPresence->suivant;
    }

    return count;
}






Liste_Etudiant* supprimer_etudiant(Liste_Etudiant* liste,  char cne[]) {
    Etudiant* current = liste->tete;
    Etudiant* etd = chercherSuppEtudiantParCNE(liste, cne);
    
    if(etd != NULL)
{
  
    Etudiant* prec = NULL;

    while (current != NULL &&strcmp(current->cne, etd->cne) != 0) {
        prec = current;
        current = current->suivant;
    }
    

    if (prec == NULL) {
     
        liste->tete = current->suivant;
      
    } else {
        prec->suivant = current->suivant;
    }

    free(current->cne);
    free(current);    
    liste->taille--;  
	
	 printf("\n L etudiant est Bien supprime :)\n");	
}

else
{
	    printf("L'Étudiant avec le CNE : [ %s ] n existe pas :( \n", cne);
}


    return liste;
}







void chercherEtudiantsParNom(Liste_Etudiant *liste,char nom[]) {
	
    Liste_Etudiant * result = initialisation_liste_etudiant();

    Etudiant *courant = liste->tete;

    
    char * nom2Maj;
    char * prenom2Maj;
    
    char * nomMaj = convertirEnMajuscules(nom);
    
        

   



    while (courant != NULL) {
    	
    
    nom2Maj = convertirEnMajuscules(courant->nom_etd);
    prenom2Maj = convertirEnMajuscules(courant->prenom_etd);
    
    
        if ((strcmp(nom2Maj, nomMaj) == 0) || (strcmp(prenom2Maj, nomMaj) == 0)) {
   
            
            Etudiant *nouvelEtudiant = (Etudiant *)malloc(sizeof(Etudiant));
            *nouvelEtudiant = *courant;
            nouvelEtudiant->suivant = NULL;

            if (result->tete == NULL) {
                result->tete = result->qeue = nouvelEtudiant;
            } 
			else {
                nouvelEtudiant->suivant = result->tete;
                result->tete = nouvelEtudiant;
            }

            result->taille++;
        }
        courant = courant->suivant;
    }
    
    
    
    afficher_liste_etudiant(result);

}



    
void modifier_etudiant(Liste_Etudiant * liste , char cne[]){
	
	Etudiant* etd = chercherSuppEtudiantParCNE(liste, cne);
   
	
	int a ;
	char nv_cne[n] , nv_nom[n] , nv_prenom[n];
	
	do {
	
	printf("\n 1 : Modifier le CNE \n");
	printf("2 : Modifier le nom \n");
	printf("3 : Modifier le prenom \n");
	printf("0 : Retour \n");
	
	
	
	scanf("%d",&a);
	system("cls");
	
	switch (a) {
	
		case 1 :
			printf(" Entrer la Neuville CNE \n");
			scanf("%s",nv_cne);
			strcpy(etd->cne,nv_cne);
			printf("\n DONE");
			    getchar();
			    getchar();
			   system("cls");break;
		case 2 :
			printf(" Entrer la Neuville Nom \n ");
			scanf("%s",nv_nom);
			strcpy(etd->nom_etd,nv_nom);
			printf("\n DONE");
			    getchar();
			    getchar();
			   system("cls");break;
		case 3 :
			printf("1 : Entrer la Neuville Prenom \n");
			scanf("%s",nv_prenom);
			strcpy(etd->prenom_etd,nv_prenom);
			printf("\n DONE");
			    getchar();
			    getchar();
			   system("cls");break;
			   
			   
			   	      default : 
			      
				printf("\n Votre choix n existe pas dans le menu :( \n");
			   getchar();
			    getchar();
			   system("cls");break;
			
	}
	}while (a!=0);
	
	
	
}


void chercherEtudiantParCNE(Liste_Etudiant *liste, char cne[]) {
    Etudiant *courant = liste->tete;
	char * cne2Maj = convertirEnMajuscules(cne);
    while (courant != NULL) {
    char *cneMajuscules = convertirEnMajuscules(courant->cne);
    	
   
    	
        if (strcmp(courant->cne, cne)==0) {  
        	
        printf("Le CNE est : %s \n",courant->cne);
		printf("Le Nom est : %s \n",courant->nom_etd);
		printf("Le prenom est : %s \n",courant->prenom_etd);

		
		return;
             
        }
        courant = courant->suivant;
    }
    
    printf("\n\tAUCUN ETUDIANT AVEC CE ** CNE **\n");
    
    
}





//note

Note * initialisation_note() {
    Note * elt_note = (Note*)malloc(sizeof(Note));
    elt_note->etudiant = NULL;
    elt_note->matiere[0] = '\0';
    elt_note->note = 0.0;
    elt_note->suivant = NULL;
    return elt_note;
}


Liste_Note * initialisation_liste_note() {
    Liste_Note * liste_note = (Liste_Note*)malloc(sizeof(Liste_Note));
    liste_note->taille = 0;
    liste_note->tete = NULL;
    liste_note->qeue = NULL;
    return liste_note;
}


Liste_Note * ajouter_note_entete(Liste_Note * lst_note, Etudiant * etud, char matiere[], float note) {
    Note * nouvelle_note = initialisation_note();
    nouvelle_note->etudiant = etud;
    strcpy(nouvelle_note->matiere, matiere);
    nouvelle_note->note = note;

    if (lst_note->tete == NULL) {
        lst_note->tete = nouvelle_note;
        lst_note->qeue = nouvelle_note;
    } else {
        nouvelle_note->suivant = lst_note->tete;
        lst_note->tete = nouvelle_note;
    }
    lst_note->taille++;

    return lst_note;
}




Liste_Note * ajouter_note_tt(Liste_Note * lst_note, char matiere[],Liste_Etudiant * lst_etd){
Etudiant * caurant = initialisation_etudiant();
caurant = lst_etd->tete;
float note ;
while (caurant != NULL) {
	do {

printf("entrer la Note de l etudiant %s %s (%s) \n",caurant->nom_etd,caurant->prenom_etd,caurant->cne);
scanf("%f",&note);
printf("\n");

if (note < 0 || note > 20)
{
	printf("\n Svp Entrer une note Comprise entre 0 et 20 \n");
}
	} while(note < 0 || note > 20);
	
lst_note = ajouter_note_entete(lst_note,caurant,matiere,note);

caurant =caurant->suivant;

}
return lst_note;
}





void afficher_liste_note(Liste_Note * lst_note) {
    Note * p = lst_note->tete;
    while (p != NULL) {
        printf("CNE  : %s \n", p->etudiant->cne);
        printf("MATIERE : %s \n", p->matiere);
        printf("NOTE : %.2f \n", p->note);

        p = p->suivant;
    }
}

void afficher_liste_note_matiere(Liste_Note * lst_note,char matiere[])
{
	
	printf("\t\t [ **  %s ** ] \n\n",matiere);
	 Note * p = lst_note->tete;
    while (p != NULL) {
    	
    	if(strcmp(matiere,p->matiere)==0)
    	{
    	printf("CNE : %s \n", p->etudiant->cne);
    	printf("NOM : %s %s \n",p->etudiant->nom_etd,p->etudiant->prenom_etd);
        printf("NOTE :  %.2f / 20  \n", p->note);
        printf("------------------------------------------------------------------\n");
    		
		}
 

        p = p->suivant;
    }
}




void afficher_liste_note_etudiant(Liste_Note *lst_note, char cne1[]) {
    Note *p = lst_note->tete;
    
   int show_name = 0;


    while (p != NULL) {
        if (strcmp(p->etudiant->cne, cne1) == 0) {
        	
        	
        
        		if(show_name == 0)
        	{
        		printf("------------------------------------\n");
        		printf("       ETUDIANT : %s %s             \n",p->etudiant->nom_etd,p->etudiant->prenom_etd);
        		printf("       CNE: %s                      \n", p->etudiant->cne);
        		printf("------------------------------------\n\n");
        		show_name =1;
        		 printf("\t[ ** LES NOTES ** ]\n\n");
			}
			
			
		
		   
            printf("MATIERE : [ %s ] -- NOTE: [ %.2f / 20 ] \n",p->matiere,p->note);
            printf("------------------------------------------------------------------\n");
            
           
        		
	

        }
        

        p = p->suivant;
    }
    
}



Note* chercherNote(Liste_Note* listeNotes, char matiere[]) {
    Note* currentNote = listeNotes->tete;

    while (currentNote != NULL) {
        if (strcmp(currentNote->matiere, matiere) == 0) {
            
            return currentNote;
        }
        currentNote = currentNote->suivant;
    }


    return NULL;
}


//presence :


Presence * initialisation_presence() {
    Presence * presence = (Presence*)malloc(sizeof(Presence));
    presence->etud = NULL;
    presence->matiere[0] = '\0';
    presence->presence = 0;

    presence->suivant = NULL;
    return presence;
}


Liste_presence * initialisation_liste_presence() {
    Liste_presence * liste_presence = (Liste_presence*)malloc(sizeof(Liste_presence));
    liste_presence->taille = 0;
    liste_presence->tete = NULL;
    liste_presence->qeue = NULL;
    return liste_presence;
}


Liste_presence * ajouter_presence_entete(Liste_presence * lst_presence, Etudiant * etud, char matiere[], int presence, Date date) {
    Presence * nouvelle_presence = initialisation_presence();
    nouvelle_presence->etud = etud;
    strcpy(nouvelle_presence->matiere, matiere);
    nouvelle_presence->presence = presence;
    nouvelle_presence->date = date;

    if (lst_presence->tete == NULL) {
        lst_presence->tete = nouvelle_presence;
        lst_presence->qeue = nouvelle_presence;
    } else {
        nouvelle_presence->suivant = lst_presence->tete;
        lst_presence->tete = nouvelle_presence;
    }
    lst_presence->taille++;

    return lst_presence;
}

Liste_presence * ajouter_presence_tt(Liste_presence * lst_presence, char matiere[], Date date,Liste_Etudiant * lst_etd){
Etudiant * caurant = initialisation_etudiant();
caurant = lst_etd->tete;
int presence ;
while (caurant != NULL) {
	do {

printf("entrer la presence de l etudiant %s %s (%s) \n",caurant->nom_etd,caurant->prenom_etd,caurant->cne);
printf("\t\t\t 1- Present\t 0- Absent \t");
printf("\n");
scanf("%d",&presence);
printf("\n");

if (presence != 0 && presence !=1)
{
	printf("\n Choix de presence est invalide ! \n");
}
	} while(presence != 0 && presence !=1);
	
lst_presence = ajouter_presence_entete(lst_presence,caurant,matiere,presence, date);

caurant =caurant->suivant;



}

return lst_presence;
}


void afficher_liste_presence(Liste_presence * lst_presence) {
    Presence * p = lst_presence->tete;
    while (p != NULL) {
    	
    
    	printf("DATE : %d / %d / %d \n",p->date.jour,p->date.mois,p->date.annee);
        printf("CNE : %s \n", p->etud->cne);
        printf("NOM ET PRENOM : %s %s \n",p->etud->nom_etd,p->etud->prenom_etd);
        printf("MATIERE : %s \n", p->matiere);
        printf("STATUE : \t");
        if(p->presence == 1)
        printf("** Present **\n");
        else
        printf("** Absent **\n");
        
        printf("\n------------------------------------------------------------\n");

        p = p->suivant;
    }
}


void afficher_liste_presence_etu(Liste_presence *lst_presence, char cne1[]) {
    Presence *p = lst_presence->tete;
    
   int show_name = 0;
   int was_abs=0;

    while (p != NULL) {
        if (strcmp(p->etud->cne, cne1) == 0) {
        	
        	
        
        		if(show_name == 0)
        	{
        		printf("------------------------------------\n");
        		printf("       ETUDIANT : %s %s            \n",p->etud->nom_etd,p->etud->prenom_etd);
        		printf("       CNE: %s                     \n", p->etud->cne);
        		printf("------------------------------------\n\n");
        		show_name =1;
        		  printf("\t[ ** LES ABSENCES ** ]\n\n");
			}
			
			
				if(p->presence == 0)
        	{
		  
            printf("DATE : [ %d / %d / %d ] -- MATIERE: [ %s ] \n\n",p->date.jour,p->date.mois,p->date.annee ,p->matiere);
        		
        		was_abs = 1;
        		
			}

        }
        

        p = p->suivant;
    }
    
    if (was_abs == 0)
    {
    	printf("\n\t\tCet Etudiant n a acune absence jusqu a ajourd hui\n\n");
    	
	}
}


void afficher_liste_presence_date(Liste_presence * lst_presence, Date date_p, char listeMatieres[][n], int nombreMatieres) {
    printf("\t\t\t\t DATE : %d / %d / %d \n", date_p.jour, date_p.mois, date_p.annee);

    for (int i = 0; i < nombreMatieres; i++) {
        char* matiereCourante = listeMatieres[i];
        printf("\n\t\tMATIERE: %s\n\n", matiereCourante);

        Presence * p = lst_presence->tete;
        int found = 0;

        while (p != NULL) {
            if (p->date.jour == date_p.jour && p->date.mois == date_p.mois && p->date.annee == date_p.annee && strcmp(p->matiere, matiereCourante) == 0) {
                printf("CNE : %s \n", p->etud->cne);
                printf("NOM : %s %s \n",p->etud->nom_etd,p->etud->prenom_etd);
                printf("STATUE : \t");
                printf("%s\n", (p->presence == 1) ? "** Present **" : "** Absent **");
                found = 1;
                printf("\n------------------------------------------------------------------------------------------------------\n");
            }
            p = p->suivant;
            
        }

        if (!found) {
            printf("Aucune presence / absence enregistree pour cette matiere a cette date.\n");
        }
        
        printf("\n\n\n");
    }
    
}










void sauvegarder_etudiants_dans_fichier_txt(Liste_Etudiant *lst_etud, const char *nom_fichier_etudiant) {
    FILE *fichier_etudiant = fopen(nom_fichier_etudiant, "w");

    if (fichier_etudiant == NULL) {
        return;
    }

    Etudiant *etud_courant = lst_etud->tete;
    while (etud_courant != NULL) {

        fprintf(fichier_etudiant, "CNE: %s\n", etud_courant->cne);
        fprintf(fichier_etudiant, "Nom: %s\n", etud_courant->nom_etd);
        fprintf(fichier_etudiant, "Prenom: %s\n", etud_courant->prenom_etd);
        fprintf(fichier_etudiant, "Pass: %s\n", etud_courant->pass);
        fprintf(fichier_etudiant, "\n");  

        etud_courant = etud_courant->suivant;
    }

    fclose(fichier_etudiant);
    printf("Les donnees des etudiants bien enregistrees.\n");
}



void sauvegarder_notes_dans_fichier_txt(Liste_Note *lst_note, const char *nom_fichier_notes) {
    FILE *fichier_notes = fopen(nom_fichier_notes, "w");

    if (fichier_notes == NULL) {
        printf("Erreur lors de l'ouverture du fichier des notes.\n");
        return;
    }

    Note *note_courante = lst_note->tete;
    while (note_courante != NULL) {
       
        fprintf(fichier_notes, "CNE de l'etudiant: %s\n", note_courante->etudiant->cne);
        fprintf(fichier_notes, "Matiere: %s\n", note_courante->matiere);
        fprintf(fichier_notes, "Valeur de la note: %.2f\n", note_courante->note);
        fprintf(fichier_notes, "\n");  

        note_courante = note_courante->suivant;
    }

    fclose(fichier_notes);
    printf("Les donnees des notes bien enregistrees.\n");
}





Liste_Etudiant * recuperer_etudiants_depuis_fichier_txt(Liste_Etudiant *lst_etud, const char *nom_fichier_etudiant) {
    FILE *fichier_etudiant = fopen(nom_fichier_etudiant, "r");

    if (fichier_etudiant == NULL) {
        return lst_etud;
    }

    char cne[n], nom[n], prenom[n], pass[n];
    while (fscanf(fichier_etudiant, "CNE: %s\nNom: %s\nPrenom: %s\nPass: %s\n\n",
                  cne, nom, prenom, pass) == 4) {
        Etudiant *nouveau_etud = initialisation_etudiant();

    
        nouveau_etud->cne = strdup(cne);
        strcpy(nouveau_etud->nom_etd, nom);
        strcpy(nouveau_etud->prenom_etd, prenom);
        strcpy(nouveau_etud->pass, pass);


        if (lst_etud->tete == NULL) {
            lst_etud->tete = nouveau_etud;
            lst_etud->qeue = nouveau_etud;
        } else {
            nouveau_etud->suivant = lst_etud->tete;
            lst_etud->tete = nouveau_etud;
        }
        lst_etud->taille++;
    }

    fclose(fichier_etudiant);

    return lst_etud;
}



Liste_Note *recuperer_notes_depuis_fichier_txt(Liste_Note *lst_note, Liste_Etudiant *lst_etud, const char *nom_fichier_notes) {
    FILE *fichier_notes = fopen(nom_fichier_notes, "r");

    if (fichier_notes == NULL) {
    
        return lst_note;
    }

    char cne[n];
    char matiere[n];
    float note;

    while (fscanf(fichier_notes, "CNE de l'etudiant: %s\nMatiere: %s\nValeur de la note: %f\n\n",
                  cne, matiere, &note) == 3) {
        Etudiant *etudiant = chercherSuppEtudiantParCNE(lst_etud, cne);
      

        if (etudiant != NULL) {
            Note *nouvelle_note = initialisation_note();

    
            nouvelle_note->etudiant = etudiant;
            strcpy(nouvelle_note->matiere, matiere);
            nouvelle_note->note = note;

        
            if (lst_note->tete == NULL) {
                lst_note->tete = nouvelle_note;
                lst_note->qeue = nouvelle_note;
            } else {
                nouvelle_note->suivant = lst_note->tete;
                lst_note->tete = nouvelle_note;
            }
            lst_note->taille++;
        }
        
    }

    fclose(fichier_notes);
  

    return lst_note;
}







Liste_presence *recuperer_presence_depuis_fichier_txt(Liste_presence *lst_presence, Liste_Etudiant *lst_etud, const char *nom_fichier_presence) {
    FILE *fichier_presence = fopen(nom_fichier_presence, "r");

    if (fichier_presence == NULL) {
        return lst_presence;
    }

    char cne[n];
    char matiere[n];
    int presence;
    Date date;

    while (fscanf(fichier_presence, "CNE de l'etudiant: %s\nMatiere: %s\nPresence: %d\nDate: %d/%d/%d\n\n",
                  cne, matiere, &presence, &date.jour, &date.mois, &date.annee) == 6) {
        Etudiant *etudiant = chercherSuppEtudiantParCNE(lst_etud, cne);

        if (etudiant != NULL) {
            Presence *nouvelle_presence = initialisation_presence();

           
            nouvelle_presence->etud = etudiant;
            strcpy(nouvelle_presence->matiere, matiere);
            nouvelle_presence->presence = presence;
            nouvelle_presence->date = date;

           
            if (lst_presence->tete == NULL) {
                lst_presence->tete = nouvelle_presence;
                lst_presence->qeue = nouvelle_presence;
            } else {
                nouvelle_presence->suivant = lst_presence->tete;
                lst_presence->tete = nouvelle_presence;
            }
            lst_presence->taille++;
        }
    }

    fclose(fichier_presence);

    return lst_presence;
}


void sauvegarder_presence_dans_fichier_txt(Liste_presence *lst_presence, const char *nom_fichier_presence) {
    FILE *fichier_presence = fopen(nom_fichier_presence, "w");

    if (fichier_presence == NULL) {
        printf("Erreur lors de l'ouverture du fichier des présences.\n");
        return;
    }

    Presence *presence_courante = lst_presence->tete;
    while (presence_courante != NULL) {

        fprintf(fichier_presence, "CNE de l'etudiant: %s\n", presence_courante->etud->cne);
        fprintf(fichier_presence, "Matiere: %s\n", presence_courante->matiere);
        fprintf(fichier_presence, "Presence: %d\n", presence_courante->presence);
        fprintf(fichier_presence, "Date: %d/%d/%d\n", presence_courante->date.jour, presence_courante->date.mois, presence_courante->date.annee);
        fprintf(fichier_presence, "\n");  

        presence_courante = presence_courante->suivant;
    }

    fclose(fichier_presence);
    printf("Les donnees des presences bien enregistrees.\n");
}









void trierEtAfficher(Liste_Etudiant *liste, int choix) {
	
	Etudiant **tabEtudiants = (Etudiant **)malloc(liste->taille * sizeof(Etudiant *));
    Etudiant *courant = liste->tete;
	
    if (liste->taille <= 1) {
    	tabEtudiants[0] = courant;
       
    }
    else
    {
    	
    for (int i = 0; i < liste->taille; i++) {
        tabEtudiants[i] = courant;
        courant = courant->suivant;
    }


    switch (choix) {
        case 1:
            for (int i = 0; i < liste->taille - 1; i++) {
                for (int j = i + 1; j < liste->taille; j++) {
                    if (strcmp(tabEtudiants[j]->nom_etd, tabEtudiants[i]->nom_etd) < 0) {
                        Etudiant *temp = tabEtudiants[i];
                        tabEtudiants[i] = tabEtudiants[j];
                        tabEtudiants[j] = temp;
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < liste->taille - 1; i++) {
                for (int j = i + 1; j < liste->taille; j++) {
                    if (strcmp(tabEtudiants[j]->prenom_etd, tabEtudiants[i]->prenom_etd) < 0) {
                        Etudiant *temp = tabEtudiants[i];
                        tabEtudiants[i] = tabEtudiants[j];
                        tabEtudiants[j] = temp;
                    }
                }
            }
            break;
        case 3:
            for (int i = 0; i < liste->taille - 1; i++) {
                for (int j = i + 1; j < liste->taille; j++) {
                    if (strcmp(tabEtudiants[j]->cne, tabEtudiants[i]->cne) < 0) {
                        Etudiant *temp = tabEtudiants[i];
                        tabEtudiants[i] = tabEtudiants[j];
                        tabEtudiants[j] = temp;
                    }
                }
            }
            break;
        default:
            printf("Choix invalide.\n");
            free(tabEtudiants);
            return;
    }
	}
    


    printf("\t ** Liste triee **\n");
    for (int i = 0; i < liste->taille; i++) {
        printf("Nom: %s \nPrenom: %s \nCNE: %s\n", tabEtudiants[i]->nom_etd, tabEtudiants[i]->prenom_etd, tabEtudiants[i]->cne);
        printf("\n ------------------------------------------------------------------------------\n");
    }

    free(tabEtudiants);
}






Liste_Note * changer_note(Liste_Note *liste,  char *cne, char *matiere, float nouvelleNote) {
    Note *courant = liste->tete;

    while (courant != NULL) {

        if (strcmp(courant->etudiant->cne,cne) == 0 && strcmp(courant->matiere, matiere) == 0) {
            courant->note = nouvelleNote;
            
             system("cls");
			printf("\n ** La note a etait bien modifiee ** \n");
			getchar();
            return liste;
        }
        courant = courant->suivant;
    }
    system("cls");
    printf("Note a modifier est introuvable, essayer de l ajouter de nouveau si necessaire !!!\n");
    return liste;
    
}



Liste_presence * modifier_presence(Liste_presence *liste_pres,char * cne, char *matiere, Date date, int nouvelle_presence) {
    Presence *courant = liste_pres->tete;

    while (courant != NULL) {
        if (strcmp(courant->etud->cne,cne) == 0 && strcmp(courant->matiere, matiere) == 0 &&
            courant->date.jour == date.jour && courant->date.mois == date.mois &&
            courant->date.annee == date.annee) {

            courant->presence = nouvelle_presence;
            
               system("cls");
			printf("\n ** La presence a etait bien modifiee ** \n");
				getchar();
			
			
            return liste_pres;
        }
        courant = courant->suivant;
    }
system("cls");
    printf("Aucune presence avec les informations entrees !!!\n");
    
    return liste_pres;
}

















Presence * chercherPresence(Liste_presence* listePresences, Date date, char matiere[]) {
    Presence * currentPresence = listePresences->tete;

    while (currentPresence != NULL) {
        if (currentPresence->date.jour == date.jour && 
            currentPresence->date.mois == date.mois && 
            currentPresence->date.annee == date.annee &&
            strcmp(currentPresence->matiere, matiere) == 0) {
      
            return currentPresence;
        }
        currentPresence = currentPresence->suivant;
    }

 
    return NULL;
}













main()
{
	// qq v glob
	int choix1,choix2,choix3,choix4, choix_matiere, choix_presence;
	int i;
	
	//v etud
    char *CNE;
    char nom[n] , prenom[n] , password[n] ;
    CNE = (char*)malloc(n*sizeof(char)) ;
    
	Liste_Etudiant * list_etud = initialisation_liste_etudiant();

	
	
    //v etud
    Liste_Note * lst_note = initialisation_liste_note();
    
    //v pres
    Liste_presence * lst_presence = initialisation_liste_presence();
    
    
    
    
    list_etud = recuperer_etudiants_depuis_fichier_txt(list_etud, "etudiants.txt");
    
    
    lst_note = recuperer_notes_depuis_fichier_txt(lst_note, list_etud,"notes.txt");
    
    lst_presence = recuperer_presence_depuis_fichier_txt(lst_presence, list_etud, "presences.txt");

    
    
    getchar();
    


    
    //v mat
    char matiers[7][n] = {"Math","Language C","Reseau informatique","Base de données","Langue Francaise","Architecture des Ordinateurs","Langue anglaise"};
    char matiere_choix[n];
    	system("color 0A");
    
 
 
     printf("                    .,,uod8B8bou,,.\n");
    printf("              ..,uod8BBBBBBBBBBBBBBBBRPFT?l!i:.\n");
    printf("         ,=m8BBBBBBBBBBBBBBBRPFT?!||||||||||||||\n");
    printf("         !...:!TVBBBRPFT||||||||||!!^^\"\"'   ||||\n");
    printf("         !.......:!?|||||!!^^\"\"'            ||||\n");
    printf("         !.........||||                     ||||\n");
    printf("         !.........||||                     ||||\n");
    printf("         !.........||||                     ||||\n");
    printf("         !.........||||                     ||||             **  BENABBI ANASS\n");  
    printf("         !.........||||                     ||||                    LAAREJ MOHAMED  **\n");               
    printf("         `.........||||                    ,||||\n");
    printf("          .;.......||||               _.-!!|||||      [ APPLICATION DE GESTION DES ETUDIANTS ]\n");
    printf("   .,uodWBBBBb.....||||       _.-!!|||||||||!:'  \n");
    printf("!YBBBBBBBBBBBBBBb..!|||:..-!!|||||||!iof68BBBBBb....\n");
    printf("!..YBBBBBBBBBBBBBBb!!||||||||!iof68BBBBBBRPFT?!::   `.           Appuyez sur n'importe quelle touche pour Commancer .... \n");
    printf("!....YBBBBBBBBBBBBBBbaaitf68BBBBBBRPFT?!:::::::::     `.\n");
    printf("!......YBBBBBBBBBBBBBBBBBBBRPFT?!::::::;:!^\"`;:::       `.\n");
    printf("!........YBBBBBBBBBBRPFT?!::::::::::^''...::::::;         iBBbo.\n");
    printf("`..........YBRPFT?!::::::::::::::::::::::::;iof68bo.      WBBBBbo.\n");
    printf("  `..........:::::::::::::::::::::::;iof688888888888b.     `YBBBP^'\n");
    printf("    `........::::::::::::::::;iof688888888888888888888b.     `\n");
    printf("      `......:::::::::;iof688888888888888888888888888888b.\n");
    printf("        `....:::;iof688888888888888888888888888888888899fT!\n");
    printf("          `..::!8888888888888888888888888888888899fT|!^\"'\n");
    printf("            `' !!988888888888888888888888899fT|!^\"'\n");
    printf("                `!!8888888888888888899fT|!^\"'\n");
    printf("                  `!988888888899fT|!^\"'\n");
    printf("                    `!9899fT|!^\"'\n");
    printf("                      `!^\"'\n");




  getchar();


	system("cls");
	system("color 0A");
		printf("\n\n\n\n\n\n\n");

		
		
		    printf("\n"
           "     :'######::'##::::'##::::'###::::'########:::'######:::'########:'##::::'##:'########:'##::: ##:'########:\n"
           "     '##... ##: ##:::: ##:::'## ##::: ##.... ##:'##... ##:: ##.....:: ###::'###: ##.....:: ###:: ##:... ##..::\n"
           "      ##:::..:: ##:::: ##::'##:. ##:: ##:::: ##: ##:::..::: ##::::::: ####'####: ##::::::: ####: ##:::: ##::::\n"
           "      ##::::::: #########:'##:::. ##: ########:: ##::'####: ######::: ## ### ##: ######::: ## ## ##:::: ##::::\n"
           "      ##::::::: ##.... ##: #########: ##.. ##::: ##::: ##:: ##...:::: ##. #: ##: ##...:::: ##. ####:::: ##::::\n"
           "      ##::: ##: ##:::: ##: ##.... ##: ##::. ##:: ##::: ##:: ##::::::: ##:.:: ##: ##::::::: ##:. ###:::: ##::::\n"
           "     . ######:: ##:::: ##: ##:::: ##: ##:::. ##:. ######::: ########: ##:::: ##: ########: ##::. ##:::: ##::::\n"
           "     :......:::..:::::..::..:::::..::..:::::..:::......::::........::..:::::..::........::..::::..:::::..:::::\n"
           " \n\n\n");
           
           
		printf("\t\t\t\t\t<<<< !!!- VEUILLEZ PATIENTER - !!! >>>>");
		
		printf("\n\n\t\t\t  ");
		
		for(int i=0; i<7; i++)
        {
            printf("\t(*_*)");
            Sleep(500);
        }

	system("cls");
	


	char motdepasse[30]="admin";
	char motdepasseentree[30];
	

	
	
	char cneentree[20];
	
	
	
	
	       int type_user;
	       
	       
	       do {
	       	
	       	system("cls");
	       		system("color 0A");
		   
        printf("\t\t\t** TYPE D UTILISATEUR **\n");
		printf("\t1- Ensignant  \n\t2- Etudiant");
		printf("\n\n\t\t 0- Quiter\n");
		
			printf("\n\n");
		
		
		 printf(
		   "\t\t       \n"
           "\t\t             \n"
           "\t\t                      ------------------\n"
           "\t\t                      ** EXPLICATIONS **\n"
           "\t\t                \n"
           "\t\t               \n"
           "\t\t                                      Pour tout les menus de l application !\n"
           "\t\t_____________________________    Taper le numero de choix, puis cliquer sur ENTRER. ___\n"
           "\t\t     	   \n"
           "\t\t     	                __________________________________________________\n"
           "\t\t     	               |==================================================|\n"
           "\t\t                       | __  ___________  ___________            A & M == |\n"
           "\t\t                       |[_j  L_I_I_I_I_j  L_I_I_I_I_j            ~~~~~ == |\n"
           "\t\t                       |________________________________ _______ ______==_|\n"
           "\t\t                       |[__I_I_I_I_I_I_I_I_I_I_I_I_I_I_] [__I__] [_I_I_I_]|\n"
           "\t\t                       |[___I_I_I_I_I_I_I_I_I_I_I_I_]  |    _    [_I_I_I_]|\n"
           "\t\t                       |[__I_I_I_I_I_I_I_I_I_I_I_I_L___|  _[_]_  [_I_I_I_]|\n"
           "\t\t                       |[_____I_I_I_I_I_I_I_I_I_I_I____] [_I_I_] [_I_I_T ||\n"
           "\t\t                       | [__I__I_________________I__L_] ________ [___I_I_j|\n"
           "\t\t                       |                                                  |\n"
           "\t\t                       l__________________________________________________|\n");
           
		
		scanf("%d",&type_user);
		
			system("cls");
	
	getchar();
		
		
		if(type_user == 1)
		{
			
				do {

	system("cls");
		system("color 0A");
		printf("\n\n\n\n\n");
	    printf("\n");

	    printf(
           "                           :::        ::::::::   ::::::::       ::::::::::: ::::    ::: \n"
           "                           :+:       :+:    :+: :+:    :+:          :+:     :+:+:   :+: \n"
           "                           +:+       +:+    +:+ +:+                 +:+     :+:+:+  +:+ \n"
           "                           +#+       +#+    +:+ :#:                 +#+     +#+ +:+ +#+ \n"
           "                           +#+       +#+    +#+ +#+   +#+#          +#+     +#+  +#+#+# \n"
           "                           #+#       #+#    #+# #+#    #+#          #+#     #+#   #+#+# \n"
           "                           ########## ########   ########       ########### ###    #### \n"
           "                                                                  \n"
           " \n");
           
           
          printf("\t\t\t\t\t ** AUTHENTIFICATION DE L ENSIGNANT **\n");
	    printf("\n\n\n\n \t\t\t\t\t\t << ENTREZ LE MOT DE PASSE : >>\t\t");
	    

	    gets(motdepasseentree);
	    if (strcmp(motdepasseentree,motdepasse)==0)
	    {







		system("cls");


 system("color 06");

		printf("\n\n\n\n\n\n");
	

    printf("\n"
           "    ::::::::: ::::::::::: :::::::::: ::::    ::: :::     ::: :::::::::: ::::    ::: :::    ::: :::::::::: \n"
           "    :+:    :+:    :+:     :+:        :+:+:   :+: :+:     :+: :+:        :+:+:   :+: :+:    :+: :+:        \n"
           "    +:+    +:+    +:+     +:+        :+:+:+  +:+ +:+     +:+ +:+        :+:+:+  +:+ +:+    +:+ +:+        \n"
           "    +#++:++#+     +#+     +#++:++#   +#+ +:+ +#+ +#+     +:+ +#++:++#   +#+ +:+ +#+ +#+    +:+ +#++:++#   \n"
           "    +#+    +#+    +#+     +#+        +#+  +#+#+#  +#+   +#+  +#+        +#+  +#+#+# +#+    +#+ +#+        \n"
           "    #+#    #+#    #+#     #+#        #+#   #+#+#   #+#+#+#   #+#        #+#   #+#+# #+#    #+# #+#        \n"
           "    ######### ########### ########## ###    ####     ###     ########## ###    ####  ########  ########## \n"
           " \n");
           printf("\n\n \t\t\t ** INTERFACE DES ENSIGNANTS **");


  

		printf("\n\n\n\n\n\t\t\t\t Appuyez sur n'importe quelle touche pour continuer .... ");
		getchar();


    
		



 
 system("color 06");
		
	printf("\t\t\t\t\t\t BIENVENUE \n");
	printf("\n");
	 do{
	 	system("cls");

           

    printf("\n\n\n\n"
           "\t                             ::::::::::       ::::::::       :::::::::::      ::::::::::      \n"
           "\t                             :+:             :+:    :+:          :+:          :+:             \n"
           "\t                             +:+             +:+                 +:+          +:+             \n"
           "\t                             :#::+::#        +#++:++#++          +#+          +#++:++#        \n"
           "\t                             +#+                    +#+          +#+          +#+             \n"
           "\t                             #+#             #+#    #+#          #+#          #+#             \n"
           "\t                             ###              ########           ###          ##########      \n"
        );
        
        	printf("\n\n \t\t\t\t\t\t    APPLICATION DE GESTION DES ETUDIANTS");
           
           
	 
	    printf("\n\n\n");
	
	   
        //system("color 02");
         system("color 06");
	
	printf("\t\t\t\t\t\t 1- GESTION DES ETUDIANTS \n ");
	printf("\t\t\t\t\t\t 2- GESTION DES PRESENCES \n ");
	printf("\t\t\t\t\t\t 3- GESTION DES NOTES \n\n ");
	printf("\t\t\t\t\t\t 0- EXIT et SAUVGARDER  \n ");
	
		

	
    scanf("%d",&choix1);
    
    
     
    switch(choix1)
    {
    	case 1 :
    		system("cls");
    		    
        system("color 06");

	do{
printf("\n\n\n\n\n\n\n");
    printf("\t\t------------------------------------------------------------------------------\n");
    printf("\t\t|                         GESTION DES ETUDIANTS                              |\n");
    printf("\t\t------------------------------------------------------------------------------\n");
    printf("\t\t|     1 - AJOUTER UN ETUDIANT                                                |\n");
    printf("\t\t|     2 - AFFICHER LA LISTE DES ETUDIANTS                                    |\n");
    printf("\t\t|     3 - RECHERCHER UN ETUDIANT PAR CNE                                     |\n");
    printf("\t\t|     4 - RECHERCHER UN ETUDIANT PAR NOM                                     |\n");
    printf("\t\t|     5 - MODIFIER UN ETUDIANT                                               |\n");
    printf("\t\t|     6 - SUPPRIMER UN ETUDIANT                                              |\n");
    printf("\t\t|     7 - ** - SAUVEGARDER - **                                              |\n");
    printf("\t\t|            0 - RETOUR                                                      |\n");
    printf("\t\t------------------------------------------------------------------------------\n");

                scanf("%d",&choix2);
                
                system("cls");
                
                 switch(choix2){
                 	
                 		   	      case 0 : 
				  printf("\n back");
			    
			    getchar();
			   system("cls");break;
			   
			   
			   
                 	case 1 : 
                 	list_etud = ajouter_Etudiant_entete(list_etud);
					  printf("\n DONE");
			    getchar();
			    getchar();
			   system("cls");break;
			   
			    case 2 : 
			    
			   
    			
    int choix_trie;
    printf("\t\t ** Choisissez le critere de tri des etudiants **\n");
    printf("1- Nom\n2- Prénom\n3- CNE\n\n   0- Retour\n");
    scanf("%d", &choix_trie);



system("cls");

    if(choix_trie !=0)
    {
    	trierEtAfficher(list_etud, choix_trie);
	}
	

					printf("\n DONE");
			    getchar();
			    getchar();
			   system("cls");break;
			   
			    case 3 : 
			    
			    	char cne[n];
			      	printf("Donner le CNE de l'etudiant a chercher :\t");
			      	scanf("%s",cne);
			      	
			      	printf("\n L Etudiant portant ce CNE :\n");
			        chercherEtudiantParCNE(list_etud,cne);
			    
					 printf("\n DONE");
			    getchar();
			    getchar();
			   system("cls");break;
			   
			    case 4 :
			    	char nom[n];
			      	printf("Donner le nom de l'etudiant a chercher (Nom ou Prenom) :\t");
			      	scanf("%s",nom);
			      	
			      	printf("\n Les Etudiants portans le nom entre  :\n");
			        chercherEtudiantsParNom(list_etud,nom);
			
				

					 printf("\n DONE");
					  
			   getchar();
			    getchar();
			   system("cls");break;
			      
			   
			    case 5 :
			    	char cne_modif[n];
			    	printf("Donner le CNE de l'etudiant a modifier	:\t ");
			    	scanf("%s",cne_modif);
			    	modifier_etudiant(list_etud,cne_modif);

					 printf("\n DONE");
			   getchar();
			    getchar();
			   system("cls");break;
			   
			   
			      case 6 : 
			      
			      char cne_supp[n];
			      	printf("Donner le CNE de l'etudiant a Supprimer :\t");
			      	scanf("%s",cne_supp);
			      	
			      	
			        list_etud = supprimer_etudiant(list_etud,cne_supp);
			       
					 printf("\n DONE");
			   getchar();
			    getchar();
			   system("cls");break;
			   
			   
			      case 7 : 
			    sauvegarder_etudiants_dans_fichier_txt(list_etud, "etudiants.txt");
				  printf("\n DONE");
			    getchar();
			    getchar();
			   system("cls");break;
			   
			
			   
			   
			   
			      default : 
			      
				printf("\n Votre choix n existe pas dans le menu :( \n");
			   getchar();
			    getchar();
			   system("cls");break;
			   		   
					 }
					 
			  	}
			  	while(choix2!=0);
			   break;
			   
			   
    case 2 :
    	
    		system("cls");
    		    
        system("color 06");
	do{
           
		    printf("\n\n\n\n\n\n\n");
		    
	printf("\t\t------------------------------------------------------------------------------\n");
    printf("\t\t|                         GESTION DES PRESENCES                              |\n");
    printf("\t\t------------------------------------------------------------------------------\n");
    printf("\t\t|     1 - AJOUTER LES PRESENCES                                              |\n");
    printf("\t\t|     2 - AFFICHER LA LISTE DE PRESENCE                                      |\n");
    printf("\t\t|     3 - CHERCHER LA LISTE DE PRESENCE D UN ETUDIANT                        |\n");
    printf("\t\t|     4 - CHERCHER LA LISTE DE PRESENCE D UNE DATE                           |\n");
    printf("\t\t|     5 - MODIFIER UNE LISTE DE PRESENCE                                     |\n");
    printf("\t\t|     6 - ** - SAUVEGARDER - **                                              |\n");
    printf("\t\t|            0 - RETOUR                                                      |\n");
    printf("\t\t------------------------------------------------------------------------------\n");
    
    
		    
		    
                		
                scanf("%d",&choix2);
                
                system("cls");
                
                 switch(choix2){
                 	
                 		   	      case 0 : 
				  printf("\n back");
			  
			    getchar();
			   system("cls");break;
			   
                 	
                 	
                 	case 1 :
					 
					 
				Date date_presence;
				date_presence = saisir_date();
					 	      
				
					system("cls");
					
					
	 
        do {
			
                 
    		    
        system("color 06");
	
	do{
           printf("\n\n\n\n\n\n\n");
		    
    printf("\t\t---------------------------------------------------------\n");
    printf("\t\t|                 CHOISIR SVP LA MATIERE                |\n");
    printf("\t\t---------------------------------------------------------\n");
    printf("\t\t|     1 - MATH                                          |\n");
    printf("\t\t|     2 - LANGAGE C                                     |\n");
    printf("\t\t|     3 - RESEAU INFORMATIQUE                           |\n");
    printf("\t\t|     4 - BASE DE DONNEES                               |\n");
    printf("\t\t|     5 - LANGUE FRANCAISE                              |\n");
    printf("\t\t|     6 - ARCHITECTURE DES ORDINATEURS                  |\n");
    printf("\t\t|     7 - LANGUE ANGLAISE                               |\n");
    printf("\t\t|            0 - RETOUR                                 |\n");
    printf("\t\t---------------------------------------------------------\n");
	    
		    
                		
                scanf("%d",&choix_matiere);
                
                system("cls");
                
                switch(choix_matiere){
                 	case 1 : 
                    
                    strcpy(matiere_choix,matiers[0]);
			    getchar();
			   
			   system("cls");break;
			   
			    case 2 : 
	
				 strcpy(matiere_choix,matiers[1]);
			    getchar();
			  
			   system("cls");break;
			   
			   
			     case 3 : 
	
				 strcpy(matiere_choix,matiers[2]);
			    getchar();
			  
			   system("cls");break;
			   
			      case 4 : 
	
				 strcpy(matiere_choix,matiers[3]);
			    getchar();
		
			   system("cls");break;
			   
			         case 5 : 
	
				 strcpy(matiere_choix,matiers[4]);
			    getchar();
			 
			   system("cls");break;
			   
			   	         case 6 : 
	
				 strcpy(matiere_choix,matiers[5]);
			    getchar();
		
			   system("cls");break;
			   
			   
			   
			           case 7 : 
	
				 strcpy(matiere_choix,matiers[6]);
			    getchar();
		
			   system("cls");break;
			   
			   	      case 0 : 
				  printf("\n back");
			
			    getchar();
			   system("cls");break;
			   
			   	
			   
			   
			   
			   
			   
			    
			      default : 
			      
				printf("\n Votre choix n existe pas dans le menu :( \n");
			   getchar();
			    getchar();
			    system("cls");break;
			   		   
					 }
					 
			  	}
			  	while(choix_matiere<0 || choix_matiere>7);
			  	
			  	if(choix_matiere != 0)
			  	{
			  		Presence* resultat = chercherPresence(lst_presence, date_presence, matiere_choix);


						if (resultat != NULL) {
			  			printf("Les presences de  cette matiere et date existe deja ! \n \t\t** Essayer de les modifier si necessaire **\n\n");
                 		getchar();
                 		system("cls");
						} else {
						   lst_presence = ajouter_presence_tt(lst_presence,matiere_choix,date_presence,list_etud);
						}
			 		
			  		
				  }
				  
				  system("cls");
		     	
		     	
		    } while (choix_matiere != 0);
			  	    
			  
			    printf("\n DONE");
			    getchar();
			    getchar();
			    system("cls");
				break;
				
				case 2 : 
			    
			        printf("La listes de toute les presences :\n\n");
    				afficher_liste_presence(lst_presence);
					printf("\n DONE");
			    getchar();
			    getchar();
			   system("cls");break;
			   
			   
			   
			   
			   case 3 : 
			    	char cne[n];
			      	printf("Donner le CNE de l'etudiant a chercher :\t");
			      	scanf("%s",cne);
			      	
			      	system("cls");
			        afficher_liste_presence_etu(lst_presence,cne);
			    
					 printf("\n DONE");
			    getchar();
			    getchar();
			   system("cls");break;
			   
			    case 4 :
			    	Date date_pp ;
			    	date_pp = saisir_date();
			    	
			    	system("cls");
			    	afficher_liste_presence_date(lst_presence,date_pp,matiers,7);
			    	
			    

					 printf("\n DONE");
					  
			   getchar();
			    getchar();
			   system("cls");break;
			   
			   
			      
			   
			    case 5 :
			    	char cne_modif[n];
			    	printf("Donner le CNE de l'etudiant a modifier	:\t ");
			    	scanf("%s",cne_modif);
			    	
			    	Etudiant * etud_modif_prs;
			    	etud_modif_prs = chercherSuppEtudiantParCNE(list_etud,cne_modif);
			    	
			    	
			    	if(etud_modif_prs != NULL)
			    	{
			    		
			    	Date date_modif ;
					date_modif = saisir_date();  
					
									 
									 
									 
			    			    	do{
           printf("\n\n\n\n\n\n\n");
		    
    printf("\t\t---------------------------------------------------------\n");
    printf("\t\t|                 CHOISIR SVP LA MATIERE                |\n");
    printf("\t\t---------------------------------------------------------\n");
    printf("\t\t|     1 - MATH                                          |\n");
    printf("\t\t|     2 - LANGAGE C                                     |\n");
    printf("\t\t|     3 - RESEAU INFORMATIQUE                           |\n");
    printf("\t\t|     4 - BASE DE DONNEES                               |\n");
    printf("\t\t|     5 - LANGUE FRANCAISE                              |\n");
    printf("\t\t|     6 - ARCHITECTURE DES ORDINATEURS                  |\n");
    printf("\t\t|     7 - LANGUE ANGLAISE                               |\n");
    printf("\t\t|            0 - RETOUR                                 |\n");
    printf("\t\t---------------------------------------------------------\n");
	    
		    
                		
                scanf("%d",&choix_matiere);
                
                system("cls");
                
                switch(choix_matiere){
                 	case 1 : 
                    
                    strcpy(matiere_choix,matiers[0]);
			    getchar();
			   
			   system("cls");break;
			   
			    case 2 : 
	
				 strcpy(matiere_choix,matiers[1]);
			    getchar();
			  
			   system("cls");break;
			   
			   
			     case 3 : 
	
				 strcpy(matiere_choix,matiers[2]);
			    getchar();
			  
			   system("cls");break;
			   
			      case 4 : 
	
				 strcpy(matiere_choix,matiers[3]);
			    getchar();
		
			   system("cls");break;
			   
			         case 5 : 
	
				 strcpy(matiere_choix,matiers[4]);
			    getchar();
			 
			   system("cls");break;
			   
			   	         case 6 : 
	
				 strcpy(matiere_choix,matiers[5]);
			    getchar();
		
			   system("cls");break;
			   
			   
			   
			           case 7 : 
	
				 strcpy(matiere_choix,matiers[6]);
			    getchar();
		
			   system("cls");break;
			   
			   	      case 0 : 
				  printf("\n back");
			
			    getchar();
			   system("cls");break;
			   
			   	
			   
			   
		
			    
			      default : 
			      
				printf("\n Votre choix n existe pas dans le menu :( \n");
			   getchar();
			    getchar();
			    system("cls");break;
			   		   
					 }
					 
			  	}
			  	while(choix_matiere<0 || choix_matiere>7);
			  	
			  		int presence_modif;
	
			  	if(choix_matiere != 0)
			  	{
			  		
			  		do {

      printf("entrer la Nouvelle presence de l etudiant %s %s (%s) \n",etud_modif_prs->nom_etd,etud_modif_prs->prenom_etd,etud_modif_prs->cne);
      printf("\t\t\t 1- Present\t 0- Absent \t");
      printf("\n");
      scanf("%d",&presence_modif);
      printf("\n");

if (presence_modif != 0 && presence_modif !=1)
{
	printf("\n Choix de presence est invalide ! \n");
}

	 else
					 {
					 		  modifier_presence(lst_presence,cne_modif, matiere_choix,date_modif,presence_modif);	
					 		
					 		 
					 }
					 
         	} while(presence_modif != 0 && presence_modif !=1);
	
			 		
			 	
				
			  	                
			    	
			    }
	
			    	
			    	
			 
			    	
			    	
				}
					else
					{
						printf("\nAucun Etudiant portant le CNE entree !!! \n");
					}
			    	
			    	
		


					 printf("\n DONE");
			   getchar();
			    getchar();
			   system("cls");
			   break;

			      case 6 : 
			        sauvegarder_presence_dans_fichier_txt(lst_presence, "presences.txt");
				  printf("\n DONE");
			    getchar();
			    getchar();
			   system("cls");break;
			   
			   
			      default : 
			      
				printf("\n Votre choix n existe pas dans le menu :( \n");
			   getchar();
			    getchar();
			   system("cls");break;
			   		   
					 }
					 
			  	}
			  	while(choix2!=0);
			   break;
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			       case 3 :
    	
    		system("cls");
    		    
        system("color 06");
	do{
           
		    printf("\n\n\n\n\n\n\n");
		    
	printf("\t\t------------------------------------------------------------------------------\n");
    printf("\t\t|                         GESTION DES NOTES                                  |\n");
    printf("\t\t------------------------------------------------------------------------------\n");
    printf("\t\t|     1 - AJOUTER LES NOTES                                                  |\n");
    printf("\t\t|     2 - AFFICHER LA LISTE DE NOTES                                         |\n");
    printf("\t\t|     3 - CHERCHER LA LISTE DES NOTES D UN ETUDIANT                          |\n");
    printf("\t\t|     4 - CHERCHER LA LISTE DE NOTES D UNE MATIERE                           |\n");
    printf("\t\t|     5 - MODIFIER UNE NOTE                                                  |\n");
    printf("\t\t|     6 - ** - SAUVEGARDER - **                                              |\n");
    printf("\t\t|            0 - RETOUR                                                      |\n");
    printf("\t\t------------------------------------------------------------------------------\n");
    
    
		    
		    
                		
                scanf("%d",&choix2);
                
                system("cls");
                
                 switch(choix2){
                 	
                 		   	      case 0 : 
				  printf("\n back");
			  
			    getchar();
			   system("cls");break;
			   
                 	
                 	
                 	case 1 :
			
					
					
	 
        do {
			
                 
    		    
        system("color 06");
	
	do{
           printf("\n\n\n\n\n\n\n");
		    
    printf("\t\t---------------------------------------------------------\n");
    printf("\t\t|                 CHOISIR SVP LA MATIERE                |\n");
    printf("\t\t---------------------------------------------------------\n");
    printf("\t\t|     1 - MATH                                          |\n");
    printf("\t\t|     2 - LANGAGE C                                     |\n");
    printf("\t\t|     3 - RESEAU INFORMATIQUE                           |\n");
    printf("\t\t|     4 - BASE DE DONNEES                               |\n");
    printf("\t\t|     5 - LANGUE FRANCAISE                              |\n");
    printf("\t\t|     6 - ARCHITECTURE DES ORDINATEURS                  |\n");
    printf("\t\t|     7 - LANGUE ANGLAISE                               |\n");
    printf("\t\t|            0 - RETOUR                                 |\n");
    printf("\t\t---------------------------------------------------------\n");
	    
		    
                		
                scanf("%d",&choix_matiere);
                
                system("cls");
                
                switch(choix_matiere){
                 	case 1 : 
                    
                    strcpy(matiere_choix,matiers[0]);
			    getchar();
			   
			   system("cls");break;
			   
			    case 2 : 
	
				 strcpy(matiere_choix,matiers[1]);
			    getchar();
			  
			   system("cls");break;
			   
			   
			     case 3 : 
	
				 strcpy(matiere_choix,matiers[2]);
			    getchar();
			  
			   system("cls");break;
			   
			      case 4 : 
	
				 strcpy(matiere_choix,matiers[3]);
			    getchar();
		
			   system("cls");break;
			   
			         case 5 : 
	
				 strcpy(matiere_choix,matiers[4]);
			    getchar();
			 
			   system("cls");break;
			   
			   	         case 6 : 
	
				 strcpy(matiere_choix,matiers[5]);
			    getchar();
		
			   system("cls");break;
			   
			   
			   
			           case 7 : 
	
				 strcpy(matiere_choix,matiers[6]);
			    getchar();
		
			   system("cls");break;
			   
			   	      case 0 : 
				  printf("\n back");
			
			    getchar();
			   system("cls");break;
			   
			   	
			   
			   
			   
			   
			   
			    
			      default : 
			      
				printf("\n Votre choix n existe pas dans le menu :( \n");
			   getchar();
			    getchar();
			    system("cls");break;
			   		   
					 }
					 
			  	}
			  	while(choix_matiere<0 || choix_matiere>7);
			  	
			  	if(choix_matiere != 0)
			  	{
			  		
			  		
			  		Note* resultat = chercherNote(lst_note, matiere_choix);

               if (resultat != NULL) {
                 printf("Les Notes de  cette matiere existe deja ! \n \t\t** Essayer de les modifier si necessaire **\n\n");
                 getchar();
                 system("cls");
              } else {
                lst_note = ajouter_note_tt(lst_note,matiere_choix,list_etud);
                     }
			 		
			  		
				  }
				  
				  system("cls");
		     	
		     	
		    } while (choix_matiere != 0);
			  	    
			  
			    printf("\n DONE");
			    getchar();
			    getchar();
			    system("cls");
				break;
				
				case 2 : 
			    
			        printf("La listes de toute Notes :\n");
    				afficher_liste_note(lst_note);
					printf("\n DONE");
			    getchar();
			    getchar();
			   system("cls");break;
			   
			   
			   
			   
			   case 3 : 
			    	char cne[n];
			      	printf("Donner le CNE de l etudiant :\t");
			      	scanf("%s",cne);
			      	
			      	system("cls");
			        afficher_liste_note_etudiant(lst_note,cne);
			    
					 printf("\n DONE");
			    getchar();
			    getchar();
			   system("cls");break;
			   
			    case 4 :
			    
			    
			    
			    
			    
			    
			        do {
			
                 
    		    
        system("color 06");
	
	do{
		strcpy(matiere_choix,"");
		
           printf("\n\n\n\n\n\n\n");
		    
    printf("\t\t---------------------------------------------------------\n");
    printf("\t\t|                 CHOISIR SVP LA MATIERE                |\n");
    printf("\t\t---------------------------------------------------------\n");
    printf("\t\t|     1 - MATH                                          |\n");
    printf("\t\t|     2 - LANGAGE C                                     |\n");
    printf("\t\t|     3 - RESEAU INFORMATIQUE                           |\n");
    printf("\t\t|     4 - BASE DE DONNEES                               |\n");
    printf("\t\t|     5 - LANGUE FRANCAISE                              |\n");
    printf("\t\t|     6 - ARCHITECTURE DES ORDINATEURS                  |\n");
    printf("\t\t|     7 - LANGUE ANGLAISE                               |\n");
    printf("\t\t|            0 - RETOUR                                 |\n");
    printf("\t\t---------------------------------------------------------\n");
	    
		    
                		
                scanf("%d",&choix_matiere);
                
                system("cls");
                
                switch(choix_matiere){
                 	case 1 : 
                    
                    strcpy(matiere_choix,matiers[0]);
			    getchar();
			   
			   system("cls");break;
			   
			    case 2 : 
	
				 strcpy(matiere_choix,matiers[1]);
			    getchar();
			  
			   system("cls");break;
			   
			   
			     case 3 : 
	
				 strcpy(matiere_choix,matiers[2]);
			    getchar();
			  
			   system("cls");break;
			   
			      case 4 : 
	
				 strcpy(matiere_choix,matiers[3]);
			    getchar();
		
			   system("cls");break;
			   
			         case 5 : 
	
				 strcpy(matiere_choix,matiers[4]);
			    getchar();
			 
			   system("cls");break;
			   
			   	         case 6 : 
	
				 strcpy(matiere_choix,matiers[5]);
			    getchar();
		
			   system("cls");break;
			   
			   
			   
			           case 7 : 
	
				 strcpy(matiere_choix,matiers[6]);
			    getchar();
		
			   system("cls");break;
			   
			   	      case 0 : 
				  printf("\n back");
			
			    getchar();
			   system("cls");break;
			   
			   	
			   
			   
			   
			   
			   
			    
			      default : 
			      
				printf("\n Votre choix n existe pas dans le menu :( \n");
			   getchar();
			    getchar();
			    system("cls");break;
			   		   
					 }
					 
			  	}
			  	while(choix_matiere<0 || choix_matiere>7);
			  	
		
		
		     	  	system("cls");
		     	  	if(strcmp(matiere_choix,"")!=0 )
		     	  	{
		     	  		afficher_liste_note_matiere(lst_note,matiere_choix);
					   }
			    	
			    	
			    	getchar();
			    	system("cls");
			    	
			    
		     	
		    } while (choix_matiere != 0);
			  	    
			    
			    
			    
			    
			    
			    
			    	
			  

					 printf("\n DONE");
					  
			   getchar();
			    getchar();
			   system("cls");break;
			   
			   
			      
			   
			    case 5 :
			    	char cne_modif[n];
			    	float Note_modif;
			    	printf("Donner le CNE de l'etudiant a modifier	:\t ");
			    	scanf("%s",cne_modif);
			    	Etudiant * etud_note_modif ;
		     	    etud_note_modif = 	chercherSuppEtudiantParCNE(list_etud,cne_modif);
			    	
			    	
			    		    	if(etud_note_modif != NULL)
			    	{
			    		
			    			    	do{
           printf("\n\n\n\n\n\n\n");
		    
    printf("\t\t---------------------------------------------------------\n");
    printf("\t\t|                 CHOISIR SVP LA MATIERE                |\n");
    printf("\t\t---------------------------------------------------------\n");
    printf("\t\t|     1 - MATH                                          |\n");
    printf("\t\t|     2 - LANGAGE C                                     |\n");
    printf("\t\t|     3 - RESEAU INFORMATIQUE                           |\n");
    printf("\t\t|     4 - BASE DE DONNEES                               |\n");
    printf("\t\t|     5 - LANGUE FRANCAISE                              |\n");
    printf("\t\t|     6 - ARCHITECTURE DES ORDINATEURS                  |\n");
    printf("\t\t|     7 - LANGUE ANGLAISE                               |\n");
    printf("\t\t|            0 - RETOUR                                 |\n");
    printf("\t\t---------------------------------------------------------\n");
	    
		    
                		
                scanf("%d",&choix_matiere);
                
                system("cls");
                
                switch(choix_matiere){
                 	case 1 : 
                    
                    strcpy(matiere_choix,matiers[0]);
			    getchar();
			   
			   system("cls");break;
			   
			    case 2 : 
	
				 strcpy(matiere_choix,matiers[1]);
			    getchar();
			  
			   system("cls");break;
			   
			   
			     case 3 : 
	
				 strcpy(matiere_choix,matiers[2]);
			    getchar();
			  
			   system("cls");break;
			   
			      case 4 : 
	
				 strcpy(matiere_choix,matiers[3]);
			    getchar();
		
			   system("cls");break;
			   
			         case 5 : 
	
				 strcpy(matiere_choix,matiers[4]);
			    getchar();
			 
			   system("cls");break;
			   
			   	         case 6 : 
	
				 strcpy(matiere_choix,matiers[5]);
			    getchar();
		
			   system("cls");break;
			   
			   
			   
			           case 7 : 
	
				 strcpy(matiere_choix,matiers[6]);
			    getchar();
		
			   system("cls");break;
			   
			   	      case 0 : 
				  printf("\n back");
			
			    getchar();
			   system("cls");break;
			   
			   	
			   
			   
		
			    
			      default : 
			      
				printf("\n Votre choix n existe pas dans le menu :( \n");
			   getchar();
			    getchar();
			    system("cls");break;
			   		   
					 }
					 
			  	}
			  	while(choix_matiere<0 || choix_matiere>7);
			  	
			  	if(choix_matiere != 0)
			  	{
			  		
			  		printf("\n Entrez la nouveau Note : \t ");
			  		scanf("%f",&Note_modif);
			  		printf("\n");
			 		
			 		if(Note_modif<0 || Note_modif>20)
			 		{
			 		
			 			  system("cls");
			 			  	printf("\n !! La note doit etre entre 0 et 20 !! \n");
					 }
					 else
					 {
					 		lst_note = changer_note(lst_note,cne_modif,matiere_choix,Note_modif);
					 		
					 		 
					 }
			  	
				  }
				  
				
			    	
					}
					else
					{
						printf("\nAucun Etudiant portant le CNE entree !!! \n");
					}
			    
			    
			    
			    
			    
			    
			    
			    
			    
			    
			    
			    
			    


					 printf("\n DONE");
			   getchar();
			    getchar();
			   system("cls");break;
			   
		 
			   
			      case 6 : 
			      sauvegarder_notes_dans_fichier_txt(lst_note, "notes.txt");
				  printf("\n DONE");
			    getchar();
			    getchar();
			   system("cls");break;
			   
			   
			      default : 
			      
				printf("\n Votre choix n existe pas dans le menu :( \n");
			   getchar();
			    getchar();
			   system("cls");break;
			   		   
					 }
					 
			  	}
			  	while(choix2!=0);
			   break;
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			
			
			
			
			   
			   
			   
			   case 0 :
			   	
				   	
			  
			   system("cls");break;
			   	
			    default : 
	
			    getchar();
			    getchar();
			   system("cls");break;
    
}

   

   
   } 
     while(choix1!=0 );
		
		








}








  else{
  	printf("\n (-_-) !!! le Mot de passe et incorrect !!! \n");
  	printf("\n\n\n\t\t\t Appuyez sur n'importe quelle touche pour re-entrer le mot de passe .... \n");
  	
  	  getchar();
			 
			   system("cls");

  }
                   }while(strcmp(motdepasseentree,motdepasse)!=0);
			
		}
		

		
				else if(type_user == 2)
		{
			
				do {

	system("cls");
		system("color 0A");
		printf("\n\n\n\n\n");
	    printf("\n");

	    printf(
           "                           :::        ::::::::   ::::::::       ::::::::::: ::::    ::: \n"
           "                           :+:       :+:    :+: :+:    :+:          :+:     :+:+:   :+: \n"
           "                           +:+       +:+    +:+ +:+                 +:+     :+:+:+  +:+ \n"
           "                           +#+       +#+    +:+ :#:                 +#+     +#+ +:+ +#+ \n"
           "                           +#+       +#+    +#+ +#+   +#+#          +#+     +#+  +#+#+# \n"
           "                           #+#       #+#    #+# #+#    #+#          #+#     #+#   #+#+# \n"
           "                           ########## ########   ########       ########### ###    #### \n"
           "                                                                  \n"
           " \n");
           
           printf("\t\t\t\t\t ** AUTHENTIFICATION DE L ETUDIANT **\n");
           
        printf("\n\n\n\n \t\t\t\t\t\t << ENTREZ lE CNE : >>\t\t");
        gets(cneentree);
        
        
        Etudiant * me = chercherSuppEtudiantParCNE(list_etud,cneentree);
      
        
        if(me != NULL)
        {
         printf("\n \t\t\t\t\t << ENTREZ LE MOT DE PASSE : >>\t\t");
         
         
         
         gets(motdepasseentree);
	    if (strcmp(motdepasseentree,me->pass)==0)
	    {







		system("cls");


 int nb_abs = nb_abs_etud(lst_presence, me->cne);
 
  system("color 06");
		printf("\n\n\n\n\n\n");
	

    printf("\n"
           "    ::::::::: ::::::::::: :::::::::: ::::    ::: :::     ::: :::::::::: ::::    ::: :::    ::: :::::::::: \n"
           "    :+:    :+:    :+:     :+:        :+:+:   :+: :+:     :+: :+:        :+:+:   :+: :+:    :+: :+:        \n"
           "    +:+    +:+    +:+     +:+        :+:+:+  +:+ +:+     +:+ +:+        :+:+:+  +:+ +:+    +:+ +:+        \n"
           "    +#++:++#+     +#+     +#++:++#   +#+ +:+ +#+ +#+     +:+ +#++:++#   +#+ +:+ +#+ +#+    +:+ +#++:++#   \n"
           "    +#+    +#+    +#+     +#+        +#+  +#+#+#  +#+   +#+  +#+        +#+  +#+#+# +#+    +#+ +#+        \n"
           "    #+#    #+#    #+#     #+#        #+#   #+#+#   #+#+#+#   #+#        #+#   #+#+# #+#    #+# #+#        \n"
           "    ######### ########### ########## ###    ####     ###     ########## ###    ####  ########  ########## \n"
           " \n");
            	printf("\n\t\t\t\t\t %s %s",me->nom_etd,me->prenom_etd);
           printf("\n\n \t\t\t\t ** INTERFACE DES ETUDIANTS **");
          




		printf("\n\n\n\n\n\t\t\t\t Appuyez sur n'importe quelle touche pour continuer .... ");
		getchar();


    
		



 system("color 06");
		
	printf("\t\t\t\t\t\t BIENVENUE \n");
	printf("\n");
	 do{
	 	system("cls");
	 	//system("color 0A");
	 

           

    printf("\n\n\n\n"
           "\t                             ::::::::::       ::::::::       :::::::::::      ::::::::::      \n"
           "\t                             :+:             :+:    :+:          :+:          :+:             \n"
           "\t                             +:+             +:+                 +:+          +:+             \n"
           "\t                             :#::+::#        +#++:++#++          +#+          +#++:++#        \n"
           "\t                             +#+                    +#+          +#+          +#+             \n"
           "\t                             #+#             #+#    #+#          #+#          #+#             \n"
           "\t                             ###              ########           ###          ##########      \n"
        );
        
        	printf("\n\n \t\t\t\t\t\t    **  UTILISATEUR : [ %s %s ] **",me->nom_etd,me->prenom_etd);
           
           
	 
	    printf("\n\n\n");
	
	   
        //system("color 02");
     
	
	printf("\t\t\t\t\t\t 1- MON PROFILE \n ");
	printf("\t\t\t\t\t\t 2- MES ABSENCES \n ");
	printf("\t\t\t\t\t\t 3- MES NOTES \n\n ");
	printf("\t\t\t\t\t\t 0- EXIT   \n ");
	
	       
	

	
    scanf("%d",&choix1);
    
    
    	system("cls");
    
    switch (choix1) {
        case 1:
            printf("\t\t\t ** PROFILE **\n");
            printf("---------------------------------------------------------------\n\n");
        	printf("\tNOM : %s\n",me->nom_etd);
        	printf("\tPRENOM : %s\n",me->prenom_etd);
        	printf("\tCNE : %s\n\n",me->cne);
        	
        	
            printf("\tNOMBRE DES ABSENCES : %d\n",nb_abs);
            
            
            
        	
        	
        	
        	getchar();
        	getchar();
        	
        	system("cls");
       
            break;

        case 2:
             afficher_liste_presence_etu(lst_presence,me->cne);
             
            getchar();
        	getchar();
        	
        	system("cls");
           
            break;

        case 3:
             afficher_liste_note_etudiant(lst_note,me->cne);
             
                 getchar();
        	getchar();
        	
        	system("cls");
     
            break;

        case 0:

          
            break;

        default:
            printf("Choix non valide !!!\n");
            		printf("\n\n\n\n\n\t\t\t\t Appuyez sur n'importe quelle touche pour recomancer .... ");
            		     getchar();
        	getchar();
            		
            
            
    }
    
 
}
    while(choix1!=0);
}

    
      else{
  	printf("\n (-_-) !!! le Mot de passe et incorrect !!! \n");
  	printf("\n\n\n\t\t\t Appuyez sur n'importe quelle touche pour re-entrer le mot de passe .... \n");
  	
  	  getchar();
			 
			   system("cls");

  }
  
		}
		
		
		else
		{
			printf("\n Le Cne entre est incorrecte !!!");
		    printf("\n\n\n\t\t\t Appuyez sur n'importe quelle touche pour recommancer .... \n");
			getchar();
		}
 
	 

			
			
			 }while(strcmp(motdepasseentree,motdepasse)!=0 && choix1 != 0);
			 
		}
		
	
		else if (type_user == 0)
		{
			return 0;
		}
		
		else
		{
			printf("\n CHOIX DE TYPE DE L UTILISATEUR EST INVALIDE !\n");
		}
		
		
		 }while(type_user != 0);
		


		if(type_user == 1)
		{
			sauvegarder_etudiants_dans_fichier_txt(list_etud, "etudiants.txt");
       
            sauvegarder_notes_dans_fichier_txt(lst_note, "notes.txt");
         
            sauvegarder_presence_dans_fichier_txt(lst_presence, "presences.txt");
         
			
		}
                   
   

}

