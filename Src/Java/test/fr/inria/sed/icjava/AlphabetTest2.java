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
