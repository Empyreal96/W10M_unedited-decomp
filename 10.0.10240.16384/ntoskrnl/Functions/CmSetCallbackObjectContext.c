// CmSetCallbackObjectContext 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmSetCallbackObjectContext(_DWORD *a1, _DWORD *a2, unsigned int a3, unsigned int *a4)
{
  int v5; // r7
  unsigned int v7; // r5
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  unsigned int v11; // r2
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  char v15; // r3
  int *v16; // r3
  int *v17; // r6
  __int64 v18; // r0
  __int64 v19; // r2
  unsigned int *v20; // r2
  unsigned int v21; // r1
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  int v25; // r0
  unsigned int v26; // r1
  __int16 v27; // r3
  unsigned int v28; // r2
  int v29; // r0
  unsigned int v30; // r2
  int v31; // r4
  int v32; // r0
  int v33; // r2
  int v34; // r3
  int v35; // r1
  int *v36; // r4
  int *v37; // r2 OVERLAPPED
  int v38; // r1 OVERLAPPED
  int v39; // r1
  unsigned int v40; // r0
  unsigned int v41; // r2
  int v42; // r0
  unsigned int v43; // r1
  __int16 v44; // r3
  int v45; // r1
  unsigned int v46; // r0
  unsigned int v47; // r2
  int v48; // r0
  unsigned int v49; // r1
  __int16 v50; // r3
  int v53; // [sp+4h] [bp-24h]

  v5 = -1073741275;
  v53 = 0;
  if ( !a1 || *a1 != 1803104306 )
    return -1073741585;
  if ( a4 )
    *a4 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = KeAbPreAcquire((unsigned int)&CmpCallbackListLock, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex((unsigned int *)&CmpCallbackListLock);
  while ( !v10 && __strex(0x11u, (unsigned int *)&CmpCallbackListLock) );
  __dmb(0xBu);
  if ( v10 )
    ExfAcquirePushLockSharedEx(&CmpCallbackListLock, v8, (unsigned int)&CmpCallbackListLock);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v11 + 308);
  v12 = KeAbPreAcquire((unsigned int)&CmpContextListLock, 0, 0);
  v13 = v12;
  do
    v14 = __ldrex((unsigned int *)&CmpContextListLock);
  while ( !v14 && __strex(0x11u, (unsigned int *)&CmpContextListLock) );
  __dmb(0xBu);
  if ( v14 )
    ExfAcquirePushLockSharedEx(&CmpContextListLock, v12, (unsigned int)&CmpContextListLock);
  if ( v13 )
  {
    v15 = *(_BYTE *)(v13 + 14) | 1;
LABEL_19:
    *(_BYTE *)(v13 + 14) = v15;
  }
  v16 = a1 + 9;
  while ( 1 )
  {
    v17 = (int *)a1[9];
    if ( v17 != v16 )
    {
      while ( 1 )
      {
        v19 = *((_QWORD *)v17 + 2);
        LODWORD(v18) = a2[1];
        HIDWORD(v18) = *a2;
        if ( __PAIR64__(v19, HIDWORD(v19)) == v18 )
          break;
        if ( v19 >= *(_QWORD *)a2 )
        {
          v17 = (int *)*v17;
          if ( v17 != a1 + 9 )
            continue;
        }
        goto LABEL_31;
      }
      __dmb(0xBu);
      v20 = (unsigned int *)(v17 + 8);
      do
        v21 = __ldrex(v20);
      while ( __strex(a3, v20) );
      __dmb(0xBu);
      if ( a4 )
        *a4 = v21;
      v5 = 0;
    }
LABEL_31:
    if ( v5 >= 0 )
      break;
    if ( v53 )
    {
      v31 = CallbackListHead;
      if ( (int *)CallbackListHead == &CallbackListHead )
      {
LABEL_54:
        v31 = 0;
      }
      else
      {
        while ( *(_QWORD *)a2 != *(_QWORD *)(v31 + 16) )
        {
          v31 = *(_DWORD *)v31;
          if ( (int *)v31 == &CallbackListHead )
            goto LABEL_54;
        }
      }
      if ( v31 )
      {
        v5 = 0;
        v32 = ExAllocatePoolWithTag(1, 40, 1667452227);
        if ( v32 )
        {
          *(_DWORD *)(v32 + 24) = v31;
          v33 = v32 + 8;
          *(_DWORD *)(v32 + 16) = *a2;
          v34 = a2[1];
          v35 = v31 + 40;
          *(_DWORD *)(v32 + 28) = a1;
          *(_DWORD *)(v32 + 20) = v34;
          *(_DWORD *)(v32 + 32) = a3;
          v36 = *(int **)(v31 + 44);
          *(_DWORD *)(v32 + 8) = v35;
          *(_DWORD *)(v32 + 12) = v36;
          if ( *v36 != v35 )
            __fastfail(3u);
          *v36 = v33;
          *(_DWORD *)(v35 + 4) = v33;
          v37 = (int *)v17[1];
          v38 = *v37;
          *(_QWORD *)v32 = *(_QWORD *)&v38;
          if ( *(int **)(v38 + 4) != v37 )
            __fastfail(3u);
          *(_DWORD *)(v38 + 4) = v32;
          *v37 = v32;
        }
        else
        {
          v5 = -1073741670;
        }
      }
      else
      {
        v5 = -1073741584;
      }
      break;
    }
    __pld(&CmpContextListLock);
    v22 = CmpContextListLock;
    v23 = CmpContextListLock - 16;
    if ( (CmpContextListLock & 0xFFFFFFF0) <= 0x10 )
      v23 = 0;
    if ( (CmpContextListLock & 2) != 0 )
      goto LABEL_40;
    __dmb(0xBu);
    do
      v24 = __ldrex((unsigned int *)&CmpContextListLock);
    while ( v24 == v22 && __strex(v23, (unsigned int *)&CmpContextListLock) );
    if ( v24 != v22 )
LABEL_40:
      ExfReleasePushLock(&CmpContextListLock, v22);
    v25 = KeAbPostRelease((unsigned int)&CmpContextListLock);
    v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v27 = *(_WORD *)(v26 + 0x134) + 1;
    *(_WORD *)(v26 + 308) = v27;
    if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
      KiCheckForKernelApcDelivery(v25);
    v53 = 1;
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v28 + 308);
    v29 = KeAbPreAcquire((unsigned int)&CmpContextListLock, 0, 0);
    v13 = v29;
    do
      v30 = __ldrex((unsigned __int8 *)&CmpContextListLock);
    while ( __strex(v30 | 1, (unsigned __int8 *)&CmpContextListLock) );
    __dmb(0xBu);
    if ( (v30 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&CmpContextListLock, v29, (unsigned int)&CmpContextListLock);
    v16 = a1 + 9;
    if ( v13 )
    {
      v15 = *(_BYTE *)(v13 + 14) | 1;
      goto LABEL_19;
    }
  }
  __pld(&CmpContextListLock);
  v39 = CmpContextListLock;
  v40 = CmpContextListLock - 16;
  if ( (CmpContextListLock & 0xFFFFFFF0) <= 0x10 )
    v40 = 0;
  if ( (CmpContextListLock & 2) != 0 )
    goto LABEL_71;
  __dmb(0xBu);
  do
    v41 = __ldrex((unsigned int *)&CmpContextListLock);
  while ( v41 == v39 && __strex(v40, (unsigned int *)&CmpContextListLock) );
  if ( v41 != v39 )
LABEL_71:
    ExfReleasePushLock(&CmpContextListLock, v39);
  v42 = KeAbPostRelease((unsigned int)&CmpContextListLock);
  v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v44 = *(_WORD *)(v43 + 0x134) + 1;
  *(_WORD *)(v43 + 308) = v44;
  if ( !v44 && *(_DWORD *)(v43 + 100) != v43 + 100 && !*(_WORD *)(v43 + 310) )
    KiCheckForKernelApcDelivery(v42);
  __pld(&CmpCallbackListLock);
  v45 = CmpCallbackListLock;
  v46 = CmpCallbackListLock - 16;
  if ( (CmpCallbackListLock & 0xFFFFFFF0) <= 0x10 )
    v46 = 0;
  if ( (CmpCallbackListLock & 2) != 0 )
    goto LABEL_83;
  __dmb(0xBu);
  do
    v47 = __ldrex((unsigned int *)&CmpCallbackListLock);
  while ( v47 == v45 && __strex(v46, (unsigned int *)&CmpCallbackListLock) );
  if ( v47 != v45 )
LABEL_83:
    ExfReleasePushLock(&CmpCallbackListLock, v45);
  v48 = KeAbPostRelease((unsigned int)&CmpCallbackListLock);
  v49 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v50 = *(_WORD *)(v49 + 0x134) + 1;
  *(_WORD *)(v49 + 308) = v50;
  if ( !v50 && *(_DWORD *)(v49 + 100) != v49 + 100 && !*(_WORD *)(v49 + 310) )
    KiCheckForKernelApcDelivery(v48);
  return v5;
}
