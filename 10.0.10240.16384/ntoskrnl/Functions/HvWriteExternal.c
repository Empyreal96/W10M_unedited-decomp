// HvWriteExternal 
 
int __fastcall HvWriteExternal(_DWORD *a1)
{
  int v2; // r4
  unsigned int v3; // r10
  _DWORD *v4; // r5
  unsigned int v5; // r7
  int v6; // r0
  _DWORD *v7; // r8
  int v8; // r0
  int v9; // r9
  int v10; // r0
  int v11; // r0
  int *v12; // r7
  int (__fastcall *v13)(_DWORD *, int, unsigned int *, int, unsigned int *, _DWORD); // r4
  int v14; // r4
  unsigned int v15; // r7
  int v16; // r0
  _DWORD *v17; // r8
  int v18; // r0
  int v19; // r10
  int v20; // r9
  unsigned int v21; // r0
  int v22; // r1
  _BYTE *v23; // r0
  int (__fastcall *v24)(_DWORD *, int, unsigned int *, int, unsigned int *, _DWORD); // r4
  int v25; // r0
  char v27[4]; // [sp+8h] [bp-40h] BYREF
  unsigned int v28; // [sp+Ch] [bp-3Ch] BYREF
  int v29; // [sp+10h] [bp-38h] BYREF
  int v30; // [sp+14h] [bp-34h]
  unsigned int v31; // [sp+18h] [bp-30h]
  unsigned int v32; // [sp+20h] [bp-28h] BYREF
  int *v33; // [sp+24h] [bp-24h]
  int v34; // [sp+28h] [bp-20h]

  v27[0] = 0;
  v29 = -1;
  if ( !a1[446] )
    return -1073741811;
  v31 = a1[238];
  v3 = v31;
  v2 = CmpDoFileSetSizeEx((int)a1, 2, v31 + 4096, 0, 0);
  if ( v2 < 0 )
    return v2;
  v4 = 0;
  v5 = 0;
  if ( v31 )
  {
    do
    {
      v6 = HvpGetCellMap((int)a1, v5);
      v7 = (_DWORD *)v6;
      if ( !v6 )
        KeBugCheckEx(81, 1, (int)a1, v5, 2906);
      v4 = 0;
      v8 = HvpMapEntryGetFreeBin(v6);
      if ( v8 )
      {
        v9 = *(_DWORD *)(v8 + 8);
        if ( (*(_DWORD *)(v8 + 16) & 1) == 0 )
          goto LABEL_15;
        v10 = HvpMapEntryGetBinAddress(v8, v7, v27, &v29);
        v4 = (_DWORD *)v10;
      }
      else
      {
        v10 = HvpMapEntryGetBinAddress(0, v7, v27, &v29);
        v9 = *(_DWORD *)(v10 + 8);
        v4 = (_DWORD *)v10;
      }
      if ( v4 )
      {
        if ( v9 + v5 > a1[238] || (v9 & 0xFFF) != 0 )
        {
          if ( v27[0] )
          {
            HvpMapEntryReleaseBinAddress(v10, (int)v7);
            v27[0] = 0;
          }
          v2 = -1073741492;
          break;
        }
        if ( v27[0] )
        {
          HvpMapEntryReleaseBinAddress(v10, (int)v7);
          v27[0] = 0;
        }
      }
LABEL_15:
      v5 += v9;
    }
    while ( v5 < v3 );
  }
  if ( v5 < a1[238] )
    return v2;
  v11 = ExAllocatePoolWithTag(5, 4096, 538987843);
  v12 = (int *)v11;
  if ( !v11 )
    return -1073741670;
  memmove(v11, a1[8], 0x1000u);
  v12[10] = v3;
  v12[11] = 1;
  v12[127] = HvpHeaderCheckSum(v12);
  v28 = 0;
  v32 = 0;
  v33 = v12;
  v13 = (int (__fastcall *)(_DWORD *, int, unsigned int *, int, unsigned int *, _DWORD))a1[5];
  v34 = 4096;
  v14 = v13(a1, 2, &v32, 1, &v28, 0);
  ExFreePoolWithTag((unsigned int)v12);
  if ( !v14 )
    return -1073741491;
  v15 = 0;
  v28 = (v28 + 4095) & 0xFFFFF000;
  if ( v3 )
  {
    while ( 1 )
    {
      v16 = HvpGetCellMap((int)a1, v15);
      v17 = (_DWORD *)v16;
      if ( !v16 )
        KeBugCheckEx(81, 1, (int)a1, v15, 3023);
      v18 = HvpMapEntryGetFreeBin(v16);
      v19 = v18;
      if ( !v18 )
        break;
      v20 = *(_DWORD *)(v18 + 8);
      if ( (*(_DWORD *)(v18 + 16) & 1) != 0 )
      {
        v21 = HvpMapEntryGetBinAddress(v18, v17, v27, &v29);
LABEL_31:
        v30 = (unsigned __int8)v27[0];
        goto LABEL_32;
      }
      v22 = *(_DWORD *)(v18 + 8);
      v30 = 0;
      v27[0] = 0;
      v23 = (_BYTE *)ExAllocatePoolWithTag(1, v22, 1648905539);
      v4 = v23;
      if ( !v23 )
        return -1073741670;
      memset(v23, 0, v20);
      *v4 = 1852400232;
      v4[1] = v15;
      v4[2] = v20;
      v4[8] = v20 - 32;
      v21 = (unsigned int)v4;
LABEL_32:
      v24 = (int (__fastcall *)(_DWORD *, int, unsigned int *, int, unsigned int *, _DWORD))a1[5];
      v32 = v28;
      v33 = (int *)v21;
      v34 = v20;
      v25 = v24(a1, 2, &v32, 1, &v28, 0);
      if ( !v25 )
      {
        if ( v30 )
          HvpMapEntryReleaseBinAddress(0, (int)v17);
        return -1073741491;
      }
      if ( v19 && (*(_DWORD *)(v19 + 16) & 1) == 0 )
        v25 = ExFreePoolWithTag((unsigned int)v4);
      if ( v30 )
      {
        HvpMapEntryReleaseBinAddress(v25, (int)v17);
        v27[0] = 0;
      }
      v15 += v20;
      if ( v15 >= v31 )
        goto LABEL_39;
    }
    v21 = HvpMapEntryGetBinAddress(0, v17, v27, &v29);
    v20 = *(_DWORD *)(v21 + 8);
    v4 = (_DWORD *)v21;
    goto LABEL_31;
  }
LABEL_39:
  if ( !CmpFileFlush((int)a1, 2) )
    return -1073741491;
  return 0;
}
