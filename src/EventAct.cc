
#include "EventAct.hh"
#include "StepAct.hh"

EventAct::EventAct(RunAct *runAct):run(runAct)
{

}

EventAct::~EventAct()
{
//    delete [] Energy;
//    delete [] Counts;
}

void EventAct::BeginOfEventAction(const G4Event *anEvent)
{
    EnergyDep1 = 0;
    EnergyDep2 = 0;

    vector<double> VecEnergy ;

//    for (int i=0; i<nStep; i++)
//    {
//        Energy[i]=i*Emax/nStep;
//        Counts[i]=0;
//    }

}

void EventAct::EndOfEventAction(const G4Event *anEvent)
{
//    Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
      run->AddEvent1(EnergyDep1);
//    run->AddEvent2(EnergyDep2, Count2);

//    for (int i=0; i<nStep; i++)
//    {
//        run->AddEvent2(Energy[i], Counts[i]);
//    }

    for (int i=0; i<VecEnergy.size(); i++)
    {run->AddEvent2(VecEnergy[i]);}

    VecEnergy.clear();
}

void EventAct::AddEnDep1(G4double en1)
{
    EnergyDep1 = en1;
}

void EventAct::AddEnDep2(G4double en2)
{
//    EnergyDep2 += en2;

//    for (int i=0; i<nStep; i++)
//    {
//        if(abs(en2-Energy[i])<=(Emax/nStep))
//        {
//            Counts[i]+=1;
//        }
//    }

    VecEnergy.push_back(en2);

}

