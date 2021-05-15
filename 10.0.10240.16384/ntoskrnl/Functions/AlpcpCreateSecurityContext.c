// AlpcpCreateSecurityContext 
 
int __fastcall AlpcpCreateSecurityContext(_DWORD *a1, int a2, int a3, _DWORD *a4)
{
  unsigned int v6; // r9
  int v7; // r6
  _BYTE *v8; // r0
  _DWORD *v9; // r4
  unsigned int *v10; // r7
  unsigned int v11; // r0
  unsigned int v12; // r1
  int v13; // r5
  unsigned int *v14; // r8
  int v15; // r0
  int v16; // r5
  unsigned int v17; // r2
  _DWORD *v18; // r5
  unsigned __int8 *v19; // r7
  int v20; // r0
  int v21; // r6
  unsigned int v22; // r2
  int v23; // r6
  bool v24; // zf
  unsigned int *v25; // r7
  int v26; // r0
  int v27; // r1
  int v28; // r3
  int v29; // r0
  unsigned __int8 *v30; // r7
  int v31; // r0
  int v32; // r6
  unsigned int v33; // r2
  _DWORD *v34; // r1
  unsigned int v35; // r1
  unsigned int v36; // r2
  unsigned int *v38; // r2
  unsigned int v39; // r1
  int v40; // r1
  unsigned int v41; // r3
  unsigned int v42; // r2
  unsigned int *v43; // r2
  unsigned int v44; // r1
  int v45; // r1
  unsigned int v46; // r2
  unsigned int v47; // r0
  unsigned int *v48; // r2
  unsigned int v49; // r1
  int v50; // r1
  unsigned int v51; // r2
  unsigned int *v52; // r2
  unsigned int v53; // r1
  int v54; // r1
  int v57[8]; // [sp+10h] [bp-20h] BYREF

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_DWORD *)(v6 + 0x74);
  v8 = (_BYTE *)AlpcpAllocateBlob(AlpcSecurityType, 80, 0);
  v9 = v8;
  if ( !v8 )
    goto LABEL_95;
  memset(v8, 0, 80);
  v10 = (unsigned int *)(v7 + 668);
  __pld((void *)(v7 + 668));
  v9[1] = -1;
  v11 = *(_DWORD *)(v7 + 668);
  __dmb(0xBu);
  if ( v11 < 0x68 )
  {
LABEL_48:
    v13 = PsChargeProcessPagedPoolQuota(v7, 104);
    if ( v13 < 0 )
    {
      __dmb(0xBu);
      v38 = v9 - 3;
      do
      {
        v39 = __ldrex(v38);
        v40 = v39 - 1;
      }
      while ( __strex(v40, v38) );
      __dmb(0xBu);
      if ( v40 > 0 )
        return v13;
      if ( v40 )
        KeBugCheckEx(24, 0, (int)v9, 33, v40);
      goto LABEL_58;
    }
  }
  else
  {
    while ( 1 )
    {
      __dmb(0xBu);
      do
        v12 = __ldrex(v10);
      while ( v12 == v11 && __strex(v11 - 104, v10) );
      __dmb(0xBu);
      if ( v12 == v11 )
        break;
      v11 = *v10;
      __dmb(0xBu);
      if ( v11 < 0x68 )
        goto LABEL_48;
    }
  }
  v13 = SeCreateClientSecurity(v6, a3, 0, v9 + 4);
  if ( v13 < 0 )
  {
    v41 = *v10;
    __dmb(0xBu);
    if ( v41 + 104 >= 0x1000 )
    {
      PsReturnProcessPagedPoolQuota(v7, 0x68u);
    }
    else
    {
      __dmb(0xBu);
      do
        v42 = __ldrex(v10);
      while ( __strex(v42 + 104, v10) );
      __dmb(0xBu);
    }
    __dmb(0xBu);
    v43 = v9 - 3;
    do
    {
      v44 = __ldrex(v43);
      v45 = v44 - 1;
    }
    while ( __strex(v45, v43) );
    __dmb(0xBu);
    if ( v45 > 0 )
      return v13;
    if ( v45 )
      KeBugCheckEx(24, 0, (int)v9, 33, v45);
LABEL_58:
    AlpcpDestroyBlob(v9);
    return v13;
  }
  ObfReferenceObjectWithTag(v7);
  v9[2] = v7;
  if ( !a2 )
  {
LABEL_46:
    v13 = 0;
    *a4 = v9;
    return v13;
  }
  v14 = a1 + 52;
  v15 = KeAbPreAcquire((unsigned int)(a1 + 52), 0, 0);
  v16 = v15;
  do
    v17 = __ldrex(v14);
  while ( !v17 && __strex(0x11u, v14) );
  __dmb(0xBu);
  if ( v17 )
    ExfAcquirePushLockSharedEx(v14, v15, (unsigned int)v14);
  if ( v16 )
    *(_BYTE *)(v16 + 14) |= 1u;
  if ( (a1[61] & 0x20) != 0 )
  {
    __dmb(0xBu);
    do
      v46 = __ldrex(v14);
    while ( v46 == 17 && __strex(0, v14) );
    if ( v46 != 17 )
      ExfReleasePushLockShared(v14);
    v47 = KeAbPostRelease((unsigned int)v14);
    __dmb(0xBu);
    v48 = v9 - 3;
    do
    {
      v49 = __ldrex(v48);
      v50 = v49 - 1;
    }
    while ( __strex(v50, v48) );
    __dmb(0xBu);
    if ( v50 <= 0 )
    {
      if ( v50 )
        KeBugCheckEx(24, 0, (int)v9, 33, v50);
      return sub_7F7D50(v47);
    }
LABEL_95:
    JUMPOUT(0x7F7D56);
  }
  v18 = v9 - 6;
  v19 = (unsigned __int8 *)(v9 - 1);
  v20 = KeAbPreAcquire((unsigned int)(v9 - 1), 0, 0);
  v21 = v20;
  do
    v22 = __ldrex(v19);
  while ( __strex(v22 | 1, v19) );
  __dmb(0xBu);
  if ( (v22 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v9 - 1, v20, (unsigned int)(v9 - 1));
  if ( v21 )
    *(_BYTE *)(v21 + 14) |= 1u;
  *((_BYTE *)v9 - 16) |= 4u;
  v23 = *(v9 - 3);
  v24 = v23 == 0;
  if ( v23 <= 0 )
  {
LABEL_82:
    if ( !v24 )
      KeBugCheckEx(24, 0, (int)v9, 32, v23);
  }
  else
  {
    v25 = v9 - 3;
    while ( 1 )
    {
      v26 = v23;
      __dmb(0xBu);
      do
        v27 = __ldrex(v25);
      while ( v27 == v23 && __strex(v23 + 1, v25) );
      v23 = v27;
      __dmb(0xBu);
      if ( v27 == v26 )
        break;
      if ( v27 <= 0 )
      {
        v24 = v27 == 0;
        goto LABEL_82;
      }
    }
  }
  v28 = a1[2];
  v57[0] = (int)v9;
  *v9 = v28 + 20;
  v29 = AlpcAddHandleTableEntry((int *)(v28 + 20), v57);
  v9[1] = v29;
  if ( v29 != -1 )
  {
    ObfReferenceObject((int)a1);
    v30 = (unsigned __int8 *)(a1 + 49);
    v9[3] = a1;
    v31 = KeAbPreAcquire((unsigned int)(a1 + 49), 0, 0);
    v32 = v31;
    do
      v33 = __ldrex(v30);
    while ( __strex(v33 | 1, v30) );
    __dmb(0xBu);
    if ( (v33 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(a1 + 49, v31, (unsigned int)(a1 + 49));
    if ( v32 )
      *(_BYTE *)(v32 + 14) |= 1u;
    v34 = (_DWORD *)a1[51];
    *v18 = a1 + 50;
    *(v9 - 5) = v34;
    if ( (_DWORD *)*v34 != a1 + 50 )
      __fastfail(3u);
    *v34 = v18;
    a1[51] = v18;
    __dmb(0xBu);
    do
      v35 = __ldrex((unsigned int *)v30);
    while ( __strex(v35 - 1, (unsigned int *)v30) );
    if ( (v35 & 2) != 0 && (v35 & 4) == 0 )
      ExfTryToWakePushLock(a1 + 49);
    KeAbPostRelease((unsigned int)(a1 + 49));
    __dmb(0xBu);
    do
      v36 = __ldrex(v14);
    while ( v36 == 17 && __strex(0, v14) );
    if ( v36 != 17 )
      ExfReleasePushLockShared(v14);
    KeAbPostRelease((unsigned int)v14);
    AlpcpEndInitialization((int)v9);
    goto LABEL_46;
  }
  __dmb(0xBu);
  do
    v51 = __ldrex(v14);
  while ( v51 == 17 && __strex(0, v14) );
  if ( v51 != 17 )
    ExfReleasePushLockShared(v14);
  KeAbPostRelease((unsigned int)v14);
  *v9 = 0;
  v47 = AlpcpEndInitialization((int)v9);
  __dmb(0xBu);
  v52 = v9 - 3;
  do
  {
    v53 = __ldrex(v52);
    v54 = v53 - 2;
  }
  while ( __strex(v54, v52) );
  __dmb(0xBu);
  if ( v54 > 0 )
    goto LABEL_95;
  if ( v54 )
    KeBugCheckEx(24, 0, (int)v9, 33, v54);
  return sub_7F7D50(v47);
}
