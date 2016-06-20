/**
 * Mandelbulber v2, a 3D fractal generator       ,=#MKNmMMKmmßMNWy,
 *                                             ,B" ]L,,p%%%,,,§;, "K
 * Copyright (C) 2014 Krzysztof Marczak        §R-==%w["'~5]m%=L.=~5N
 *                                        ,=mm=§M ]=4 yJKA"/-Nsaj  "Bw,==,,
 * This file is part of Mandelbulber.    §R.r= jw",M  Km .mM  FW ",§=ß., ,TN
 *                                     ,4R =%["w[N=7]J '"5=],""]]M,w,-; T=]M
 * Mandelbulber is free software:     §R.ß~-Q/M=,=5"v"]=Qf,'§"M= =,M.§ Rz]M"Kw
 * you can redistribute it and/or     §w "xDY.J ' -"m=====WeC=\ ""%""y=%"]"" §
 * modify it under the terms of the    "§M=M =D=4"N #"%==A%p M§ M6  R' #"=~.4M
 * GNU General Public License as        §W =, ][T"]C  §  § '§ e===~ U  !§[Z ]N
 * published by the                    4M",,Jm=,"=e~  §  §  j]]""N  BmM"py=ßM
 * Free Software Foundation,          ]§ T,M=& 'YmMMpM9MMM%=w=,,=MT]M m§;'§,
 * either version 3 of the License,    TWw [.j"5=~N[=§%=%W,T ]R,"=="Y[LFT ]N
 * or (at your option)                   TW=,-#"%=;[  =Q:["V""  ],,M.m == ]N
 * any later version.                      J§"mr"] ,=,," =="""J]= M"M"]==ß"
 *                                          §= "=C=4 §"eM "=B:m\4"]#F,§~
 * Mandelbulber is distributed in            "9w=,,]w em%wJ '"~" ,=,,ß"
 * the hope that it will be useful,                 . "K=  ,=RMMMßM"""
 * but WITHOUT ANY WARRANTY;                            .'''
 * without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with Mandelbulber. If not, see <http://www.gnu.org/licenses/>.
 *
 * ###########################################################################
 *
 * Authors: Krzysztof Marczak (buddhi1980@gmail.com)
 *
 * cMaterialSelector class - promoted QWidget for selection of a material
 */

#ifndef MANDELBULBER2_QT_MATERIAL_SELECTOR_H_
#define MANDELBULBER2_QT_MATERIAL_SELECTOR_H_

#include <QWidget>
#include <QtWidgets/QHBoxLayout>
#include <qlabel.h>

#include "common_my_widget_wrapper.h"
#include "material_widget.h"

class cMaterialSelector : public QWidget, public CommonMyWidgetWrapper
{
	Q_OBJECT

public:
	cMaterialSelector(QWidget *parent = NULL);
	~cMaterialSelector();

	void SetMaterialIndex(int materialIndex);
	int GetMaterialIndex() { return actualValue; }

private:
	cMaterialWidget *materialWidget;
	QHBoxLayout *layout;
	QLabel *label;

	// methods to define from CommonMyWidgetWrapper
	virtual void resetToDefault();
	virtual QString getDefaultAsString();
	virtual QString getFullParameterName();

	int GetDefault();
	int defaultValue;
	bool gotDefault;
	int actualValue;

protected:
	void contextMenuEvent(QContextMenuEvent *event);
	void paintEvent(QPaintEvent *event);

private slots:
	void slotClicked(Qt::MouseButton button);
	void slotMaterialSelected(int matIndex);
	void slotMaterialEdited();
};

#endif /* MANDELBULBER2_QT_MATERIAL_SELECTOR_H_ */
