// Bezier drawing support


// Find the midpoint
inline POINT midpoint (POINT a, POINT b)
{
	POINT res;

	res.x = int ((float(a.x + b.x) / 2.0) + 0.5);
	res.y = int ((float (a.y + b.y) / 2.0) + 0.5);

	return res;
}

// Compare two points.
inline int operator == (POINT p1, POINT p2)
{
	return abs (p1.x - p2.x) <= 1 && abs (p1.y - p2.y) <= 1;
}


// This is a class used to simulate function closures for the
// draw_bezier function.  A BezierAction to draw the curve
// is provided below.  One to plot the points in color
// space is possible as well.
// (Think of this as a function pointer from which you can derive
//  a new function context)
struct BezierClosure
{
virtual void operator () (int x, int y) = 0;
};

// The API call for beziers.  What it does is call
// the closure with every point along the bezier curve
// described by the parameter points.
void bezier (BezierClosure &func, POINT pts[4]);


// eof - bezier.h
