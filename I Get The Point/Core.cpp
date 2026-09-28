#include <iostream>
#include <string>

using namespace std;

class Point
{
	double pnt[2];
	string point;

	public:friend istream& operator>> (istream& in, Point& newPoint);

	public:Point(double first, double second)
	{
		pnt[0] = first;
		pnt[1] = second;
	
		point = "(";
		point += to_string(pnt[0]);
		point += ",";
		point += to_string(pnt[1]);
		point += ")";
	}

	public:Point()
	{
		pnt[0] = 0;
		pnt[1] = 0;

		point = "(";
		point += to_string(pnt[0]);
		point += ",";
		point += to_string(pnt[1]);
		point += ")";
	}

	double getX()
	{
		return pnt[0];
	}

	double getY()
	{
		return pnt[1];
	}

	public:string getPoint()
	{
		return point;
	}

	public:void pointFormat()
	{
		point = "(";
		point += to_string(pnt[0]);
		point += ",";
		point += to_string(pnt[1]);
		point += ")";
	}

	Point operator- (Point other)
	  {
		double D;
		double a = (pnt[0] - other.pnt[0]) * (pnt[0] - other.pnt[0]);
		double b = (pnt[1] - other.pnt[1]) * (pnt[1] - other.pnt[1]);
		double c = a + b;
		D = sqrt(c);
		cout << "The Distance between the two points is: " << D << "units." << endl;
		return *this;
	}

	bool operator== (const Point& other) const
	{
		return (pnt[0] == pnt[0]) && (pnt[1] == pnt[1]);
	}

	bool operator!= (Point other)
	{
		return (pnt[0] != pnt[0]) || (pnt[1] != pnt[1]);
	}

	Point operator/ (Point other)
	{
		Point mPnt;
		double a = (pnt[0] + other.pnt[0]) / 2;
		double b = (pnt[1] + other.pnt[1]) / 2;
		cout << "The Midpoint of the two points is: (" << a << "," << b << ")." << endl;
		return mPnt = Point(a,b);
	}

	Point& operator++ ()
	{
		pnt[0]++;
		pointFormat();
		return *this;
	}
	
	Point& operator++ (int)
	{
		pnt[1]++;
		pointFormat();
		return *this;
	}

	Point& operator-- ()
	{
		pnt[0]--;
		pointFormat();
		return *this;
	}

	Point& operator-- (int)
	{
		pnt[1]--;
		pointFormat();
		return *this;
	}
};

ostream& operator<< (ostream& out, Point other)
{
	out << other.getPoint();
	return out;
}

istream& operator>> (istream& in, Point& newPoint)
{
	char openParen;
	char comma;
	char closeParen;

	in >> openParen
		>> newPoint.pnt[0]
		>> comma
		>> newPoint.pnt[1]
		>> closeParen;
	newPoint.pointFormat();

	if (openParen != '(' || comma != ',' || closeParen != ')')
		in.setstate(ios::failbit);

	return in;
}

int main()
{
	//Setup for Operator Tests, allows variance by user input
	string input;
	cout << "Creating Point to Test..." << endl;
	cout << "Enter the first Integer or Decimal." << endl;
	double first;
	cin >> input;
	first = stod(input);
	input = "";
	cout << "Enter the second Integer or Decimal. " << endl;
	double second;
	cin >> input;
	second = stod(input);
	Point tester = Point(first,second);
	cout << "Test Point's Format: " << tester.getPoint() << endl;
	cout << "Point Object created Successfully!" << endl;

	cout << "Creating Reference Point for relevant future Operator Tests..." << endl;
	Point ref = Point(10, 10);
	cout << "Reference Point's Format: " << ref.getPoint() << endl;

	//Operator Tests in order written

	cout << "\nTesting [-] Operator" << endl;
	cout << (tester - ref) << endl;
	cout << "[-] Operator Test Complete." << endl;

	cout << "\nTesting [==] Operator" << endl;
	cout << (tester == ref) << endl;
	cout << "[==] Operator Test Complete." << endl;

	cout << "\nTesting [!=] Operator" << endl;
	cout << (tester != ref) << endl;
	cout << "[!=] Operator Test Complete." << endl;

	cout << "\nTesting [/] Operator" << endl;
	cout << (tester / ref) << endl;
	cout << "[/] Operator Test Complete." << endl;

	cout << "\nTesting [++ (prefix)] Operator" << endl;
	cout << (++tester) << endl;
	cout << "Trial Point format after Test: " << tester.getPoint() << endl;
	cout << "[++ (prefix)] Operator Test Complete." << endl;
	
	cout << "\nTesting [++ (postfix)] Operator" << endl;
	cout << (tester++) << endl;
	cout << "Trial Point format after Test: " << tester.getPoint() << endl;
	cout << "[-] Operator Test Complete." << endl;

	cout << "\nTesting [-- (prefix)] Operator" << endl;
	cout << (--tester) << endl;
	cout << "Trial Point format after Test: " << tester.getPoint() << endl;
	cout << "[-- (prefix)] Operator Test Complete." << endl;

	cout << "\nTesting [-- (postfix)] Operator" << endl;
	cout << (tester--) << endl;
	cout << "Trial Point format after Test: " << tester.getPoint() << endl;
	cout << "[-- (postfix)] Operator Test Complete." << endl;

	cout << "\nTesting [<<] Operator" << endl;
	cout << "Streaming Trial Point to Output: " << tester << endl;
	cout << "[<<] Operator Test Complete." << endl;

	cout << "\nTesting [>>] Operator" << endl;
	cout << "Input a Point in Proper Format: ";
	Point final;
	cin >> final;
	cout << "The Point entered was: " << final.getPoint() << endl;
	cout << "[>>] Operator Test Complete." << endl;
}