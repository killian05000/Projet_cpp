#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "Forme.hpp"

class Ellipse : public Forme {
	private :
		uint height;
		uint width;
		void ecrire (ostream &os) const override;

	public :
		Ellipse(ulong color, uint x, uint y, uint width, uint height);
		Ellipse(istream &is);
		~Ellipse();
		virtual void dessiner (EZWindow &fenetre, bool isActive = false) const;
		inline uint getWidth () const {return width;}
		inline void setWidth (uint _width) { width = _width; }
		inline uint getHeight () const { return height; }
		inline void setHeight (uint _height) { height = _height; }
		double perimetre () const override;
};
#endif
