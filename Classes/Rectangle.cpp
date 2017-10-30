#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "Rectangle.h"


Rectangle::Rectangle():Forme()//default
{
	cout << "Default constuctor Rectangle" << endl;
	
	id = NULL;
	setDimX(1);
	setDimY(1);
	setRempli(false);
}

Rectangle::Rectangle(const char * ID, const Point &objPoint,int xDim, int yDim, bool filled, const Couleur * objCouleur, const int depth):Forme(objPoint, objCouleur, depth)//initialisation)
{
	cout << "Initialisation constuctor Rectangle" << endl;
	
	id = NULL;
	setId(ID);
	setDimX(xDim);
	setDimY(yDim);
	setRempli(filled);
}

Rectangle::Rectangle(const Rectangle &obj):Forme(obj)//copy
{
	cout << "Copy constuctor Rectangle" << endl;
	
	id = NULL;
	setId(obj.getId());
	setDimX(obj.getDimX());
	setDimY(obj.getDimY());
	setRempli(obj.isRempli());
}

int Rectangle::getDimX() const
{
	return dimX;
}

void Rectangle::setDimX(int dim)
{
	if(dim > 0)
		dimX = dim;
}

int Rectangle::getDimY() const
{
	return dimY;
}

void Rectangle::setDimY(int dim)
{
	if(dim > 0)
		dimY = dim;
}

bool Rectangle::isRempli() const
{
	return rempli;
}

void Rectangle::setRempli(bool filled)
{
	rempli = filled;
}

const char * Rectangle::getInfos()
{
	char chaine[200];

	
	if(getCouleur())
	{
		if(couleur->getNom())
		{
			sprintf(chaine, "[Rectangle : id(%s), Position(%d, %d), dimX(%d), dimY(%d), Rempli(%d), Couleur(%d, %d, %d, %s), Profondeur(%d)]",getId(), getPosition().getX(), getPosition().getY(), getDimX(), getDimY(), isRempli(), getCouleur()->getRouge(),getCouleur()->getVert(),getCouleur()->getBleu(),getCouleur()->getNom(), getProfondeur());
		}
		else
			sprintf(chaine, "[Rectangle : id(%s), Position(%d, %d), dimX(%d), dimY(%d), Rempli(%d), Couleur(%d, %d, %d), Profondeur(%d)]",getId(), getPosition().getX(), getPosition().getY(), getDimX(), getDimY(), isRempli(), getCouleur()->getRouge(),getCouleur()->getVert(),getCouleur()->getBleu(), getProfondeur());
	}
	else
		sprintf(chaine, "[Rectangle : id(%s), Position(%d, %d), dimX(%d), dimY(%d), Rempli(%d), Profondeur(%d)]",getId(), getPosition().getX(), getPosition().getY(), getDimX(), getDimY(), isRempli(), getCouleur()->getRouge(),getCouleur()->getVert(),getCouleur()->getBleu(), getProfondeur());
	
	if(infos)
		delete infos;
	
	infos = new char[strlen(chaine)];		
	
	return infos;
	
}

ostream& operator<< (ostream &os, const Rectangle &obj)
{
	if(obj.getId())
		os << "id : " << obj.getId() << endl;
		
	os << "Position : " << obj.position << endl;
	os << "dimX : " << obj.getDimX() << "   dimY : " << obj.getDimY() << "   Rempli : " << obj.isRempli() << endl;
	
	if(obj.getCouleur())
		os << "Couleur : " << *(obj.getCouleur()) << endl;
		
	os << "Profondeur : " << obj.getProfondeur() << endl;
	
	return os;
}

void Rectangle::setId(const char * ID)
{
	if(ID[0] != 'R' || !isdigit(ID[1]) || !isdigit(ID[2]) || ID[3] != '\0')
		throw BaseException();

	if(id)
		delete id;
	
	id = new  char[strlen(ID) + 1];
	strcpy(id, ID);
}



Rectangle::~Rectangle()
{
	
}
