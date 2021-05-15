// ObpCallPreOperationCallbacks 
 
int __fastcall ObpCallPreOperationCallbacks(int a1, int *a2, _DWORD *a3)
{
  _DWORD *v3; // r6
  _DWORD *v7; // r10
  unsigned int *v8; // r7
  unsigned int v9; // r4
  unsigned int v10; // r4
  unsigned int *v11; // r5
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  unsigned int *v15; // r4
  unsigned int v16; // r0
  unsigned int v17; // r1
  int v18; // r1
  unsigned int v19; // r0
  unsigned int v20; // r2
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3
  unsigned int v24; // r4
  unsigned int v25; // r1
  _DWORD *v26; // r0
  _DWORD *v27; // r2
  void (__fastcall *v28)(_DWORD, int *); // r2
  unsigned int v29; // r2
  int v30; // r0
  int v31; // r4
  unsigned int v32; // r2
  int v33; // r1
  unsigned int v34; // r0
  unsigned int *v35; // r0
  unsigned int v36; // r4
  unsigned int v37; // r1
  int v38; // r4
  int v39; // r3
  int v40; // r0
  __int16 v41; // r3
  unsigned int v42; // r2
  int v43; // r0
  unsigned int v44; // r1
  __int16 v45; // r3
  unsigned int v46; // r0
  unsigned int v47; // r1
  int v48; // r0
  unsigned int v49; // r1
  __int16 v50; // r3
  _DWORD *v52; // [sp+0h] [bp-40h]
  int v53[14]; // [sp+8h] [bp-38h] BYREF

  v3 = (_DWORD *)(a1 + 136);
  v52 = (_DWORD *)(a1 + 136);
  v7 = 0;
  v8 = 0;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  ObfReferenceObjectWithTag(a2[2]);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v10 + 310);
  v11 = (unsigned int *)(a1 + 128);
  v12 = KeAbPreAcquire((unsigned int)v11, 0, 0);
  v13 = v12;
  do
    v14 = __ldrex(v11);
  while ( !v14 && __strex(0x11u, v11) );
  __dmb(0xBu);
  if ( v14 )
    ExfAcquirePushLockSharedEx(v11, v12, (unsigned int)v11);
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  while ( 1 )
  {
    while ( 1 )
    {
      v3 = (_DWORD *)*v3;
      if ( v3 == v52 )
      {
        __pld(v11);
        v33 = *v11;
        if ( (*v11 & 0xFFFFFFF0) <= 0x10 )
          v34 = 0;
        else
          v34 = v33 - 16;
        if ( (v33 & 2) != 0 )
          goto LABEL_71;
        __dmb(0xBu);
        do
          v42 = __ldrex(v11);
        while ( v42 == v33 && __strex(v34, v11) );
        if ( v42 != v33 )
LABEL_71:
          ExfReleasePushLock(v11, v33);
        v43 = KeAbPostRelease((unsigned int)v11);
        v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v45 = *(_WORD *)(v44 + 0x136) + 1;
        *(_WORD *)(v44 + 310) = v45;
        if ( !v45 && *(_DWORD *)(v44 + 100) != v44 + 100 )
          KiCheckForKernelApcDelivery(v43);
        if ( v8 )
        {
          __pld(v8);
          v46 = *v8 & 0xFFFFFFFE;
          __dmb(0xBu);
          do
            v47 = __ldrex(v8);
          while ( v47 == v46 && __strex(v46 - 2, v8) );
          if ( v47 != v46 )
            ExfReleaseRundownProtection((unsigned __int8 *)v8);
        }
        if ( (_DWORD *)*a3 == a3 )
        {
          v48 = ObfDereferenceObjectWithTag(a2[2]);
          v49 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v50 = *(_WORD *)(v49 + 0x134) + 1;
          *(_WORD *)(v49 + 308) = v50;
          if ( !v50 && *(_DWORD *)(v49 + 100) != v49 + 100 && !*(_WORD *)(v49 + 310) )
            KiCheckForKernelApcDelivery(v48);
        }
        return 0;
      }
      if ( (v3[3] & 1) != 0 && (v3[2] & *a2) != 0 )
      {
        v15 = v3 + 8;
        __pld(v3 + 8);
        v16 = v3[8] & 0xFFFFFFFE;
        do
          v17 = __ldrex(v15);
        while ( v17 == v16 && __strex(v16 + 2, v15) );
        __dmb(0xBu);
        if ( v17 == v16 || ExfAcquireRundownProtection(v3 + 8) )
          break;
      }
    }
    __pld(v11);
    v18 = *v11;
    v19 = *v11 - 16;
    if ( (*v11 & 0xFFFFFFF0) <= 0x10 )
      v19 = 0;
    if ( (v18 & 2) != 0 )
      goto LABEL_22;
    __dmb(0xBu);
    do
      v20 = __ldrex(v11);
    while ( v20 == v18 && __strex(v19, v11) );
    if ( v20 != v18 )
LABEL_22:
      ExfReleasePushLock(v11, v18);
    v21 = KeAbPostRelease((unsigned int)v11);
    v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v23 = *(_WORD *)(v22 + 0x136) + 1;
    *(_WORD *)(v22 + 310) = v23;
    if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 )
      KiCheckForKernelApcDelivery(v21);
    if ( v8 )
    {
      __pld(v8);
      v24 = *v8 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v25 = __ldrex(v8);
      while ( v25 == v24 && __strex(v24 - 2, v8) );
      if ( v25 != v24 )
        ExfReleaseRundownProtection((unsigned __int8 *)v8);
      v8 = 0;
      v15 = v3 + 8;
    }
    if ( v3[7] )
      break;
