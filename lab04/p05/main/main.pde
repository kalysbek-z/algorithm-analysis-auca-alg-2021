final int MAX_LEVEL = 8;

void setup(){
 fullScreen();
 noStroke();
}

void draw(){
  background(0);
  drawRecursiveSquare(0, width / 2f, height / 2f, 200, 255f);
}

void drawRecursiveSquare(int n, float xc, float yc, float r, float c){
  if(n < MAX_LEVEL){
  drawRecursiveSquare(n + 1, xc - r, yc - r, r / 2, c - 250 / MAX_LEVEL);
  drawRecursiveSquare(n + 1, xc + r, yc - r, r / 2, c - 250 / MAX_LEVEL);
  drawRecursiveSquare(n + 1, xc - r, yc + r, r / 2, c - 250 / MAX_LEVEL);
  drawRecursiveSquare(n + 1, xc + r, yc + r, r / 2, c - 250 / MAX_LEVEL);
  fill(c, 0f, 0f);
  square(xc - r, yc - r, 2 * r);
  }
  
}
