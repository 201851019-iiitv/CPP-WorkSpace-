#include <bits/stdc++.h>
#include <fstream>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;

bool rule1(vector<string>&v)
{
//vector size is 6.
//Rule1:   <subject> <verb> <article> <adjective> <predicate> <.>

if(v[0]=="subject" && v[1]=="verb" && v[2]=="article" &&v[3]=="adjective" && v[4]=="predicate" && v[5]==".")
return true;


return false;

}
bool rule2(vector<string>&v)
{
//vector size is 5.
//Rule2:   <subject> <verb> <article>  <predicate> <.>
if(v[0]=="subject" && v[1]=="verb" && v[2]=="article" &&v[3]=="predicate" && v[5]==".")
return true;


return false;


}
bool rule3(vector<string>&v)
{
//vector size is 6.  
//Rule3:   <Verb> <subject> <article> <adjective> <predicate> <?>
if(v[0]=="verb" && v[1]=="subject" && v[2]=="article" &&v[3]=="adjective" && v[4]=="predicate" && v[5]=="?")
return true;


return false;


}
bool rule4(vector<string>&v)
{
//vector size is 5.   
//Rule4:   <Verb> <subject> <article>  <predicate> <?>

if(v[0]=="verb" && v[1]=="subject" && v[2]=="article" &&v[3]=="predicate" && v[5]=="?")
return true;


return false;


}

string  getdatatypes(string &s,unordered_map<string,string>&mp)
{

vector<string>types;
int n=s.length();


string s1="";
for(int i=0;i<n-1;i++)
{
   s1 +=s[i];
   if(s[i+1]==' ')
   {
 transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
   types.push_back(mp[s1]);
      s1="";
      i++;

   }

}

   
types.push_back(mp[s1]);
 // last char also a type 
string s3="";
    s3 +=s[n-1];

    types.push_back(s3);



   // *for debug  
   // for(auto &x:types)
   // {
   //   cout<<x<<" ";
   // }

   // cout<<"\n";


  if(types.size()==6)
  {
    
    if(rule1(types))
    {
         return "(Valid. Supports Rule1)";
    }
   
   if(rule3(types))
   {
      return "(Valid. Supports Rule3)";
   }

  return "(Invalid)";

  }
  else
  {

    if(rule2(types))
    {
         return "(Valid. Supports Rule2)";
    }
   
   if(rule4(types))
   {
      return "(Valid. Supports Rule4)";
   }

  return "(Invalid)";



  }


}

int main()
{

   unordered_map<string, string> mp;

   ifstream input;
   input.open("tokens.txt");

   string s, value, key;
   int i;
   while (getline(input, s))
   {

      value = "", key = ""; // value and key of
      i = 0;

      while (i < s.length() && s[i] != ':')
      {
         value += s[i];
         i++;
      }
      i++;
      while (i < s.length())
      {
         key += s[i];
         i++;
      }

      transform(value.begin(), value.end(), value.begin(), ::tolower);
      transform(key.begin(), key.end(), key.begin(), ::tolower);

      mp[key] = value;
   }
   input.close(); // token file close and store all value in map .
                  // taken O(numberofstring *stringlength).

   // //*for debug
   // for(auto &x:mp)
   // deb2(x.first,x.second);

   // *Open input.txt


string res="";
   input.open("input.txt");

   while (getline(input, s))
   {
   
    res= getdatatypes(s,mp);
    cout<<s<<"\t \t  "<<res<<"\n";

   }

   input.close();

   return 0;
}