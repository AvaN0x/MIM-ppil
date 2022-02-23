package org.avanox.visitor;

import javax.swing.JFrame;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;
import java.util.ArrayList;
import java.util.logging.Logger;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import org.avanox.Shapes.*;

public class DrawSwing extends Draw {
    private JFrame frame;
    private BufferStrategy strategie;
    private Graphics graphics;
    private static final Logger LOGGER = Logger.getLogger("Serveur");

    public DrawSwing(int x, int y) {
        this.frame = new JFrame("Frame toute simple");
        this.frame.setBounds(0, 0, x, y);
        this.frame.setVisible(true);
        this.frame.createBufferStrategy(2);
        try {
            Thread.sleep(150);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Close the window
        this.frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent event) {
                frame.dispose();
                strategie.dispose();
                graphics.dispose();
            }
        });

        this.strategie = this.frame.getBufferStrategy();
        this.graphics = this.strategie.getDrawGraphics();

        LOGGER.info("La fenetre swing a ete initialisee");
    }

    @Override
    public void visit(Triangle triangle) {
        int[] xPoints = {
                triangle.getA().getX(),
                triangle.getB().getX(),
                triangle.getC().getX()
        };
        int[] yPoints = {
                triangle.getA().getY(),
                triangle.getB().getY(),
                triangle.getC().getY()
        };

        graphics.drawPolygon(xPoints, yPoints, 3);

        strategie.show();
    }

    @Override
    public void visit(Circle circle) {
        graphics.drawOval(
                circle.getCenter().getX(),
                circle.getCenter().getY(),
                circle.getRadius(),
                circle.getRadius());

        strategie.show();
    }

    @Override
    public void visit(Segment segment) {
        graphics.drawLine(
                segment.getA().getX(),
                segment.getA().getY(),
                segment.getB().getX(),
                segment.getB().getY());

        strategie.show();
    }

    @Override
    public void visit(AnyPolygon other) {
        ArrayList<Integer> xPoints = new ArrayList<Integer>();
        ArrayList<Integer> yPoints = new ArrayList<Integer>();
        for (Point point : other.getSegments()) {
            xPoints.add(point.getX());
            yPoints.add(point.getY());
        }
        graphics.drawPolygon(
                xPoints.stream().mapToInt(i -> i).toArray(),
                yPoints.stream().mapToInt(i -> i).toArray(),
                xPoints.size());

        strategie.show();
    }

    @Override
    public void closeDraw() {
        frame.dispose();
        strategie.dispose();
        graphics.dispose();
    }
}
