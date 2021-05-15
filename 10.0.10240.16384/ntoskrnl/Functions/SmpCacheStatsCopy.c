// SmpCacheStatsCopy 
 
_DWORD *__fastcall SmpCacheStatsCopy(int a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // r4
  _DWORD *v4; // r10
  _DWORD *v5; // r9
  _DWORD *v6; // r2
  _DWORD *v7; // r8
  int v8; // r4
  int v9; // r5
  int v10; // r6
  _DWORD *v11; // lr
  int v12; // r1
  int v13; // r2
  int v14; // r3
  _DWORD *v15; // r5
  int v16; // r1
  int v17; // r2
  int v18; // r3
  _DWORD *v19; // r5
  unsigned int v20; // r8
  unsigned int v21; // r5
  char *v22; // r7
  int v23; // r9
  int *v24; // r4
  unsigned int *v25; // r6
  unsigned int v26; // r0
  unsigned int v27; // r1
  int v28; // r3
  unsigned int v29; // r4
  unsigned int v30; // r1
  unsigned int *v31; // r4
  unsigned int v32; // r2
  int v33; // r0
  int v34; // r5
  unsigned int v35; // r2
  unsigned int v36; // r2
  _DWORD *result; // r0
  unsigned int v38; // r1
  __int16 v39; // r3
  unsigned int i; // r4
  unsigned int j; // r5
  unsigned int v42; // r4
  unsigned int v43; // r1
  unsigned int v44; // [sp+0h] [bp-650h]
  int v47; // [sp+Ch] [bp-644h]
  _DWORD *v49; // [sp+14h] [bp-63Ch]
  int v50[16]; // [sp+5D0h] [bp-80h] BYREF
  char v51[64]; // [sp+610h] [bp-40h] BYREF

  v3 = a2;
  v4 = a3;
  memset(a2, 0, 896);
  v47 = 8;
  v5 = v4;
  v6 = v4;
  v7 = v3;
  do
  {
    *v7 = *v6;
    v7 += 26;
    v8 = v5[9];
    v9 = v5[10];
    v10 = v5[11];
    v11 = v7 - 24;
    v49 = v6 + 1;
    *v11 = v5[8];
    v11[1] = v8;
    v11[2] = v9;
    v11[3] = v10;
    v12 = v5[41];
    v13 = v5[42];
    v14 = v5[43];
    v15 = v7 - 16;
    *v15 = v5[40];
    v15[1] = v12;
    v15[2] = v13;
    v15[3] = v14;
    v16 = v5[73];
    v17 = v5[74];
    v18 = v5[75];
    v19 = v7 - 8;
    *v19 = v5[72];
    v19[1] = v16;
    v19[2] = v17;
    v19[3] = v18;
    v6 = v49;
    v5 += 4;
    --v47;
  }
  while ( v47 );
  v20 = 0;
  v21 = 0;
  v22 = v51;
  v23 = a1;
  do
  {
    v44 = v21 | (32 * (*(_WORD *)(v23 + 12) & 0x7FF));
    v24 = (int *)(a1 + 96 * (v44 & 0x1F));
    v25 = (unsigned int *)(v24 + 1);
    __pld(v24 + 1);
    v26 = v24[1] & 0xFFFFFFFE;
    do
      v27 = __ldrex(v25);
    while ( v27 == v26 && __strex(v26 + 2, v25) );
    __dmb(0xBu);
    if ( v27 == v26 || ExfAcquireRundownProtection(v24 + 1) )
    {
      if ( (v24[3] & 0x7FF) == v44 >> 5 )
      {
        v28 = *v24;
        goto LABEL_17;
      }
      __pld(v25);
      v29 = *v25 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v30 = __ldrex(v25);
      while ( v30 == v29 && __strex(v29 - 2, v25) );
      if ( v30 != v29 )
        ExfReleaseRundownProtection((unsigned __int8 *)v25);
    }
    v28 = 0;
LABEL_17:
    if ( v28 )
    {
      *v22++ = v21;
      ++v20;
    }
    ++v21;
    v23 += 96;
  }
  while ( v21 < 0x20 );
  v31 = a3 + 104;
  v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v32 + 308);
  v33 = KeAbPreAcquire((unsigned int)(a3 + 104), 0, 0);
  v34 = v33;
  do
    v35 = __ldrex(v31);
  while ( !v35 && __strex(0x11u, v31) );
  __dmb(0xBu);
  if ( v35 )
    ExfAcquirePushLockSharedEx(v31, v33, (unsigned int)v31);
  if ( v34 )
    *(_BYTE *)(v34 + 14) |= 1u;
  memmove((int)(a2 + 208), (int)(a3 + 105), 0x40u);
  __dmb(0xBu);
  do
    v36 = __ldrex(v31);
  while ( v36 == 17 && __strex(0, v31) );
  if ( v36 != 17 )
    ExfReleasePushLockShared(v31);
  result = (_DWORD *)KeAbPostRelease((unsigned int)v31);
  v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v39 = *(_WORD *)(v38 + 0x134) + 1;
  *(_WORD *)(v38 + 308) = v39;
  if ( !v39 && *(_DWORD *)(v38 + 100) != v38 + 100 && !*(_WORD *)(v38 + 310) )
    result = (_DWORD *)KiCheckForKernelApcDelivery((int)result);
  for ( i = 0; i < v20; ++i )
  {
    SMKM_STORE<SM_TRAITS>::SmStGetStoreStats();
    result = StLcBucketsCombine(a2 + 208, v50);
  }
  for ( j = 0; j < v20; ++j )
  {
    result = (_DWORD *)(a1 + 96 * (v51[j] & 0x1F) + 4);
    __pld(result);
    v42 = *result & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v43 = __ldrex(result);
    while ( v43 == v42 && __strex(v42 - 2, result) );
    if ( v43 != v42 )
      result = ExfReleaseRundownProtection((unsigned __int8 *)result);
  }
  return result;
}
