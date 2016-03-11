#pragma once

#include <QtGui/QtGui>

class draw_area : public QWidget
{

	private :

	bool m_drawing ;
    	QImage m_image;
    	QPoint m_last;
    	QPen m_pen ;
    
	public :

	draw_area(QWidget * parent = 0 ): QWidget(parent),m_drawing(false),m_pen(Qt::blue)
	/**
	*	Create an instance of draw_area
	*	@constructor @access public
	*	@param {QWidget *} parent
	**/
	{}
	
    void draw(const QPoint & end )
    /**
    *	Draw a line to the end point.
    *	@method @access public
    *	@param {const QPoint & } end
    **/
	{
		QPainter painter(&m_image);
		painter.setPen(m_pen);
		painter.drawLine(m_last,end);
		
		update(QRect(m_last,end));
		m_last = end ;
	}
	
	void blit( QImage & buffer , const QImage & back_buffer )
	/**
	*	Copy the source buffer in the destination buffer
	*	@method @access public
	*	@param {const QImage &} buffer
	*	@param {const QImage &} back_buffer
	**/
	{
		buffer.fill(Qt::white); 	// fill the dest buffer with white ( no specification makes it black )
		QPainter painter(&buffer);	// set a painter for the dest buffer
		painter.setPen(m_pen);	// set a pen for the painter
		painter.drawImage(QPoint(0, 0),back_buffer);	// the painter draws the back_buffer starting at (0,0) in the dest buffer
	}
	
    void resize(QImage * image , const QSize & sz)
    /**	
    *	Resize an image.
    *	@method @access public
    *	@param {QImage *} image
    *	@param {const QSize &} sz
    **/
   	{
		QImage new_image(sz, QImage::Format_RGB32);	// create a new image with the new size
		blit(new_image,*image);	
		*image= new_image;	// deferenciate the image for the new_image
	}

    

    void mousePressEvent(QMouseEvent *event)
    /**
    *	Called when the mouse is pressed
    *	@param {QMouseEvent *} event
    **/
    {
		if (event->button() == Qt::LeftButton) 
		{
		    m_last = event->pos();
		    m_drawing = true ;
		}
    }
    void mouseMoveEvent(QMouseEvent *event) 
    /**
    *	Called when the mouse is moving
    *	@param {QMouseEvent *} event
    **/
    {
		if ((event->buttons() & Qt::LeftButton) && m_drawing )
		{
			draw(event->pos());
		}
	}

    void mouseReleaseEvent(QMouseEvent *event)
    /**
    *	Called when the mouse is released
    *	@method @access public
    *	@param {QMouseEvent*} event
    **/
    {
		if (event->button() == Qt::LeftButton && m_drawing )
		{
		    draw(event->pos());
		    m_drawing = false ;
    	}
	}
	
    void paintEvent(QPaintEvent *event)
    /**
    *	Set a painter for this
    *	@method @access public
    *	@param {QPaintEvent *} event
    **/
 	{
		QPainter painter(this);	//set a painter that will paint this
		QRect region = event->rect();	// this is the region where we will draw
		painter.setPen(m_pen); // set a pen for the painter
		painter.drawImage(region, m_image,region); // draw the rect region of m_image into the target region in the paint device.
	}
	
    void resizeEvent(QResizeEvent *event)
    /**
    *	Called when the window is resized
    *	@method @access public
    *	@param {QResizeEvent *} event
    **/
	{
		QSize sz(event->size());
		resize(&m_image,QSize(sz.width(),sz.height()));
		QWidget::resizeEvent(event);
   }


};

