// HvpSetRangeProtection 
 
int __fastcall HvpSetRangeProtection(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r5
  int v7; // r6
  int v8; // r10
  int v9; // r0
  _DWORD *v10; // r5
  int v11; // r0
  int v12; // r4
  _DWORD *v13; // r0
  int v14; // r2
  int v15; // r9
  int v18; // r0
  char v19[4]; // [sp+8h] [bp-30h] BYREF
  int v20; // [sp+Ch] [bp-2Ch]
  int v21; // [sp+10h] [bp-28h]
  int v22; // [sp+14h] [bp-24h]
  int v23[8]; // [sp+18h] [bp-20h] BYREF

  v5 = *(_DWORD *)(a1 + 92);
  v6 = a4;
  v20 = a4;
  v21 = a3;
  v22 = a2;
  if ( (v5 & 0x11) != 0 )
    return 1;
  v7 = a2;
  v8 = a3;
  if ( !a3 )
    return (*(_BYTE *)(a1 + 72) & 4) == 0 || v6 != 4 || HvViewMapPinForFileOffset(a1 + 152, a2 + 4096, a3) >= 0;
  while ( 1 )
  {
    v9 = HvpGetCellMap(a1, v7);
    v10 = (_DWORD *)v9;
    if ( !v9 )
      KeBugCheckEx(81, 1, a1, v7, 964);
    if ( !HvpMapEntryIsBinPresent(v9) )
      goto LABEL_14;
    v11 = HvpMapEntryGetFreeBin((int)v10);
    v12 = v11 ? v7 - *(_DWORD *)(v11 + 12) : *v10;
    v13 = (_DWORD *)HvpMapEntryGetBinAddress(v11, v10, v19, v23);
    if ( *v13 != 1852400232 )
      break;
    v14 = v13[2];
    if ( !v14 || (v14 & 0xFFF) != 0 || (v13[1] & 0xFFF) != 0 || (unsigned int)(v14 + v13[1]) > *(_DWORD *)(a1 + 952) )
      break;
    v15 = (unsigned __int8)v19[0];
    if ( (*(_BYTE *)(a1 + 72) & 4) == 0 || v19[0] )
    {
      v18 = ExProtectPool((unsigned int)v13 + v12, 4096, v20);
      if ( !v18 )
        return sub_80422C();
      if ( v15 )
        HvpMapEntryReleaseBinAddress(v18, (int)v10);
    }
LABEL_14:
    v8 -= 4096;
    v7 += 4096;
    if ( !v8 )
    {
      v6 = v20;
      a3 = v21;
      a2 = v22;
      return (*(_BYTE *)(a1 + 72) & 4) == 0 || v6 != 4 || HvViewMapPinForFileOffset(a1 + 152, a2 + 4096, a3) >= 0;
    }
  }
  if ( KdDebuggerEnabled && !KdDebuggerNotPresent )
    __debugbreak();
  if ( v19[0] )
    HvpMapEntryReleaseBinAddress((int)v13, (int)v10);
  return 0;
}
