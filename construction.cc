#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
  Brique(Forme form, Couleur col) : forme(form), couleur(col) {};
  ~Brique() {};
  void afficher(ostream& sortie) const;
  Forme getForme() const {return forme;};
  Couleur getCouleur() const {return couleur;};
};

void Brique::afficher(ostream& sortie) const
{
  if (couleur !="")
   {
     sortie << "(" << forme << ", " << couleur <<")";
   }
   else 
   {
     sortie << forme ;
   }
}

ostream& operator << (ostream& out, Brique const& brique)
{
  brique.afficher(out);
  return out;
}


class Construction
{
  friend class Grader;
  private :
    vector<vector<vector<Brique>>> contenu;
  public :
    Construction (Brique const& brique) : contenu({{{brique}}}) {};
    ostream& afficher(ostream& sortie) const;
    ~Construction(){};
    Construction& operator ^=(Construction const& construction);
    Construction& operator -=(Construction const& b);
};

Construction& Construction::operator ^=(Construction const& c)
{
  Construction tmp(Brique("       ",""));
  tmp.contenu = (*this).contenu;
  (*this).contenu.clear();
  vector<vector<vector<Brique>>> results; 
  for (auto j:c.contenu)
  {
    results.push_back(j);
  }
  for(auto i:tmp.contenu)
  {
    results.push_back(i);
  }
  (*this).contenu = results;
  return *this;
}

const Construction operator ^(Construction a,Construction const& b)
{
  return (a ^= b);
}

ostream& Construction::afficher(ostream& sortie) const
{
  size_t i = contenu.size();
  size_t j= i-1;
  if (contenu.empty()) sortie << "";
  else
  {
    for(auto hauteur:contenu)
    {
      sortie << "Couche " << j <<" : " << endl;
      for(auto profondeur:hauteur)
      {
        for(auto largeur:profondeur)
        {
          sortie << largeur <<" , ";
        }
        sortie << endl;
      }
      j -=1;
    }
  }
  return sortie;
}

ostream& operator << (ostream& out,Construction const& construction)
{
  construction.afficher(out);
  return out;
} 

Construction& Construction::operator -=(Construction const& b)
{
  size_t l = (*this).contenu.size();
  size_t m = b.contenu.size();
  size_t cnt = 0;
  
  if(l != m)
  {
    return *this;
  }

  else
  {
    for(auto hauteur:(*this).contenu)
    {
      size_t n = b.contenu[cnt].size();
      for( size_t cmp(0);cmp < n;cmp++ )
      {
        for(size_t i = 0; i<b.contenu[cnt][cmp].size();i++)
        {  cout<<"b: "<<b.contenu[cnt][cmp][i]<<endl;
          vector<Brique> Hauteur_cp;
          Hauteur_cp = hauteur[i];
          hauteur[i].clear();
          hauteur[i].push_back(b.contenu[cnt][cmp][i]);
          hauteur[i].push_back(Hauteur_cp)
        }
        cout<<"hauteur: "<<hauteur[cnt][cmp]<<endl;
      }
      cnt +=1;
    }
    return (*this);
  }

  /*

  for(auto hauteur:(*this).contenu)
    {
      for( auto alpha:b.contenu)
      {
        for(auto beta:alpha)
        {
          hauteur.push_back(beta);
        }
      }
    }
  return (*this);
    */
    /*size_t n = hauteur.size();


      vector<vector<brique>> results;
      results = hauteur;
      
      for(auto i(0); i<n;i++)
      {
        hauteur.push_back(b.contenu[ctn][i]);
      }
      for( auto elt:results)
      {
        hauteur.push_back(elt)
      }
      hauteur.push_back;
      cnt -=1;
    }
  }*/
}



const Construction operator*(unsigned int n, Construction const& a)
{
}

const Construction operator/(unsigned int n, Construction const& a)
{
}

const Construction operator%(unsigned int n, Construction const& a)
{
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");

  Construction maison1 (mur);
  Construction maison2 (toitM);
  Construction maison3 (maison1^maison2);
  //cout << (maison1 ^= maison2);
  

  //cout << maison1 << endl;
  //cout << maison2 << endl;

  maison2 -= maison1;
  //cout <<maison2<< endl;

  /*unsigned int largeur(4);
  unsigned int profondeur(3);
  unsigned int hauteur(3); // sans le toit

  // on construit les murs
  Construction maison( hauteur / ( profondeur % (largeur * mur) ) );

  // on construit le toit
  Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  toit ^= profondeur % (vide + toitG + toitD);

  // on pose le toit sur les murs
  maison ^= toit;

  // on admire notre construction
  cout << maison << endl; */

  return 0;
}
