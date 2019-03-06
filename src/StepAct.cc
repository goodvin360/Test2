
#include "StepAct.hh"
#include "G4SystemOfUnits.hh"


StepAct::StepAct(EventAct *eventAct):event(eventAct)
{

}

void StepAct::UserSteppingAction(const G4Step *aStep)

{


    if (aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName() =="Source")

    {
        event->AddEnDep1(aStep->GetTrack()->GetKineticEnergy());
    };


    if
    (
    (aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName() == "Detector")

//    &&(aStep->GetTrack()->GetParticleDefinition()->GetParticleName() != "neutron")

            )

    {

//                event->AddEnDep2(aStep->GetTrack()->GetKineticEnergy());
        event->AddEnDep2(aStep->GetTotalEnergyDeposit());


//
//        cout << "VertexKineticEnergy =  " << aStep->GetTrack()->GetVertexKineticEnergy()<< '\n';
//        cout << "Step Lenght = " << aStep->GetStepLength()<< '\n';
//        cout << "Track Lenght = " << aStep->GetTrack()->GetTrackLength() << '\n';
//        cout << "ParticleName  " << aStep->GetTrack()->GetDynamicParticle()->GetDefinition()->GetParticleName() << '\n';
//        cout << "Kinetic Energy = " << aStep->GetTrack()->GetKineticEnergy() << '\n';
//        cout << "Total Energy Deposit = " << aStep->GetTotalEnergyDeposit() << '\n';
//        cout << "Number of Secondaries in current step = " << aStep->GetNumberOfSecondariesInCurrentStep() << '\n';
//        cout << "DeltaEnergy = " << aStep->GetDeltaEnergy() << '\n';
//        cout << "Total track energy " << aStep->GetTrack()->GetTotalEnergy()<< '\n';
//        cout << '\n';


    };



}

