// AlpcpCreateSectionView 
 
int __fastcall AlpcpCreateSectionView(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v6; // r6
  unsigned __int8 *v7; // r9
  int v9; // r0
  unsigned int v10; // r5
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int v14; // r1
  int v15; // r0
  char v16; // r2
  int v17; // r5
  int v18; // r7
  int v19; // r3
  unsigned int *v20; // r4
  unsigned int v21; // r1
  unsigned int *v22; // r2
  unsigned int v23; // r0
  int v24; // r0
  int v25; // r5
  int v26; // r4
  unsigned __int8 *v27; // r7
  int v28; // r0
  int v29; // r6
  unsigned int v30; // r2
  unsigned int *v31; // r1
  unsigned int v32; // r2
  int v33; // r2
  int v34; // r0
  char v35; // r2
  int v36; // r8
  int v37; // r3
  unsigned int *v38; // r6
  unsigned int v39; // r1
  unsigned int *v40; // r2
  unsigned int v41; // r0
  int v42; // r0
  unsigned int *v43; // r2
  unsigned int v44; // r1
  int v45; // r1
  int v47; // [sp+Ch] [bp-24h] BYREF
  int v48; // [sp+10h] [bp-20h]

  v6 = a1 - 24;
  v7 = (unsigned __int8 *)(a1 - 4);
  v48 = a2;
  *a5 = 0;
  v9 = KeAbPreAcquire(a1 - 4, 0, 0);
  do
    v10 = __ldrex(v7);
  while ( __strex(v10 | 1, v7) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    return sub_7F5D8C(v9);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  *(_BYTE *)(v6 + 8) |= 1u;
  __dmb(0xBu);
  v12 = (unsigned int *)(v6 + 12);
  do
  {
    v13 = __ldrex(v12);
    v14 = v13 + 0x10000;
  }
  while ( __strex(v14, v12) );
  __dmb(0xBu);
  if ( v14 <= 0 )
    KeBugCheckEx(24, 0, a1, 38, v14);
  v15 = AlpcpCreateRegion(a1, a3, a4, &v47);
  v16 = *(_BYTE *)(v6 + 8);
  v17 = 0;
  v18 = v15;
  if ( (v16 & 1) != 0 )
  {
    v19 = *(__int16 *)(v6 + 10);
    *(_WORD *)(v6 + 10) = 0;
    v17 = 0x10000 - v19;
    *(_BYTE *)(v6 + 8) = v16 & 0xFE;
  }
  v20 = (unsigned int *)(v6 + 20);
  __dmb(0xBu);
  do
    v21 = __ldrex(v20);
  while ( __strex(v21 - 1, v20) );
  if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v6 + 20));
  KeAbPostRelease(v6 + 20);
  if ( v17 > 0 )
  {
    __dmb(0xBu);
    v22 = (unsigned int *)(v6 + 12);
    do
    {
      v23 = __ldrex(v22);
      v24 = v23 - v17;
    }
    while ( __strex(v24, v22) );
    __dmb(0xBu);
    if ( v24 <= 0 )
    {
      if ( v24 )
        KeBugCheckEx(24, 0, a1, 40, v24);
      AlpcpDestroyBlob(a1);
    }
  }
  if ( v18 >= 0 )
  {
    v25 = v47;
    v26 = v47 - 24;
    v27 = (unsigned __int8 *)(v47 - 4);
    v28 = KeAbPreAcquire(v47 - 4, 0, 0);
    v29 = v28;
    do
      v30 = __ldrex(v27);
    while ( __strex(v30 | 1, v27) );
    __dmb(0xBu);
    if ( (v30 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v27, v28, (unsigned int)v27);
    if ( v29 )
      *(_BYTE *)(v29 + 14) |= 1u;
    *(_BYTE *)(v26 + 8) |= 1u;
    __dmb(0xBu);
    v31 = (unsigned int *)(v26 + 12);
    do
    {
      v32 = __ldrex(v31);
      v33 = v32 + 0x10000;
    }
    while ( __strex(v33, v31) );
    __dmb(0xBu);
    if ( v33 <= 0 )
      KeBugCheckEx(24, 0, v25, 38, v33);
    v34 = AlpcpCreateView(v25, v48, &v47);
    v35 = *(_BYTE *)(v26 + 8);
    v18 = v34;
    v36 = 0;
    if ( (v35 & 1) != 0 )
    {
      v37 = *(__int16 *)(v26 + 10);
      *(_WORD *)(v26 + 10) = 0;
      v36 = 0x10000 - v37;
      *(_BYTE *)(v26 + 8) = v35 & 0xFE;
    }
    v38 = (unsigned int *)(v26 + 20);
    __dmb(0xBu);
    do
      v39 = __ldrex(v38);
    while ( __strex(v39 - 1, v38) );
    if ( (v39 & 2) != 0 && (v39 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v26 + 20));
    KeAbPostRelease(v26 + 20);
    if ( v36 > 0 )
    {
      __dmb(0xBu);
      v40 = (unsigned int *)(v26 + 12);
      do
      {
        v41 = __ldrex(v40);
        v42 = v41 - v36;
      }
      while ( __strex(v42, v40) );
      __dmb(0xBu);
      if ( v42 <= 0 )
      {
        if ( v42 )
          KeBugCheckEx(24, 0, v25, 40, v42);
        AlpcpDestroyBlob(v25);
      }
    }
    __dmb(0xBu);
    v43 = (unsigned int *)(v25 - 12);
    do
    {
      v44 = __ldrex(v43);
      v45 = v44 - 1;
    }
    while ( __strex(v45, v43) );
    __dmb(0xBu);
    if ( v45 <= 0 )
    {
      if ( v45 )
        KeBugCheckEx(24, 0, v25, 33, v45);
      AlpcpDestroyBlob(v25);
    }
    if ( v18 >= 0 )
    {
      v18 = 0;
      *a5 = v47;
    }
  }
  return v18;
}
