// sub_540CCC 
 
void sub_540CCC()
{
  unsigned __int64 v0; // r8
  int v1; // lr

  if ( v1 == -1 )
    __brkdiv0();
  _rt_udiv64((unsigned int)(v1 + 1), v0);
  JUMPOUT(0x4ADD00);
}
