#include <vector.hpp>
#include <catch.hpp>

SCENARIO(" init", "[init]")
{
	vector_t vector;
	REQUIRE(vector.size() == 0);
	REQUIRE(vector.capacity() == 0);
}

SCENARIO(" init with param", "[init with param]")
{ 
	vector_t vector(3); 
	REQUIRE(vector.size() == 3); 
	REQUIRE(vector.capacity() == 3); 
} 
SCENARIO("vector init with object", "[init with object]")
{ 
	vector_t vector; 
	vector.push_back(5); 
	vector.push_back(6); 
	vector_t vector2(vector);
	REQUIRE(vector.size() == vector2.size());
	REQUIRE(vector.capacity() == vector2.capacity());
	REQUIRE(vector[0] == vector2[0]);
	REQUIRE(vector[1] == vector2[1]);
}
SCENARIO("=")
{ 
	vector_t vector, vector2(2); 
	vector.push_back(1); 
	vector.push_back(2);  
	REQUIRE(vector.size() == 2); 
	REQUIRE(vector.capacity() == 2); 
	vector2 = vector; 
	REQUIRE(vector2.size() == 2); 
	REQUIRE(vector2.capacity() == 2); 
	REQUIRE(vector2[0]==1);
	REQUIRE(vector2[1]==2);
} 
SCENARIO("push_back")
{
	vector_t vector(2);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	REQUIRE(vector.size() == 5);
	REQUIRE(vector.capacity() == 8);
	REQUIRE(vector[0] == 0);
	REQUIRE(vector[1] == 0);
	REQUIRE(vector[2] == 1);
	REQUIRE(vector[3] == 2);
	REQUIRE(vector[4] == 3);
}
SCENARIO("delete")
{
	vector_t vector(2);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	REQUIRE(vector.size() == 5);
	REQUIRE(vector.capacity() == 8);
	REQUIRE(vector.delval()==1);
	REQUIRE(vector.size() == 4);
	REQUIRE(vector.capacity() == 8);
	REQUIRE(vector.delval()==1);
	REQUIRE(vector.size() == 3);
	REQUIRE(vector.capacity() == 4);
	REQUIRE(vector.delval()==1);
	REQUIRE(vector.size() == 2);
	REQUIRE(vector.capacity() == 4);
	REQUIRE(vector.delval()==1);
	REQUIRE(vector.size() == 1);
	REQUIRE(vector.capacity() == 2);
	REQUIRE(vector.delval()==1);
	REQUIRE(vector.size() == 0);
	REQUIRE(vector.capacity() == 1);
	REQUIRE(vector.delval()==0);
}
