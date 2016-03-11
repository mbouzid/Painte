#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include "draw_area.hpp"

class draw_widget : public QWidget
{
 
private :

	draw_area * m_draw_area ;
	QVBoxLayout * m_layout ;
public:

    draw_widget()
    /**
    *	Create an instance of draw_widget
    *	@constructor @access public
    **/
    {
    	m_layout = new QVBoxLayout(this);
    	m_draw_area = new draw_area;
    	m_layout->addWidget(m_draw_area);
	
	}


    

};
