#ifndef _LISTE1ENDE_H
#define _LISTE1ENDE_H
struct knoten {
    int wert; /* oder komplexere Daten */
    struct knoten *next;
};

void durchlaufen(struct knoten *kopf);
struct knoten *suchen(struct knoten *kopf, int gesuchter_wert);
int einfuegen_kopf(struct knoten **kopfref, struct knoten *einzufueg);
int einfuegen_nach(struct knoten *nachdiesem, struct knoten *einzufueg);
int einfuegen_ende(struct knoten **kopfref, struct knoten **enderef, struct knoten *einzufueg);
struct knoten *entfernen_kopf(struct knoten **kopfref);
struct knoten *entfernen_ende(struct knoten **kopfref);
struct knoten *entfernen(struct knoten **kopfref, struct knoten *auszufueg);
#endif
