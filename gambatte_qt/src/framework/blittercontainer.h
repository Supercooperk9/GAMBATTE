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
#ifndef BLITTERCONTAINER_H
#define BLITTERCONTAINER_H

#include <QWidget>

class BlitterWidget;
class FullModeToggler;
class VideoDialog;

class BlitterContainer : public QWidget {
	const VideoDialog *const videoDialog;
	BlitterWidget *blitter_;
	bool parentExclusive;
	
	void doLayout(int w, int h);
	void testExclusive();
	
protected:
	void moveEvent(QMoveEvent *event);
	void resizeEvent(QResizeEvent *event);
	
public:
	BlitterContainer(const VideoDialog *videoDialog, QWidget *parent = 0);
	~BlitterContainer();
	void setBlitter(BlitterWidget *blitter);
	void updateLayout() { doLayout(width(), height()); }
	void parentExclusiveEvent(bool fs) { parentExclusive = fs; testExclusive(); }
	BlitterWidget* blitter() { return blitter_; }
};

#endif
