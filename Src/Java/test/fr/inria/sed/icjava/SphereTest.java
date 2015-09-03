package fr.inria.sed.icjava;

import org.junit.Test;

import javax.vecmath.Point3d;

import static org.junit.Assert.*;

/**
 * Created by dparsons on 12/08/15.
 */
public class SphereTest {

    @Test
    public void testDefaultCtor() throws Exception {
        Sphere mySphere = new Sphere();
        Point3d point = new Point3d(0, 0, 0);
        assertEquals(0., mySphere.getRadius(), 0.0);
        assertEquals(point, mySphere.getPos());
    }

    @Test
    public void testCtor1() throws Exception {
        Sphere mySphere = new Sphere(1.5);
        assertEquals(1.5, mySphere.getRadius(), 0.0);
        Point3d point = new Point3d(0, 0, 0);
        assertEquals(point, mySphere.getPos());
    }

    @Test
    public void testCtor2() throws Exception {
        Sphere mySphere = new Sphere(1.5, new Point3d(1., 2., 3.5));
        assertEquals(1.5, mySphere.getRadius(), 0.0);
        Point3d point = new Point3d(1., 2., 3.5);
        assertEquals(point, mySphere.getPos());
    }

    @Test
    public void testComputeVolumeExact() throws Exception {
        Sphere mySphere = new Sphere(1.5);
        assertEquals(14.137166941154069, mySphere.ComputeVolume(), 0.0);
    }

    @Test
    public void testComputeVolume() throws Exception {
        Sphere mySphere = new Sphere(1.5);
        assertEquals(14.137166941154069, mySphere.ComputeVolume(), 1e-14);
    }

    @Test
    public void testComputeVolume0Radius() throws Exception {
        Sphere mySphere = new Sphere();
        assertEquals(0., mySphere.ComputeVolume(), 0.);
    }

    @Test
    public void testDistanceTo() throws Exception {
        Sphere mySphere1 = new Sphere(1.5, new Point3d(1.2, 3.45, 2.3));
        Sphere mySphere2 = new Sphere(1.7, new Point3d(0.1, 2.3, 4.5));
        assertEquals(2.7152347964770933, mySphere1.DistanceTo(mySphere2), 0.);
    }

    @Test
    public void testInContactWith() throws Exception {
        Sphere mySphere1 = new Sphere(1.7152347964770932, new Point3d(1.2, 3.45, 2.3));
        Sphere mySphere2 = new Sphere(1.0000000000000001, new Point3d(0.1, 2.3, 4.5));
        assertTrue(mySphere1.InContactWith(mySphere2));
        assertTrue(mySphere2.InContactWith(mySphere1));
    }
}