LABEL_37:
    v28 = (void (__fastcall *)(_DWORD, int *))v3[6];
    if ( v28 )
    {
      v28(*(_DWORD *)(v3[4] + 4), a2);
      if ( v3[7] )
        v7[3] = a2[4];
      else
        v8 = v15;
      a2[4] = 0;
    }
    v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v29 + 310);
    v30 = KeAbPreAcquire((unsigned int)v11, 0, 0);
    v31 = v30;
    do
      v32 = __ldrex(v11);
    while ( !v32 && __strex(0x11u, v11) );
    __dmb(0xBu);
    if ( v32 )
      ExfAcquirePushLockSharedEx(v11, v30, (unsigned int)v11);
    if ( v31 )
      *(_BYTE *)(v31 + 14) |= 1u;
  }
  v26 = (_DWORD *)ExAllocatePoolWithTag(1, 16, 1816552015);
  v7 = v26;
  if ( v26 )
  {
    v26[2] = v3;
    v26[3] = 0;
    v27 = (_DWORD *)a3[1];
    *v26 = a3;
    v26[1] = v27;
    if ( (_DWORD *)*v27 != a3 )
      __fastfail(3u);
    *v27 = v26;
    a3[1] = v26;
    goto LABEL_37;
  }
  v35 = v3 + 8;
  __pld(v3 + 8);
  v36 = v3[8] & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v37 = __ldrex(v35);
  while ( v37 == v36 && __strex(v36 - 2, v35) );
  if ( v37 != v36 )
    ExfReleaseRundownProtection((unsigned __int8 *)v35);
  v38 = -1073741670;
  if ( (_DWORD *)*a3 == a3 )
  {
    v40 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v41 = *(_WORD *)(v40 + 0x134) + 1;
    *(_WORD *)(v40 + 308) = v41;
    if ( !v41 && *(_DWORD *)(v40 + 100) != v40 + 100 && !*(_WORD *)(v40 + 310) )
      KiCheckForKernelApcDelivery(v40);
    ObfDereferenceObjectWithTag(a2[2]);
  }
  else
  {
    memset(v53, 0, 28);
    v53[0] = *a2;
    v39 = a2[1];
    v53[5] = -1073741670;
    v53[1] = v39;
    v53[3] = a2[3];
    v53[2] = a2[2];
    ObpCallPostOperationCallbacks((int)v53, a3);
  }
  return v38;
}
