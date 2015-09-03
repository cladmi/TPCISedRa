package fr.inria.sed.icjava;

public class Main {

    public static void main(String[] args) {
        Sphere mySphere = new Sphere(1.5);

        System.out.printf("%.20f\n", mySphere.ComputeVolume1());
        System.out.printf("%.20f\n", mySphere.ComputeVolume2());
    }
}
