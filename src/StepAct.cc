
#include "StepAct.hh"
#include "G4SystemOfUnits.hh"


StepAct::StepAct(EventAct *eventAct):event(eventAct)
{

}

void StepAct::UserSteppingAction(const G4Step *aStep)

{


    G4Track*theTrack = aStep->GetTrack();

//    G4cout << G4endl << "Neutron step number is " << aStep->GetTrack()->GetCurrentStepNumber() << G4endl << G4endl;

    if (aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName() =="Source")

    {
        event->AddEnDep1(aStep->GetTrack()->GetKineticEnergy());

    };

    G4Track*secTrack;
    if (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "neutron" &&
        aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName() =="Detector" &&
        aStep->GetNumberOfSecondariesInCurrentStep())

        for (unsigned i=0; i< aStep->GetNumberOfSecondariesInCurrentStep(); i++)
        {
            secTrack = aStep->GetSecondary()->at(i);
            if (
                    secTrack->GetDefinition()->GetParticleName()=="proton"
//                    && secTrack->GetCurrentStepNumber() == 0
                    )
                event->AddEnDep2(secTrack->GetKineticEnergy());
                G4cout << "Proton step number is " << secTrack->GetCurrentStepNumber() << G4endl;
                G4cout << "Proton kinetic energy is " << secTrack->GetKineticEnergy() << " MeV" << G4endl;
        }




}

