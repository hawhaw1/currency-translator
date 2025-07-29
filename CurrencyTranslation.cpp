/*==========================================================

 Title:     Assignment 13 (Final) - C++ Currency Translation Machine
 Course:  	CSC 1100
 Author:  	<Hawraa Alzamel>
 Date:    	<11 /30 /23 >
 Description: This program takes amount needed in exchange currency and gives the amount due in US dollar.

 ==========================================================
*/
#include <iostream>
#include <fstream>
#include <iomanip>
class ctm {
protected:
int cuse;
double conv;
std :: string cn;
public: 
void intro() {
    do {
        std:: cout << "";
        std :: cin >> cuse;
        if (std:: cin.fail() || cuse < 1 || cuse > 3) {
            std:: cin.clear();
            std:: cin.ignore(100, '\n');
            std:: cerr << "Invlalid entry, Please enter a number between 1-3:" << std:: endl;
        }   
        }
    
        
     while (cuse < 1 || cuse > 3);
    if (cuse ==1) {
        conv = 6.77;
        cn = "Yuan";
    } else if (cuse ==2) {
        conv = 0.98;
        cn = "Euro";
    } else{
        conv = 0.83;
        cn = "Pounds";
    }
        
    }
    

    };
    class amount: public ctm {
        protected:
        double ac;
        double ca;
        double cf;
        double tt;
        
    public:
    void calculations() {
        std:: cout << "";
        std:: cin >> ac;
        
        ca = ac / conv;
        cf = ca * 0.05;
        tt = ca + cf;
        
        
    }
    
    };
    class rc : public amount {
        public:
        void rctype() {
            std::ofstream outFile("receipt.txt");
            if (outFile .is_open()) {
                outFile << std:: fixed << std::setprecision(2);
                outFile << ac << " "<< cn << std:: endl;
                outFile << ca << " dollars" << std:: endl;
                outFile << cf << " dollars" << std::endl;
               outFile << tt << " dollars" << std::endl;
               outFile.close();
               
               std ::ifstream inFile("receipt.txt");
               if (inFile.is_open()) {
                   std :: string line;
                   while (getline(inFile, line)) {
                       std :: cout << line << std::endl;
                       
                   }
                   inFile.close();
               } 
               }
            };
        };
    


int main()
{
    rc obj; 
    obj.ctm::intro();
    obj.amount::calculations();
    obj.rctype();
    
    return 0;
}

