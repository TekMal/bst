#include "tree.hpp"

/*------------------------------funkcje klasy---------------*/

node * BST::maxNode(node * x)
{
  while(x -> right) 
     x = x -> right;
  return x;
}


/*--------------------------------------------------*/

node * BST::minNode(node * x)
{
  while(x -> left)
     x = x -> left;
  return x;
}
/*--------------------------------------------------*/


void BST::Insert_node(int key, node * x){
  if(key <= x -> key){
     if(x -> left)
         Insert_node(key, x -> left);
      else{
         node * n = new node;
         n -> key = key;
         n -> parent = x;
         x -> left = n;
      }
  }
  else{
      if(x -> right)
         Insert_node(key, x -> right);
      else{
         node * n = new node;
         n -> key = key;
         n -> parent = x;
         x -> right = n;
      }
  }

}


void BST::Del_node(node * x){
  if(x){
     Del_node(x -> left);
     Del_node(x -> right);
     delete x;
  }
}
/*--------------------------------------------------*/

BST::BST()
{
  root = NULL;
  Lnode = 0;
}

BST::~BST(){
  Del_node(root);
}

/*--------------------------------------------------*/
node * BST::Search(int key)
{
  node * x = root;

  while((x) && (x -> key != key))
     x = (key < x -> key) ? x -> left : x -> right;

  return x;  
}
/*--------------------------------------------------*/

node * BST::Successor(node * x)
{
  if(x -> right) 
     return minNode(x -> right);

  node * y;

  do
  {
     y = x;
     x = x -> parent;
  } while((x) && (x -> left != y));

  return x;
}
/*--------------------------------------------------*/

node * BST::Predecessor(node * x)
{
  if(x -> left) 
     return maxNode(x -> left);

  node * y;

  do
  {
     y = x;
     x = x -> parent;
  } while((x) && (x -> right != y));

  return x;
}
/*--------------------------------------------------*/

node * BST::Remove_node(node * x)
{
  node * y = x -> parent, * z;

  if((x -> left) && (x -> right))
  {
     z = Remove_node(Successor(x));
     z -> left = x -> left;   
     if(z -> left) 
         z -> left -> parent  = z;
     z -> right = x -> right;
     if(z -> right)
         z -> right -> parent = z;
     Lnode++ ;
  }
  else 
     z = (x -> left) ? x -> left : x -> right;

  if(z)
     z -> parent = y;
  
  if(!y)
     root = z;
  else
     if(y -> left == x)
         y -> left = z; 
     else 
         y -> right = z;
  
  Lnode--;
  
  return x;
}


/*--------------------------------------------------*/

int BST::MaxKey(node * x)
{
  while(x -> right) 
      x = x -> right;
  return x -> key;  
}




/*--------------------------------------------------*/

int BST::MinKey(node * x)
{
  while(x -> left)
      x = x -> left;
  return x -> key;  
}

/*--------------------------------------------------*/

void BST::Preorder(node * x)
{
  cout << x -> key << " : left-> ";
  if(x -> left) 
     cout << x -> left -> key;
  else   
     cout << "NULL";
  cout << ", right-> ";
  if(x -> right)
     cout << x -> right -> key;
  else   
     cout << "NULL";
  if(x -> parent) 
     cout << " ,     parent->" << x -> parent -> key;
  else
      cout << ", ROOT";
  cout << endl;
  if(x -> left) 
      Preorder(x -> left);
  if(x -> right)
      Preorder(x -> right);
 
}

/*--------------------------------------------------*/

void BST::Inorder(node * x)
{
  if(x -> left) 
      Inorder(x -> left);
  cout << x -> key << " : left-> ";
  if(x -> left) 
     cout << x -> left -> key;
  else   
     cout << "NULL";
  cout << ", right-> ";
  if(x -> right)
     cout << x -> right -> key;
  else   
     cout << "NULL";
  if(x -> parent) 
     cout << " ,     parent->" << x -> parent -> key;
  else
      cout << ", ROOT";
  cout << endl;
  if(x -> right)
      Inorder(x -> right);
 
}


/*--------------------------------------------------*/



/*--------------------------------------------------*/


void BST::Insert_node(int key){
 if(root == NULL){
     node * n = new node;
     n -> key = key;
     root = n;
   }
   else { 
       Insert_node(key, root);
     } 
 Lnode++;
}
/*---------------------------------------------------funkcje Testujace funkcje klasy w mainie---------------*/

