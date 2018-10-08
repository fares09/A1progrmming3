#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    int n1,n2,n3,n4;
    cin >> n1 >> n2 >> n3 >> n4;

    ofstream of("fares.svg");



    double maxNum =max(max(max(n1,n2),n3),n4);

    // max / ? = 400; max * (1/?) = 400; 1/? = 400/max , ? =max / 400;


    if(maxNum > 400){
        double scale = maxNum/400;
        n1= int(n1/scale);
        n2= int(n2/scale);
        n3= int(n3/scale);
        n4= int(n4/scale);

        maxNum = maxNum =max(max(max(n1,n2),n3),n4);
    }
    of << "<?xml version=\"1.0\" standalone=\"no\"?> "<< endl;
    of << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">  "<< endl;
    of << "<svg width=\"500\" height=\"500\" xmlns=\"http://www.w3.org/2000/svg\">  "<< endl;








    //lines
    of << " <line x1=\"200\" y1=\"0\" x2=\"200\" " << " y2= \"" << maxNum + 10 << "\" " << endl
    <<" style=\"stroke:black;stroke-width:2\"/> " << endl << endl;


    of << " <line x1= \"200\" y1=\" " << maxNum +10 << "\" x2= \" " << 200 + 200 << "\" y2= \" " << maxNum +10 << endl <<
     "\" style=\"stroke:black;stroke-width:2\"/>" << endl << endl;

    // bars
    of << " <rect x=\"210\" y=\" " <<maxNum +10 -n1 << "\" width=\"30\" height=\" " << n1 << "\"" << endl
    << " style=\"fill:blue;\"/> " << endl << endl;

    of << " <rect x=\"250\" y=\" " <<maxNum +10 -n2 << "\" width=\"30\" height=\" " << n2 << "\"" << endl
    << " style=\"fill:blue;\"/> " << endl << endl;

    of << " <rect x=\"290\" y=\" " <<maxNum +10 -n3 << "\" width=\"30\" height=\" " << n3 << "\"" << endl
    << " style=\"fill:blue;\"/> " << endl << endl;

    of << " <rect x=\"330\" y=\" " <<maxNum +10 -n4 << "\" width=\"30\" height=\" " << n4 << "\"" << endl
    << " style=\"fill:blue;\"/> " << endl << endl;

    of << "</svg>";




}
