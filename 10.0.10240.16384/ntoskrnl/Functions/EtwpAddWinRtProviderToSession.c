// EtwpAddWinRtProviderToSession 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall EtwpAddWinRtProviderToSession(_DWORD *a1, unsigned __int16 *a2, unsigned int *a3)
{
  unsigned __int8 *v3; // r8
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r4
  int v9; // r4
  unsigned int *v10; // r5
  unsigned int *v11; // r7
  unsigned int *v12; // r0
  unsigned int *v13; // r6
  unsigned int v14; // r2
  unsigned int v15; // r3
  unsigned int v16; // r4
  _DWORD *v17; // r4
  unsigned int v18; // r2
  unsigned int v19; // r4
  unsigned int v20; // r6
  unsigned int v21; // r10
  int v22; // r0
  unsigned int *v23; // r4
  unsigned int v24; // r1
  unsigned int v25; // r2
  unsigned int v26; // r3
  int v27; // r4
  unsigned int *v28; // r1 OVERLAPPED
  unsigned int **v29; // r2 OVERLAPPED
  unsigned int *v30; // r2
  unsigned int v31; // r4
  unsigned int v32; // r1

  v3 = (unsigned __int8 *)(a1 + 126);
  v6 = KeAbPreAcquire((unsigned int)(a1 + 126), 0, 0);
  v7 = v6;
  do
    v8 = __ldrex(v3);
  while ( __strex(v8 | 1, v3) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v3, v6, (unsigned int)v3);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v9 = *a2;
  if ( (unsigned int)(v9 + a1[63]) > a1[1] )
    goto LABEL_29;
  v10 = (unsigned int *)a1[158];
  v11 = a1 + 158;
  if ( v10 == a1 + 158 )
  {
LABEL_12:
    v12 = (unsigned int *)ExAllocatePoolWithTag(1, v9 + 34, 1651995717);
    v13 = v12;
    if ( !v12 )
      goto LABEL_29;
    v12[3] = 1;
    v14 = a3[1];
    v15 = a3[2];
    v16 = a3[3];
    v12[4] = *a3;
    v12[5] = v14;
    v12[6] = v15;
    v12[7] = v16;
    v17 = v12 + 8;
    v12[2] = *a2 + 2;
    memmove((int)(v12 + 8), *((_DWORD *)a2 + 1), *a2);
    *((_WORD *)v17 + (*a2 >> 1)) = 0;
    a1[63] += v13[2] + 16;
LABEL_14:
    v18 = *v11;
    *v13 = *v11;
    v13[1] = (unsigned int)v11;
    if ( *(unsigned int **)(v18 + 4) != v11 )
      __fastfail(3u);
    *(_DWORD *)(v18 + 4) = v13;
    *v11 = (unsigned int)v13;
    __dmb(0xBu);
    v30 = a1 + 153;
    do
      v31 = __ldrex(v30);
    while ( __strex(v31 | 0x80, v30) );
    __dmb(0xBu);
    goto LABEL_29;
  }
  while ( v10[2] != v9 + 2 || RtlCompareMemory((unsigned __int8 *)&v10[4 * v10[3] + 4], *((_DWORD *)a2 + 1), v9) != v9 )
  {
    v10 = (unsigned int *)*v10;
    if ( v10 == v11 )
      goto LABEL_12;
  }
  v19 = v10[3];
  v20 = 0;
  if ( !v19 )
  {
LABEL_20:
    if ( v19 >= 0x10 )
      goto LABEL_29;
    v22 = ExAllocatePoolWithTag(1, v10[2] + 16 * (v19 + 2), 1651995717);
    v13 = (unsigned int *)v22;
    if ( !v22 )
      goto LABEL_29;
    memmove(v22 + 16, (int)(v10 + 4), 16 * v10[3]);
    v23 = &v13[4 * v10[3] + 4];
    v24 = a3[1];
    v25 = a3[2];
    v26 = a3[3];
    *v23 = *a3;
    v23[1] = v24;
    v23[2] = v25;
    v23[3] = v26;
    v27 = v10[3] + 1;
    v13[3] = v27;
    v13[2] = v10[2];
    memmove((int)&v13[4 * v27 + 4], (int)&v10[4 * v10[3] + 4], v10[2]);
    *(_QWORD *)&v28 = *(_QWORD *)v10;
    if ( *(unsigned int **)(*v10 + 4) != v10 || *v29 != v10 )
      __fastfail(3u);
    *v29 = v28;
    v28[1] = (unsigned int)v29;
    ExFreePoolWithTag((unsigned int)v10);
    goto LABEL_14;
  }
  v21 = (unsigned int)(v10 + 4);
  while ( memcmp((unsigned int)a3, v21, 16) )
  {
    ++v20;
    v21 += 16;
    if ( v20 >= v19 )
      goto LABEL_20;
  }
LABEL_29:
  __dmb(0xBu);
  do
    v32 = __ldrex((unsigned int *)v3);
  while ( __strex(v32 - 1, (unsigned int *)v3) );
  if ( (v32 & 2) != 0 && (v32 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v3);
  return KeAbPostRelease((unsigned int)v3);
}
