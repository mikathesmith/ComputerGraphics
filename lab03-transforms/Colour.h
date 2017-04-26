#pragma once

#ifndef COLOUR_H_INCLUDED
#define COLOUR_H_INCLUDED

/** \file
 * \brief Colour structure header file.
 */

/**
 * \brief Basic structure for Colours
 * 
 * A Colour is a red-green-blue triple. T
 * The values are stored as bytes (unsigned chars) so are in the range [0,255].
 */
struct Colour {

  /**
   * \brief Colour constructor
   *
   * Create a new colour with the given RGB values.
   *
   * \param r The red value of the new Colour
   * \param g The green value of the new Colour
   * \param b The blue value of the new Colour
   */
  Colour (unsigned char r, unsigned char g, unsigned char b) :
  red(r), green(g), blue(b) {}

  unsigned char red;   //!< Red value of the Colour
  unsigned char green; //!< Red value of the Colour
  unsigned char blue;  //!< Red value of the Colour
};

const Colour red(255,0,0);          //!< Predefined Colour for red
const Colour green(0,255,0);        //!< Predefined Colour for green
const Colour blue(0,0,255);         //!< Predefined Colour for blue
const Colour cyan(0,255,255);       //!< Predefined Colour for cyan
const Colour magenta(255,0,255);    //!< Predefined Colour for magenta
const Colour yellow(255,255,0);     //!< Predefined Colour for yellow
const Colour white(255,255,255);    //!< Predefined Colour for white

#endif
