//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file B4/B4d/include/EventAction.hh
/// \brief Definition of the B4d::EventAction class

#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"

#include "G4THitsMap.hh"
#include "globals.hh"

namespace B4d
{

  /// Event action class
  ///
  /// In EndOfEventAction(), it prints the accumulated quantities of the energy
  /// deposit and track lengths of charged particles in Absober and Gap layers
  /// stored in the hits collections.

  class EventAction : public G4UserEventAction
  {
  public:
    EventAction() = default;
    ~EventAction() override = default;

    void BeginOfEventAction(const G4Event *event) override;
    void EndOfEventAction(const G4Event *event) override;

  private:
    // methods
    G4THitsMap<G4double> *GetHitsCollection(G4int hcID,
                                            const G4Event *event) const;
    G4double GetSum(G4THitsMap<G4double> *hitsMap) const;
    void PrintEventStatistics(G4double absoEdep, G4double absoTrackLength) const;

    // data members
    G4int fAbsoEdepHCID = -1;
    // G4int fGapEdepHCID = -1;
    G4int fAbsoTrackLengthHCID = -1;
    // G4int fGapTrackLengthHCID = -1;
  };

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
