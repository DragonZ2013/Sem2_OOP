#include <iostream>
#include <fstream>

using namespace std;

class Konto{
  private:
      double sum=0;
  public:
    void File_Transaction(bool is_in,double val1,double val2);
    void Bezhalen(const double &Betrag)
    {
        if(Betrag<=sum)
            {sum-=Betrag;
            File_Transaction(1,Betrag,sum);}
        else
            cout<<"Not enough amount\n";
    }
    void Einzhalung(const double &Betrag)
    {
        {sum+=Betrag;
        File_Transaction(0,Betrag,sum);}
    }
    double Kontostand()
    {
        return sum;
    }
};

void Konto::File_Transaction(bool is_in,double val1,double val2)
{
  ofstream outfile;
  outfile.open("test.txt", std::ios_base::app); // append instead of overwrite
  if(is_in)
    outfile << "IN "<< val1<<" "<<val2<<'\n';
  else
    outfile << "OUT "<< val1<<" "<<val2<<'\n';
}


int main()
{
    Konto a;
    a.Einzhalung(100.2);
    a.Bezhalen(102.2);
    cout<<a.Kontostand();
    return 0;
}
