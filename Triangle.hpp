#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Forme.hpp"

//#define Triangle MyTriangle

class Triangle : public Forme {
	private :
		uint height;
		uint width;
		void ecrire (ostream &os) const override;

	public :
		Triangle(ulong color, uint x, uint y, uint width, uint height);
		Triangle(istream &is);
		~Triangle();
		virtual void dessiner (EZWindow &fenetre, bool isActive = false) const;
		inline uint getWidth () const {return width;}
		inline void setWidth (uint _width) { width = _width; }
		inline uint getHeight () const { return height; }
		inline void setHeight (uint _height) { height = _height; }
		double perimetre () const override;
};
#endif
