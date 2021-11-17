#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
// Chaines de caractères à utiliser pour les affichages:
/*

été jeté

d'un

n'est

L'oeuvre

bibliothèque

détruit

*/

/*************** DEBUT AUTEUR *****************/
class Auteur
{
     private:
          string nom;
          bool prime=false;

     public:
          Auteur (string nom, bool prime=false);
          //Auteur ();
          ~Auteur ();
          string getNom () const;
          bool getPrime () const;
          //Auteur (Auteur const&) = delete; // pour interdire la copie



};


Auteur::Auteur (string nom, bool prime)
:nom(nom),prime(prime)
{
     cout << "Nouveau auteur !" << endl;
}

/*Auteur:: Auteur()
{
     cout << "Nouveau auteur !" << endl;
}*/
Auteur::~Auteur()
{
     cout << "Suppression de l'auteur !" << endl;
}

string Auteur::getNom() const
{
     return nom;
}

bool Auteur::getPrime () const
{
     return prime;
}

/************************** FIN AUTEUR *************/



/************************* DEBUT Oeuvre **************/

class Oeuvre
{
private:
     string titre;
     string langue;
     Auteur a;
public:
     Oeuvre(string const& titre, Auteur const& a, string langue);
     ~Oeuvre();
     string getTitre () const;
     Auteur const& getAuteur ()const;
     string getLangue () const;
     void affiche () const;
     //Oeuvre (Oeuvre const&) = delete; // interdire la copie de Oeuvre


     
};

string Oeuvre::getTitre () const
{
     return titre;
}

Auteur const& Oeuvre::getAuteur () const
{
     return a;
}

string Oeuvre::getLangue () const
{
     return langue;
}

void Oeuvre::affiche() const
{
     cout << getTitre()<< " , " << getAuteur().getNom() << " , en " << getLangue() << endl;
}

Oeuvre::Oeuvre(string const& titre,  Auteur const& a, string langue)
:titre(titre),a(a), langue(langue)
{
     cout << "Nouvelle oeuvre !" << endl;
}

Oeuvre::~Oeuvre()
{
     cout << "L'oeuvre \" " << getTitre() << " , " << getAuteur().getNom() << ", en " << getLangue() << " \" n'est plus disponible."<< endl;
}


/**************************FIN Oeuvre  ***************/



/**************************DEBUT Examplaire **************/

class Examplaire
{
private:
     Oeuvre o;

public:
     Examplaire(Oeuvre const& o);
     ~Examplaire();
     Oeuvre const& getOeuvre () const;
     void affiche () const;
     Examplaire (Examplaire const& example);
};

Examplaire::Examplaire(Oeuvre const& o)
:o(o)
{
     cout << "Nouvel examplaire de : " << o.getTitre() << " , " << o.getAuteur().getNom() << " en " << o.getLangue() << endl;
}

Examplaire::~Examplaire()
{
     cout << " Un exemplaire de \" " << o.getTitre() << " , " << o.getAuteur().getNom() << " en " << o.getLangue() << "\" " << " a été jeté !" << endl; 
}

Examplaire::Examplaire (Examplaire const& example)
:o(example.o)
{
     cout << " Copie d'un examplaire de : " << o.getTitre() << " , " << o.getAuteur().getNom() << " en " << o.getLangue() << endl;

}

Oeuvre const& Examplaire::getOeuvre() const
{
     return o;
}


void Examplaire::affiche () const 
{
     cout << o.getTitre() << ", " << o.getAuteur().getNom() <<", en " << o.getLangue(); 
}

/**************************FIN Examplaire ***************/


/************************ DEBUT Bibliotheque *******************/

class Bibliotheque
{
private:
     string nom;
     vector <Examplaire > examplaires;
public:
     Bibliotheque(string nom);
     ~Bibliotheque();
     string getNom() const;
     void stocker (Oeuvre const& o, int nb_examplaires=1);
     void lister_exemplaires(string langue ="") const;
     int compter_exemplaires (Oeuvre const&  o) const;
     void afficher_auteurs (bool prix = false) const;
};

Bibliotheque::Bibliotheque(string nom)
: nom (nom)
{
     cout << "La bibliotheque" << getNom()<< " est ouverte !" << endl;
}

Bibliotheque::~Bibliotheque()
{
     cout << "La bibliothèque " << getNom() << " ferme ses portes, et détruit ses examplaires :" <<endl;
}

string Bibliotheque::getNom() const 
{
     return nom;
}

void Bibliotheque::stocker(Oeuvre const& o, int nb_examplaires)
{
     for(int i = 0; i< nb_examplaires; i++)
     {
          examplaires.push_back(Examplaire(o));
     }
}

void Bibliotheque::lister_exemplaires(string langue ) const
{
     size_t n = examplaires.size();

     if (langue =="")
     {
          for(auto i:examplaires)
          {
               i.affiche();
          }
     }
     else
     {
          for(auto i:examplaires)
          {
               if ((i).getOeuvre().getLangue()==langue)
               {
                    i.affiche();
               }
          }
     }

}

int Bibliotheque::compter_exemplaires(Oeuvre const& o) const
{
     int nombre = 0;
     size_t n = examplaires.size();
     for( auto i:examplaires)
     {
          if (i.getOeuvre().getAuteur().getNom()== o.getAuteur().getNom() && i.getOeuvre().getLangue()==o.getLangue() && i.getOeuvre().getTitre()==o.getTitre())
          {
               ++nombre;
          }
     }
     return nombre;
}

void Bibliotheque::afficher_auteurs (bool prix) const
{
     size_t n = examplaires.size();
     if (prix == false)
     {
          for(auto i:examplaires)
          {
               cout << (i).getOeuvre().getAuteur().getNom() << endl;
          }
     }

     else
     {
          for(auto i:examplaires)
          {
               if ((i).getOeuvre().getAuteur().getPrime() == true)
               {
                    cout << (i).getOeuvre().getAuteur().getNom() <<endl;
               }
          }
     }
}


/************************ FIN Bibliotheque *********************/




/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/ 

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);
  
  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