void Test_Insert(BST * T)
{ int i, n, x;
  
  cout << "Podaj liczbe wezlow ktore chcesz utworzyc(aby potwierdzic wcisnij enter)\n" << endl;
  cin >> n;
  cout << endl;
  cout << "Podaj klucze tych wezlow za kazdym razem w celu potwierdzenia wcisnij enter\n" << endl;
  
  for(i = 0; i < n; i++)
  {
     cin >> x;
     T -> Insert_node(x);   
  }
  
  cout << endl;
  cout << "\nLiczba wezlow w drzewie po wstawieniu: " << T -> Lnode << endl << endl;       
}

/*--------------------------------------------------*/


void Test_Remove_node(BST * T)
{ 
  node * x;
  int key;
  
  cout << "podaj klucz wezla ktory chcesz usunac : "; 
  cin >> key;
  cout << endl;
  
  x = T -> Search(key);
  
  if(x)
  {
     T -> Remove_node(x);
     cout << endl;
     if(T -> root)
	       cout << "\nLiczba wezlow w drzewie po usunieciu: " << T -> Lnode << endl << endl; 
     else
         cout << "\nBrak wezlow w drzewie po usunieciu" << endl; 
  }
  else 
      cout << "\nwezel o takim kluczu nie istnieje\n";
}

/*--------------------------------------------------*/

void Test_MinMax(BST * T)
{
  cout << "najmniejszy klucz w drzewie  : " << T -> MinKey(T -> root) << endl << "najwiekszy klucz w drzewie: " << T -> MaxKey(T -> root) << endl;
}

/*--------------------------------------------------*/

void Test_Suc_Predecessor(BST * T)
{ 
  int key;
  node * x;
  node * y;
  cout << "Podaj klucz wezla: ";
  cin >> key;
  cout << endl;
  
  x = T -> Search(key);
  y = x;
  
  if(x)
  {
     x = T -> Successor(x);
     y = T -> Predecessor(y);

     if(y) 
	       cout << "poprzednikiem [" << key << "] jest " << y -> key << endl;
     else  
	       cout << "wezel [" << key << "] nie posiada poprzednika\n";

     if(x) 
         cout << "nastepnikiem [" << key << "] jest " << x -> key << endl;
     else  
         cout << "wezel [" << key << "] nie posiada nastepnika\n";
  }
  else 
      cout << "wezel o podanym kluczu niestety nie istnieje\n";     
}

/*--------------------------------------------------*/

void Test_Search(BST * T)
{ node * x;
  int key;
  cout << "podaj klucz wezla ktory chcesz znalezc : ";
  cin >> key;
  cout << endl;
  x = T -> Search(key);
 if(x) 
     cout << "wezel o podanym kluczu to: \n"<<endl;
 else 
     cout<<"wezel o podanym kluczy nie istnieje\n"<<endl;

 while(x){
     cout << x -> key << " : left-> ";
     if(x->left) 
          cout << x -> left -> key;
     else  
         cout << "NULL";
     cout << ", right-> ";
     if(x -> right)
         cout << x -> right -> key;
     else  
         cout << "NULL";
     if(x -> parent)
         cout << "      parent->" << x -> parent -> key;
     else
         cout << "   ROOT";
     cout << endl;
     x = NULL;
  }

}


/*--------------------------------------------------*/

void Test_Preorder(BST * T)
{
  T -> Preorder(T -> root);
}
/*--------------------------------------------------*/

void Test_Inorder(BST * T)
{
  T -> Inorder(T -> root);
}
/*--------------------------------------------------*/


void Number_of_nodes(BST * T){
  cout << "\nLiczba wezlow w drzewie : " << T -> Lnode << endl << endl;  
}

/*--------------------------------------------------*/


void Menu(BST * T){
  if(T -> root == NULL){
      cout << "Menu:\n"
      " 0 - zakoncz\n"
      " 1 - dodaj wezel/wezly\n";
   }
  else{
     cout << endl;
     cout << "Menu:\n"
     " 0 - zakoncz\n"
     " 1 - dodaj wezel/wezly\n" 
     " 2 - usun wezel\n"
     " 3 - wyswietl wezel o wartosci minimalnej i wezel o wartosci maksymalnej\n"
     " 4 - wyswietl poprzednika i nastepnika podanego wezla\n"
     " 5 - znajdz wybrany klucz\n"
     " 6 - przejdz przez drzewo (metoda preorder)\n"
     " 7 - przejdz przez drzewo (metoda inorder)\n"
     " 8 - ilosc wezlow\n";
   }
 }


