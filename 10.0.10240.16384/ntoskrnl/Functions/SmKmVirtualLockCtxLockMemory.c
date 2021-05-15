// SmKmVirtualLockCtxLockMemory 
 
int __fastcall SmKmVirtualLockCtxLockMemory(unsigned int *a1, int a2, int a3, int a4)
{
  int v5; // r6
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r5
  unsigned int v9; // r2
  unsigned int *v10; // r5
  unsigned int v11; // r1
  unsigned int i; // r0
  unsigned int v13; // r2
  int v14; // r0
  int v15; // r5
  unsigned int v16; // r5
  unsigned int v17; // r2
  int v18; // r0
  __int16 v19; // r3
  unsigned int v20; // r2
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3
  unsigned int *varg_r0; // [sp+18h] [bp+8h]

  varg_r0 = a1;
  v5 = 0;
  while ( 1 )
  {
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 308);
    v7 = KeAbPreAcquire((unsigned int)a1, 0, 0);
    v8 = v7;
    do
      v9 = __ldrex(a1);
    while ( !v9 && __strex(0x11u, a1) );
    __dmb(0xBu);
    if ( v9 )
      ExfAcquirePushLockSharedEx(a1, v7, (unsigned int)a1);
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    if ( !v5 )
    {
      v10 = a1 + 1;
      v11 = a1[1];
      for ( i = v11 + a3; i <= a1[2]; i = v13 + a3 )
      {
        do
          v13 = __ldrex(v10);
        while ( v13 == v11 && __strex(i, v10) );
        if ( v13 == v11 )
        {
          v5 = 1;
          goto LABEL_18;
        }
        v11 = v13;
      }
      goto LABEL_20;
    }
LABEL_18:
    v14 = ZwLockVirtualMemory();
    v15 = v14;
    if ( v14 >= 0 )
      break;
    if ( v14 != -1073741663 )
      goto LABEL_32;
LABEL_20:
    v16 = a1[2];
    __dmb(0xBu);
    do
      v17 = __ldrex(a1);
    while ( v17 == 17 && __strex(0, a1) );
    if ( v17 != 17 )
      ExfReleasePushLockShared(a1);
    KeAbPostRelease((unsigned int)a1);
    v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v19 = *(_WORD *)(v18 + 0x134) + 1;
    *(_WORD *)(v18 + 308) = v19;
    if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
      KiCheckForKernelApcDelivery(v18);
    v15 = SmKmVirtualLockContextIncreaseWsMin((unsigned int)a1, a3, v16);
    if ( v15 < 0 )
      goto LABEL_41;
  }
  v5 = 0;
  v15 = 0;
LABEL_32:
  __dmb(0xBu);
  do
    v20 = __ldrex(a1);
  while ( v20 == 17 && __strex(0, a1) );
  if ( v20 != 17 )
    ExfReleasePushLockShared(a1);
  v21 = KeAbPostRelease((unsigned int)a1);
  v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v23 = *(_WORD *)(v22 + 0x134) + 1;
  *(_WORD *)(v22 + 308) = v23;
  if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
    KiCheckForKernelApcDelivery(v21);
LABEL_41:
  if ( v5 )
    SmKmVirtualLockCtxMemoryUnlocked(a1, a3);
  return v15;
}
