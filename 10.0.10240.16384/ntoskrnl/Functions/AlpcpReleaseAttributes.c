// AlpcpReleaseAttributes 
 
int __fastcall __spoils<R0,R2,R3,R12> AlpcpReleaseAttributes(_DWORD *a1)
{
  int v2; // r0
  int v3; // r5
  int result; // r0
  int v5; // r3
  unsigned int *v6; // r2
  unsigned int v7; // r1
  signed int v8; // r1
  int v9; // r9
  unsigned __int8 *v10; // r7
  int v11; // r0
  int v12; // r6
  unsigned int v13; // r2
  unsigned int *v14; // r1
  unsigned int v15; // r0
  int v16; // r0
  int v17; // r7
  int v18; // r9
  char v19; // r2
  int v20; // r3
  unsigned int *v21; // r8
  unsigned int v22; // r1
  unsigned int *v23; // r2
  unsigned int v24; // r6
  int v25; // r6
  unsigned int *v26; // r2
  unsigned int v27; // r1
  int v28; // r1
  unsigned int *v29; // r2
  unsigned int v30; // r1
  int v31; // r1

  v2 = a1[4];
  if ( v2 )
  {
    __dmb(0xBu);
    v6 = (unsigned int *)(v2 - 12);
    do
    {
      v7 = __ldrex(v6);
      v8 = v7 - 1;
    }
    while ( __strex(v8, v6) );
    __dmb(0xBu);
    if ( v8 <= 0 )
    {
      if ( v8 )
        sub_7F42DC();
      AlpcpDestroyBlob(v2);
    }
    a1[4] = 0;
  }
  v3 = a1[5];
  if ( v3 )
  {
    v9 = *(_DWORD *)(v3 + 8);
    v10 = (unsigned __int8 *)(v9 - 4);
    v11 = KeAbPreAcquire(v9 - 4, 0, 0);
    v12 = v11;
    do
      v13 = __ldrex(v10);
    while ( __strex(v13 | 1, v10) );
    __dmb(0xBu);
    if ( (v13 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v9 - 4), v11, v9 - 4);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    *(_BYTE *)(v9 - 16) |= 1u;
    __dmb(0xBu);
    v14 = (unsigned int *)(v9 - 12);
    do
    {
      v15 = __ldrex(v14);
      v16 = v15 + 0x10000;
    }
    while ( __strex(v16, v14) );
    __dmb(0xBu);
    if ( v16 <= 0 )
      KeBugCheckEx(24, 0, v9, 38, v16);
    v17 = *(_DWORD *)(v3 + 8);
    v18 = 0;
    --*(_DWORD *)(v3 + 40);
    v19 = *(_BYTE *)(v17 - 16);
    if ( (v19 & 1) != 0 )
    {
      v20 = *(__int16 *)(v17 - 14);
      *(_WORD *)(v17 - 14) = 0;
      v18 = 0x10000 - v20;
      *(_BYTE *)(v17 - 16) = v19 & 0xFE;
    }
    v21 = (unsigned int *)(v17 - 4);
    __dmb(0xBu);
    do
      v22 = __ldrex(v21);
    while ( __strex(v22 - 1, v21) );
    if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v17 - 4));
    KeAbPostRelease(v17 - 4);
    if ( v18 > 0 )
    {
      __dmb(0xBu);
      v23 = (unsigned int *)(v17 - 12);
      do
      {
        v24 = __ldrex(v23);
        v25 = v24 - v18;
      }
      while ( __strex(v25, v23) );
      __dmb(0xBu);
      if ( v25 <= 0 )
      {
        if ( v25 )
          KeBugCheckEx(24, 0, v17, 40, v25);
        AlpcpDestroyBlob(v17);
      }
    }
    __dmb(0xBu);
    v26 = (unsigned int *)(v3 - 12);
    do
    {
      v27 = __ldrex(v26);
      v28 = v27 - 1;
    }
    while ( __strex(v28, v26) );
    __dmb(0xBu);
    if ( v28 <= 0 )
    {
      if ( v28 )
        KeBugCheckEx(24, 0, v3, 33, v28);
      AlpcpDestroyBlob(v3);
    }
    a1[5] = 0;
  }
  result = a1[6];
  if ( result )
  {
    __dmb(0xBu);
    v29 = (unsigned int *)(result - 12);
    do
    {
      v30 = __ldrex(v29);
      v31 = v30 - 1;
    }
    while ( __strex(v31, v29) );
    __dmb(0xBu);
    if ( v31 <= 0 )
    {
      if ( v31 )
        KeBugCheckEx(24, 0, result, 33, v31);
      result = AlpcpDestroyBlob(result);
    }
    a1[6] = 0;
  }
  v5 = a1[7];
  if ( v5 )
  {
    if ( (v5 & 1) != 0 )
      result = ObfDereferenceObject(v5 & 0xFFFFFFFE);
    a1[7] = 0;
  }
  return result;
}
