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

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class AlphabetTest2 {
    @Test
    public void testCountVowels2() throws Exception {
        String testStr = "Hello Claudine and Yves";
        assertEquals(9, Alphabet.CountVowels(testStr));
    }

    @Test
    public void testCountConsonants2() throws Exception {
        String testStr = "ps -ef | grep test";
        assertEquals(9, Alphabet.CountConsonants(testStr));
    }
}
