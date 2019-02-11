
#include "RunAct.hh"
#include "EventAct.hh"
#include "StepAct.hh"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

RunAct::RunAct()
{
    result1 = new std::map<G4double, G4int>;

    result2 = new std::map<G4double, G4int>;


}

RunAct::~RunAct()
{
    delete result1;

    delete result2;


}

void RunAct::BeginOfRunAction(const G4Run *aRun)
{
    result1->clear();

    for (int i=0; i <nStep; i++)
        result1->insert(std::pair<G4double, G4int> (i *Emax / nStep, 0));

    result2->clear();
    for (int i=0; i <nStep; i++)
        result2->insert(std::pair<G4double, G4int> (i *Emax / nStep, 0));


}

void RunAct::EndOfRunAction(const G4Run *aRun)
{

    fstream fout1("/mnt/hgfs/VMplayer/Test2/Source.txt", ios::out);
//    fstream fout1("../YAP.txt", ios::out);
    for (auto it1: *result1)
        fout1 << it1.first << " " << it1.second << '\n';
    fout1.close();

    fstream fout2("/mnt/hgfs/VMplayer/Test2/Detector.txt", ios::out);
//    fstream fout2("../CH.txt", ios::out);
    for (auto it2: *result2)
        fout2 << it2.first << " " << it2.second << '\n';
    fout2.close();

    auto P1 = new double *[nStep];
    for (int i = 0; i < nStep; i++) {
        P1[i] = new double[nStep];
    }

    auto Sigma = new double[nStep];
    auto Energy = new double[nStep];
    auto Counts = new double[nStep];
    auto NormCounts = new double[nStep];
    auto NormCounts_1 = new double[nStep];

    double E, Cnt;

    double PI = 3.1415;

    ifstream infile1;

    infile1.open("/mnt/hgfs/VMplayer/Test2/Detector.txt");

    for (int i = 0; i < nStep; i++) {
        infile1 >> E >> Cnt;
        Energy[i] = E;
        Counts[i] = Cnt;
    }

    infile1.close();

    double delta = Energy[10]-Energy[9];

    for (int i=0; i<nStep; i++)
    {
        //Sigma[i] = a+b/sqrt(Energy[i]);
        Sigma[i] = 0.0001;
    }

    for (int i = 0; i < nStep; i++)
    {
        for (int j = 0; j < nStep; j++)
        {

            P1[i][j] = (delta*Counts[j] / (sqrt(2 * PI * Sigma[i]))) *
                       exp(-1*(((Energy[i] - Energy[j]) * (Energy[i] - Energy[j])) /
                               (2 * Sigma[i])));

        }

    }

    double sum1 = 0;

    for (int i = 0; i < nStep; i++)
    {
        for (int j = 0; j < nStep; j++)
        {
            sum1 += P1[i][j];
        }

        NormCounts_1[i] = sum1;
        sum1 = 0;

    }

    double sum2 =0;

    for (int i=0; i<nStep; i++)
    {
        sum2+=delta*Counts[i];
    }

    double sum3 =0;

    for (int i=0; i<nStep; i++)
    {
        sum3+=delta*NormCounts_1[i];
    }

    for (int i=0; i<nStep; i++)
    {
        NormCounts[i]=(sum2/sum3)*NormCounts_1[i];
    }



        fstream fout3 ("/mnt/hgfs/VMplayer/Test2/DetectorNorm.txt", ios::out);


        for (int i = 0; i < nStep; i++) {

        fout3 << Energy[i] << '\t'<< NormCounts[i] << '\n';

        }
        fout3.close();


    for (int i = 0; i < nStep; i++) { delete[] P1[i]; }

    delete [] Energy;
    delete [] Counts;
    delete [] NormCounts;
    delete [] NormCounts_1;
    delete [] Sigma;


}

void RunAct::AddEvent1(G4double energy1)
{
    auto it1 = result1->lower_bound(energy1);
    it1->second++;
}

void RunAct::AddEvent2(G4double energy2)
{
    auto it2 = result2->lower_bound(energy2);
    it2->second++;
}




