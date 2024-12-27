//
// Created by yuancunkuan on 2024/12/26.
//
#include <iostream>
#include <string>

class ObjectA {
public:
	ObjectA() {
		std::cout << "ObjectA is being constructed" << std::endl;
	}
	virtual ~ObjectA() {
		std::cout << "ObjectA is being destroyed!" << std::endl; 
	}

	virtual const std::string getName() = 0;
};

class RealObjectAC : public ObjectA {
public:
	RealObjectAC() {
		std::cout << "RealObjectAC is being constructed!" << std::endl;
	}

	~RealObjectAC() {
		std::cout << "RealObjectAC is being destroyed!" << std::endl;
	}
	const std::string getName() {
		return "AC";
	}
};

class RealObjectAN : public ObjectA {
public:
	RealObjectAN() {
		std::cout << "RealObjectAN is being constructed!" << std::endl;
	}
	~RealObjectAN() {
		std::cout << "RealObjectAN is being destroyed!" << std::endl;
	}
	const std::string getName() {
		return "AN";
	}
};

class ObjectB {
public:
	ObjectB() {
		std::cout << "ObjectB is being constructed!" << std::endl;
	}
	virtual ~ObjectB() {
		std::cout << "ObjectB is being destroyed!" << std::endl;
	}
	virtual const std::string getName() = 0;
};

class RealObjectBC : public ObjectB {
public:
	RealObjectBC() {
		std::cout << "RealObjectBC is being constructed!" << std::endl;
	}
	virtual ~RealObjectBC() {
		std::cout << "RealObjectBC is being destroyed!" << std::endl;
	}

	const std::string getName() {
		return "BC";
	}
};

class RealObjectBN : public ObjectB {
public:
	RealObjectBN() {
		std::cout << "RealObjectBN is being constructed!" << std::endl;
	}
	~RealObjectBN() {
		std::cout << "RealObjectBN is being destroyed!" << std::endl;
	}
	const std::string getName() {
		return "BN";
	}
};

class AbstractFactory {
public:
	AbstractFactory() {
		std::cout << "Create AbstractFactory!" << std::endl;
	}
	virtual ~AbstractFactory() {
		std::cout << "Destroy AbstractFactory!" << std::endl;
	}

	virtual ObjectA* createObjectA() = 0;
	virtual ObjectB* createObjectB() = 0;
};

class RealFactoryC : public AbstractFactory {
public:
	RealFactoryC() {
		std::cout << "Create RealFactoryC!" << std::endl;
	}
	~RealFactoryC() {
		std::cout << "Destroy RealFactoryC!" << std::endl;
	}
	ObjectA* createObjectA() {
		return new RealObjectAC();
	}
	ObjectB* createObjectB() {
		return new RealObjectBC();
	}
};

class RealFactoryN : public AbstractFactory {
public:
	RealFactoryN() {
		std::cout << "Create RealFactoryN!" << std::endl;
	}
	~RealFactoryN() {
		std::cout << "Destroy RealFactoryN!" << std::endl;
	}
	ObjectA* createObjectA() {
		return new RealObjectAN();
	}
	ObjectB* createObjectB() {
		return new RealObjectBN();
	}
};

int main() {
	RealFactoryC* factory_c = new RealFactoryC();
	RealFactoryN* factory_n = new RealFactoryN();

	ObjectA* obj1 = factory_c->createObjectA();
	std::cout << "Object: " << obj1->getName() << std::endl;

	ObjectA* obj2 = factory_n->createObjectA();
	std::cout << "Object: " << obj2->getName() << std::endl;

	ObjectB* obj3 = factory_c->createObjectB();
	std::cout << "Object: " << obj3->getName() << std::endl;

	ObjectB* obj4 = factory_n->createObjectB();
	std::cout << "Object: " << obj4->getName() << std::endl;

	delete obj1;
	delete obj2;

	delete obj3;
	delete obj4;

	delete factory_c;
	delete factory_n;

	return 0;
}