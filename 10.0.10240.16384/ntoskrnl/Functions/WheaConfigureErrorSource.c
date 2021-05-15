// WheaConfigureErrorSource 
 
int __fastcall WheaConfigureErrorSource(unsigned int a1, int *a2)
{
  int *v4; // r4
  int v5; // r8
  int v6; // r0
  unsigned int v7; // r2
  int v9; // r0
  int v10; // r6
  unsigned int v11; // r2
  int v12; // r3
  int v13; // r3
  int v14; // r3
  int v15; // r3
  int v16; // r3
  int v17; // r3
  int v18; // r3
  unsigned int v19; // r1
  unsigned int v20; // r2

  if ( a1 > 0xB )
    return -1073741811;
  v4 = &WheapSourceConfiguration[7 * a1];
  v5 = -1073741823;
  v6 = KeAbPreAcquire((unsigned int)&WheapConfigTableLock, 0, 0);
  do
    v7 = __ldrex((unsigned int *)&WheapConfigTableLock);
  while ( !v7 && __strex(0x11u, (unsigned int *)&WheapConfigTableLock) );
  __dmb(0xBu);
  if ( v7 )
    return sub_694820(v6, 17);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v9 = KeAbPreAcquire((unsigned int)v4, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex((unsigned __int8 *)v4);
  while ( __strex(v11 | 1, (unsigned __int8 *)v4) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v4, v9, (unsigned int)v4);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v12 = *((unsigned __int8 *)v4 + 4);
  __dmb(0xBu);
  if ( !v12 )
  {
    v13 = *a2;
    __dmb(0xBu);
    v4[2] = v13;
    v14 = a2[1];
    if ( v14 )
    {
      __dmb(0xBu);
      v4[3] = v14;
    }
    v15 = a2[2];
    if ( v15 )
    {
      __dmb(0xBu);
      v4[4] = v15;
    }
    v16 = a2[3];
    if ( v16 )
    {
      __dmb(0xBu);
      v4[5] = v16;
    }
    v17 = a2[4];
    if ( v17 )
    {
      __dmb(0xBu);
      v4[6] = v17;
    }
    __dmb(0xFu);
    *((_BYTE *)v4 + 4) = 1;
    v18 = (unsigned __int8)WheapInitializationComplete;
    __dmb(0xBu);
    if ( v18 )
      v5 = WheapInitializeDeferredErrorSources(a1);
  }
  __dmb(0xBu);
  do
    v19 = __ldrex((unsigned int *)v4);
  while ( __strex(v19 - 1, (unsigned int *)v4) );
  if ( (v19 & 2) != 0 && (v19 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v4);
  KeAbPostRelease((unsigned int)v4);
  __dmb(0xBu);
  do
    v20 = __ldrex((unsigned int *)&WheapConfigTableLock);
  while ( v20 == 17 && __strex(0, (unsigned int *)&WheapConfigTableLock) );
  if ( v20 != 17 )
    ExfReleasePushLockShared(&WheapConfigTableLock);
  KeAbPostRelease((unsigned int)&WheapConfigTableLock);
  return v5;
}
