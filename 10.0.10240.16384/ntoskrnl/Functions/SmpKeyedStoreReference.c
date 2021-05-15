// SmpKeyedStoreReference 
 
int SmpKeyedStoreReference(unsigned int *a1, int a2, ...)
{
  int v4; // r5
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r7
  unsigned int v11; // r8
  int v12; // r9
  unsigned int *v13; // r5
  unsigned int v14; // r4
  unsigned int v15; // r1
  unsigned int v16; // r4
  unsigned int v17; // r1
  unsigned int v18; // r2
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  va_list varg_r2; // [sp+28h] [bp+10h] BYREF

  va_start(varg_r2, a2);
  v4 = -1;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire((unsigned int)a1, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex(a1);
  while ( !v8 && __strex(0x11u, a1) );
  __dmb(0xBu);
  if ( v8 )
    ExfAcquirePushLockSharedEx(a1, v6, (unsigned int)a1);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v9 = SmpKeyedStoreEntryGet((int)a1, (int)varg_r2, 0, 1);
  v10 = v9;
  if ( v9 )
  {
    v11 = *(unsigned __int16 *)(v9 + 8);
    v12 = a2 + 96 * (v11 & 0x1F);
    v13 = (unsigned int *)(v12 + 4);
    __pld((void *)(v12 + 4));
    v14 = *(_DWORD *)(v12 + 4) & 0xFFFFFFFE;
    do
      v15 = __ldrex(v13);
    while ( v15 == v14 && __strex(v14 + 2, v13) );
    __dmb(0xBu);
    if ( (v15 == v14 || ExfAcquireRundownProtection((_DWORD *)(v12 + 4))) && (*(_WORD *)(v12 + 12) & 0x7FF) != v11 >> 5 )
    {
      __pld(v13);
      v16 = *v13 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v17 = __ldrex(v13);
      while ( v17 == v16 && __strex(v16 - 2, v13) );
      if ( v17 != v16 )
        ExfReleaseRundownProtection((unsigned __int8 *)(v12 + 4));
    }
    v4 = *(unsigned __int16 *)(v10 + 8);
  }
  __dmb(0xBu);
  do
    v18 = __ldrex(a1);
  while ( v18 == 17 && __strex(0, a1) );
  if ( v18 != 17 )
    ExfReleasePushLockShared(a1);
  v19 = KeAbPostRelease((unsigned int)a1);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v19);
  return v4;
}
