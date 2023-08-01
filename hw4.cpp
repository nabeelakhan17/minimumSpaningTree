#include <iostream>
#include <vector>
#include "math.h"
using namespace std;

pair<vector<float>, vector<int>> WWWWW(vector<float> w, vector<float> p , int s, int t)
{
    int j = w.size();
    vector <int> decisions(j-1, 1);
    vector <float> table(j, 0);
    table[j-1] = w[j-1];
    for(int i =j-2; i>=0; i--)
    {
     int min = 0;
     if(i+1> t)
     {
         min = t;
     }
     else if(i+1 > s)
     {
         min = s;
     }
     table[i] = fmax(table[i+1] *p[i+1] + (1-p[i+1])* w[min], w[i]);
     if(table[i] == w[i])
     {
         decisions[i] =0;
     }
 }


    return make_pair(table, decisions);

}


pair< vector< vector<float> > , vector< vector<int> > >  WWWWW_1(vector<float> w, vector<float> p, int s, int t)
{
    int j = w.size();
    vector < vector<float> > fres(2, vector<float>(j,0));
    vector < vector<int> > fres2(2,vector<int>(j,1));

    fres[0][j-1] = w[j-1];
    fres[1][j-1] = w[j-1];

   for(int i =j-2; i>=0; i--)
   {
       int min =0;
       if(i+1>t)
       {
           min = t;

       }
       else if(i+1 > s)
       {
           min = s;
       }

       float easier = fmax(0.6f, p[i+1]);
       fres[0][i] = fmax(fres[0][i+1] * p[i+1] + (1 - p[i+1]) * w[min], w[i]);

       float nope = fres[1][i+1]*p[i+1] +(1-p[i+1])* w[min];
       float yes = fres[0][i+1] *easier + (1-easier)*w[min];

       fres[1][i] = fmax(fmax(nope, yes), w[i]);
       if(fres[0][i] == w[i])
       {
           fres2[0][i] = 0;
       }
       else
       {
           fres2[0][i] = 1;
       }

       fres2[1][i] = (fres[1][i] == w[i])? 0 : (fres[1][i]== nope)? 1:2;


   }
   fres2[0][j-1] = 1;
   fres2[1][j-1] =1;

    return make_pair(fres, fres2);
}

//pair< vector< vector<float> > , vector< vector<int> > >  WWWWW_2(vector<float> w, vector<float> p, int s, int t)
//{
//    vector < vector<float> > fres;
//    vector < vector<int> > fres2;
//
//    vector <float> res0;
//    vector <int> res1;
//
//    res0.push_back(1.0);
//    res0.push_back(2.0);
//    res1.push_back(1);
//
//    fres.push_back(res0);
//    fres.push_back(res0);
//    fres.push_back(res0);
//    fres.push_back(res0);
//    fres2.push_back(res1);
//    fres2.push_back(res1);
//    fres2.push_back(res1);
//    fres2.push_back(res1);
//
//    return make_pair(fres, fres2);
//}
//
//
