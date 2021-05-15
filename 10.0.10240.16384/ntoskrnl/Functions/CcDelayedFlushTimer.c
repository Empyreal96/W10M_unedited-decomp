// CcDelayedFlushTimer 
 
int __fastcall CcDelayedFlushTimer(int a1, int a2)
{
  int v2; // r8
  int result; // r0
  int v4; // r2
  char *v5; // r10
  unsigned int v6; // r6
  int v7; // r0
  int v8; // r1
  unsigned int v9; // lr
  unsigned __int8 *v10; // r9
  unsigned __int8 *v11; // r7
  char *v12; // r3
  char v13; // r3
  char v14; // r7
  char v15; // r0
  char v16; // r8
  unsigned int v17; // r10
  unsigned int v18; // r4
  int v19; // r3
  unsigned int v20; // r5
  int v21; // r0
  int v22; // r3
  char v23; // r5
  char v24; // r8
  char v25; // r10
  char v26; // r9
  int v27; // t1
  unsigned int v28; // r1
  int v29; // r3
  char *i; // r3
  unsigned int v31; // r6
  char v32; // r1
  unsigned int v33; // r0
  __int64 v34; // r4
  unsigned __int64 v35; // r6
  int v36; // r0
  __int64 v37; // r2
  __int64 v38; // kr10_8
  unsigned int v39; // r0
  __int64 v40; // r0
  unsigned int v41; // r3
  unsigned int v42; // r2
  int *v43; // r4
  _DWORD *v44; // r1
  int v45; // r3
  __int64 v46; // r0
  int v47; // r5
  __int64 v48; // r0
  int v49; // r0
  unsigned __int8 *v51; // [sp+18h] [bp-38h]
  char *v52; // [sp+20h] [bp-30h]
  char v53; // [sp+28h] [bp-28h]
  int v54[8]; // [sp+30h] [bp-20h] BYREF

  v2 = a2;
  if ( *(_DWORD *)(a2 + 116) )
    return ExQueueWorkItem((_DWORD *)(a2 + 120), 1);
  v4 = *(_DWORD *)(a2 + 84);
  v5 = *(char **)(a2 + 80);
  v6 = *(_DWORD *)(a2 + 88);
  v7 = *(unsigned __int8 *)(a2 + 112);
  v9 = *(_DWORD *)(a2 + 108);
  v8 = *(_DWORD *)(a2 + 104);
  v52 = *(char **)(v2 + 80);
  v10 = (unsigned __int8 *)((*(_DWORD *)v5 & 0xFFFFFFFE) + v4);
  v11 = v10;
  v51 = v10;
  v54[0] = v7;
  v12 = (char *)v10;
  if ( v10 < &v10[v6] )
  {
    do
    {
      __pld(v12);
      v12 += 128;
    }
    while ( v12 < (char *)&v10[v6] );
  }
  v13 = v7;
  v53 = v7;
  if ( v6 >= 8 )
  {
    v14 = v7 & 0x3F;
    v15 = 32 - (v7 & 0x3F);
    v16 = 64 - v14;
    v17 = v6 >> 3;
    do
    {
      v6 -= 8;
      v18 = v8 ^ *(_DWORD *)v10;
      v19 = *((_DWORD *)v10 + 1);
      v10 += 8;
      v20 = v9 ^ v19;
      v21 = ((v9 ^ v19) << v14) | (v18 >> v15) | (v18 << (v14 - 32));
      v22 = __PAIR64__(v9 ^ v19, v18) >> v16;
      v9 = v21 | (v20 >> v16);
      v8 = (v18 << v14) | v22;
      v15 = 32 - v14;
      --v17;
    }
    while ( v17 );
    v2 = a2;
    v5 = v52;
    v13 = v53;
    v11 = v10;
    v10 = v51;
  }
  if ( v6 )
  {
    v23 = v13 & 0x3F;
    v24 = 32 - (v13 & 0x3F);
    v25 = (v13 & 0x3F) - 32;
    v26 = 64 - (v13 & 0x3F);
    do
    {
      v27 = *v11++;
      v28 = v8 ^ v27;
      v29 = __PAIR64__(v9, v28) >> v26;
      v9 = (v9 << v23) | (v28 >> v24) | (v28 << v25) | (v9 >> v26);
      v8 = (v28 << v23) | v29;
      --v6;
    }
    while ( v6 );
    v2 = a2;
    v10 = v51;
    v5 = v52;
  }
  for ( i = v5; i < v5 + 8; i += 128 )
    __pld(i);
  v31 = v8 ^ *(_DWORD *)v5;
  v32 = 64 - (v54[0] & 0x3F);
  v33 = v9 ^ *((_DWORD *)v5 + 1);
  LODWORD(v34) = (v31 >> v32) | (v33 << ((v54[0] & 0x3F) - 32)) | (v33 >> (32 - (v54[0] & 0x3F)));
  HIDWORD(v34) = v33 >> v32;
  v35 = v34 | (__PAIR64__(v33, v31) << (v54[0] & 0x3F));
  v36 = ExGenRandom(1);
  _rt_sdiv64(100000000i64, (unsigned int)v36);
  v38 = -6000000000i64 - v37;
  v39 = ExGenRandom(1);
  HIDWORD(v40) = v39 / 0xEA60;
  v41 = v39 % 0xEA60;
  LODWORD(v40) = v2 + 32;
  result = KeSetCoalescableTimer(v40, v38, 0, v41, v2);
  if ( v35 != *(_QWORD *)(v2 + 96) )
  {
    __disable_irq();
    v42 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v43 = *(int **)(v42 + 3136);
    v44 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v45 = *(unsigned __int8 *)(v42 + 3162);
    __dmb(0xBu);
    if ( !v45 || v54 > v43 || v54 < v43 - 3072 )
      v43 = (int *)v44[8];
    v44[214] = 0;
    v44[231] = 0;
    ExTryAcquireSpinLockExclusiveAtDpcLevel((unsigned int *)&PsLoadedModuleSpinLock);
    v46 = FsRtlRemovePerStreamContextEx(3, 0, 27279, 0);
    if ( v46 )
    {
      if ( v46 == 1 )
        v47 = __ROR4__(34340864, 17);
      else
        v47 = __ROR4__(8585216, 15);
    }
    else
    {
      v47 = __ROR4__(137363456, 19);
    }
    FsRtlRemovePerStreamContextEx(3, 0, 27276, 0);
    v48 = FsRtlRemovePerStreamContextEx(3, 0, 27275, 0);
    if ( v48 )
    {
      if ( v48 == 1 )
        v49 = __ROR4__(555745280, 21);
      else
        v49 = __ROR4__(542720, 11);
    }
    else
    {
      v49 = __ROR4__(33920, 7);
    }
    CcUnmapBehindLazyReader(v49, -1849117464, 0, (int)v10, v47, (int (__fastcall *)(int))KeBugCheckEx, v43);
    __debugbreak();
  }
  return result;
}
