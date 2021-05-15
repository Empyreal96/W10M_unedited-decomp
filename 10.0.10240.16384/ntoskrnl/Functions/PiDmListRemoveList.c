// PiDmListRemoveList 
 
int __fastcall PiDmListRemoveList(int a1, unsigned int a2, int a3, unsigned int *a4)
{
  unsigned int *v5; // r6
  _DWORD **v6; // r10
  unsigned int v7; // r4
  int v8; // r0
  int v9; // r8
  unsigned int v10; // r4
  unsigned int v11; // r2
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  unsigned int v15; // r2
  __int16 v16; // r3
  int v17; // r0
  int v18; // r4
  unsigned int v19; // r2
  unsigned int v20; // r2
  int v21; // r0
  unsigned int v22; // r2
  int v23; // r0
  unsigned int v24; // r2
  _DWORD *v25; // r9
  unsigned int *v26; // r4
  unsigned int v27; // r2
  int v28; // r0
  int v29; // r8
  unsigned int v30; // r2
  int v31; // r1
  unsigned int v32; // r0
  unsigned int v33; // r2
  int v34; // r0
  unsigned int v35; // r1
  __int16 v36; // r3
  int v37; // r1
  unsigned int v38; // r0
  unsigned int v39; // r2
  int v40; // r0
  unsigned int v41; // r1
  __int16 v42; // r3
  int v43; // r1
  unsigned int v44; // r0
  unsigned int v45; // r2
  unsigned int v46; // r3
  unsigned int v47; // r0
  unsigned int v48; // r2
  int v49; // r0
  unsigned int v50; // r1
  __int16 v51; // r3
  int v52; // r1
  unsigned int v53; // r0
  unsigned int v54; // r2
  unsigned int v55; // r0
  unsigned int v56; // r0
  int result; // r0
  unsigned int v58; // r1
  __int16 v59; // r3
  void *v60; // [sp+8h] [bp-28h]

  v5 = a4;
  v60 = PiDmGetObjectManagerForObjectType(*(_DWORD *)(a2 + 20));
  v6 = (_DWORD **)(v5 + 11);
  if ( a2 < (unsigned int)v5 )
  {
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v7 + 308);
    v8 = KeAbPreAcquire(a2, 0, 0);
    v9 = v8;
    do
      v10 = __ldrex((unsigned __int8 *)a2);
    while ( __strex(v10 | 1, (unsigned __int8 *)a2) );
    __dmb(0xBu);
    if ( (v10 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)a2, v8, a2);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
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
    goto LABEL_13;
  }
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134);
  if ( a2 > (unsigned int)v5 )
  {
    *(_WORD *)(v15 + 308) = v16 - 1;
    v17 = KeAbPreAcquire((unsigned int)v5, 0, 0);
    v18 = v17;
    do
      v19 = __ldrex(v5);
    while ( !v19 && __strex(0x11u, v5) );
    __dmb(0xBu);
    if ( v19 )
      ExfAcquirePushLockSharedEx(v5, v17, (unsigned int)v5);
    if ( v18 )
      *(_BYTE *)(v18 + 14) |= 1u;
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v20 + 308);
    v21 = KeAbPreAcquire(a2, 0, 0);
    v13 = v21;
    do
      v22 = __ldrex((unsigned __int8 *)a2);
    while ( __strex(v22 | 1, (unsigned __int8 *)a2) );
    __dmb(0xBu);
    if ( (v22 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)a2, v21, a2);
LABEL_13:
    if ( !v13 )
      goto LABEL_33;
    goto LABEL_32;
  }
  *(_WORD *)(v15 + 308) = v16 - 1;
  v23 = KeAbPreAcquire(a2, 0, 0);
  v13 = v23;
  do
    v24 = __ldrex((unsigned __int8 *)a2);
  while ( __strex(v24 | 1, (unsigned __int8 *)a2) );
  __dmb(0xBu);
  if ( (v24 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)a2, v23, a2);
  if ( v13 )
LABEL_32:
    *(_BYTE *)(v13 + 14) |= 1u;
