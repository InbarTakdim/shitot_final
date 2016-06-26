#pragma once

#include "CONTROL.h"
#include <vector>
#include <string.h>

class Row{
private:
	string text;
	boolean isChecked;
public:
	Row(string r , boolean b);
	~Row();
	string getText(){ return text; };
	boolean getIsChecked(){ return isChecked; };
};

class CheckList : public CONTROL
{
private:
	vector <Row> ar;
	int focusedRow;
protected:
public:
	CheckList();
	virtual ~CheckList();
	void draw(Graphics graphics, int x_relative, int y_relative, size_t p);
	void mousePressed(int, int, unsigned long);
	void keyDown(unsigned short, char);
	bool canGetFocus();

private:
};

