package fr.inria.sed.icjava;

/**
 * Created by dparsons on 12/08/15.
 */

import javax.vecmath.Point3d;

public class Sphere {
    // ***********************************************************************
    //                               Constructors
    // ***********************************************************************
    public Sphere() {
        radius_ = 0.;
        pos_ = new Point3d();
    }
    public Sphere(double radius) {
        radius_ = radius;
        pos_ = new Point3d();
    }
    public Sphere(double radius, Point3d pos) {
        radius_ = radius;
        pos_ = pos;
    }


    // ***********************************************************************
    //                                 Methods
    // ***********************************************************************
    public double ComputeVolume() {
        return ComputeVolume1();
    }
    public double ComputeVolume1() {
        return 4 * Math.PI * Math.pow(radius_, 3) / 3;
    }
    public double ComputeVolume2() {
        return FOUR_PI_THREE * Math.pow(radius_, 3);
    }
    public double DistanceTo(Sphere other) {
        return pos_.distance(other.pos_);
    }
    public double DistanceSquaredTo(Sphere other) {
        return pos_.distanceSquared(other.pos_);
    }
    public boolean InContactWith(Sphere other) {
        return DistanceSquaredTo(other) <= Math.pow(radius_ + other.radius_, 2);
    }

    // ***********************************************************************
    //                                Accessors
    // ***********************************************************************
    public Point3d getPos() {
        return pos_;
    }
    public double getRadius() {
        return radius_;
    }

    // ***********************************************************************
    //                               Attributes
    // ***********************************************************************
    protected double radius_ = 0.;
    protected Point3d pos_;


    static final double FOUR_PI_THREE = 4. * Math.PI / 3;
}
