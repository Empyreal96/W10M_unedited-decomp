// MiChargeSegmentCommit 
 
int __fastcall MiChargeSegmentCommit(int **a1, int *a2, unsigned int a3, int a4)
{
  unsigned int v4; // r8
  int **v5; // r9
  unsigned int v6; // r6
  int v7; // r10
  int *v8; // r7
  unsigned __int8 *v10; // r4
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r2
  int **v14; // r1
  int v15; // r5
  int v16; // r9
  int v17; // r10
  int v18; // r2
  unsigned int v19; // r0
  unsigned int v20; // r1
  int v21; // r0
  int v22; // r3
  int v23; // r2
  unsigned int v25; // r1
  int v26; // r0
  __int16 v27; // r3
  int **v28; // [sp+0h] [bp-38h]
  int *v29; // [sp+4h] [bp-34h]
  int v30; // [sp+4h] [bp-34h]
  int v31; // [sp+8h] [bp-30h]
  int v32; // [sp+Ch] [bp-2Ch]

  v4 = a3;
  v29 = a2;
  v5 = a1;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v28 = a1;
  v32 = **a1;
  v7 = (int)&a1[1][(_DWORD)a1[7]];
  v8 = a2;
  if ( a4 == 1 )
    return sub_7E9748();
  v31 = MiChargeCommit((int)MiSystemPartition, a3, 0);
  --*(_WORD *)(v6 + 310);
  v10 = (unsigned __int8 *)(v32 + 28);
  v11 = KeAbPreAcquire(v32 + 28, 0, 0);
  v12 = v11;
  do
    v13 = __ldrex(v10);
  while ( __strex(v13 | 1, v10) );
  __dmb(0xBu);
  if ( (v13 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v10, v11, (unsigned int)v10);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  if ( v31 )
    goto LABEL_10;
  v23 = 0;
  while ( 1 )
  {
    if ( *v8++ )
      --v4;
    if ( ++v23 == a3 )
      break;
    if ( v8 == (int *)v7 )
    {
      v5 = (int **)v5[2];
      v8 = v5[1];
      v7 = (int)&v8[(_DWORD)v5[7]];
    }
  }
  v8 = v29;
  if ( !v4 )
  {
    __dmb(0xBu);
    do
      v20 = __ldrex((unsigned int *)v10);
    while ( __strex(v20 - 1, (unsigned int *)v10) );
LABEL_26:
    if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v10);
    v21 = KeAbPostRelease((unsigned int)v10);
    v22 = (__int16)(*(_WORD *)(v6 + 310) + 1);
    *(_WORD *)(v6 + 310) = v22;
    if ( !v22 && *(_DWORD *)(v6 + 100) != v6 + 100 )
      KiCheckForKernelApcDelivery(v21);
    return 1;
  }
  if ( MiChargeCommit((int)MiSystemPartition, v4, 0) )
  {
LABEL_10:
    v14 = v28;
    v15 = 0;
    v16 = 0;
    v17 = 16 * (*(_BYTE *)(v32 + 10) & 0x3E);
    v18 = (int)&v28[1][(_DWORD)v28[7]];
LABEL_11:
    v30 = v18;
    while ( 1 )
    {
      if ( *v8 )
      {
        ++v15;
      }
      else if ( (unsigned int)v8 < 0xC0000000 || (unsigned int)v8 > 0xC03FFFFF )
      {
        *v8 = v17;
      }
      else
      {
        __dmb(0xBu);
        *v8 = v17;
        if ( (unsigned int)(v8 + 267649024) <= 0xFFF )
        {
          MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v17, (__int16)v8);
          v14 = v28;
        }
        v18 = v30;
      }
      ++v16;
      ++v8;
      if ( v16 == a3 )
        break;
      if ( v8 == (int *)v18 )
      {
        v14 = (int **)v14[2];
        v8 = v14[1];
        v28 = v14;
        v18 = (int)&v8[(_DWORD)v14[7]];
        goto LABEL_11;
      }
    }
    if ( v31 == 1 )
    {
      v4 -= v15;
      if ( v15 )
        MiReturnCommit((int)MiSystemPartition, v15);
    }
    if ( v4 )
    {
      MiUpdateProcessSharedCommit(*(_DWORD *)v32, v4);
      do
        v19 = __ldrex((unsigned int *)&dword_634DAC);
      while ( __strex(v19 + v4, (unsigned int *)&dword_634DAC) );
    }
    __dmb(0xBu);
    do
      v20 = __ldrex((unsigned int *)v10);
    while ( __strex(v20 - 1, (unsigned int *)v10) );
    goto LABEL_26;
  }
  __dmb(0xBu);
  do
    v25 = __ldrex((unsigned int *)v10);
  while ( __strex(v25 - 1, (unsigned int *)v10) );
  if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v10);
  v26 = KeAbPostRelease((unsigned int)v10);
  v27 = *(_WORD *)(v6 + 310) + 1;
  *(_WORD *)(v6 + 310) = v27;
  if ( !v27 && *(_DWORD *)(v6 + 100) != v6 + 100 )
    KiCheckForKernelApcDelivery(v26);
  return 0;
}
