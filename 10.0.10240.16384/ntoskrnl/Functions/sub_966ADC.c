// sub_966ADC 
 
void sub_966ADC()
{
  unsigned int v0; // r4
  int v1; // r6
  _DWORD *v2; // r8

  if ( v0 == v1 )
  {
    v0 = 30;
    *v2 = 30;
  }
  else if ( v0 > 0x12C )
  {
    v0 = 300;
    *v2 = 300;
  }
  if ( !v0 )
    __brkdiv0();
  PopIdleBackgroundIgnoreCount = (v0 + 59) / v0;
  PopBackgroundTaskIgnoreCount = (v0 + 179) / v0;
  JUMPOUT(0x94C300);
}
