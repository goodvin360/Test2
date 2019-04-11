
#include "StepAct.hh"
#include "G4SystemOfUnits.hh"


StepAct::StepAct(EventAct *eventAct):event(eventAct)
{

}

void StepAct::UserSteppingAction(const G4Step *aStep)

{


    G4Track*theTrack = aStep->GetTrack();

    if (aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName() =="Source")

    {
        event->AddEnDep1(aStep->GetTrack()->GetKineticEnergy());
    };


    if
                                (
aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName()=="Detector" )

    {

        event->AddEnDep2(aStep->GetTotalEnergyDeposit(), 1);

    };



}

