

#ifndef CPROJECT_EVENTACT_HH
#define CPROJECT_EVENTACT_HH

#include "G4UserEventAction.hh"
#include "G4RunManager.hh"
#include "RunAct.hh"
#include "Run.hh"
#include <vector>
#include "G4SystemOfUnits.hh"

using namespace std;

class RunAct;

class EventAct : public G4UserEventAction
{
public:
    EventAct(RunAct* runAct);
    ~EventAct();
   // virtual void BeginOfEventAction(const G4Event* event);
   // virtual void EndOfEventAction(const G4Event* event);
      void BeginOfEventAction(const G4Event* anEvent);
      void EndOfEventAction(const G4Event* anEvent);
      void AddEnDep1 (G4double en1);
      void AddEnDep2 (G4double en2);
      int nStep = 2000;
      double Emax = 20*MeV;
      vector <double> VecEnergy;

//        G4double*Energy=new G4double [nStep];
//        G4int*Counts=new G4int [nStep];

private:
      RunAct *run;
      G4double EnergyDep1;
      G4double EnergyDep2;
//      G4int Count2;


};

#endif //CPROJECT_EVENTACT_HH
