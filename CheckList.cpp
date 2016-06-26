#include "CheckList.h"

Row::Row(string r, boolean b){
	text = r;
	isChecked = b;

}

Row::~Row(){

}


CheckList::CheckList() :CONTROL("checkInbar", 10, 10, 20, 10){
	graphics.moveTo(0, 0);
	focusedRow = 0;
	Row *p1 = new Row("try1", false);
	Row *p2 = new Row("try2", true);
	Row *p3 = new Row("try3", true);
	Row *p4 = new Row("try4", false);

	ar.push_back(*p1);
	ar.push_back(*p2);
	ar.push_back(*p3);
	ar.push_back(*p4);

}

CheckList::~CheckList(){

}

void CheckList::mousePressed(int, int, unsigned long){



}

void CheckList::keyDown(unsigned short code, char ascii){
	graphics.moveTo(_position.X + 1, _position.Y  + 3);
	graphics.write("01");

	if (code == VK_DOWN){
		
	}

	else if (code == VK_RETURN){
		if (focusedRow == ar.size()-1){
			focusedRow = 0;
		}
		else{
			focusedRow++;
		}

		graphics.moveTo(_position.X + 1, _position.Y + focusedRow + 2);
		graphics.write("01");
		//graphics.setForeground(Color::Red);

	}

}

bool CheckList::canGetFocus(){ return true; }

void CheckList::draw(Graphics graphics, int x_relative, int y_relative, size_t p){
	//set graphics
	this->graphics = graphics;
	graphics.setBackground(bc);
	graphics.setForeground(fc);
	// change color of textbox in focus
	if (this == focus)
	{
		graphics.setBackground(Color::White);
		graphics.setForeground(Color::Black);
	}
	// init position
	int xAbs = this->_position.X + x_relative,
		yAbs = this->_position.Y + y_relative;
	// draw frame of control
	drawFrame(graphics, xAbs, yAbs);
	// init position
	graphics.moveTo(xAbs + 1, yAbs + 1);
	// draw control content
	graphics.write(this->value);

	//graphics.moveTo(_position.X+3, _position.Y+3);
	for (int i = 0; i < ar.size(); i++)
	{
		graphics.moveTo(_position.X+1, _position.Y+i+2);
		graphics.write("[ ] "+ar[i].getText());

		if (ar[i].getIsChecked() == TRUE){
			graphics.moveTo(_position.X + 2, _position.Y + i + 2);
			graphics.write("*");
		}

		//graphics.write(string(ar[i].getIsChecked()));
	}
}