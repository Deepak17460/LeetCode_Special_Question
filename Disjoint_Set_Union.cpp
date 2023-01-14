class DSU{
    //Access modifier
    public:
     vector<int>rank;
      vector<int>parent;
      // Contructor Calling
      DSU(int n){
          rank.resize(n);
          parent.resize(n);
          for(int i=0;i<n;i++){
              rank[i]=i;
              parent[i]=i;
          }
      }
         int findparent(int x) {
             if(x==parent[x]){
                 return x;
             }
             return parent[x]=findparent(parent[x]);
         }
         void makeUnion(int x,int y){
             int p1=findparent(x),p2=findparent(y);
             if(p1!=p2){
                 if(rank[p1]<rank[p2]){
                     parent[p2]=p1;
                 }
                 else{
                     parent[p1]=p2;
                 }
             }
         }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // Using Dsu(Disjoint Set Union)
        DSU dsu(26);
        for(int i=0;i<s1.size();i++){
            dsu.makeUnion(s1[i]-'a',s2[i]-'a');
        }
         string res="";
         for(int i=0;i<baseStr.size();i++){
             char ch=dsu.findparent(baseStr[i]-'a')+'a';
             res+=ch;
         }
         return res;
    }
};
