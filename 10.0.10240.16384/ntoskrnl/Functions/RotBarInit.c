// RotBarInit 
 
int RotBarInit()
{
  int *v0; // r2

  v0 = pbih;
  pbih[1] = 1;
  v0[2] = 1;
  *((_WORD *)v0 + 6) = 1;
  v0[6] = 2834;
  v0[7] = 2834;
  *v0 = 40;
  *((_WORD *)v0 + 7) = 4;
  v0[4] = 0;
  v0[5] = 4;
  v0[8] = 0;
  v0[9] = 0;
  PltRotBarStatus = 1;
  PaletteNum = 0;
  AnimBarPos = 0;
  VidScreenToBufferBlt_0();
  VidScreenToBufferBlt_0();
  VidScreenToBufferBlt_0();
  return VidSolidColorFill_0();
}
