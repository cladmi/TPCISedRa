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

/**
 * Created by dparsons on 13/08/15.
 */
public class Alphabet {
    public static boolean IsVowel(char c) {
        c = Character.toLowerCase(c);
        if (c == 'a')
            return true;
        if (c == 'e')
            return true;
        if (c == 'i')
            return true;
        if (c == 'o')
            return true;
        if (c == 'u')
            return true;
        if (c == 'y')
            return true;
        return false;
    }

    public static boolean IsConsonant(char c) {
        c = Character.toLowerCase(c);
        if (c < 'a')
            return false;
        if (c > 'z')
            return false;
        return (!IsVowel(c));
    }

    public static int CountVowels(String s) {
        int nbVowels = 0;
        for (char c : s.toCharArray())
            if (IsVowel(c))
                nbVowels++;
        return nbVowels;
    }

    public static int CountConsonants(String s) {
        int nbConsonants = 0;
        for (char c : s.toCharArray())
            if (IsConsonant(c))
                nbConsonants++;
        return nbConsonants;
    }
}
