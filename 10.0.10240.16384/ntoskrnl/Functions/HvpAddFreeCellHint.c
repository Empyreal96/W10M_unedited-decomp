// HvpAddFreeCellHint 
 
int __fastcall HvpAddFreeCellHint(int a1, int a2, int a3, int a4)
{
  _DWORD *v7; // r0
  int v8; // r6
  unsigned int v9; // r0
  unsigned int v10; // r5
  int v11; // r4
  _BYTE *v12; // r0
  int v14; // [sp+0h] [bp-28h]
  int v15; // [sp+8h] [bp-20h] BYREF
  int v16[7]; // [sp+Ch] [bp-1Ch] BYREF

  v14 = a1;
  v15 = a3;
  v16[0] = a4;
  v7 = (_DWORD *)HvpGetCellMap(a1, a2);
  v8 = (int)v7;
  if ( !v7 )
    sub_804048();
  v9 = HvpMapEntryGetBinAddress((int)v7, v7, (char *)&v15, v16);
  v10 = *(_DWORD *)(v9 + 4) >> 12;
  v11 = 412 * a4;
  v12 = RtlSetBits((_BYTE *)(412 * a4 + 16 * (a3 + 61) + a1), v10, *(_DWORD *)(v9 + 8) >> 12);
  *(_DWORD *)(v11 + 16 * a3 + a1 + 972) = v10;
  *(_DWORD *)(v11 + a1 + 1360) |= 1 << a3;
  if ( (_BYTE)v15 )
    HvpMapEntryReleaseBinAddress((int)v12, v8);
  return v14;
}
