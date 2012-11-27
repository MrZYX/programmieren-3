#include <stdlib.h>
#include <stdio.h>

#include "liste1ende.h"

int test(void) {
    struct knoten* kopf= NULL;
    
    struct knoten *neu4, *neu5, *neu6, *neu7, *such, *entf;

    neu5 = malloc(sizeof(*neu5));
    neu5->wert = 5;
    neu5->next = NULL;

    if (einfuegen_kopf(&kopf, neu5) != 0) {
      printf("Fehler beim einfügen\n"); 
      return -1;
    }

    neu6 = malloc(sizeof(*neu6));
    neu6->wert = 6;
    neu6->next = NULL;
    if (einfuegen_nach(neu5, neu6) != 0) {
      printf("Fehler beim einfügen\n"); 
      return -1;
    }

    durchlaufen(kopf);
   
    such= suchen(kopf, 5);
    if (such == NULL || such->wert != 5) {
      printf("Fehler: suchen. 5 nicht gefunden\n"); 
      return -1;
    }
    
    such= suchen(kopf, 6);
    if (such == NULL || such->wert != 6) {
      printf("Fehler: suchen. 6 nicht gefunden\n"); 
      return -1;
    }
    
    such= suchen(kopf, 7);
    if (such != NULL) {
      printf("Fehler: suchen. 7 gibt es gar nicht\n"); 
      return -1;
    }
    
    neu4 = malloc(sizeof(*neu4));
    neu4->wert = 4;
    neu4->next = NULL;
    if (einfuegen_kopf(&kopf, neu4) != 0) {
      printf("Fehler beim einfügen\n"); 
      return -1;
    }
    	
    	        
    such= suchen(kopf, 4);
    if (such == NULL || such->wert != 4) {
      printf("Fehler: suchen. 4 nicht gefunden\n"); 
      return -1;
    }
    
    such= suchen(kopf, 6);
    if (such == NULL || such->wert != 6) {
      printf("Fehler: suchen. 6 nicht gefunden\n"); 
      return -1;
    }
    

    neu7 = malloc(sizeof(*neu7));
    neu7->wert = 7;
    neu7->next = NULL;
    if (einfuegen_ende(&kopf, &neu6, neu7) != 0) {
      printf("Fehler beim einfügen\n"); 
      return -1;
    }
    	
    	        
    such= suchen(kopf, 4);
    if (such == NULL || such->wert != 4) {
      printf("Fehler: suchen. 4 nicht gefunden\n"); 
      return -1;
    }
    
    such= suchen(kopf, 6);
    if (such == NULL || such->wert != 6) {
      printf("Fehler: suchen. 6 nicht gefunden\n"); 
      return -1;
    }
    
    such= suchen(kopf, 7);
    if (such == NULL || such->wert != 7) {
      printf("Fehler: suchen. 7 nicht gefunden\n"); 
      return -1;
    }
    

    entf= entfernen(&kopf, neu5);
    if (entf == NULL) {
      printf("Fehler: entfernen. 5 nicht gefunden\n"); 
      return -1;
    }

    entf= entfernen(&kopf, neu7);
    if (entf == NULL) {
      printf("Fehler: entfernen. 7 nicht gefunden\n"); 
      return -1;
    }

    entf= entfernen_kopf(&kopf);
    if (entf == NULL) {
      printf("Fehler: entfernen. 4 nicht gefunden\n"); 
      return -1;
    }
    
    durchlaufen(kopf);
    
    entf= entfernen_ende(&kopf);
    if (entf == NULL) {
      printf("Fehler: entfernen. 6 nicht gefunden\n"); 
      return -1;
    }

    printf("Leerer Durchlauf:");    
    durchlaufen(kopf);
    
    return 0;
}


int main(void) {

    return test();
}
