// AlpcpReleaseMessageAttributesOnCancel 
 
int __fastcall AlpcpReleaseMessageAttributesOnCancel(_DWORD *a1, int a2)
{
  int v3; // r0
  int v4; // r5
  int result; // r0
  int v6; // r3
  unsigned int *v7; // r2
  unsigned int v8; // r5
  signed int v9; // r5
  unsigned int *v10; // r2
  unsigned int v11; // r1
  int v12; // r1
  int v13; // r9
  unsigned __int8 *v14; // r7
  int v15; // r0
  int v16; // r6
  unsigned int v17; // r2
  unsigned int *v18; // r1
  unsigned int v19; // r0
  int v20; // r0
  int v21; // r7
  int v22; // r9
  char v23; // r2
  int v24; // r3
  unsigned int *v25; // r8
  unsigned int v26; // r1
  unsigned int *v27; // r2
  unsigned int v28; // r6
  int v29; // r6
  unsigned int *v30; // r2
  unsigned int v31; // r1
  int v32; // r1

  v3 = a1[18];
  if ( v3 )
  {
    __dmb(0xBu);
    v7 = (unsigned int *)(v3 - 12);
    do
    {
      v8 = __ldrex(v7);
      v9 = v8 - 1;
    }
    while ( __strex(v9, v7) );
    __dmb(0xBu);
    if ( v9 <= 0 )
      return sub_7E60F0();
    a1[18] = 0;
  }
  v4 = a1[19];
  if ( v4 && (!a2 || (a1[5] & 0x8000) == 0) )
  {
    v13 = *(_DWORD *)(v4 + 8);
    v14 = (unsigned __int8 *)(v13 - 4);
    v15 = KeAbPreAcquire(v13 - 4, 0, 0);
    v16 = v15;
    do
      v17 = __ldrex(v14);
    while ( __strex(v17 | 1, v14) );
    __dmb(0xBu);
    if ( (v17 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v13 - 4), v15, v13 - 4);
    if ( v16 )
      *(_BYTE *)(v16 + 14) |= 1u;
    *(_BYTE *)(v13 - 16) |= 1u;
    __dmb(0xBu);
    v18 = (unsigned int *)(v13 - 12);
    do
    {
      v19 = __ldrex(v18);
      v20 = v19 + 0x10000;
    }
    while ( __strex(v20, v18) );
    __dmb(0xBu);
    if ( v20 <= 0 )
      KeBugCheckEx(24, 0, v13, 38, v20);
    v21 = *(_DWORD *)(v4 + 8);
    v22 = 0;
    --*(_DWORD *)(v4 + 40);
    v23 = *(_BYTE *)(v21 - 16);
    if ( (v23 & 1) != 0 )
    {
      v24 = *(__int16 *)(v21 - 14);
      *(_WORD *)(v21 - 14) = 0;
      v22 = 0x10000 - v24;
      *(_BYTE *)(v21 - 16) = v23 & 0xFE;
    }
    v25 = (unsigned int *)(v21 - 4);
    __dmb(0xBu);
    do
      v26 = __ldrex(v25);
    while ( __strex(v26 - 1, v25) );
    if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v21 - 4));
    KeAbPostRelease(v21 - 4);
    if ( v22 > 0 )
    {
      __dmb(0xBu);
      v27 = (unsigned int *)(v21 - 12);
      do
      {
        v28 = __ldrex(v27);
        v29 = v28 - v22;
      }
      while ( __strex(v29, v27) );
      __dmb(0xBu);
      if ( v29 <= 0 )
      {
        if ( v29 )
          KeBugCheckEx(24, 0, v21, 40, v29);
        AlpcpDestroyBlob(v21);
      }
    }
    __dmb(0xBu);
    v30 = (unsigned int *)(v4 - 12);
    do
    {
      v31 = __ldrex(v30);
      v32 = v31 - 1;
    }
    while ( __strex(v32, v30) );
    __dmb(0xBu);
    if ( v32 <= 0 )
    {
      if ( v32 )
        KeBugCheckEx(24, 0, v4, 33, v32);
      AlpcpDestroyBlob(v4);
    }
    a1[19] = 0;
  }
  result = a1[20];
  if ( result )
  {
    __dmb(0xBu);
    v10 = (unsigned int *)(result - 12);
    do
    {
      v11 = __ldrex(v10);
      v12 = v11 - 1;
    }
    while ( __strex(v12, v10) );
    __dmb(0xBu);
    if ( v12 <= 0 )
    {
      if ( v12 )
        KeBugCheckEx(24, 0, result, 33, v12);
      result = AlpcpDestroyBlob(result);
    }
    a1[20] = 0;
  }
  v6 = a1[21];
  if ( v6 )
  {
    if ( (v6 & 1) != 0 )
      result = ObfDereferenceObject(v6 & 0xFFFFFFFE);
    a1[21] = 0;
  }
  return result;
}
