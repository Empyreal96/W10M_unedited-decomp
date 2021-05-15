// AlpcpCreateClientPort 
 
int __fastcall AlpcpCreateClientPort(int a1, _DWORD *a2, int a3, int a4, int a5, int a6, _DWORD *a7, int a8, int a9, int a10, unsigned __int8 a11)
{
  _BYTE *v11; // r6
  int v12; // r0
  int v13; // r4
  _DWORD *v14; // r7
  int v15; // r2
  int v17; // r4
  _BYTE *v18; // r5
  BOOL v19; // r9
  _DWORD *v20; // r0
  _DWORD *v21; // r8
  unsigned __int8 *v22; // r6
  int v23; // r0
  int v24; // r4
  unsigned int v25; // r2
  unsigned int v26; // r1
  unsigned int *v27; // r4
  unsigned int v28; // r1
  int v29; // r6
  char v30; // r2
  int v31; // r8
  int v32; // r3
  unsigned int *v33; // r7
  unsigned int v34; // r1
  unsigned int *v35; // r2
  unsigned int v36; // r4
  int v37; // r4
  _DWORD *v38; // r2
  int v39; // r6
  unsigned __int8 *v40; // r4
  int v41; // r0
  int v42; // r5
  unsigned int v43; // r2
  unsigned int v44; // r1
  unsigned int *v45; // r8
  int v46; // r0
  int v47; // r4
  unsigned int v48; // r2
  unsigned int v49; // r5
  unsigned __int8 *v50; // r6
  int v51; // r0
  int v52; // r4
  unsigned int v53; // r2
  _DWORD *v54; // r1
  int v55; // r2
  _DWORD *v56; // r0
  int v57; // [sp+18h] [bp-38h] BYREF
  _BYTE *v58; // [sp+1Ch] [bp-34h] BYREF
  int v59; // [sp+20h] [bp-30h] BYREF
  int v60; // [sp+24h] [bp-2Ch]
  _DWORD *v61; // [sp+28h] [bp-28h]
  _DWORD *v62; // [sp+2Ch] [bp-24h]

  v60 = a3;
  v61 = (_DWORD *)a1;
  v62 = a2;
  v11 = (_BYTE *)*(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v58 = v11;
  if ( a5 )
    v12 = ObReferenceObjectByNameEx(a5, a2, 1, AlpcPortObjectType, v11, 0, &v57);
  else
    v12 = ObReferenceObjectByName(a4, 0, 0, 1, AlpcPortObjectType, (char)v11, 0, &v57);
  v13 = v12;
  if ( v12 < 0 )
    return v13;
  v14 = (_DWORD *)v57;
  v15 = *(_DWORD *)(v57 + 244);
  if ( (v15 & 6) != 2 )
    return sub_7F43B0();
  if ( !a11 && (v15 & 0x1000) != 0 )
  {
    v40 = (unsigned __int8 *)(v57 + 208);
    v41 = KeAbPreAcquire(v57 + 208, 0, 0);
    v42 = v41;
    do
      v43 = __ldrex(v40);
    while ( __strex(v43 | 1, v40) );
    __dmb(0xBu);
    if ( (v43 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v14 + 52, v41, (unsigned int)(v14 + 52));
    if ( v42 )
      *(_BYTE *)(v42 + 14) |= 1u;
    v14[61] &= 0xFFFFDFFF;
    __dmb(0xBu);
    do
      v44 = __ldrex((unsigned int *)v40);
    while ( __strex(v44 - 1, (unsigned int *)v40) );
    if ( (v44 & 2) != 0 && (v44 & 4) == 0 )
      ExfTryToWakePushLock(v14 + 52);
    KeAbPostRelease((unsigned int)(v14 + 52));
  }
  if ( a8 || a9 )
  {
    v45 = v14 + 52;
    v46 = KeAbPreAcquire((unsigned int)(v14 + 52), 0, 0);
    v47 = v46;
    do
      v48 = __ldrex(v45);
    while ( !v48 && __strex(0x11u, v45) );
    __dmb(0xBu);
    if ( v48 )
      ExfAcquirePushLockSharedEx(v14 + 52, v46, (unsigned int)(v14 + 52));
    if ( v47 )
      *(_BYTE *)(v47 + 14) |= 1u;
    v39 = v14[3];
    if ( (v39 & 1) != 0 )
    {
      v39 = 0;
    }
    else if ( v39 )
    {
      ObfReferenceObjectWithTag(v14[3]);
    }
    __dmb(0xBu);
    do
      v49 = __ldrex(v45);
    while ( v49 == 17 && __strex(0, v45) );
    if ( v49 != 17 )
      ExfReleasePushLockShared(v14 + 52);
    KeAbPostRelease((unsigned int)(v14 + 52));
    if ( v39 )
    {
      v17 = AlpcpCheckConnectionSecurity(v39, v58, a9, a8);
      ObfDereferenceObjectWithTag(v39);
    }
    else
    {
      v17 = -1073741152;
    }
    if ( v17 < 0 )
LABEL_107:
      JUMPOUT(0x7F43B2);
    v11 = v58;
  }
  if ( ObCreateObject(v11, AlpcPortObjectType, a6, v11, 0, 284, 0, 0, &v58) < 0 )
    goto LABEL_107;
  v18 = v58;
  memset(v58, 0, 284);
  v19 = a7 && (*a7 & 0x40000) != 0;
  if ( AlpcpInitializePort(v18, 2, v19) < 0
    || (*((_DWORD *)v18 + 61) |= 8u, v20 = (_DWORD *)AlpcpAllocateBlob(AlpcConnectionType, 40, 1), (v21 = v20) == 0) )
  {
    ObfDereferenceObject((int)v14);
    goto LABEL_108;
  }
  *((_DWORD *)v18 + 2) = v20;
  *v20 = v14;
  v20[1] = 0;
  v20[9] = 0;
  v20[2] = v18;
  v22 = (unsigned __int8 *)(v14[2] - 4);
  v23 = KeAbPreAcquire((unsigned int)v22, 0, 0);
  v24 = v23;
  do
    v25 = __ldrex(v22);
  while ( __strex(v25 | 1, v22) );
  __dmb(0xBu);
  if ( (v25 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v22, v23, (unsigned int)v22);
  if ( v24 )
    *(_BYTE *)(v24 + 14) |= 1u;
  v50 = (unsigned __int8 *)(v14 + 52);
  v51 = KeAbPreAcquire((unsigned int)(v14 + 52), 0, 0);
  v52 = v51;
  do
    v53 = __ldrex(v50);
  while ( __strex(v53 | 1, v50) );
  __dmb(0xBu);
  if ( (v53 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v14 + 52, v51, (unsigned int)(v14 + 52));
  if ( v52 )
    *(_BYTE *)(v52 + 14) |= 1u;
  v54 = v21 + 3;
  v55 = v14[2] + 12;
  v56 = *(_DWORD **)(v14[2] + 16);
  v21[3] = v55;
  v21[4] = v56;
  if ( *v56 != v55 )
    __fastfail(3u);
  *v56 = v54;
  *(_DWORD *)(v55 + 4) = v54;
  __dmb(0xBu);
  do
    v26 = __ldrex((unsigned int *)v50);
  while ( __strex(v26 - 1, (unsigned int *)v50) );
  if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
    ExfTryToWakePushLock(v14 + 52);
  KeAbPostRelease((unsigned int)(v14 + 52));
  v27 = (unsigned int *)(v14[2] - 4);
  __dmb(0xBu);
  do
    v28 = __ldrex(v27);
  while ( __strex(v28 - 1, v27) );
  if ( (v28 & 2) != 0 && (v28 & 4) == 0 )
    ExfTryToWakePushLock(v27);
  KeAbPostRelease((unsigned int)v27);
  if ( AlpcInitializeHandleTable(v21 + 5) < 0
    || AlpcpValidateAndSetPortAttributes(v18, a7, v14, a10, 0, v19, a11) < 0
    || AlpcpAllocateMessage(v21 + 9, 32, 1) < 0 )
  {
    goto LABEL_108;
  }
  ++*(_WORD *)(v21[9] - 14);
  *(_DWORD *)(v21[9] + 136) |= 0x80000000;
  v29 = v21[9];
  if ( AlpcpMessageLogEnabled )
    AlpcpEnterStateChangeEventMessageLog(v21[9]);
  v30 = *(_BYTE *)(v29 - 16);
  v31 = 0;
  if ( (v30 & 1) != 0 )
  {
    v32 = *(__int16 *)(v29 - 14);
    *(_WORD *)(v29 - 14) = 0;
    v31 = 0x10000 - v32;
    *(_BYTE *)(v29 - 16) = v30 & 0xFE;
  }
  v33 = (unsigned int *)(v29 - 4);
  __dmb(0xBu);
  do
    v34 = __ldrex(v33);
  while ( __strex(v34 - 1, v33) );
  if ( (v34 & 2) != 0 && (v34 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v29 - 4));
  KeAbPostRelease(v29 - 4);
  if ( v31 > 0 )
  {
    __dmb(0xBu);
    v35 = (unsigned int *)(v29 - 12);
    do
    {
      v36 = __ldrex(v35);
      v37 = v36 - v31;
    }
    while ( __strex(v37, v35) );
    __dmb(0xBu);
    if ( v37 <= 0 )
    {
      if ( v37 )
        KeBugCheckEx(24, 0, v29, 40, v37);
      AlpcpDestroyBlob(v29);
    }
  }
  if ( a11 )
    *((_DWORD *)v18 + 61) |= 0x1000u;
  if ( (v60 & 0x80000) != 0 )
    *((_DWORD *)v18 + 61) |= 0x100u;
  if ( v18[164] == 1 )
  {
    *((_DWORD *)v18 + 61) |= 0x400u;
    goto LABEL_54;
  }
  if ( SeCreateClientSecurity(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v18 + 156, 0, v18 + 32) < 0 )
LABEL_108:
    JUMPOUT(0x7F43B4);
LABEL_54:
  AlpcpSetOwnerProcessPort(v18, a7);
  ObfReferenceObject((int)v18);
  v13 = ObInsertObjectEx(v18, 0, 2031617, 0, 0, 0, &v59);
  if ( v13 < 0 )
    goto LABEL_108;
  v38 = v61;
  *((_DWORD *)v18 + 7) = v59;
  *v38 = v59;
  *v62 = v18;
  return v13;
}
