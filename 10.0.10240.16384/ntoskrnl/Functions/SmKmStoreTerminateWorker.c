// SmKmStoreTerminateWorker 
 
int __fastcall SmKmStoreTerminateWorker(int a1)
{
  int v2; // r7
  int *v3; // r6
  int v4; // t1
  unsigned int v5; // r1
  int *v6; // r0
  _DWORD *v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r1
  _DWORD *v11; // r8
  int *v12; // r6
  int v13; // r2
  _BYTE *v14; // r0
  int v15; // r1
  int v16; // r2
  _DWORD *v17; // r3
  int v18; // r1
  _DWORD *v19; // r0
  _DWORD *v20; // r3
  int v21; // r4
  _DWORD *v22; // r0
  unsigned int v23; // r4
  unsigned int v24; // r1
  const __int16 *v25; // r2
  __int64 v26; // r0
  unsigned int v27; // [sp+20h] [bp-578h]
  int v28[12]; // [sp+38h] [bp-560h] BYREF
  int v29[18]; // [sp+68h] [bp-530h] BYREF
  int v30[282]; // [sp+B0h] [bp-4E8h] BYREF
  _DWORD v31[4]; // [sp+518h] [bp-80h] BYREF
  char v32[80]; // [sp+528h] [bp-70h] BYREF

  v31[0] = 0;
  v31[1] = 0;
  v31[2] = 0;
  v31[3] = 0;
  memset(v32, 0, sizeof(v32));
  memset(v29, 0, 68);
  v29[0] = v29[0] & 0xFFFFFF00 | 1;
  if ( ZwQuerySystemInformation() >= 0
    && (memset(v30, 0, sizeof(v30)), v2 = 0, v30[0] = v30[0] & 0xFFFFFE00 | 0x103, (v29[0] & 0xFF00) != 0) )
  {
    v3 = v29;
    while ( 1 )
    {
      v4 = v3[1];
      ++v3;
      v30[1] = v4;
      if ( ZwQuerySystemInformation() >= 0 )
      {
        v5 = 0;
        if ( v30[4] )
          break;
      }
LABEL_10:
      if ( ++v2 >= (unsigned int)BYTE1(v29[0]) )
        goto LABEL_11;
    }
    v6 = &v30[2];
    while ( (((1 << v5) & v30[24]) == 0) != *(_DWORD *)(a1 + 28) || v6[6] != *(_DWORD *)(a1 + 24) )
    {
      ++v5;
      ++v6;
      if ( v5 >= v30[4] )
        goto LABEL_10;
    }
    memset(v28, 0, 24);
    v28[3] = 6;
    v28[1] = (int)v30;
    v28[5] = 1036;
    v11 = v31;
    v28[0] = (int)v31;
    if ( (dword_636E9C & 0x40) != 0 )
    {
      v12 = (int *)&unk_636E90;
      v13 = v28[4];
      v14 = (char *)v30 + v28[4];
      if ( a1 != -32 )
        *v14 = *(_BYTE *)(a1 + 32);
      v15 = v28[2];
      v16 = v13 + 1;
      v17 = &v31[4 * v28[2]];
      *v17 = v14;
      v17[1] = 0;
      v17[2] = 1;
      v17[3] = 0;
      v18 = v15 + 1;
      v19 = (int *)((char *)v30 + v16);
      if ( a1 != -36 )
        *v19 = *(_DWORD *)(a1 + 36);
      v20 = &v31[4 * v18];
      *v20 = v19;
      v20[1] = 0;
      v20[2] = 4;
      v20[3] = 0;
      v21 = *(_DWORD *)(a1 + 20);
      v28[2] = v18 + 1;
      v28[4] = v16 + 4;
      SmKmEtwAppendProductName(v28, v21, v16 + 4, (int)v20);
      SmKmEtwAppendObjectName(v28, *(_DWORD *)(v21 + 4));
      v11 = (_DWORD *)v28[0];
    }
    else
    {
      v12 = 0;
    }
    v22 = (_DWORD *)(*(_DWORD *)(a1 + 16) + 96 * (*(_DWORD *)(a1 + 24) & 0x1F) + 4);
    __pld(v22);
    v23 = *v22 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v24 = __ldrex(v22);
    while ( v24 == v23 && __strex(v23 - 2, v22) );
    if ( v24 != v23 )
      ExfReleaseRundownProtection((unsigned __int8 *)v22);
    v28[6] = 1;
    v28[7] = v29[v2 + 1];
    if ( ZwSetSystemInformation() >= 0 )
    {
      if ( v12 )
      {
        EtwWriteEx(*v12, v12[1], (int)SmEventCacheTermination, v28[2], 0, 0, 0, 0, 0, v28[2], (int)v11);
        if ( !*(_DWORD *)(a1 + 32) )
        {
          v27 = v11[14];
          memmove((int)v30, v11[12], v27);
          *((_WORD *)v30 + (v27 >> 1)) = 0;
          v25 = (const __int16 *)v30;
          if ( !LOWORD(v30[0]) )
            v25 = L"(null)";
          v28[8] = 2;
          v28[9] = (int)v25;
          v26 = *(_QWORD *)v12;
          v28[11] = *(_DWORD *)(a1 + 36);
          v28[10] = 1;
          SmKmSqmAddToStream(v26, HIDWORD(v26));
        }
      }
    }
  }
  else
  {
LABEL_11:
    v7 = (_DWORD *)(*(_DWORD *)(a1 + 16) + 96 * (*(_DWORD *)(a1 + 24) & 0x1F) + 4);
    __pld(v7);
    v8 = *v7 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v9 = __ldrex(v7);
    while ( v9 == v8 && __strex(v8 - 2, v7) );
    if ( v9 != v8 )
      ExfReleaseRundownProtection((unsigned __int8 *)v7);
  }
  return ExFreePoolWithTag(a1);
}
