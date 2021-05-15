// AlpcpCaptureViewAttributeInternal 
 
int __fastcall AlpcpCaptureViewAttributeInternal(int a1, _DWORD *a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r8
  int v9; // r4
  int v10; // r9
  unsigned __int8 *v11; // r6
  int v12; // r0
  int v13; // r5
  unsigned int v14; // r2
  unsigned int *v15; // r1
  unsigned int v16; // r0
  int v17; // r0
  int v18; // r9
  int v19; // r8
  unsigned int *v20; // r6
  unsigned int v21; // r1
  unsigned int *v22; // r2
  unsigned int v23; // r5
  int v24; // r5
  unsigned int *v25; // r2
  unsigned int v26; // r1
  int v27; // r1
  unsigned int *v28; // r2
  unsigned int v29; // r1
  int v30; // r1
  int v31; // r1
  int v32; // r4
  int v33; // r3
  int v34; // r0
  int v35; // r6
  int v36; // r4
  int v37; // r1
  int v38; // r5
  unsigned int *v39; // r2
  unsigned int v40; // r1
  int v41; // r1
  unsigned int *v42; // r2
  unsigned int v43; // r1
  int v44; // r1
  int v47[8]; // [sp+10h] [bp-20h] BYREF

  v5 = a1;
  v6 = a4;
  if ( (*a2 & 0xFFF8FFFF) != 0 )
    return sub_7F5B58();
  v9 = *(_DWORD *)(a3 + 76);
  v47[0] = v9;
  if ( v9 )
  {
    *(_DWORD *)(a3 + 76) = 0;
    v10 = *(_DWORD *)(v9 + 8);
    v11 = (unsigned __int8 *)(v10 - 4);
    v12 = KeAbPreAcquire(v10 - 4, 0, 0);
    v13 = v12;
    do
      v14 = __ldrex(v11);
    while ( __strex(v14 | 1, v11) );
    __dmb(0xBu);
    if ( (v14 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v10 - 4), v12, v10 - 4);
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    *(_BYTE *)(v10 - 16) |= 1u;
    __dmb(0xBu);
    v15 = (unsigned int *)(v10 - 12);
    do
    {
      v16 = __ldrex(v15);
      v17 = v16 + 0x10000;
    }
    while ( __strex(v17, v15) );
    __dmb(0xBu);
    if ( v17 <= 0 )
      KeBugCheckEx(24, 0, v10, 38, v17);
    v18 = 0;
    --*(_DWORD *)(v9 + 40);
    v19 = *(_DWORD *)(v9 + 8);
    if ( (*(_BYTE *)(v19 - 16) & 1) != 0 )
    {
      v18 = 0x10000 - *(__int16 *)(v19 - 14);
      *(_BYTE *)(v19 - 16) &= 0xFEu;
      *(_WORD *)(v19 - 14) = 0;
    }
    v20 = (unsigned int *)(v19 - 4);
    __dmb(0xBu);
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 - 1, v20) );
    if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v19 - 4));
    KeAbPostRelease(v19 - 4);
    if ( v18 > 0 )
    {
      __dmb(0xBu);
      v22 = (unsigned int *)(v19 - 12);
      do
      {
        v23 = __ldrex(v22);
        v24 = v23 - v18;
      }
      while ( __strex(v24, v22) );
      __dmb(0xBu);
      if ( v24 <= 0 )
      {
        if ( v24 )
          KeBugCheckEx(24, 0, v19, 40, v24);
        AlpcpDestroyBlob(v19);
      }
    }
    if ( (*a2 & 0x10000) != 0 )
    {
      if ( AlpcpDeleteBlob(v9) )
      {
        __dmb(0xBu);
        v25 = (unsigned int *)(v9 - 12);
        do
        {
          v26 = __ldrex(v25);
          v27 = v26 - 1;
        }
        while ( __strex(v27, v25) );
        __dmb(0xBu);
        if ( v27 <= 0 )
        {
          if ( v27 )
            KeBugCheckEx(24, 0, v9, 33, v27);
          AlpcpDestroyBlob(v9);
        }
      }
    }
    __dmb(0xBu);
    v28 = (unsigned int *)(v9 - 12);
    do
    {
      v29 = __ldrex(v28);
      v30 = v29 - 1;
    }
    while ( __strex(v30, v28) );
    __dmb(0xBu);
    if ( v30 <= 0 )
    {
      if ( v30 )
        KeBugCheckEx(24, 0, v9, 33, v30);
      AlpcpDestroyBlob(v9);
    }
    v5 = a1;
    v6 = a4;
  }
  *(_DWORD *)(a3 + 20) &= 0xFFFF7FFF;
  v31 = a2[1];
  if ( !v31 )
    return 0;
  v32 = a2[2];
  if ( !v32 )
    return -1073741503;
  v33 = *(_DWORD *)(v5 + 8);
  if ( !v33 )
    return -1073741816;
  v34 = AlpcReferenceBlobByHandle(v33 + 20, v31, AlpcSectionType);
  v35 = v34;
  if ( !v34 )
    return -1073741816;
  v36 = AlpcpLocateSectionView(v34, v5, v32, v47);
  if ( v36 >= 0 )
  {
    if ( (*a2 & 0x40000) != 0 )
      v37 = (*(_DWORD *)(v35 + 24) >> 1) & 1;
    else
      v37 = 0;
    v38 = v47[0];
    v36 = AlpcpPrepareViewForDelivery(v47[0], v37, (*a2 & 0x20000) != 0);
    if ( v36 < 0 )
    {
      __dmb(0xBu);
      v42 = (unsigned int *)(v38 - 12);
      do
      {
        v43 = __ldrex(v42);
        v44 = v43 - 1;
      }
      while ( __strex(v44, v42) );
      __dmb(0xBu);
      if ( v44 <= 0 )
      {
        if ( v44 )
          KeBugCheckEx(24, 0, v38, 33, v44);
        AlpcpDestroyBlob(v38);
      }
    }
    else
    {
      *(_DWORD *)(v6 + 20) = v38;
    }
  }
  __dmb(0xBu);
  v39 = (unsigned int *)(v35 - 12);
  do
  {
    v40 = __ldrex(v39);
    v41 = v40 - 1;
  }
  while ( __strex(v41, v39) );
  __dmb(0xBu);
  if ( v41 <= 0 )
  {
    if ( v41 )
      KeBugCheckEx(24, 0, v35, 33, v41);
    AlpcpDestroyBlob(v35);
  }
  return v36;
}
