#include <iostream>
#include<fstream>
#include<cctype>
using namespace std;

int main()
{
  int Rank;
  string boy_name,girl_name,name;
  bool find_boy=false,find_girl=false;
  ifstream file;
  file.open("babynames2012.txt",ios::in);
  if(!file.is_open()){
    cout<<"error while opening the file"<<endl;
  }
  else{

    cout<<"file opened successfully"<<endl;
    cout<<"enter the name that you search about it :"<<endl;
    cin>>name;

    int BRank, GRank;
    while(!file.eof() && (find_boy != true || find_girl !=true))
    {
        file>>Rank;
        file>>boy_name;
        file>>girl_name;

        // to make "Justice" == "justice";
        boy_name[0] = tolower(boy_name[0]);
        girl_name[0] = tolower(girl_name[0]);
        if(name==boy_name)
        {
            BRank = Rank;
            find_boy=true;
        }
        if(name==girl_name){
            GRank = Rank;
            find_girl=true;
        }

    }



    if(find_boy==true&&find_girl==false)
    {
        cout<<name<<" is ranked "<<BRank<<" in popularity among boys."<<endl;
        cout<<name<<" is not ranked among the top 1000 girl name"<<endl;
    }
    else if(find_boy==false&&find_girl==true)
    {
        cout<<name<<" is ranked "<<GRank<<" in popularity among girls."<<endl;
        cout<<name<<" is not ranked among the top 1000 boy name"<<endl;
    }
    else if(find_boy==true&&find_girl==true)
    {
        cout<<name<<" is ranked "<<BRank<<" in popularity among boys."<<endl;
        cout<<name<<" is ranked "<<GRank<<" in popularity among girls."<<endl;
    }
    else
    {
        cout<<name<<" is not ranked among the top 1000 boy name and the top 1000 girl name"<<endl;
    }

  }// end of file else.
  file.close();
}
/*
int matrix[1000][3];
string name;
ifstream file("babynames2012.txt");
if(!file.is_open())
{

    cout<<"error while opening the file"<<endl;


}
else
{
    cout<<"file opened successfully"<<endl;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=3;j++)
        {

            file>>matrix[i][j];



        }



    }
cout<<"enter the name to search about it :"<<endl;
cin>>name;
 for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=3;j++)
        {
        {






        }



    }
}
}*/
