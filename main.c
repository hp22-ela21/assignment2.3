/* Inkluderingsdirektiv: */
#include "header.h"

/**********************************************************************************************
* Objektet e1 anv�nds f�r att l�sa in sp�nning samt str�m fr�n tangentbordet, d�r resistansen
* sedan ber�knas med Ohms lag. Inmatade v�rde skrivs ut i konsolen och skrivs �ven till en
* textfil d�pt data.txt. Eventuellt tidigare inneh�ll skrivs �ver. Pekare e2 anv�nds f�r
* att lagra motsvarande storheter, fast med storheterna justerade med en given ratio,
* inmatad av anv�ndaren. Sp�nningen multipliceras med denna faktor, men str�mmen divideras.
* Inneh�llet skrivs ut i konsolen och l�ggs dessutom till l�ngst ned i textfilen data.txt.
**********************************************************************************************/
int main(void)
{
   struct electrical e1, *e2;
   FILE* fstream;
   double ratio;

   electrical_new(&e1);
   e1.vptr->get_input(&e1);
   e1.vptr->print(&e1, stdout);
   fstream = fopen("data.txt", "w");
   e1.vptr->print(&e1, fstream);

   fprintf(stdout, "Enter a change ratio for the electrical quantities:\n");
   ratio = get_double();

   e2 = electrical_ptr_new();
   e2->vptr->set(e2, e1.vptr->voltage(&e1) * ratio, e1.vptr->current(&e1) / ratio);
   e2->vptr->print(e2, stdout);
   fstream = fopen("data.txt", "a");
   e2->vptr->print(e2, fstream);
   fclose(fstream);

   electrical_delete(&e1);
   electrical_ptr_delete(e2);
   return 0;
}

