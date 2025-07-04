#include "Fixed.hpp"
#include "Point.hpp"

static Fixed find_area(Point a, Point b, Point c)
{
    Fixed area = (a.get_x() * (b.get_y() - c.get_y()) +
                  b.get_x() * (c.get_y() - a.get_y()) +
                  c.get_x() * (a.get_y() - b.get_y())) / 2;
    if (area < Fixed(0))
        area = area * Fixed(-1);
    return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    //if point is a corner
    if ((point == a) || (point == b) || (point == c))
        return false;

    //if the point exists on a line of 
    if (find_area(a, b, point).toFloat() == 0 ||
        find_area(b, c, point).toFloat() == 0 ||
        find_area(c, a, point).toFloat() == 0)
        return false;
    
    //control if the corner points exist in a line
    if (find_area(a, b, c).toFloat() == 0)
        return false;
    
    float triangle_area = find_area(a, b, c).toFloat();
    
    float predicted_area =  find_area(a, b, point).toFloat() + 
                            find_area(b, c, point).toFloat() +
                            find_area(c, a, point).toFloat() ;
    
    if (triangle_area == predicted_area)
        return 1;
    else
        return 0;
}