// PiDqDispatch 
 
int __fastcall PiDqDispatch(int a1, int a2)
{
  unsigned __int8 *v2; // r8
  int v4; // r4
  int v5; // r7
  int v6; // r3
  _DWORD *v7; // r6
  unsigned int v9; // r2
  char *v11; // r6
  int v12; // r9
  int v13; // r10
  unsigned int v14; // r2
  unsigned __int8 *v15; // r4
  int v16; // r0
  unsigned int v17; // r2
  int v18; // r1
  unsigned int v19; // lr
  unsigned int v20; // r2
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3
  unsigned int v24; // r2
  int v25; // r0
  int v26; // r8
  unsigned int v27; // r2
  int v28; // r3
  int v29; // r1
  unsigned int v30; // r0
  unsigned int v31; // r2
  int v32; // r0
  unsigned int v33; // r1
  __int16 v34; // r3
  unsigned int *v35; // r2
  unsigned int v36; // r1

  v2 = *(unsigned __int8 **)(a2 + 96);
  v4 = *(_DWORD *)(a2 + 24);
  v5 = *((_DWORD *)v2 + 7);
  v6 = *v2;
  v7 = *(_DWORD **)(v5 + 16);
  if ( v6 == 14 )
  {
    v9 = *((_DWORD *)v2 + 4);
    if ( v9 != 4653056 )
    {
      if ( v9 > 0x470006 )
      {
        if ( v9 <= 0x470008 )
          return PiDqIrpQueryGetResult(a2);
        if ( v9 == 4653068 )
          return PiDqIrpPropertySet(a2);
      }
      v4 = -1073741637;
LABEL_16:
      *(_DWORD *)(a2 + 24) = v4;
      goto LABEL_7;
    }
    return PiDqIrpQueryCreate(a2);
  }
  if ( !*v2 )
  {
    v11 = *(char **)(v5 + 52);
    v4 = 0;
    if ( !wcscmp((char *)L"\\Dev\\Query", v11) )
    {
      v4 = PiDqQueryCreate(0, v5 + 16);
    }
    else if ( !wcscmp((char *)L"\\Dev\\NoState", v11) )
    {
      *(_DWORD *)(v5 + 16) = 0;
    }
    else
    {
      v4 = -1073741811;
    }
    goto LABEL_16;
  }
  if ( v6 == 2 )
  {
    if ( v7 )
    {
      PiDqQueryRelease(v7);
      *(_DWORD *)(*((_DWORD *)v2 + 7) + 16) = 0;
    }
LABEL_6:
    v4 = 0;
    *(_DWORD *)(a2 + 24) = 0;
LABEL_7:
    IofCompleteRequest(a2, 0);
    return v4;
  }
  if ( v6 != 18 )
    return v4;
  if ( !v7 )
    goto LABEL_6;
  v12 = 0;
  v13 = 0;
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v14 + 308);
  v15 = (unsigned __int8 *)(v7 + 8);
  v16 = KeAbPreAcquire((unsigned int)(v7 + 8), 0, 0);
  do
    v17 = __ldrex(v15);
  while ( __strex(v17 | 1, v15) );
  __dmb(0xBu);
  if ( (v17 & 1) == 0 )
  {
    if ( v16 )
      *(_BYTE *)(v16 + 14) |= 1u;
    if ( (v7[29] & 4) != 0 )
      v13 = PiDqQueryGetObjectManager(v7);
    __pld(v15);
    v18 = *(_DWORD *)v15;
    if ( (*(_DWORD *)v15 & 0xFFFFFFF0) > 0x10 )
      v19 = v18 - 16;
    else
      v19 = 0;
    if ( (v18 & 2) != 0 )
      goto LABEL_68;
    __dmb(0xBu);
    do
      v20 = __ldrex((unsigned int *)v15);
    while ( v20 == v18 && __strex(v19, (unsigned int *)v15) );
    if ( v20 != v18 )
LABEL_68:
      ExfReleasePushLock(v7 + 8, v18);
    v21 = KeAbPostRelease((unsigned int)(v7 + 8));
    v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v23 = *(_WORD *)(v22 + 0x134) + 1;
    *(_WORD *)(v22 + 308) = v23;
    if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
      KiCheckForKernelApcDelivery(v21);
    if ( v13 )
      PiDqObjectManagerUnregisterQuery(v13, v7);
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v24 + 308);
    v25 = KeAbPreAcquire((unsigned int)(v7 + 8), 0, 0);
    v26 = v25;
    do
      v27 = __ldrex(v15);
    while ( __strex(v27 | 1, v15) );
    __dmb(0xBu);
    if ( (v27 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v7 + 8, v25, (unsigned int)(v7 + 8));
    if ( v26 )
      *(_BYTE *)(v26 + 14) |= 1u;
    v7[29] |= 8u;
    v28 = v7[23];
    if ( v28 )
    {
      __dmb(0xBu);
      v35 = (unsigned int *)(v28 + 56);
      do
        v36 = __ldrex(v35);
      while ( __strex(0, v35) );
      __dmb(0xBu);
      if ( v36 )
      {
        v12 = v7[23];
        v7[23] = 0;
      }
    }
    __pld(v15);
    v29 = *(_DWORD *)v15;
    if ( (*(_DWORD *)v15 & 0xFFFFFFF0) > 0x10 )
      v30 = v29 - 16;
    else
      v30 = 0;
    if ( (v29 & 2) != 0 )
      goto LABEL_72;
    __dmb(0xBu);
    do
      v31 = __ldrex((unsigned int *)v15);
    while ( v31 == v29 && __strex(v30, (unsigned int *)v15) );
    if ( v31 != v29 )
LABEL_72:
      ExfReleasePushLock(v7 + 8, v29);
    v32 = KeAbPostRelease((unsigned int)(v7 + 8));
    v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v34 = *(_WORD *)(v33 + 0x134) + 1;
    *(_WORD *)(v33 + 308) = v34;
    if ( !v34 && *(_DWORD *)(v33 + 100) != v33 + 100 && !*(_WORD *)(v33 + 310) )
      KiCheckForKernelApcDelivery(v32);
    if ( v12 )
    {
      *(_DWORD *)(v12 + 24) = -1073741536;
      *(_DWORD *)(v12 + 28) = 0;
      IofCompleteRequest(v12, 0);
    }
    goto LABEL_6;
  }
  return sub_7C6F64(v16);
}
