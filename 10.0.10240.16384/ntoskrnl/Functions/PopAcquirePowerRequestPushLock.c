// PopAcquirePowerRequestPushLock 
 
int __fastcall PopAcquirePowerRequestPushLock(int a1)
{
  unsigned int v1; // r2
  __int16 v2; // r3
  int result; // r0
  unsigned int v4; // r2
  int v5; // r4
  unsigned int v6; // r2

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = *(_WORD *)(v1 + 0x134);
  if ( a1 )
  {
    *(_WORD *)(v1 + 308) = v2 - 1;
    result = KeAbPreAcquire((unsigned int)&PopPowerRequestLock, 0, 0);
    do
      v4 = __ldrex((unsigned __int8 *)&PopPowerRequestLock);
    while ( __strex(v4 | 1, (unsigned __int8 *)&PopPowerRequestLock) );
    __dmb(0xBu);
    if ( (v4 & 1) != 0 )
    {
      result = sub_7F3390(result);
    }
    else
    {
      if ( result )
        *(_BYTE *)(result + 14) |= 1u;
      dword_61F834 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    }
  }
  else
  {
    *(_WORD *)(v1 + 308) = v2 - 1;
    result = KeAbPreAcquire((unsigned int)&PopPowerRequestLock, 0, 0);
    v5 = result;
    do
      v6 = __ldrex((unsigned int *)&PopPowerRequestLock);
    while ( !v6 && __strex(0x11u, (unsigned int *)&PopPowerRequestLock) );
    __dmb(0xBu);
    if ( v6 )
      result = ExfAcquirePushLockSharedEx(&PopPowerRequestLock, result, (unsigned int)&PopPowerRequestLock);
    if ( v5 )
      *(_BYTE *)(v5 + 14) |= 1u;
  }
  return result;
}
