#include <simplecpp>

const float Swidth = 50;
const float Cwidth = 200;
const float Cheight= 150;
const float Cdescent=70;
const float Bheight = 20;  //space for horizontal bar in \upon

struct Rect{
  float w,h;
  Rect(float w1,float h1){w=w1;h=h1;}
};

struct Exp{
  Exp* lhs;
  Exp* rhs;
  char op;
  int value;
  float width, height, descent;
  Exp(int v){lhs=rhs=NULL;op=' ';value=v;}
  Exp(Exp* lhs1, char op1, Exp* rhs1){
    lhs = lhs1; rhs = rhs1; op = op1; value=0;}
  void setSize(){
    cout << op << endl;
    switch (op){
    case '+':
    case '-':
    case '*': 
      lhs->setSize(); 
      rhs->setSize();
      descent = max(lhs->descent, rhs->descent);
      width = lhs->width + Swidth + rhs->width;
      height = descent + max(lhs->height - lhs->descent, 
			     rhs->height - rhs->descent);
      break;
    case ' ': width = Cwidth; height = Cheight; descent = Cdescent;
      break;
    case '/':
      lhs->setSize(); 
      rhs->setSize();
      width = max(lhs->width, rhs->width);
      height = lhs->height + Bheight + rhs->height;
      descent = rhs->height + Bheight/2;
      break;
    default: cout << "Invalid input.\n";
    }
    cout << "width "<<width<<" height "<<height<<" descent "<< descent<<endl;
  }
  void draw(float clx, float cly){
    cout << ":"<<op<<":" << endl;
    switch(op){
    case '+':
    case '-':
    case '*': 
      Point(5,Position(clx+lhs->width+Swidth/2,cly)).imprint();
      Rectangle(clx+width/2, cly+descent-height/2, 
		width, height, false).imprint();
      lhs->draw(clx,cly);
      rhs->draw(clx+lhs->width+Swidth, cly);
      break;
    case ' ': 
      Rectangle(clx+width/2,cly+descent-height/2,width,height).imprint();
      break;
    case '/':
      Line(Position(clx,cly), Position(clx+width,cly)).imprint();
      Rectangle(clx+width/2, cly+descent-height/2, 
		width, height, false).imprint();
      lhs->draw(clx+width/2-lhs->width/2,cly-Bheight/2-lhs->descent);
      rhs->draw(clx+width/2-rhs->width/2,cly+Bheight/2+rhs->height-rhs->descent);
      break;
    default: cout << "Invalid input.\n";
    }
  }
};

int main(){
  Exp e(new Exp(1), '+', 
	new Exp(new Exp(2), '/', new Exp(new Exp(new Exp(4),'/',new Exp(5)),
					 '+', new Exp(3))));
  e.setSize();

  initCanvas("Formula drawing");
  e.draw(20,20+e.height-e.descent);
  wait(5);
}


