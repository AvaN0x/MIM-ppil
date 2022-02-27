package org.avanox.Shapes;

public class Point {
    protected int x;
    protected int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    /**
     * Return the x coordinate
     * 
     * @return the x coordinate
     */
    public int getX() {
        return x;
    }

    /**
     * Return the y coordinate
     * 
     * @return the y coordinate
     */
    public int getY() {
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
