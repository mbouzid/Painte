#pragma once

#include <QWidget>
#include <QHBoxLayout>

#include "draw_area.hpp"
class draw_widget : public QWidget
{

	private :

		QHBoxLayout * m_layout ;
		QPushButton * m_toss ;
		draw_area * m_draw_area ;
		
	public :
	
    draw_widget( QWidget * parent = 0 ):QWidget(parent)
    /**
    *	Create an instance of draw_widget
    *	@constructor @access public
    **/
   	{
   		m_draw_area = new draw_area ;
		m_layout = new QHBoxLayout(this);
  		m_toss = new QPushButton("Toss");
  		
  		m_layout->addWidget(m_draw_area);
  		m_layout->addWidget(m_toss);
  	
  		m_toss->setMaximumWidth(m_toss->minimumSizeHint().width());
  		m_toss->setEnabled(false);
  	
  		QObject::connect(m_draw_area,SIGNAL(is_used(bool)),m_toss,SLOT(setEnabled(bool)));
  		QObject::connect(m_toss,SIGNAL(clicked()),m_draw_area,SLOT(toss()));
  		
	}
	

};
