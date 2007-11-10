/***************************************************************************
 *   Copyright (C) 2007 by Sindre Aam�s                                    *
 *   aamas@stud.ntnu.no                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License version 2 as     *
 *   published by the Free Software Foundation.                            *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License version 2 for more details.                *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   version 2 along with this program; if not, write to the               *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef ENVELOPE_UNIT_H
#define ENVELOPE_UNIT_H

#include "sound_unit.h"

class EnvelopeUnit : public SoundUnit {
// 	bool zombie;
	unsigned char nr2;
	unsigned char volume;
	
public:
	void event();
	bool dacIsOn() const { return nr2 & 0xF8; }
	unsigned getVolume() const { return volume; }
	bool nr2Change(unsigned newNr2);
	bool nr4Init(unsigned long cycleCounter);
	void reset();
	void init(bool ch1, unsigned long cc);
};

#endif
