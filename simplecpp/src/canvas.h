#ifndef _CANVAS_INCLUDED
#define _CANVAS_INCLUDED

//#include <simplecpp>

namespace canvas{
  double randuv(double u, double v); 
  void srand(unsigned int);
  void wait(float duration);

  int initCanvas(const char window_title[]="Simplecpp Canvas",
		 int w=500, int h=500);
  void closeCanvas();

  int canvas_width();
  int canvas_height();
  int textWidth(string text);
  int textWidth(char op);
  int textHeight();
  int textDescent();

  void addSprite(Sprite *t);
  void removeSprite(Sprite *t);

  void drawLine(XPoint start, XPoint end, Color line_color, unsigned int line_width=0);

  void drawPoint(XPoint point, Color point_color, int function=GXcopy);

  void drawCircle(XPoint centre, int radius, Color fill_color, bool fill=true, unsigned int line_width=0, int line_style=LineSolid, int cap_style=CapButt, int join_style=JoinMiter, int function=GXcopy);

  void drawEllipse(XPoint centre, int width, int height, Color fill_color, bool fill=true, unsigned int line_width=1, int line_style=LineSolid, int cap_style=CapButt, int join_style=JoinMiter, int function=GXcopy);

  void drawPolygon(XPoint *points, int npoints, Color fill_color, bool fill=true, unsigned int line_width=0, int line_style=LineSolid, int cap_style=CapButt, int join_style=JoinMiter, int fill_rule=WindingRule, int function=GXcopy);

  void drawText(XPoint position, const char *text, Color clr);
  void drawText(Position position, string text, Color clr = Color("Blue"));
  void drawText(float x, float y, string text, Color clr = Color("Blue"));
  void drawText(XPoint position, string message, Color clr);

  Color COLOR(const char *color_string);
  Color COLOR(unsigned short red, unsigned short green, unsigned short blue);

  void c_imprint(Sprite* s);
  void repaint();
  void beginFrame();
  void endFrame();

  void nextEvent(XEvent *event);
  bool mouseDragEvent(XEvent *event);
  bool keyPressEvent(XEvent *event);
  bool mouseButtonPressEvent(XEvent *event);
  bool mouseButtonReleaseEvent(XEvent *event);
  char charFromEvent(XEvent *event);
  bool checkEvent(XEvent *event);
  void spriteStatus();
  int getClick();
}

#endif
