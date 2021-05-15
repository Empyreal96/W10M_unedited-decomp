// HvpMapHiveImage 
 
int __fastcall HvpMapHiveImage(int a1, unsigned int a2, int a3, int a4, _DWORD *a5)
{
  int v6; // r4
  unsigned int v7; // r7
  int v8; // r6
  int v9; // r5
  int v10; // r8
  int v11; // r10
  int v12; // r0
  unsigned int v13; // r2
  unsigned int v14; // r3
  int v15; // r1
  int v16; // r7
  unsigned int v17; // r4
  char v18; // r3
  unsigned int v20; // r4
  int v21; // r4
  unsigned int v22; // [sp+10h] [bp-40h]
  int v23; // [sp+14h] [bp-3Ch] BYREF
  int v24; // [sp+18h] [bp-38h] BYREF
  int v25; // [sp+1Ch] [bp-34h]
  unsigned int v26; // [sp+20h] [bp-30h] BYREF
  int v27[2]; // [sp+24h] [bp-2Ch] BYREF
  unsigned int v28; // [sp+2Ch] [bp-24h]

  v25 = 0;
  v27[1] = *(_DWORD *)(a1 + 28);
  v28 = a2;
  v6 = HvpInitMap();
  if ( v6 >= 0 )
  {
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    v23 = 0;
    v24 = 0;
    v11 = 0;
    while ( 1 )
    {
      v12 = HvpReadHiveDataFromFile(a5, v27, &v26);
      if ( v12 < 0 )
        break;
      v13 = v26;
      v14 = 0;
      v22 = 0;
      if ( v26 )
      {
        v15 = v27[0];
LABEL_6:
        if ( v7 )
          goto LABEL_16;
        v16 = v25;
        v17 = v14 + v15;
        if ( HvpValidateLoadedBin(v14 + v15, v25, v28) )
          v10 = *(_DWORD *)(v17 + 8);
        else
          v10 = 4096;
        if ( HvpAllocateBin(a1, v10, 0, v16, 825445699, &v24, &v23) < 0 )
          JUMPOUT(0x805BC4);
        v8 = v23;
        v9 = v24;
        if ( v23 )
        {
          v11 = v23;
        }
        else
        {
          v11 = v24;
          if ( v24 )
          {
            v18 = 0;
            goto LABEL_13;
          }
        }
        v18 = 1;
LABEL_13:
        if ( HvpProtectBin(a1, v10, 0, v16, v11, v18) < 0 )
          return sub_805BC0();
        v14 = v22;
        v13 = v26;
        v15 = v27[0];
        v7 = v10;
LABEL_16:
        v20 = v13 - v14;
        if ( v7 <= v13 - v14 )
          v20 = v7;
        memmove(v11, v15 + v14, v20);
        v7 -= v20;
        v11 += v20;
        v14 = v22 + v20;
        v22 += v20;
        if ( !v7 )
        {
          v21 = v25;
          HvpPointMapEntriesToBuffer(a1, v9, v8, v10, v25, 0);
          v9 = 0;
          v8 = 0;
          v14 = v22;
          v23 = 0;
          v24 = 0;
          v25 = v21 + v10;
        }
        v13 = v26;
        v15 = v27[0];
        if ( v14 >= v26 )
          continue;
        goto LABEL_6;
      }
    }
    if ( v12 != -1073741807 )
      JUMPOUT(0x805BDC);
    v6 = 0;
    if ( v9 || v8 )
      HvpFreeBin(a1, v10, 0, v9, v8);
  }
  return v6;
}
