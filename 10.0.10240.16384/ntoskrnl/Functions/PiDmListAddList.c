// PiDmListAddList 
 
int __fastcall PiDmListAddList(int a1, unsigned int a2, int a3, unsigned int *a4)
{
  unsigned int *v5; // r6
  _DWORD **v6; // r10
  unsigned int v7; // r4
  int v8; // r0
  unsigned int v9; // r4
  int result; // r0
  unsigned int v11; // r2
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  _DWORD *v15; // r9
  int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r2
  int v19; // r0
  unsigned int v20; // r1
  int v21; // r3
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  unsigned int v25; // r0
  unsigned int v26; // r1
  int v27; // r3
  unsigned int v28; // r2
  __int16 v29; // r3
  int v30; // r0
  int v31; // r4
  unsigned int v32; // r2
  unsigned int v33; // r2
  int v34; // r0
  unsigned int v35; // r2
  int v36; // r0
  unsigned int v37; // r2
  unsigned int *v38; // r4
  unsigned int v39; // r2
  int v40; // r0
  int v41; // r8
  unsigned int v42; // r2
  int v43; // r1
  unsigned int v44; // r0
  unsigned int v45; // r2
  int v46; // r0
  unsigned int v47; // r1
  __int16 v48; // r3
  unsigned int v49; // r3
  unsigned int v50; // r0
  unsigned int v51; // r2
  int v52; // r0
  unsigned int v53; // r1
  __int16 v54; // r3
  int v55; // r1
  unsigned int v56; // r0
  unsigned int v57; // r2
  unsigned int v58; // r0
  void *v59; // [sp+8h] [bp-28h]

  v5 = a4;
  v59 = PiDmGetObjectManagerForObjectType(*(_DWORD *)(a2 + 20));
  v6 = (_DWORD **)(v5 + 11);
  if ( a2 < (unsigned int)v5 )
  {
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v7 + 308);
    v8 = KeAbPreAcquire(a2, 0, 0);
    do
      v9 = __ldrex((unsigned __int8 *)a2);
    while ( __strex(v9 | 1, (unsigned __int8 *)a2) );
    __dmb(0xBu);
    if ( (v9 & 1) != 0 )
      return sub_7F0124(v8);
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v11 + 308);
    v12 = KeAbPreAcquire((unsigned int)v5, 0, 0);
    v13 = v12;
    do
      v14 = __ldrex(v5);
    while ( !v14 && __strex(0x11u, v5) );
    __dmb(0xBu);
    if ( v14 )
      ExfAcquirePushLockSharedEx(v5, v12, (unsigned int)v5);
LABEL_13:
    if ( !v13 )
      goto LABEL_15;
    goto LABEL_14;
  }
  v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v29 = *(_WORD *)(v28 + 0x134);
  if ( a2 > (unsigned int)v5 )
  {
    *(_WORD *)(v28 + 308) = v29 - 1;
    v30 = KeAbPreAcquire((unsigned int)v5, 0, 0);
    v31 = v30;
    do
      v32 = __ldrex(v5);
    while ( !v32 && __strex(0x11u, v5) );
    __dmb(0xBu);
    if ( v32 )
      ExfAcquirePushLockSharedEx(v5, v30, (unsigned int)v5);
    if ( v31 )
      *(_BYTE *)(v31 + 14) |= 1u;
    v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v33 + 308);
    v34 = KeAbPreAcquire(a2, 0, 0);
    v13 = v34;
    do
      v35 = __ldrex((unsigned __int8 *)a2);
    while ( __strex(v35 | 1, (unsigned __int8 *)a2) );
    __dmb(0xBu);
    if ( (v35 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)a2, v34, a2);
    goto LABEL_13;
  }
  *(_WORD *)(v28 + 308) = v29 - 1;
  v36 = KeAbPreAcquire(a2, 0, 0);
  v13 = v36;
  do
    v37 = __ldrex((unsigned __int8 *)a2);
  while ( __strex(v37 | 1, (unsigned __int8 *)a2) );
  __dmb(0xBu);
  if ( (v37 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)a2, v36, a2);
  if ( v13 )
LABEL_14:
    *(_BYTE *)(v13 + 14) |= 1u;
