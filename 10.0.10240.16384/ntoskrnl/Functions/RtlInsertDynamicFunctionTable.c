// RtlInsertDynamicFunctionTable 
 
int __fastcall RtlInsertDynamicFunctionTable(_DWORD *a1, int a2)
{
  _DWORD *v2; // r9
  unsigned int v3; // r3
  unsigned int v4; // r3
  int v5; // r5
  unsigned int v6; // r2
  unsigned __int8 *v7; // r8
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  unsigned int *v11; // r4
  unsigned int v12; // r8
  unsigned int v13; // r2
  int v14; // r4
  unsigned __int64 v15; // kr00_8
  int v16; // r6
  unsigned int *v17; // r0
  unsigned int v18; // r0
  _DWORD *v19; // r2
  unsigned int *v20; // r6
  bool v21; // zf
  unsigned int *v22; // r6
  unsigned int v23; // r1
  int v24; // r0
  __int16 v25; // r3
  unsigned int v27; // [sp+0h] [bp-48h]
  int v28; // [sp+8h] [bp-40h]
  unsigned int v29; // [sp+Ch] [bp-3Ch]
  int v30; // [sp+14h] [bp-34h]
  unsigned int v31; // [sp+18h] [bp-30h]
  unsigned int v32; // [sp+1Ch] [bp-2Ch]
  int v33; // [sp+20h] [bp-28h]
  unsigned int v34; // [sp+24h] [bp-24h]

  v2 = a1;
  if ( ((unsigned __int8)a1 & 7) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  v3 = a1[8];
  __dmb(0xBu);
  v27 = v3;
  v4 = a1[7];
  __dmb(0xBu);
  v29 = v4;
  if ( v4 < v27 )
    return -1073741675;
  v32 = v4 - v27;
  v6 = a1[13];
  __dmb(0xBu);
  if ( v6 > 0x1FFFFFFF )
    return -1073741675;
  v33 = 8 * v6;
  v28 = 0;
  v5 = 0;
  v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v30 = *(_DWORD *)(v34 + 0x150);
  --*(_WORD *)(v34 + 310);
  v7 = (unsigned __int8 *)(v30 + 708);
  v8 = KeAbPreAcquire(v30 + 708, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v7);
  while ( __strex(v10 | 1, v7) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v7, v8, (unsigned int)v7);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v11 = *(unsigned int **)(v30 + 704);
  if ( v11 )
  {
    v12 = *v11;
    v13 = v11[1];
  }
  else
  {
    v12 = 0;
    v13 = 0;
  }
  if ( v12 + 1 > v13 )
  {
    v31 = v13 + 10;
    if ( v13 + 10 < v13 || (v15 = 16 * (v13 + 10) + __PAIR64__((v13 + 10) >> 28, 16), v15 >= 0xFFFFFFFF) )
    {
      v5 = -1073741675;
LABEL_19:
      v14 = 0;
      goto LABEL_40;
    }
    v16 = *(_DWORD *)(v30 + 704);
    v28 = v16;
    v17 = (unsigned int *)ExAllocatePoolWithQuotaTag(9u, v15, 1178891346);
    v11 = v17;
    if ( !v17 )
    {
      v5 = -1073741670;
      goto LABEL_19;
    }
    if ( v12 )
    {
      memmove((int)(v17 + 4), v16 + 16, 16 * v12);
    }
    else
    {
      v17[4] = 0;
      v17[5] = 0;
      v17[6] = 0;
      v17[7] = 0;
      v12 = 1;
    }
    *v11 = v12;
    v11[1] = v31;
    *((_BYTE *)v11 + 12) = 0;
    *(_DWORD *)(v30 + 704) = v11;
  }
  v18 = 1;
  if ( v12 > 1 )
  {
    v19 = v11 + 4;
    do
    {
      if ( v27 < v19[5] )
        break;
      ++v18;
      v19 += 4;
    }
    while ( v18 < v12 );
  }
  v20 = &v11[4 * v18];
  if ( v20[1] + v20[2] > v27 )
    goto LABEL_32;
  v21 = v18 == v12;
  if ( v18 >= v12 )
  {
LABEL_36:
    if ( !v21 )
      memmove((int)&v11[4 * v18 + 8], (int)(v20 + 4), 16 * (v12 - v18));
    v20[4] = (unsigned int)v2;
    v20[5] = v27;
    v20[6] = v32;
    v20[7] = v33;
    *v11 = v12 + 1;
    goto LABEL_39;
  }
  if ( v20[5] >= v29 )
  {
    v21 = v18 == v12;
    goto LABEL_36;
  }
LABEL_32:
  v5 = -1073741800;
LABEL_39:
  v14 = v28;
LABEL_40:
  __dmb(0xBu);
  v22 = (unsigned int *)(v30 + 708);
  do
    v23 = __ldrex(v22);
  while ( __strex(v23 - 1, v22) );
  if ( (v23 & 2) != 0 && (v23 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v30 + 708));
  v24 = KeAbPostRelease((unsigned int)v22);
  v25 = *(_WORD *)(v34 + 310) + 1;
  *(_WORD *)(v34 + 310) = v25;
  if ( !v25 && *(_DWORD *)(v34 + 100) != v34 + 100 )
    KiCheckForKernelApcDelivery(v24);
  if ( v14 )
    ExFreePoolWithTag(v14, 1178891346);
  return v5;
}
