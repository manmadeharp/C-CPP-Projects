# Basics:
###A declaration is a statement that introduces a name into the program. It specifies a type for the named entity:
- A type defines a set of possible values and a set of operations (for an object).
- An object is some memory that holds a value of some type.
- A value is a set of bits interpreted according to a type.
- A variable is a named object.

### Initialization
double d1 = 2.3;
double d2 {2.3};

complex<double> z = 1;           // a complex number with double-precision floating-point scalars
complex<double> z2 {d1,d2};
complex<double> z3 = {1,2};      // the = is optional with { ... }

vector<int> v {1,2,3,4,5,6};     // a vector of ints

