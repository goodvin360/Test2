//#define OuterSpectra
#define SingleEnergy

#ifndef CPROJECT_PRIMARYGEN_HH
#define CPROJECT_PRIMARYGEN_HH


#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4SingleParticleSource.hh"
#include "G4GeneralParticleSource.hh"
#include "G4UniformRandPool.hh"

#include "G4Event.hh"

#include "G4SystemOfUnits.hh"

#include "G4Gamma.hh"
#include "G4Positron.hh"
#include "G4Electron.hh"
#include "G4Neutron.hh"
#include "G4Deuteron.hh"
#include "G4Alpha.hh"
#include <map>
#include "PrimaryGenMessenger.hh"
#include "vector"
#include <fstream>
#include <iostream>
#include <stdio.h>

#include "math.h"

using namespace std;

class G4ParticleGun;
class G4Event;
class PrimaryGenMessenger1;
class PrimaryGenMessenger2;


class PrimaryGen : public G4VUserPrimaryGeneratorAction
{
private:

   G4ParticleGun*  gun;

   PrimaryGenMessenger1 * primarygenmessenger1;

   PrimaryGenMessenger2 * primarygenmessenger2;


#ifdef OuterSpectra
   map<G4double, G4double> *ew;
#endif


    public:
    PrimaryGen();
    virtual ~PrimaryGen();
    virtual void GeneratePrimaries(G4Event*);


    void SetParticleCounts(G4double newValue)
    {
        PCounts = newValue;
    }

    void SetCountsStep (G4double newValue)
    {
        Step = newValue;
    }

    G4String outerspectrapath = "/home/renat/CLionProjects/Test2/TestSpectra.txt";

    G4String theEnd = "gun.txt";

    G4String outerspectrapath2 = (outerspectrapath+theEnd);

    double Counter = 0;
    double Sum = 0;
    double t2 =0;
    double t1 =0;
    double dt = 0;
    double PCounts = 1000;
    double Step = 1000;

};

#endif //CPROJECT_PRIMARYGEN_HH
