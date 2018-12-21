

#include "DetGeometry.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4Color.hh"
#include "G4RotationMatrix.hh"
#include "G4Sphere.hh"
#include "G4SubtractionSolid.hh"

DetGeometry::DetGeometry() {

}

DetGeometry::~DetGeometry() {}

G4VPhysicalVolume* DetGeometry::Construct(){

    G4NistManager* nist = G4NistManager::Instance();

    G4double size = 5*m;

    G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");

    G4Box* solidWorld =
      new G4Box("World",
         0.5*size, 0.5*size, 0.5*size);

    G4LogicalVolume* logicWorld =
      new G4LogicalVolume(solidWorld,
                          world_mat,
                          "World");

logicWorld->SetVisAttributes(G4VisAttributes::Invisible);

 G4VPhysicalVolume* physWorld =
      new G4PVPlacement(0,
                        G4ThreeVector(),
                        logicWorld,
                        "World",
                        0,
                        false,
                        0);


//create an SPHERE container

//    G4Material*sc_mat = nist->FindOrBuildMaterial("G4_Fe");
//
//    G4double size_of_sc = 1*cm;
//
//    G4ThreeVector sc_pos = G4ThreeVector(0*cm, 0*cm, 0*cm);
//
//    G4Sphere*spcont = new G4Sphere("SpCont", 100*size_of_sc, 113*size_of_sc, 0.*deg, 360.*deg, 0.*deg, 180.*deg);
//
//    G4RotationMatrix* myRotation = new G4RotationMatrix();
//    myRotation->rotateX(0.*deg);
//    myRotation->rotateY(0.*deg);
//    myRotation->rotateZ(0.*rad);
//
//    G4LogicalVolume*logicSpCont = new G4LogicalVolume(spcont, sc_mat, "SpCont");
//
//    G4VisAttributes*logicSpContcolour = new G4VisAttributes(G4Colour(0.0, 1.0, 1.0));
//
//    logicSpCont->SetVisAttributes(logicSpContcolour);
//
//
//    new G4PVPlacement(myRotation,
//                      sc_pos,
//                      logicSpCont,
//                      "SpCont",
//                      logicWorld,
//                      false,
//                      0);


   // create an complex BOX container

//    G4double box_size = 1*cm;
//
//    G4Material*sub_mat1 = nist->FindOrBuildMaterial("G4_Fe");
//
//    G4ThreeVector sub1_pos = G4ThreeVector(0*cm, 0*cm, 0*cm);
//
//    G4Box*box0 = new G4Box("Box0", 100*box_size, 100*box_size, 100*box_size);
//
//    G4Box*box1 = new G4Box("Box1", 103*box_size, 103*box_size, 103*box_size);
//
//    G4SubtractionSolid*Sub1 = new G4SubtractionSolid ("Sub1", box1, box0);
//    G4LogicalVolume*logicSub1 = new G4LogicalVolume(Sub1, sub_mat1, "Sub1");
//    G4VisAttributes*logicSub1colour = new G4VisAttributes(G4Colour(0.0, 1.0, 1.0));
//    logicSub1->SetVisAttributes(logicSub1colour);
//
//
//    new G4PVPlacement(0,
//                      sub1_pos,
//                      logicSub1,
//                      "Sub1",
//                      logicWorld,
//                      false,
//                      0);
//
//    G4Material*sub_mat2 = nist->FindOrBuildMaterial("G4_CONCRETE");
//
//    G4ThreeVector sub2_pos = G4ThreeVector(0*cm, 0*cm, 0*cm);
//
//    G4Box*box3 = new G4Box("Box3", 104*box_size, 104*box_size, 104*box_size);
//
//    G4Box*box4 = new G4Box("Box4", 109*box_size, 109*box_size, 109*box_size);
//
//    G4SubtractionSolid*Sub2 = new G4SubtractionSolid ("Sub2", box4, box3);
//    G4LogicalVolume*logicSub2 = new G4LogicalVolume(Sub2, sub_mat2, "Sub2");
//    G4VisAttributes*logicSub2colour = new G4VisAttributes(G4Colour(133.0, 133.0, 133.0));
//    logicSub2->SetVisAttributes(logicSub2colour);
//
//
//    new G4PVPlacement(0,
//                      sub2_pos,
//                      logicSub2,
//                      "Sub2",
//                      logicWorld,
//                      false,
//                      0);
//
//    G4Material*sub_mat3 = nist->FindOrBuildMaterial("G4_Fe");
//
//    G4ThreeVector sub3_pos = G4ThreeVector(0*cm, 0*cm, 0*cm);
//
//    G4Box*box5 = new G4Box("Box5", 110*box_size, 110*box_size, 110*box_size);
//
//    G4Box*box6 = new G4Box("Box6", 113*box_size, 113*box_size, 113*box_size);
//
//    G4SubtractionSolid*Sub3 = new G4SubtractionSolid ("Sub3", box6, box5);
//    G4LogicalVolume*logicSub3 = new G4LogicalVolume(Sub3, sub_mat3, "Sub3");
//    G4VisAttributes*logicSub3colour = new G4VisAttributes(G4Colour(0.0, 1.0, 1.0));
//    logicSub3->SetVisAttributes(logicSub3colour);
//
//
//    new G4PVPlacement(0,
//                      sub3_pos,
//                      logicSub3,
//                      "Sub3",
//                      logicWorld,
//                      false,
//                      0);






    // create an SOURSE

    G4Material*InSp_det_mat = nist->FindOrBuildMaterial("G4_Galactic");

    G4double size_of_sourse = 1*cm;

    G4ThreeVector InSp_det_pos = G4ThreeVector(0*cm, 0*cm, 0*cm);

    G4Box*InSp_det = new G4Box("Source", 0.05*size_of_sourse, 0.05*size_of_sourse, 0.05*size_of_sourse);

    G4LogicalVolume*logicInSpDet = new G4LogicalVolume(InSp_det, InSp_det_mat, "Source");

    G4VisAttributes*logicSpDet = new G4VisAttributes(G4Colour(1.0, 0.0, 0.0));

    logicInSpDet->SetVisAttributes(logicSpDet);


    new G4PVPlacement(0,
                      InSp_det_pos,
                      logicInSpDet,
                      "Source",
                      logicWorld,
                      false,
                      0);

    // create an OUTER SPHERE detector

//    G4Material*OuSp_det_mat = nist->FindOrBuildMaterial("G4_Galactic");
//
//    G4double OuSp_size_of_det = 1*cm;
//
//    G4ThreeVector OuSp_det_pos = G4ThreeVector(0*cm, 0*cm, 0*cm);
//
//    G4Sphere*OuSp_det = new G4Sphere("OuSpDetector", 30*OuSp_size_of_det, 30.1*OuSp_size_of_det, 0.*deg, 23.*deg, 0.*deg, 180.*deg);
//
//    G4LogicalVolume*logicOuSpDet = new G4LogicalVolume(OuSp_det, OuSp_det_mat, "OuSpDetector");
//
//    G4VisAttributes*logicOutSpDet = new G4VisAttributes(G4Colour(1.0, 0.0, 0.0));
//
//    logicOuSpDet->SetVisAttributes(logicOutSpDet);
//
//
//    new G4PVPlacement(0,
//                      OuSp_det_pos,
//                      logicOuSpDet,
//                      "OuSpDetector",
//                      logicWorld,
//                      false,
//                      0);

   //// create an BOX detector

//    G4Material*OuSp_det_mat = nist->FindOrBuildMaterial("G4_Galactic");
//
//    G4double OuSp_size_of_det = 1*cm;
//
//    G4ThreeVector OuSp_det_pos = G4ThreeVector(0*cm, 0*cm, -1.65*cm);
//
//    G4Box*OuSp_det = new G4Box("OuSpDetector", 0.5*OuSp_size_of_det, 0.5*OuSp_size_of_det, 0.05*OuSp_size_of_det);
//
//    G4LogicalVolume*logicOuSpDet = new G4LogicalVolume(OuSp_det, OuSp_det_mat, "OuSpDetector");
//
//    G4VisAttributes*logicOutSpDet = new G4VisAttributes(G4Colour(1.0, 0.0, 0.0));
//
//    logicOuSpDet->SetVisAttributes(logicOutSpDet);
//
//
//    new G4PVPlacement(0,
//                      OuSp_det_pos,
//                      logicOuSpDet,
//                      "OuSpDetector",
//                      logicWorld,
//                      false,
//                      0);

    G4String name, symbol;
    G4double a, z, det_density;
    G4int ncomponents;
    G4int natoms;
    a = 80.9058*g/mole;
    G4Element*elY = new G4Element(name="Yttrium", symbol="Y", z = 39., a);
    a = 26.9816*g/mole;
    G4Element*elAl = new G4Element(name="Aluminium", symbol="Al", z = 13., a);
    a = 16*g/mole;
    G4Element*elO = new G4Element(name="Oxygen", symbol="O", z = 8., a);
    det_density = 5.37*g/cm3;
    G4Material*det_mat2 = new G4Material(name="Gen Wall", det_density, ncomponents = 3);
    det_mat2->AddElement(elY, natoms = 1);
    det_mat2->AddElement(elAl, natoms = 1);
    det_mat2->AddElement(elO, natoms = 3);

    G4Element *Y = nist->FindOrBuildElement("Y");
    G4Element *Al = nist->FindOrBuildElement("Al");
    G4Element *O = nist->FindOrBuildElement("O");
    G4Material *YAP = new G4Material("YAP", 5.37*g/cm3,3, kStateSolid);
    YAP->AddElement(Y,1);
    YAP->AddElement(Al,1);
    YAP->AddElement(O,3);



//    create an CYLLINDER detector

    G4Material*det_mat = nist->FindOrBuildMaterial("G4_STILBENE");

    G4ThreeVector det_pos = G4ThreeVector(0*cm, 0*cm, -6.715*cm);

    G4Tubs*det = new G4Tubs("Detector", 0.0*cm, 2.525*cm, 1.565*cm,  0*deg, 360*deg);

    G4LogicalVolume*logicDet = new G4LogicalVolume(det, YAP, "Detector");

    G4VisAttributes*logicVisDet = new G4VisAttributes(G4Colour(1.0, 0.0, 0.0));

    logicDet->SetVisAttributes(logicVisDet);


    new G4PVPlacement(0,
                      det_pos,
                      logicDet,
                      "Detector",
                      logicWorld,
                      false,
                      0);

    //    create an CYLLINDER conteiner

    G4Material*cont_wall = nist->FindOrBuildMaterial("G4_Al");

    G4ThreeVector cont_wall_pos = G4ThreeVector(0*cm, 0*cm, -6.715*cm);

    G4Tubs*wall = new G4Tubs("ContWall", 2.730*cm, 2.880*cm, 1.565*cm,  0*deg, 360*deg);

    G4LogicalVolume*logicWall = new G4LogicalVolume(wall, cont_wall, "ContWall");

    G4VisAttributes*logicWallCol = new G4VisAttributes(G4Colour(0.0, 1.0, 1.0));

    logicWall->SetVisAttributes(logicWallCol);


    new G4PVPlacement(0,
                      cont_wall_pos,
                      logicWall,
                      "ContWall",
                      logicWorld,
                      false,
                      0);

    G4Material*cont_roof = nist->FindOrBuildMaterial("G4_Al");

    G4ThreeVector cont_roof_pos = G4ThreeVector(0*cm, 0*cm, -5.0*cm);

    G4Tubs*roof = new G4Tubs("ContRoof", 0*cm, 2.880*cm, 0.15*cm,  0*deg, 360*deg);

    G4LogicalVolume*logicRoof = new G4LogicalVolume(roof, cont_roof, "ContRoof");

    G4VisAttributes*logicRoofCol = new G4VisAttributes(G4Colour(0.0, 1.0, 1.0));

    logicRoof->SetVisAttributes(logicRoofCol);


    new G4PVPlacement(0,
                      cont_roof_pos,
                      logicRoof,
                      "ContRoof",
                      logicWorld,
                      false,
                      0);



    return physWorld;
}


