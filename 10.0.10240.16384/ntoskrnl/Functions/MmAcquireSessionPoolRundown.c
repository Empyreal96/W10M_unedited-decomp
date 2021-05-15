// MmAcquireSessionPoolRundown 
 
int __fastcall MmAcquireSessionPoolRundown(int a1)
{
  unsigned int v1; // r4
  int v2; // r8
  unsigned int v3; // r1
  int v4; // r0
  int v5; // r3
  int v7; // r6
  unsigned int v8; // r1
  int v9; // r3
  unsigned int v10; // r1
  int v11; // r0
  __int16 v12; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  if ( a1 != 1 )
  {
    __dmb(0xBu);
    do
      v3 = __ldrex((unsigned int *)&dword_63378C);
    while ( v3 == 17 && __strex(0, (unsigned int *)&dword_63378C) );
    if ( v3 != 17 )
      ExfReleasePushLockShared(&dword_63378C);
    v4 = KeAbPostRelease((unsigned int)&dword_63378C);
    v5 = (__int16)(*(_WORD *)(v1 + 310) + 1);
    *(_WORD *)(v1 + 310) = v5;
    if ( !v5 && *(_DWORD *)(v1 + 100) != v1 + 100 )
      KiCheckForKernelApcDelivery(v4);
    return 1;
  }
  --*(_WORD *)(v1 + 310);
  v7 = KeAbPreAcquire((unsigned int)&dword_63378C, 0, 0);
  do
    v8 = __ldrex((unsigned int *)&dword_63378C);
  while ( !v8 && __strex(0x11u, (unsigned int *)&dword_63378C) );
  __dmb(0xBu);
  if ( v8 )
    return sub_7D5D34(17);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v9 = *(_DWORD *)(v2 + 4);
  if ( (v9 & 1) != 0 && (v9 & 0x20) == 0 )
    return 1;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&dword_63378C);
  while ( v10 == 17 && __strex(0, (unsigned int *)&dword_63378C) );
  if ( v10 != 17 )
    ExfReleasePushLockShared(&dword_63378C);
  v11 = KeAbPostRelease((unsigned int)&dword_63378C);
  v12 = *(_WORD *)(v1 + 310) + 1;
  *(_WORD *)(v1 + 310) = v12;
  if ( !v12 && *(_DWORD *)(v1 + 100) != v1 + 100 )
    KiCheckForKernelApcDelivery(v11);
  return 0;
}
