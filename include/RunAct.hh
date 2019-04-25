

#ifndef CPROJECT_RUNACT_HH
#define CPROJECT_RUNACT_HH

#include <G4UserRunAction.hh>
#include <G4SystemOfUnits.hh>
#include "Run.hh"
#include "EventAct.hh"
#include <map>

using namespace std;

class G4Run;


class RunAct : public G4UserRunAction {
public:

    RunAct();
    ~RunAct();
    void BeginOfRunAction(const G4Run *aRun);
    void EndOfRunAction(const G4Run *aRun);

    void AddEvent1(G4double energy1);

//    void AddEvent2(G4double energy2, G4int count2);
     void AddEvent2(G4double energy2);

    int nStep = 2000;
    G4double Emax = 20.0*MeV;
    double a = 0.01;
    double b = 0.002;


private:

    std::map <G4double, G4int> *result1;
    std::map <G4double, G4int> *result2;

//    G4double*REnergy=new G4double [nStep];
//    G4int*RCounts=new G4int [nStep];

};

#endif //CPROJECT_RUNACT_HH
