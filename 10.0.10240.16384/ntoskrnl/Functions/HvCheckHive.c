// HvCheckHive 
 
int __fastcall HvCheckHive(int a1, _DWORD *a2, _BYTE *a3, _DWORD *a4)
{
  int v5; // r3
  int v6; // r2
  _DWORD *v7; // r4
  unsigned int v8; // r6
  unsigned int v10; // r9
  unsigned int v11; // r3
  int v12; // r0
  _DWORD *v13; // r7
  int v14; // r0
  _DWORD *v15; // r0
  unsigned int v16; // r2
  _DWORD *v17; // r8
  int v18; // r5
  int v20; // r1
  _DWORD *v21; // r0
  int v22; // r3
  char v23[4]; // [sp+8h] [bp-40h] BYREF
  _DWORD *v24; // [sp+Ch] [bp-3Ch]
  unsigned int v25; // [sp+10h] [bp-38h]
  int v26; // [sp+14h] [bp-34h]
  int v27; // [sp+18h] [bp-30h]
  int v28; // [sp+1Ch] [bp-2Ch] BYREF
  _BYTE *v29; // [sp+20h] [bp-28h]
  int v30[9]; // [sp+24h] [bp-24h] BYREF

  v28 = 0;
  v29 = a3;
  v5 = a1;
  v6 = a1;
  v7 = *(_DWORD **)(a1 + 28);
  v8 = 0;
  v26 = a1;
  v27 = a1;
  v24 = a4;
  v10 = 0;
  while ( 2 )
  {
    v11 = *(_DWORD *)(v5 + 952);
    v25 = v11;
    while ( v8 < v11 )
    {
      v12 = HvpGetCellMap(v6, v8);
      v13 = (_DWORD *)v12;
      if ( !v12 )
      {
        v18 = 2005;
        if ( v7 )
        {
          SetFailureLocation((int)v7, 0, 16, 2005, 0);
          v7[63] = v10;
          v7[64] = v8;
        }
        return v18;
      }
      v14 = HvpMapEntryGetFreeBin(v12);
      if ( v14 )
      {
        v20 = *(_DWORD *)(v14 + 8);
        v8 += v20;
        if ( a4 )
        {
          v21 = (_DWORD *)HvAddToLayoutStats((int)a4, v20);
          HvMoveLayoutStats(v21);
        }
      }
      else
      {
        v15 = (_DWORD *)HvpMapEntryGetBinAddress(0, v13, v23, v30);
        v16 = v15[2];
        v17 = v15;
        if ( v16 > v25 - v8 || v16 < 0x20 || (v16 & 0xFFF) != 0 || *v15 != 1852400232 || v15[1] != v8 )
        {
          v18 = 2010;
          if ( v7 )
          {
            v22 = 32;
LABEL_27:
            v15 = (_DWORD *)SetFailureLocation((int)v7, 0, 16, v18, v22);
            v7[63] = v10;
            v7[64] = v8;
            v7[65] = v17;
          }
LABEL_28:
          if ( v23[0] )
            HvpMapEntryReleaseBinAddress((int)v15, (int)v13);
          return v18;
        }
        v15 = (_DWORD *)HvCheckBin(v26, (int)v15, &v28, v29, a4);
        v18 = (int)v15;
        if ( v15 )
        {
          if ( v7 )
          {
            v22 = 48;
            goto LABEL_27;
          }
          goto LABEL_28;
        }
        v8 += v17[2];
        if ( v23[0] )
          return sub_8036D4();
        a4 = v24;
      }
      v11 = v25;
      v6 = v26;
    }
    ++v10;
    v8 = 0x80000000;
    v5 = v27 + 412;
    v27 += 412;
    if ( v10 <= 1 )
      continue;
    break;
  }
  if ( a2 )
    *a2 = v28;
  return 0;
}
