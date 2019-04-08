
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
aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName()=="Detector" &&
        aStep->GetTrack()->GetParticleDefinition()->GetParticleName()=="proton")

    {

        event->AddEnDep2(aStep->GetTrack()->GetKineticEnergy(), 1);

        theTrack->SetTrackStatus(fKillTrackAndSecondaries);


    };



}

