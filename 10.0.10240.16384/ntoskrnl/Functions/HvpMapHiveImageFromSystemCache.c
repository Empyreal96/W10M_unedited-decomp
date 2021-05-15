// HvpMapHiveImageFromSystemCache 
 
int __fastcall HvpMapHiveImageFromSystemCache(int a1, int a2, int a3)
{
  int v4; // r5
  int v5; // r4
  int v7; // r10
  int v8; // r0
  int v9; // r6
  int v10; // r3
  int v11; // r4
  int v12; // r7
  int result; // r0
  int v14; // [sp+10h] [bp-30h] BYREF
  int v15; // [sp+14h] [bp-2Ch] BYREF
  int v16; // [sp+18h] [bp-28h]
  int v17; // [sp+1Ch] [bp-24h]

  v4 = 0;
  v5 = 0;
  v15 = 0;
  v16 = 4096;
  v7 = 0;
  v14 = 0;
  v8 = HvpInitMap();
  v9 = v8;
  if ( v8 < 0 )
    goto LABEL_13;
  v17 = a3;
  if ( a3 )
  {
    v10 = 4096;
    while ( 1 )
    {
      v11 = HvViewMapAddressForFileOffset(a1 + 152, v10);
      v12 = HvpValidateLoadedBin(v11, v7, a3) ? *(_DWORD *)(v11 + 8) : 4096;
      v8 = HvpAllocateBin(a1, v12, 0, v7, 825445699, &v14, &v15);
      v9 = v8;
      v5 = v15;
      if ( v8 < 0 )
        break;
      if ( v15 )
      {
        v8 = HvpProtectBin(a1, v12, 0, v7, v15, 1);
        v9 = v8;
        if ( v8 < 0 )
          break;
        HvViewMapCopyFromFileOffset(a1 + 152, v5, v16, v12);
      }
      v8 = HvpPointMapEntriesToBuffer(a1, v14, v5, v12, v7, 0);
      v5 = 0;
      v14 = 0;
      v15 = 0;
      v10 = v16 + v12;
      v16 += v12;
      v17 -= v12;
      v7 += v12;
      if ( !v17 )
        goto LABEL_9;
    }
    v4 = v14;
  }
  else
  {
LABEL_9:
    v9 = 0;
  }
  if ( v4 || v5 )
    result = sub_548744(v8);
  else
LABEL_13:
    result = v9;
  return result;
}
