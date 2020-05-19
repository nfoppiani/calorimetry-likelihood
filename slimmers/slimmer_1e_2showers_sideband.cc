#include "Riostream.h"
// #include "TString.h"
// #include "TFile.h"
// #include "TTree.h"
#include <map>
#include <iostream>
#include <cstdlib>

void slimmer_1e_2showers_sideband()
{
  // Get old file, old tree and set top branch address
  TString finname = "~/Desktop/MicroBooNE/bnb_nue_analysis/PELEE/0304/run1/nuepresel/data_bnb_peleeTuple_unblinded_uboone_v08_00_00_42_run1_C1_nuepresel.root";
  TString foutname = "~/Desktop/MicroBooNE/bnb_nue_analysis/PELEE/0304/run1/nuepresel/data_bnb_peleeTuple_unblinded_uboone_v08_00_00_42_run1_C1_nuepresel_1e_2showers_sideband_skimmed.root";
  TFile oldfile(finname);
  TTree *oldtree;
  oldfile.GetObject("searchingfornues/NeutrinoSelectionFilter", oldtree);

  int numevts = 0;

  const auto nentries = oldtree->GetEntries();

  // Deactivate all branches
  oldtree->SetBranchStatus("*", 1);

  int backtracked_pdg;

  int nslice;
  int selected;
  float shr_energy_tot_cali;
  uint n_showers_contained;

  oldtree->SetBranchAddress("nslice", &nslice);
  oldtree->SetBranchAddress("selected", &selected);
  oldtree->SetBranchAddress("shr_energy_tot_cali", &shr_energy_tot_cali);
  oldtree->SetBranchAddress("n_showers_contained", &n_showers_contained);


  // Create a new file + a clone of old tree in new file
  TFile newfile(foutname, "recreate");
  TDirectory *searchingfornues = newfile.mkdir("searchingfornues");
  searchingfornues->cd();

  auto newtree = oldtree->CloneTree(0);

  std::cout << "Start loop with entries " << nentries << std::endl;

  for (auto i : ROOT::TSeqI(nentries))
  {
    if (i % 10000 == 0)
    {
      std::cout << "Entry num  " << i << std::endl;
    }

    oldtree->GetEntry(i);

    bool preseq = (nslice == 1) &&
         (selected == 1) &&
         (shr_energy_tot_cali > 0.07);

    bool preseq_two_plus_shower = preseq && (n_showers_contained >=2);

    if (preseq_two_plus_shower)
    {
      newtree->Fill();
    }// if cuts pass
  }// for all entries
  newtree->Print();
  newfile.Write();
}