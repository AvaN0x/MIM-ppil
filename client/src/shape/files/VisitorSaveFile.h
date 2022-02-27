#pragma once
#include <string>

namespace shape
{
    class Shape;
    class Circle;
    class Polygon;
    class Segment;
    class Triangle;
    class ComposedShape;
};

class VisitorSaveFile
{
public:
    /**
     * @brief Load a shape from a file
     *
     * @param filePath The path of the file
     * @return shape::Shape* The shape or nullptr if an error occured
     */
    virtual shape::Shape *loadFile(const std::string &filePath) = 0;

    /**
     * @brief Save a Circle to a file
     *
     * @param s The Circle to save
     * @param filePath The path of the file
     */
    virtual void visit(const shape::Circle *s, const std::string &filePath) const = 0;
    /**
     * @brief Save a Polygon to a file
     *
     * @param s The Polygon to save
     * @param filePath The path of the file
     */
    virtual void visit(const shape::Polygon *s, const std::string &filePath) const = 0;
    /**
     * @brief Save a shape to a file
     *
     * @param s The shape to save
     * @param filePath The path of the file
     */
    virtual void visit(const shape::Segment *s, const std::string &filePath) const = 0;
    /**
     * @brief Save a Triangle to a file
     *
     * @param s The Triangle to save
     * @param filePath The path of the file
     */
    virtual void visit(const shape::Triangle *s, const std::string &filePath) const = 0;
    /**
     * @brief Save a ComposedShape to a file
     *
     * @param s The ComposedShape to save
     * @param filePath The path of the file
     */
    virtual void visit(const shape::ComposedShape *s, const std::string &filePath) const = 0;
};
