/**
 * This file is a part of TPCI_SEDRA project
 * Copyright (c) INRIA 2015
 *
 * Contributor (s) : David Parsons
 * Contacts : david.parsons@inria.fr
 * 
 * This project is headed by SED Rhone-Alpes service at INRIA.
 *
 */
package fr.inria.sed.icjava;

public class Main {

    public static void main(String[] args) {
        Sphere mySphere = new Sphere(1.5);

        System.out.printf("%.20f\n", mySphere.ComputeVolume1());
        System.out.printf("%.20f\n", mySphere.ComputeVolume2());
    }
}
