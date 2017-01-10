/*
 * given.cc
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

#define CASE 2

// Give alias declarations for pair<string, int> and vector<pair<string, int>>.
typedef pair<string, int> entry;
typedef vector<entry> sequence;

// Declare overloading a function insert(string, vector<pair_si> for inserting a
// string into a verctor, in a copy and a move version regarding the string.
void insert(string&& str, sequence& seq);
void insert(const string str, sequence& seq);

// Declare overloadings operator<< for pair and vector (beware of ADL).
ostream& operator<<(ostream& os, const sequence& s);
ostream& operator<<(ostream& os, const entry& e);

int main()
{
   sequence v;
   string s;

   while (cin >> s)
   {
      insert(s, v);  // test copy and move version!
   }

   // Print the content of the vector, with each entry on a line of its own.
   cout << v << endl;

   return 0;
}

struct entry_compare {
   bool operator()(entry const& lhs, string const& rhs) {
      lhs.first < rhs;
   }
};

#if CASE == 1

void insert(string&& str, sequence& seq) {
   entry e {str, seq.size()};
   seq.push_back(e);
}

// Define the overloadings of insert()
void insert(string str, sequence& seq) {
   auto it = lower_bound(seq.begin(), seq.end(), str, entry_compare());
   if (it == seq.end() || it->first != str) {
      entry e {str, 0};
      seq.insert(it, e);
   } else {
      ++it->second;
   }
}

#elif CASE == 2

// Define the overloadings of insert()
void insert(string str, sequence& seq) {
   entry e {str, seq.size() + 1};
   auto it = lower_bound(seq.begin(), seq.end(), str, entry_compare());
   seq.insert(it, e);
}

#endif

// Define the overloadings of operator<<
ostream& operator<<(ostream& os, const sequence& s) {
   for(entry e : s) {
      os << e << endl;;
   }
   return os; 
}

ostream& operator<<(ostream& os, const entry& e) {
   os << "(" << e.second << ") " << e.first;
   return os;
}
