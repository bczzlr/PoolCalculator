class square{
private:
	float length;
public:
	square::square(double l):length(l){};
	float perimeter();
	float area();
	void change(double a);
};