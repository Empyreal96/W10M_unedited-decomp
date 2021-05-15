// PsQueryTotalCycleTimeProcess 
 
int __fastcall PsQueryTotalCycleTimeProcess(_DWORD *a1, _QWORD *a2)
{
  int v4; // r5
  unsigned int *v5; // r6
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r2
  int v9; // r4
  _DWORD *v10; // r2
  _DWORD *v11; // r8
  unsigned __int64 *v12; // r9
  unsigned __int64 v13; // r0
  unsigned __int64 v14; // kr08_8
  unsigned int v15; // r2
  int v16; // r0
  __int16 v17; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  KeFlushProcessWriteBuffers(1);
  KeUpdateTotalCyclesCurrentThread(v4, a2);
  --*(_WORD *)(v4 + 308);
  v5 = a1 + 180;
  v6 = KeAbPreAcquire((unsigned int)(a1 + 180), 0, 0);
  v7 = v6;
  do
    v8 = __ldrex(v5);
  while ( !v8 && __strex(0x11u, v5) );
  __dmb(0xBu);
  if ( v8 )
    ExfAcquirePushLockSharedEx(a1 + 180, v6, (unsigned int)(a1 + 180));
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v9 = a1[32];
  v10 = (_DWORD *)a1[99];
  v11 = a1 + 99;
  while ( v10 != v11 )
  {
    v12 = (unsigned __int64 *)(v10 - 221);
    while ( 1 )
    {
      v13 = *v12;
      do
        v14 = __ldrexd(v12);
      while ( v14 == v13 && __strexd(v13, v12) );
      if ( v13 == v14 )
        break;
      __dmb(0xAu);
      __yield();
    }
    v10 = (_DWORD *)*v10;
    v9 += v13;
  }
  __dmb(0xBu);
  do
    v15 = __ldrex(v5);
  while ( v15 == 17 && __strex(0, v5) );
  if ( v15 != 17 )
    ExfReleasePushLockShared(v5);
  v16 = KeAbPostRelease((unsigned int)v5);
  v17 = *(_WORD *)(v4 + 308) + 1;
  *(_WORD *)(v4 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    KiCheckForKernelApcDelivery(v16);
  return v9;
}
