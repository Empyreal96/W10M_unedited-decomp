// sub_6A2000 
 
int __fastcall sub_6A2000(int a1)
{
  int v1; // r2
  _DWORD *v2; // r10
  unsigned int v3; // r6
  int v4; // r8
  int v5; // r0
  unsigned __int8 *v6; // r9
  unsigned __int8 *v7; // r7
  int v8; // r1
  unsigned int v9; // lr
  char *v10; // r3
  char v11; // r3
  char v12; // r7
  char v13; // r0
  char v14; // r8
  unsigned int v15; // r10
  unsigned int v16; // r4
  int v17; // r3
  unsigned int v18; // r5
  int v19; // r0
  int v20; // r3
  char v21; // r5
  char v22; // r8
  char v23; // r10
  char v24; // r9
  int v25; // t1
  unsigned int v26; // r1
  int v27; // r3
  char *v28; // r3
  unsigned int v29; // r6
  char v30; // r1
  unsigned int v31; // r0
  __int64 v32; // r4
  unsigned __int64 v33; // r6
  int v34; // r0
  __int64 v35; // r2
  __int64 v36; // kr10_8
  unsigned int v37; // r0
  __int64 v38; // r0
  unsigned int v39; // r3
  int result; // r0
  unsigned int v41; // r2
  int *v42; // r4
  _DWORD *v43; // r1
  int v44; // r3
  __int64 v45; // r0
  int v46; // r5
  __int64 v47; // r0
  int v48; // r0
  unsigned __int8 *v50; // [sp+18h] [bp-38h]
  _DWORD *v51; // [sp+20h] [bp-30h]
  char v52; // [sp+28h] [bp-28h]
  int v53[8]; // [sp+30h] [bp-20h] BYREF

  v1 = *(_DWORD *)(a1 + 84);
  v2 = *(_DWORD **)(a1 + 80);
  v3 = *(_DWORD *)(a1 + 88);
  v4 = a1;
  v5 = *(unsigned __int8 *)(a1 + 112);
  v6 = (unsigned __int8 *)((*v2 & 0xFFFFFFFE) + v1);
  v7 = v6;
  v9 = *(_DWORD *)(v4 + 108);
  v8 = *(_DWORD *)(v4 + 104);
  v50 = v6;
  v51 = v2;
  v53[0] = v5;
  v10 = (char *)v6;
  if ( v6 < &v6[v3] )
  {
    do
    {
      __pld(v10);
      v10 += 128;
    }
    while ( v10 < (char *)&v6[v3] );
  }
  v11 = v5;
  v52 = v5;
  if ( v3 >= 8 )
  {
    v12 = v5 & 0x3F;
    v13 = 32 - (v5 & 0x3F);
    v14 = 64 - v12;
    v15 = v3 >> 3;
    do
    {
      v3 -= 8;
      v16 = *(_DWORD *)v6 ^ v8;
      v17 = *((_DWORD *)v6 + 1);
      v6 += 8;
      v18 = v17 ^ v9;
      v19 = ((v17 ^ v9) << v12) | (v16 >> v13) | (v16 << (v12 - 32));
      v20 = __PAIR64__(v17 ^ v9, v16) >> v14;
      v9 = v19 | (v18 >> v14);
      v8 = (v16 << v12) | v20;
      v13 = 32 - v12;
      --v15;
    }
    while ( v15 );
    v4 = a1;
    v2 = v51;
    v11 = v52;
    v7 = v6;
    v6 = v50;
  }
  if ( v3 )
  {
    v21 = v11 & 0x3F;
    v22 = 32 - (v11 & 0x3F);
    v23 = (v11 & 0x3F) - 32;
    v24 = 64 - (v11 & 0x3F);
    do
    {
      v25 = *v7++;
      v26 = v8 ^ v25;
      v27 = __PAIR64__(v9, v26) >> v24;
      v9 = (v9 << v21) | (v26 >> v22) | (v26 << v23) | (v9 >> v24);
      v8 = (v26 << v21) | v27;
      --v3;
    }
    while ( v3 );
    v4 = a1;
    v6 = v50;
    v2 = v51;
  }
  v28 = (char *)v2;
  if ( v2 < v2 + 2 )
  {
    do
    {
      __pld(v28);
      v28 += 128;
    }
    while ( v28 < (char *)v2 + 8 );
  }
  v29 = *v2 ^ v8;
  v30 = 64 - (v53[0] & 0x3F);
  v31 = v2[1] ^ v9;
  LODWORD(v32) = (v29 >> v30) | (v31 << ((v53[0] & 0x3F) - 32)) | (v31 >> (32 - (v53[0] & 0x3F)));
  HIDWORD(v32) = v31 >> v30;
  v33 = v32 | (__PAIR64__(v31, v29) << (v53[0] & 0x3F));
  v34 = ExGenRandom(1);
  _rt_sdiv64(100000000i64, (unsigned int)v34);
  v36 = -6000000000i64 - v35;
  v37 = ExGenRandom(1);
  HIDWORD(v38) = v37 / 0xEA60;
  v39 = v37 % 0xEA60;
  LODWORD(v38) = v4 + 32;
  result = KeSetCoalescableTimer(v38, v36, 0, v39, v4);
  if ( v33 != *(_QWORD *)(v4 + 96) )
  {
    __disable_irq();
    v41 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v42 = *(int **)(v41 + 3136);
    v43 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v44 = *(unsigned __int8 *)(v41 + 3162);
    __dmb(0xBu);
    if ( !v44 || v53 > v42 || v53 < v42 - 3072 )
      v42 = (int *)v43[8];
    v43[214] = 0;
    v43[231] = 0;
    ExTryAcquireSpinLockExclusiveAtDpcLevel((unsigned int *)&PsLoadedModuleSpinLock);
    v45 = FsRtlRemovePerStreamContextEx(3i64, 0x6A8Fui64);
    if ( v45 )
    {
      if ( v45 == 1 )
        v46 = __ROR4__(34340864, 17);
      else
        v46 = __ROR4__(8585216, 15);
    }
    else
    {
      v46 = __ROR4__(137363456, 19);
    }
    FsRtlRemovePerStreamContextEx(3i64, 0x6A8Cui64);
    v47 = FsRtlRemovePerStreamContextEx(3i64, 0x6A8Bui64);
    if ( v47 )
    {
      if ( v47 == 1 )
        v48 = __ROR4__(555745280, 21);
      else
        v48 = __ROR4__(542720, 11);
    }
    else
    {
      v48 = __ROR4__(33920, 7);
    }
    CcUnmapBehindLazyReader(v48, -1849117464, 0, (int)v6, v46, (int (__fastcall *)(int))KeBugCheckEx, v42);
    __debugbreak();
  }
  return result;
}
