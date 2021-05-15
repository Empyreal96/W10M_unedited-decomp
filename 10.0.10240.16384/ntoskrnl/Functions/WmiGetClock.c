// WmiGetClock 
 
int __fastcall WmiGetClock(int a1, int a2, int a3, int a4)
{
  _DWORD v5[2]; // [sp+0h] [bp-8h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  if ( !a1 )
    return ((int (*)(void))*(&EtwpSystemTimeStamp + (unsigned __int16)word_61AD82))();
  if ( a1 != 1 )
  {
    if ( a1 == 2 )
    {
      KeQueryPerformanceCounter(v5, 0);
      return v5[0];
    }
    if ( a1 > 2 )
    {
      if ( a1 <= 4 )
        return 0;
      if ( a1 == 5 )
        return ReadTimeStampCounter();
    }
  }
  return RtlGetSystemTimePrecise();
}
