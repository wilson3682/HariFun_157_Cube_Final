void OneAtATime()
{
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[ i ] = CRGB::Blue;
    FastLED.delay(100);
    leds[ i ] = CRGB::Black;
  }
}

void DrawDiagonal(CRGB c)
{
  DrawLine( 0, 0, 0, 7, 7, 7, c);
}

void DrawXYRects()
{
  Point a = {0, 0, 0};
  Point b = {7, 4, 0};
  DrawXYRect(a, b, CRGB::Red);
  FastLED.show();
}

int xP, yP, zP, szP;

void EtchSketch()
{
  int x0 = map( analogRead(A2), 0, 1023, 0, 7);
  int y0 = map( analogRead(A1), 0, 1023, 0, 7);
  int z0 = map( analogRead(A0), 1023,0, 0, 7);
  int sz = map( analogRead(A3), 0, 1023, 1, 7);

  if (x0 != xP || y0 != yP || z0 != zP || szP != sz) {
    int x1 = min(x0 + sz, 7);
    int y1 = min(y0 + sz, 7);
    int z1 = min(z0 - sz, 7);
    xP = x0;
    yP = y0;
    zP = z0;
    szP = sz;
    Point a = {x0, y0, z0};
    Point b = {x1, y1, z1};
    SetAll(CRGB::Black);
    DrawCube(a,b, CRGB::Blue);
    FastLED.show();
  }
  delay(100);
}