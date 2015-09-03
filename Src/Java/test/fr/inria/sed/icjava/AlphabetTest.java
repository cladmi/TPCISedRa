package fr.inria.sed.icjava;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by dparsons on 13/08/15.
 */
public class AlphabetTest {
    @Test
    public void testIsVowel() throws Exception {
        char c = 'a';
        assertTrue(Alphabet.IsVowel(c));
    }

    @Test
    public void testCountVowels() throws Exception {
        String testStr = "Hello World!";
        assertEquals(3, Alphabet.CountVowels(testStr));
    }

    @Test
    public void testCountConsonants() throws Exception {
        String testStr = "Hello World!";
        assertEquals(7, Alphabet.CountConsonants(testStr));
    }
}

