// PsImpersonateClient 
 
int __fastcall PsImpersonateClient(_DWORD *a1, int a2, int a3, unsigned int a4, int a5)
{
  int v6; // r5
  int v7; // r6
  int v8; // r7
  int v9; // r8
  unsigned int *v11; // r8
  int v12; // r5
  int v13; // r9
  unsigned int v14; // r6
  unsigned __int8 *v15; // r10
  int v16; // r0
  unsigned int v17; // r2
  int result; // r0
  unsigned int v19; // r1
  unsigned int v20; // r1
  int v21; // r0
  __int16 v22; // r3
  _DWORD *v23; // r1
  int v24; // r0
  unsigned int v25; // r9
  unsigned int v26; // r7
  __int16 v27; // r1
  unsigned __int8 *v28; // r9
  int v29; // r0
  int v30; // r5
  unsigned int v31; // r2
  unsigned int *v32; // r0
  unsigned int v33; // r1
  unsigned int v34; // r3
  unsigned int v35; // r1
  unsigned int *v36; // r6
  unsigned int v37; // r1
  int v38; // r0
  __int16 v39; // r3
  unsigned int v40; // r1
  int v41; // r3
  int v42; // r2
  int v43; // r5
  int v44; // r0
  int v45; // r2
  int v46; // r6
  char v47[4]; // [sp+8h] [bp-30h] BYREF
  int v48; // [sp+Ch] [bp-2Ch]
  int v49; // [sp+10h] [bp-28h] BYREF
  int v50; // [sp+14h] [bp-24h] BYREF
  unsigned int v51; // [sp+18h] [bp-20h]

  v51 = a4;
  v6 = a2;
  v7 = 0;
  v8 = a1[84];
  v49 = 0;
  v50 = 0;
  v9 = 0;
  v47[0] = 0;
  if ( !a2 )
  {
    v11 = a1 + 240;
    v12 = 0;
    v13 = 0;
    if ( (a1[240] & 8) == 0 )
      return 0;
    v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v14 + 0x134);
    v15 = (unsigned __int8 *)(a1 + 236);
    v16 = KeAbPreAcquire((unsigned int)(a1 + 236), 0, 0);
    do
      v17 = __ldrex(v15);
    while ( __strex(v17 | 1, v15) );
    __dmb(0xBu);
    if ( (v17 & 1) != 0 )
      return sub_800ED4(v16);
    if ( v16 )
      *(_BYTE *)(v16 + 14) |= 1u;
    if ( (*v11 & 8) != 0 )
    {
      v13 = a1[263];
      v12 = a1[226] & 0xFFFFFFF8;
      a1[263] = 0;
      __dmb(0xBu);
      do
        v19 = __ldrex(v11);
      while ( __strex(v19 & 0xFFFFFFF7, v11) );
      __dmb(0xBu);
    }
    __dmb(0xBu);
    do
      v20 = __ldrex((unsigned int *)v15);
    while ( __strex(v20 - 1, (unsigned int *)v15) );
    if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v15);
    v21 = KeAbPostRelease((unsigned int)v15);
    v22 = *(_WORD *)(v14 + 308) + 1;
    *(_WORD *)(v14 + 308) = v22;
    if ( !v22 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
      KiCheckForKernelApcDelivery(v21);
    v23 = (_DWORD *)v14;
LABEL_42:
    PspWriteTebImpersonationInfo(a1, v23);
    if ( v12 )
      ObfDereferenceObject(v12);
    if ( v13 )
      ObfDereferenceObject(v13);
    return 0;
  }
  v24 = PsReferencePrimaryToken(v8);
  v25 = v24;
  if ( !v24 )
  {
    v48 = a5;
LABEL_23:
    ObfReferenceObject(v6);
LABEL_24:
    v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v27 = *(_WORD *)(v26 + 0x134);
    v51 = v6 & 0xFFFFFFF8 | (4 * (v51 & 1)) | v48 & 3;
    *(_WORD *)(v26 + 308) = v27 - 1;
    v28 = (unsigned __int8 *)(a1 + 236);
    v29 = KeAbPreAcquire((unsigned int)(a1 + 236), 0, 0);
    v30 = v29;
    do
      v31 = __ldrex(v28);
    while ( __strex(v31 | 1, v28) );
    __dmb(0xBu);
    if ( (v31 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(a1 + 236, v29, (unsigned int)(a1 + 236));
    if ( v30 )
      *(_BYTE *)(v30 + 14) |= 1u;
    v32 = a1 + 240;
    if ( (a1[240] & 8) != 0 )
    {
      v13 = a1[263];
      v12 = a1[226] & 0xFFFFFFF8;
      a1[263] = 0;
    }
    else
    {
      v12 = 0;
      v13 = 0;
      __dmb(0xBu);
      do
        v33 = __ldrex(v32);
      while ( __strex(v33 | 8, v32) );
      __dmb(0xBu);
    }
    v34 = v51;
    a1[263] = v7;
    a1[226] = v34;
    __dmb(0xBu);
    if ( a3 )
    {
      do
        v35 = __ldrex(v32);
      while ( __strex(v35 | 0x100, v32) );
    }
    else
    {
      do
        v40 = __ldrex(v32);
      while ( __strex(v40 & 0xFFFFFEFF, v32) );
    }
    __dmb(0xBu);
    __dmb(0xBu);
    v36 = a1 + 236;
    do
      v37 = __ldrex(v36);
    while ( __strex(v37 - 1, v36) );
    if ( (v37 & 2) != 0 && (v37 & 4) == 0 )
      ExfTryToWakePushLock(a1 + 236);
    v38 = KeAbPostRelease((unsigned int)(a1 + 236));
    v39 = *(_WORD *)(v26 + 308) + 1;
    *(_WORD *)(v26 + 308) = v39;
    if ( !v39 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
      KiCheckForKernelApcDelivery(v38);
    v23 = (_DWORD *)v26;
    goto LABEL_42;
  }
  v48 = a5;
  if ( SeTokenCanImpersonate(v24, (_DWORD *)v6, a5, v47) < 0 )
  {
    v41 = *(_DWORD *)(v6 + 168);
    v42 = 1;
    v48 = 1;
    if ( v41 == 2 && *(int *)(v6 + 172) < 1 )
    {
      v42 = *(_DWORD *)(v6 + 172);
      v48 = v42;
    }
    v43 = SeCopyClientToken(v6, v42, v42, 0, 0, &v50);
    if ( v43 >= 0 )
    {
      v6 = v50;
      v9 = 1;
      goto LABEL_22;
    }
    ObFastDereferenceObject((_DWORD *)(v8 + 244), v25);
    result = v43;
  }
  else
  {
    if ( !v47[0] )
      goto LABEL_22;
    v44 = SeQueryTokenTrustSid(v25);
    v46 = SeCopyClientToken(v6, a5, v45, 1, v44, &v49);
    if ( v46 >= 0 )
    {
      if ( a3 )
      {
        v7 = v49;
        SeSetTokenTrustLink(v49, v6);
      }
      else
      {
        v6 = v49;
        v7 = 0;
        v9 = 1;
      }
LABEL_22:
      ObFastDereferenceObject((_DWORD *)(v8 + 244), v25);
      if ( v9 )
        goto LABEL_24;
      goto LABEL_23;
    }
    ObFastDereferenceObject((_DWORD *)(v8 + 244), v25);
    result = v46;
  }
  return result;
}
