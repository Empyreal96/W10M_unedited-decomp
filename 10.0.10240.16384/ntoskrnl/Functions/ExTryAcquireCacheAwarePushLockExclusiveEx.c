// ExTryAcquireCacheAwarePushLockExclusiveEx 
 
int __fastcall ExTryAcquireCacheAwarePushLockExclusiveEx(unsigned int a1, int a2)
{
  unsigned int v2; // r5
  unsigned __int8 **v3; // r6
  unsigned int v4; // r7
  int v5; // r4
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  int result; // r0
  unsigned int *v9; // r0
  unsigned int *v10; // t1
  unsigned int v11; // r1

  v2 = a1;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    KeBugCheck2(338, a2, a1, 0, 0, 0);
  v3 = (unsigned __int8 **)a1;
  v4 = a1 + 128;
  if ( (a2 & 2) != 0 )
    v5 = 0;
  else
    v5 = KeAbPreAcquire(a1, 0, 1);
  if ( v2 >= v4 )
  {
LABEL_11:
    if ( v5 )
      *(_BYTE *)(v5 + 14) |= 1u;
    result = 1;
  }
  else
  {
    while ( 1 )
    {
      v6 = *v3;
      do
        v7 = __ldrex(v6);
      while ( __strex(v7 | 1, v6) );
      __dmb(0xBu);
      if ( (v7 & 1) != 0 )
        break;
      if ( (unsigned int)++v3 >= v4 )
        goto LABEL_11;
    }
    while ( v3 != (unsigned __int8 **)v2 )
    {
      v10 = (unsigned int *)*--v3;
      v9 = v10;
      __dmb(0xBu);
      do
        v11 = __ldrex(v9);
      while ( __strex(v11 - 1, v9) );
      if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
        ExfTryToWakePushLock(v9);
    }
    if ( v5 )
      KeAbPostReleaseEx(v2, v5);
    result = 0;
  }
  return result;
}
