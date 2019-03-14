
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

//            &&(aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "proton")

              &&(aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "neutron")

            )

    {

//        cout << "VertexKineticEnergy =  " << aStep->GetTrack()->GetVertexKineticEnergy()<< '\n';
//        cout << "Step Lenght = " << aStep->GetStepLength()<< '\n';
//        cout << "Track Lenght = " << aStep->GetTrack()->GetTrackLength() << '\n';
//        cout << "ParticleName  " << aStep->GetTrack()->GetDynamicParticle()->GetDefinition()->GetParticleName() << '\n';
//        cout << "Kinetic Energy = " << aStep->GetTrack()->GetKineticEnergy() << '\n';
//        cout << "Total Energy Deposit = " << aStep->GetTotalEnergyDeposit() << '\n';
//        cout << "Number of Secondaries in current step = " << aStep->GetNumberOfSecondariesInCurrentStep() << '\n';
//        cout << '\n' << "DeltaEnergy = " << abs(aStep->GetDeltaEnergy()) << '\n';
//        cout << "Total track energy " << aStep->GetTrack()->GetTotalEnergy()<< '\n';
//        cout << '\n';
//        cout << '\n' << "Proton kinetic energy = " << aStep->GetTrack()->GetKineticEnergy() << " MeV" << '\n';
//        cout <<  "Proton total energy deposited = " << aStep->GetTotalEnergyDeposit() << " MeV" << '\n';
//        cout << "Track status is " << aStep->GetTrack()->GetTrackStatus() << '\n';
//        event->AddEnDep2(aStep->GetTotalEnergyDeposit());
//        event->AddEnDep2(abs(aStep->GetDeltaEnergy()));



    };

    if
            (
            (aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName() == "Detector")

                        &&(aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "proton")

//            &&(aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "neutron")

            )

    {

        a = aStep->GetTrack()->GetKineticEnergy();
        b += aStep->GetTrack()->GetKineticEnergy();
//        cout << "VertexKineticEnergy =  " << aStep->GetTrack()->GetVertexKineticEnergy()<< '\n';
//        cout << "Step Lenght = " << aStep->GetStepLength()<< '\n';
//        cout << "Track Lenght = " << aStep->GetTrack()->GetTrackLength() << '\n';
//        cout << "ParticleName  " << aStep->GetTrack()->GetDynamicParticle()->GetDefinition()->GetParticleName() << '\n';
//        cout << "Kinetic Energy = " << aStep->GetTrack()->GetKineticEnergy() << '\n';
//        cout << "Total Energy Deposit = " << aStep->GetTotalEnergyDeposit() << '\n';
//        cout << "Number of Secondaries in current step = " << aStep->GetNumberOfSecondariesInCurrentStep() << '\n';
//        cout << "DeltaEnergy = " << aStep->GetDeltaEnergy()*-1 << '\n';
//        cout << "Total track energy " << aStep->GetTrack()->GetTotalEnergy()<< '\n';
        cout << '\n';
        cout  << "Proton kinetic energy = " << a << " MeV" << '\n';
        cout <<  "Proton total energy deposited = " << aStep->GetTotalEnergyDeposit() << " MeV" << '\n';
//        cout << "Track status is " << aStep->GetTrack()->GetTrackStatus() << '\n';
//        event->AddEnDep2(aStep->GetTotalEnergyDeposit());
//        event->AddEnDep2(aStep->GetTrack()->GetKineticEnergy());



    };






}