LABEL_33:
  v25 = *v6;
  if ( *v6 != v6 )
  {
    do
    {
      v26 = v25 - 10;
      v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v27 + 308);
      v28 = KeAbPreAcquire((unsigned int)(v25 - 10), 0, 0);
      v29 = v28;
      do
        v30 = __ldrex(v26);
      while ( !v30 && __strex(0x11u, v26) );
      __dmb(0xBu);
      if ( v30 )
        ExfAcquirePushLockSharedEx(v25 - 10, v28, (unsigned int)(v25 - 10));
      if ( v29 )
        *(_BYTE *)(v29 + 14) |= 1u;
      PiDmListRemoveObjectWorker(2, v60, a2, v25 - 10, 0);
      __pld(v26);
      v31 = *v26;
      v32 = *v26 - 16;
      if ( (*v26 & 0xFFFFFFF0) <= 0x10 )
        v32 = 0;
      if ( (v31 & 2) != 0 )
        goto LABEL_48;
      __dmb(0xBu);
      do
        v33 = __ldrex(v26);
      while ( v33 == v31 && __strex(v32, v26) );
      if ( v33 != v31 )
LABEL_48:
        ExfReleasePushLock(v25 - 10, v31);
      v34 = KeAbPostRelease((unsigned int)(v25 - 10));
      v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v36 = *(_WORD *)(v35 + 0x134) + 1;
      *(_WORD *)(v35 + 308) = v36;
      if ( !v36 && *(_DWORD *)(v35 + 100) != v35 + 100 && !*(_WORD *)(v35 + 310) )
        KiCheckForKernelApcDelivery(v34);
      v25 = (_DWORD *)*v25;
    }
    while ( v25 != v6 );
    v5 = a4;
  }
  if ( a2 < (unsigned int)v5 )
  {
    __pld(v5);
    v37 = *v5;
    v38 = *v5 - 16;
    if ( (*v5 & 0xFFFFFFF0) <= 0x10 )
      v38 = 0;
    if ( (v37 & 2) != 0 )
      goto LABEL_63;
    __dmb(0xBu);
    do
      v39 = __ldrex(v5);
    while ( v39 == v37 && __strex(v38, v5) );
    if ( v39 != v37 )
LABEL_63:
      ExfReleasePushLock(v5, v37);
    v40 = KeAbPostRelease((unsigned int)v5);
    v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v42 = *(_WORD *)(v41 + 0x134) + 1;
    *(_WORD *)(v41 + 308) = v42;
    if ( !v42 && *(_DWORD *)(v41 + 100) != v41 + 100 && !*(_WORD *)(v41 + 310) )
      KiCheckForKernelApcDelivery(v40);
    __pld((void *)a2);
    v43 = *(_DWORD *)a2;
    v44 = *(_DWORD *)a2 - 16;
    if ( (*(_DWORD *)a2 & 0xFFFFFFF0) <= 0x10 )
      v44 = 0;
    if ( (v43 & 2) != 0 )
      goto LABEL_104;
    __dmb(0xBu);
    do
      v45 = __ldrex((unsigned int *)a2);
    while ( v45 == v43 && __strex(v44, (unsigned int *)a2) );
LABEL_103:
    if ( v45 == v43 )
    {
LABEL_105:
      v55 = a2;
      goto LABEL_106;
    }
LABEL_104:
    ExfReleasePushLock((_DWORD *)a2, v43);
    goto LABEL_105;
  }
  __pld((void *)a2);
  v43 = *(_DWORD *)a2;
  v46 = *(_DWORD *)a2 & 0xFFFFFFF0;
  if ( a2 <= (unsigned int)v5 )
  {
    v56 = v43 - 16;
    if ( v46 <= 0x10 )
      v56 = 0;
    if ( (v43 & 2) != 0 )
      goto LABEL_104;
    __dmb(0xBu);
    do
      v45 = __ldrex((unsigned int *)a2);
    while ( v45 == v43 && __strex(v56, (unsigned int *)a2) );
    goto LABEL_103;
  }
  v47 = v43 - 16;
  if ( v46 <= 0x10 )
    v47 = 0;
  if ( (v43 & 2) != 0 )
    goto LABEL_83;
  __dmb(0xBu);
  do
    v48 = __ldrex((unsigned int *)a2);
  while ( v48 == v43 && __strex(v47, (unsigned int *)a2) );
  if ( v48 != v43 )
LABEL_83:
    ExfReleasePushLock((_DWORD *)a2, v43);
  v49 = KeAbPostRelease(a2);
  v50 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v51 = *(_WORD *)(v50 + 0x134) + 1;
  *(_WORD *)(v50 + 308) = v51;
  if ( !v51 && *(_DWORD *)(v50 + 100) != v50 + 100 && !*(_WORD *)(v50 + 310) )
    KiCheckForKernelApcDelivery(v49);
  __pld(v5);
  v52 = *v5;
  v53 = *v5 - 16;
  if ( (*v5 & 0xFFFFFFF0) <= 0x10 )
    v53 = 0;
  if ( (v52 & 2) != 0 )
    goto LABEL_95;
  __dmb(0xBu);
  do
    v54 = __ldrex(v5);
  while ( v54 == v52 && __strex(v53, v5) );
  if ( v54 != v52 )
LABEL_95:
    ExfReleasePushLock(v5, v52);
  v55 = (unsigned int)v5;
LABEL_106:
  result = KeAbPostRelease(v55);
  v58 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v59 = *(_WORD *)(v58 + 0x134) + 1;
  *(_WORD *)(v58 + 308) = v59;
  if ( !v59 && *(_DWORD *)(v58 + 100) != v58 + 100 && !*(_WORD *)(v58 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
