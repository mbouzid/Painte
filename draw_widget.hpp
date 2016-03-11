#pragma once

#include <QMainWindow>
#include "draw_area.hpp"

class draw_widget : public QMainWindow
{
 
private :

	draw_area * m_draw_area ;
	
public:

    draw_widget()
    /**
    *	Create an instance of draw_widget
    *	@constructor @access public
    **/
    {
    	m_draw_area = new draw_area;
    	setCentralWidget(m_draw_area);

	}


    

};
