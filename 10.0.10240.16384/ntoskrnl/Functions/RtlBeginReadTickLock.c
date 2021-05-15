// RtlBeginReadTickLock 
 
int __fastcall RtlBeginReadTickLock(__int64 *a1)
{
  __int64 v1; // kr00_8

  while ( 1 )
  {
    v1 = *a1;
    __dmb(0xBu);
    if ( (v1 & 1) == 0 )
      break;
    __dmb(0xAu);
    __yield();
  }
  return v1;
}
