// PfpRpFileKeyUpdate 
 
int __fastcall PfpRpFileKeyUpdate(_DWORD *a1, int a2, int a3)
{
  _DWORD *v6; // r6
  _DWORD *v7; // r7
  int v8; // r9
  int v9; // r5
  unsigned int *v10; // r10
  unsigned int v11; // r0
  unsigned int v12; // r1
  unsigned int v13; // r8
  int v14; // r0
  unsigned __int16 *v15; // r8
  int v16; // r3
  int v17; // r5
  unsigned int v18; // r3
  unsigned int v19; // r10
  unsigned int v20; // t1
  unsigned int v21; // r2
  int v22; // r8
  unsigned __int8 *v23; // r0
  unsigned int v24; // r2
  int v25; // r9
  unsigned int v26; // r2
  int v27; // r0
  _DWORD *i; // r2
  _DWORD *v29; // r1
  unsigned int v30; // r2
  int v31; // r1
  int v32; // r3
  int v33; // r2
  unsigned int v34; // r3
  int v35; // r1
  int v36; // r2
  unsigned int *v37; // r4
  unsigned int v38; // r1
  int v39; // r0
  unsigned int v40; // r1
  __int16 v41; // r3
  unsigned int v42; // r4
  unsigned int v43; // r1
  unsigned int v44; // r0
  int v46; // [sp+0h] [bp-38h] BYREF
  int v47; // [sp+4h] [bp-34h]
  unsigned int v48; // [sp+8h] [bp-30h] BYREF
  int v49; // [sp+Ch] [bp-2Ch]
  int v50; // [sp+10h] [bp-28h]
  unsigned int *v51; // [sp+14h] [bp-24h]

  v47 = 0;
  v48 = 0;
  v49 = *(_DWORD *)(a2 + 8);
  v50 = a3;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  if ( (a1[24] & 1) == 0 )
    return -1073741696;
  v10 = a1 + 20;
  __pld(a1 + 20);
  v11 = a1[20] & 0xFFFFFFFE;
  do
    v12 = __ldrex(v10);
  while ( v12 == v11 && __strex(v11 + 2, v10) );
  __dmb(0xBu);
  if ( v12 != v11 && !ExfAcquireRundownProtection(a1 + 20) )
    return -1073741696;
  if ( a3 )
  {
    v7 = (_DWORD *)ExAllocatePoolWithTag(1, 12, 1262904912);
    if ( !v7 )
    {
      v9 = -1073741670;
      v13 = 0;
      goto LABEL_66;
    }
    v14 = a1[1] >> 5;
    if ( *a1 >= (unsigned int)(2 * v14) && RtlULongLongToULong(2 * v14, 0, &v46) >= 0 )
    {
      v8 = v46;
      if ( !v46 )
        v8 = 64;
      v47 = ExAllocatePoolWithTag(1, 4 * v8, 1212573264);
      v48 = v47;
      if ( !v47 )
        v8 = 0;
    }
    v15 = *(unsigned __int16 **)(a2 + 12);
    v16 = *(unsigned __int16 *)(a2 + 18);
    v17 = 314159;
    v18 = (unsigned int)&v15[v16];
    v46 = v18;
    if ( (unsigned int)v15 < v18 )
    {
      v19 = v18;
      do
      {
        v20 = *v15++;
        LOWORD(v46) = RtlUpcaseUnicodeChar(v20);
        v17 = 37 * (37 * v17 + (unsigned __int8)v46) + BYTE1(v46);
      }
      while ( (unsigned int)v15 < v19 );
      v10 = a1 + 20;
    }
    if ( !v17 )
    {
      v9 = -1073741747;
      v13 = v47;
      goto LABEL_66;
    }
  }
  else
  {
    v17 = 0;
  }
  v51 = a1 + 7;
  v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v21 + 308);
  v22 = KeAbPreAcquire((unsigned int)(a1 + 7), 0, 0);
  v23 = (unsigned __int8 *)(a1 + 7);
  do
    v24 = __ldrex(v23);
  while ( __strex(v24 | 1, v23) );
  __dmb(0xBu);
  if ( (v24 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v23, v22, (unsigned int)(a1 + 7));
  if ( v22 )
    *(_BYTE *)(v22 + 14) |= 1u;
  if ( !v50 )
  {
    v25 = v49;
    while ( *a1 )
    {
      v26 = a1[1];
      v27 = -1 << (v26 & 0x1F);
      v46 = v27 & v25;
      for ( i = (_DWORD *)(a1[2]
                         + 4
                         * ((37
                           * (37
                            * (37 * ((unsigned __int8)(v27 & v25) + 11623883)
                             + (unsigned __int8)((unsigned __int16)(v27 & v25) >> 8))
                            + (unsigned __int8)((v27 & (unsigned int)v25) >> 16))
                           + ((v27 & (unsigned int)v25) >> 24)) & ((v26 >> 5) - 1))); ; i = (_DWORD *)*i )
      {
        v29 = (_DWORD *)*i;
        if ( (*i & 1) != 0 )
          break;
        if ( (v29[1] & v27) == (v27 & v25) )
        {
          *i = *v29;
          --*a1;
          *v29 |= 0x80000002;
          goto LABEL_39;
        }
      }
      v29 = 0;
LABEL_39:
      if ( !v29 )
        break;
      if ( (_DWORD *)a1[3] == v29 )
        a1[3] = a1 + 4;
      *v29 = v6;
      v6 = v29;
    }
    goto LABEL_51;
  }
  v30 = a1[1];
  v31 = -1 << (v30 & 0x1F);
  v32 = v49;
  v46 = v31 & v49;
  if ( v30 >> 5 )
  {
    v33 = a1[2]
        + 4
        * ((37 * (37 * (37 * ((unsigned __int8)v46 + 11623883) + BYTE1(v46)) + BYTE2(v46)) + HIBYTE(v46)) & ((v30 >> 5) - 1));
    while ( 1 )
    {
      v33 = *(_DWORD *)v33;
      if ( (v33 & 1) != 0 )
        break;
      if ( (v31 & v49) == (*(_DWORD *)(v33 + 4) & v31) )
        goto LABEL_49;
    }
    v33 = 0;
LABEL_49:
    if ( v33 )
    {
      *(_DWORD *)(v33 + 8) = v17;
LABEL_51:
      v13 = v47;
      goto LABEL_56;
    }
    v32 = v49;
  }
  *v7 = 0;
  v7[1] = 0;
  v7[1] = v32;
  v7[2] = 0;
  v7[2] = v17;
  if ( !PfpRpRehashIfNeeded(a1, &v48, v8) )
  {
    v9 = -1073741670;
    v13 = v48;
    goto LABEL_57;
  }
  v34 = a1[1];
  v13 = v48;
  v47 = v7[1] & (-1 << (v34 & 0x1F));
  v35 = ((v34 >> 5) - 1) & (37 * (37 * (37 * ((unsigned __int8)v47 + 11623883) + BYTE1(v47)) + BYTE2(v47)) + HIBYTE(v47));
  v36 = a1[2];
  *v7 = *(_DWORD *)(v36 + 4 * v35);
  *(_DWORD *)(v36 + 4 * v35) = v7;
  ++*a1;
  v7 = 0;
LABEL_56:
  v9 = 0;
LABEL_57:
  __dmb(0xBu);
  v37 = v51;
  do
    v38 = __ldrex(v37);
  while ( __strex(v38 - 1, v37) );
  if ( (v38 & 2) != 0 && (v38 & 4) == 0 )
    ExfTryToWakePushLock(v37);
  v39 = KeAbPostRelease((unsigned int)v37);
  v40 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v41 = *(_WORD *)(v40 + 0x134) + 1;
  *(_WORD *)(v40 + 308) = v41;
  if ( !v41 && *(_DWORD *)(v40 + 100) != v40 + 100 && !*(_WORD *)(v40 + 310) )
    KiCheckForKernelApcDelivery(v39);
LABEL_66:
  __pld(v10);
  v42 = *v10 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v43 = __ldrex(v10);
  while ( v43 == v42 && __strex(v42 - 2, v10) );
  if ( v43 != v42 )
    ExfReleaseRundownProtection((unsigned __int8 *)v10);
  if ( !v7 )
    goto LABEL_76;
  v44 = (unsigned int)v7;
  while ( 1 )
  {
    ExFreePoolWithTag(v44);
LABEL_76:
    if ( !v6 )
      break;
    v44 = (unsigned int)v6;
    v6 = (_DWORD *)*v6;
  }
  if ( v13 )
    ExFreePoolWithTag(v13);
  return v9;
}
