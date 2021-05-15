// EtwpLockUnlockBufferList 
 
unsigned int *__fastcall EtwpLockUnlockBufferList(unsigned int *result)
{
  unsigned int *v1; // r4
  unsigned int v2; // r3
  int v3; // r5

  v1 = result;
  if ( result[56] == 1 )
  {
    __dmb(0xFu);
    v2 = result[127];
    __dmb(0xBu);
    if ( (v2 & 1) != 0 )
    {
      v3 = KeAbPreAcquire((unsigned int)(result + 127), 0, 0);
      ExfAcquirePushLockExclusiveEx(v1 + 127, v3, (unsigned int)(v1 + 127));
      if ( v3 )
        *(_BYTE *)(v3 + 14) |= 1u;
      result = ExfReleasePushLockExclusive(v1 + 127);
      if ( v3 )
        result = (unsigned int *)KeAbPostRelease((unsigned int)(v1 + 127));
    }
  }
  else if ( result[127] )
  {
    result = (unsigned int *)sub_54CA8C();
  }
  return result;
}
