class triangle{
private:
	float length;
public:
	triangle::triangle(double l):length(l){};
	float area();
	float perimeter();
	void change(double a);
};