LABEL_15:
  v15 = *v6;
  if ( *v6 != v6 )
  {
    do
    {
      v38 = v15 - 10;
      v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v39 + 308);
      v40 = KeAbPreAcquire((unsigned int)(v15 - 10), 0, 0);
      v41 = v40;
      do
        v42 = __ldrex(v38);
      while ( !v42 && __strex(0x11u, v38) );
      __dmb(0xBu);
      if ( v42 )
        ExfAcquirePushLockSharedEx(v15 - 10, v40, (unsigned int)(v15 - 10));
      if ( v41 )
        *(_BYTE *)(v41 + 14) |= 1u;
      PiDmListAddObjectWorker(2, (int)v59, a2, (int)(v15 - 10), 0);
      __pld(v38);
      v43 = *v38;
      if ( (*v38 & 0xFFFFFFF0) <= 0x10 )
        v44 = 0;
      else
        v44 = v43 - 16;
      if ( (v43 & 2) != 0 )
        goto LABEL_71;
      __dmb(0xBu);
      do
        v45 = __ldrex(v38);
      while ( v45 == v43 && __strex(v44, v38) );
      if ( v45 != v43 )
LABEL_71:
        ExfReleasePushLock(v15 - 10, v43);
      v46 = KeAbPostRelease((unsigned int)(v15 - 10));
      v47 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v48 = *(_WORD *)(v47 + 0x134) + 1;
      *(_WORD *)(v47 + 308) = v48;
      if ( !v48 && *(_DWORD *)(v47 + 100) != v47 + 100 && !*(_WORD *)(v47 + 310) )
        KiCheckForKernelApcDelivery(v46);
      v15 = (_DWORD *)*v15;
    }
    while ( v15 != v6 );
    v5 = a4;
  }
  if ( a2 >= (unsigned int)v5 )
  {
    __pld((void *)a2);
    v22 = *(_DWORD *)a2;
    v49 = *(_DWORD *)a2 & 0xFFFFFFF0;
    if ( a2 > (unsigned int)v5 )
    {
      if ( v49 <= 0x10 )
        v50 = 0;
      else
        v50 = v22 - 16;
      if ( (v22 & 2) != 0 )
        goto LABEL_91;
      __dmb(0xBu);
      do
        v51 = __ldrex((unsigned int *)a2);
      while ( v51 == v22 && __strex(v50, (unsigned int *)a2) );
      if ( v51 != v22 )
LABEL_91:
        ExfReleasePushLock((_DWORD *)a2, v22);
      v52 = KeAbPostRelease(a2);
      v53 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v54 = *(_WORD *)(v53 + 0x134) + 1;
      *(_WORD *)(v53 + 308) = v54;
      if ( !v54 && *(_DWORD *)(v53 + 100) != v53 + 100 && !*(_WORD *)(v53 + 310) )
        KiCheckForKernelApcDelivery(v52);
      __pld(v5);
      v55 = *v5;
      if ( (*v5 & 0xFFFFFFF0) <= 0x10 )
        v56 = 0;
      else
        v56 = v55 - 16;
      if ( (v55 & 2) != 0 )
        goto LABEL_104;
      __dmb(0xBu);
      do
        v57 = __ldrex(v5);
      while ( v57 == v55 && __strex(v56, v5) );
      if ( v57 != v55 )
LABEL_104:
        ExfReleasePushLock(v5, v55);
      v25 = (unsigned int)v5;
      goto LABEL_33;
    }
    if ( v49 <= 0x10 )
      v58 = 0;
    else
      v58 = v22 - 16;
    if ( (v22 & 2) != 0 )
      goto LABEL_37;
    __dmb(0xBu);
    do
      v24 = __ldrex((unsigned int *)a2);
    while ( v24 == v22 && __strex(v58, (unsigned int *)a2) );
  }
  else
  {
    __pld(v5);
    v16 = *v5;
    if ( (*v5 & 0xFFFFFFF0) > 0x10 )
      v17 = v16 - 16;
    else
      v17 = 0;
    if ( (v16 & 2) != 0 )
      goto LABEL_35;
    __dmb(0xBu);
    do
      v18 = __ldrex(v5);
    while ( v18 == v16 && __strex(v17, v5) );
    if ( v18 != v16 )
LABEL_35:
      ExfReleasePushLock(v5, v16);
    v19 = KeAbPostRelease((unsigned int)v5);
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v21 = (__int16)(*(_WORD *)(v20 + 0x134) + 1);
    *(_WORD *)(v20 + 308) = v21;
    if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
      KiCheckForKernelApcDelivery(v19);
    __pld((void *)a2);
    v22 = *(_DWORD *)a2;
    if ( (*(_DWORD *)a2 & 0xFFFFFFF0) > 0x10 )
      v23 = v22 - 16;
    else
      v23 = 0;
    if ( (v22 & 2) != 0 )
      goto LABEL_37;
    __dmb(0xBu);
    do
      v24 = __ldrex((unsigned int *)a2);
    while ( v24 == v22 && __strex(v23, (unsigned int *)a2) );
  }
  if ( v24 != v22 )
LABEL_37:
    ExfReleasePushLock((_DWORD *)a2, v22);
  v25 = a2;
LABEL_33:
  result = KeAbPostRelease(v25);
  v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v27 = (__int16)(*(_WORD *)(v26 + 0x134) + 1);
  *(_WORD *)(v26 + 308) = v27;
  if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
