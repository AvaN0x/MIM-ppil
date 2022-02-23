package org.avanox.visitor;

import org.avanox.Shapes.*;

import java.awt.Insets;

import java.util.ArrayList;
import java.util.logging.Logger;

import java.awt.image.BufferStrategy;
import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.Graphics;

public class DrawAWT extends Draw {
    private Frame frame;
    private BufferStrategy strategie;
    private Graphics graphics;
    private static final Logger LOGGER = Logger.getLogger("Serveur");

    public DrawAWT(int x, int y) {
        this.frame = new Frame("Frame toute simple"); // TODO edit frame name
        this.frame.setBounds(0, 0, x + 16, y + 39);
        this.frame.setVisible(true);
        this.frame.setResizable(false);
        this.frame.createBufferStrategy(2);
        try {
            Thread.sleep(150);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        this.frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent event) {
                frame.dispose();
                strategie.dispose();
                graphics.dispose();
            }
        });

        this.strategie = this.frame.getBufferStrategy();
        this.graphics = this.strategie.getDrawGraphics();

        LOGGER.info("La fenetre awt a ete initialisee");
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
        graphics.setColor(triangle.getColor());
        graphics.fillPolygon(xPoints, yPoints, 3);

        strategie.show();
    }

    @Override
    public void visit(Circle circle) {
        Insets insets = frame.getInsets();
        graphics.setColor(circle.getColor());

        graphics.fillOval(
                insets.left + circle.getCenter().getX() - circle.getRadius(),
                insets.top + circle.getCenter().getY() - circle.getRadius(),
                circle.getRadius() * 2,
                circle.getRadius() * 2);

        strategie.show();
    }

    @Override
    public void visit(Segment segment) {
        graphics.setColor(segment.getColor());
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
        graphics.setColor(other.getColor());
        graphics.fillPolygon(
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
