#include "tree.hpp"

int main(void)
{
  BST * T = new BST();
  int choice;
  
  do
  {
      Menu(T);
      cout << endl;
      cout << "Twoj wybor: ";
      cin >> choice;
    
      if((choice < 0) || (choice > 8)){
         cout << endl << "bledny wybor!\n";
     }

     cout << endl;

     if((T -> root == NULL) && (choice == 1)){ 
         Test_Insert(T); 
     }
     else{
         switch(choice){
             case 1 : 
                 Test_Insert(T);
                 break;
             case 2 : 
                 Test_Remove_node(T);
                 break;
             case 3 :
                 cout << "Wynik: " << endl; 
                 Test_MinMax(T);
                 break;
             case 4 : 
                 Test_Suc_Predecessor(T);
                 break;
             case 5 : 
                 Test_Search(T);
                 break;
             case 6 :
                 cout << "Wynik: " << endl;
                 Test_Preorder(T);
                 break;
             case 7 :
                 cout << "Wynik: " << endl;
                 Test_Inorder(T);
                 break;
             case 8 :
                 Number_of_nodes(T);
           }
        } 
  } while(choice);
  
  delete T;
  return 0;
}
