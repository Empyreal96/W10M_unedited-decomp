// PfpRpCHashEmpty 
 
__int64 __fastcall PfpRpCHashEmpty(int a1, unsigned int *a2, unsigned __int8 *a3)
{
  unsigned int v4; // r3
  int i; // r2
  unsigned __int8 *v7; // r6
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r2
  unsigned int v12; // r7
  unsigned int v13; // r2
  int v14; // r0
  int v15; // r4
  unsigned int v16; // r2
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  unsigned int v21; // r1
  int v22; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  __int64 v26; // [sp+0h] [bp-28h]

  v4 = 1 << a2[1];
  for ( i = -1; v4; ++i )
    v4 >>= 1;
  if ( (((1 << a2[1]) - 1) & (1 << a2[1])) != 0 )
    ++i;
  HIDWORD(v26) = i;
  LODWORD(v26) = 0;
  v7 = (unsigned __int8 *)(a1 + 76);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = KeAbPreAcquire(a1 + 76, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v7);
  while ( __strex(v11 | 1, v7) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v7, v9, (unsigned int)v7);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v12 = *a2;
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v13 + 308);
  v14 = KeAbPreAcquire((unsigned int)a3, 0, 0);
  v15 = v14;
  do
    v16 = __ldrex(a3);
  while ( __strex(v16 | 1, a3) );
  __dmb(0xBu);
  if ( (v16 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a3, v14, (unsigned int)a3);
  if ( v15 )
    *(_BYTE *)(v15 + 14) |= 1u;
  *a2 = 0;
  a2[1] = HIDWORD(v26);
  a2[2] = 0;
  a2[3] = 0;
  __dmb(0xBu);
  do
    v17 = __ldrex((unsigned int *)a3);
  while ( __strex(v17 - 1, (unsigned int *)a3) );
  if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)a3);
  v18 = KeAbPostRelease((unsigned int)a3);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(_WORD *)(v19 + 0x134) + 1;
  *(_WORD *)(v19 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
    KiCheckForKernelApcDelivery(v18);
  __dmb(0xBu);
  do
    v21 = __ldrex((unsigned int *)v7);
  while ( __strex(v21 - 1, (unsigned int *)v7) );
  if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v7);
  v22 = KeAbPostRelease((unsigned int)v7);
  v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v24 = *(_WORD *)(v23 + 0x134) + 1;
  *(_WORD *)(v23 + 308) = v24;
  if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
    KiCheckForKernelApcDelivery(v22);
  if ( v12 )
    ExFreePoolWithTag(v12);
  return v26;
}
