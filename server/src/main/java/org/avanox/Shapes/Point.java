package org.avanox.Shapes;

public class Point {
    protected double x;
    protected double y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    @Override
    public boolean equals(Object obj) {
        if (this.getClass() != obj.getClass())
            return false;
        if (this.x != ((Point) obj).x)
            return false;
        if (this.y != ((Point) obj).y)
            return false;

        return true;
    }
}
