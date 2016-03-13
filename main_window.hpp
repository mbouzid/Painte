#pragma once

#include <QtGui/QMainWindow>
#include <QtGui/QSplitter>
#include "draw_widget.hpp" 
#include <QtGui/QGridLayout>

class main_window : public QMainWindow
{

	private :
	
		QSplitter * m_top_splitter ;
		QSplitter * m_bottom_splitter ;
		QGridLayout * m_layout ;
		draw_widget * m_first ;
		draw_widget * m_second ;
		draw_widget * m_third ;
		
	public :
	
		main_window()
		{
			
			QWidget * top = new QWidget(this);	
			m_layout = new QGridLayout(top);
			setCentralWidget(top);
			
			m_first = new draw_widget(top);
			m_second = new draw_widget(top);
			m_third = new draw_widget(top);
			
			m_top_splitter = new QSplitter(top);
			m_top_splitter->addWidget(m_first);
			
			QSplitter * other = new QSplitter(top);
			other->addWidget(m_second);
		
			
			QSplitter * another = new QSplitter(top);
			another->addWidget(m_third);
			another->setOrientation(Qt::Horizontal);
			
			
			m_layout->addWidget(m_top_splitter,0,0);
			m_layout->addWidget(other,1,0,1,2);
			m_layout->addWidget(another,0,1);
			
		}
	
		~main_window()
		{
		
		}
};
