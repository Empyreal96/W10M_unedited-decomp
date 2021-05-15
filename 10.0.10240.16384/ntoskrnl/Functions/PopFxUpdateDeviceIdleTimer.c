// PopFxUpdateDeviceIdleTimer 
 
int __fastcall PopFxUpdateDeviceIdleTimer(int result)
{
  int v1; // r4
  unsigned int *v2; // r5
  unsigned int v3; // r1
  unsigned int v4; // r1

  v1 = result;
  __dmb(0xBu);
  v2 = (unsigned int *)(result + 16);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3, v2) );
  __dmb(0xBu);
  if ( (v3 & 4) != 0 )
  {
    result = KeCancelTimer(result + 192);
    if ( result )
    {
      __dmb(0xBu);
      do
        v4 = __ldrex(v2);
      while ( __strex(v4 & 0xFFFFFFFB, v2) );
      __dmb(0xBu);
      result = PopFxScheduleDeviceIdleTimer(v1);
      if ( !result )
        result = sub_5263D8();
    }
  }
  return result;
}
