//created by Karthik Chavan k1833342 at 6/20/20

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class LinkedChar
{
public:
   LinkedChar()
   {
      list = NULL;
      listL = 0;
   }
   LinkedChar(const string s)
   {
      list = NULL;
      listL = s.size();
      for (int i = s.size() - 1; i >= 0; i--)
      {
         C* item = new C;
         item->val = s[i];
         item->next = list;
         list = item;
      }
   }
   int length()
   {
      return listL;
   }
   bool isEmpty()
   {
      return length() == 0;
   }
   int index(char ch)
   {
      C* item = list;
      int index = 0;
      while (item != NULL)
      {
         if (item->val == ch)
         {
            return index;
         }
         index = index + 1;
         item = item->next;
      }
      return -1;
   }
   void append(LinkedChar& lc)
   {
      C* item = list;
      while (item->next != NULL)
      {
         item = item->next;
         cout << item->val << endl;
      }
      item->next = lc.list;
   }
   bool submatch(LinkedChar& lc)
   {
      C* item = list;
      while (item != NULL)
      {
         C* secstr = lc.list;
         while (lc.list != NULL && item != NULL && item->val == lc.list->val)
         {
            item = item->next;
            lc.list = lc.list->next;
         }
         if (lc.list == NULL)
         {
            return true;
         }
         lc.list = secstr;
         item = item->next;
      }
      return false;
   }
private:
   struct C
   {
      char val;
      C* next;
   };
   C* list;
   int listL;
};

int main()
{
   string s1;
   string s2;
   string s3;
   string s4;
   string s5;
   char c;
   int n = 0;

   cout << "Enter a new string" << endl;
   cin >> s1;
   LinkedChar string1 = LinkedChar(s1);
   cout << "1.Enter a new string" << endl;
   cout << "2.Get current legnth" << endl;
   cout << "3.Find index of char" << endl;
   cout << "4.Append another list to the current list" << endl;
   cout << "5.Test is (4) submatched" << endl;
   cout << "6.Quit" << endl;
   cout << "enter a number: ";
   cin >> n;
   while (n != 6)
   {
      if (n == 1)
      {
         cout << "Enter a new string" << endl;
         cin >> s1;
         LinkedChar string1 = LinkedChar(s1);
      }
      if (n == 2)
      {
         cout << "get length: " << string1.length() << endl;
         
      }
      if (n == 3)
      {
         cout << "enter a char" << endl;
         cin >> c;
         cout << "index: " << string1.index(c) << endl;
         
      }
      if (n == 4)
      {
         cout << "Enter a new string" << endl;
         cin >> s2;
         LinkedChar string2 = LinkedChar(s2);
         string1.append(string2);
         
      }
      if (n == 5)
      {
         cout << "Enter a new string" << endl;
         cin >> s3;
         LinkedChar string3 = LinkedChar(s3);
         string1.append(string3);
         cout << "Test submatch" << string1.submatch(string3) << endl;
         
      }
      if (n == 6)
      {
         return 0;
      }
      cout << "1.Enter a new string" << endl;
      cout << "2.Get current legnth" << endl;
      cout << "3.Find index of char" << endl;
      cout << "4.Append another list to the current list" << endl;
      cout << "5.Test is (4) submatched" << endl;
      cout << "6.Quit" << endl;
      cout << "enter a number: ";
      cin >> n;
      cout << endl;
   }



   

   return 0;
}
