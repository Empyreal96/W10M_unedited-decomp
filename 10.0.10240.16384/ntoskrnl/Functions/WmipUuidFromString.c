// WmipUuidFromString 
 
int __fastcall WmipUuidFromString(int a1, int a2, int a3, int a4)
{
  int v6; // r2
  int v7; // r2
  int v8; // r2
  int v9; // r2
  int v10; // r2
  int v11; // r2
  int v12; // r2
  int v13; // r2
  int result; // r0
  int v15[4]; // [sp+0h] [bp-10h] BYREF

  v15[0] = a3;
  v15[1] = a4;
  if ( !WmipHexStringToDword(a1, a2, 8, 45) )
    return -1073741811;
  if ( !WmipHexStringToDword(a1 + 18, v15, 4, 45) )
    return -1073741811;
  *(_WORD *)(a2 + 4) = v15[0];
  if ( !WmipHexStringToDword(a1 + 28, v15, v6, 45) )
    return -1073741811;
  *(_WORD *)(a2 + 6) = v15[0];
  if ( !WmipHexStringToDword(a1 + 38, v15, 2, 0) )
    return -1073741811;
  *(_BYTE *)(a2 + 8) = v15[0];
  if ( !WmipHexStringToDword(a1 + 42, v15, v7, 45) )
    return -1073741811;
  *(_BYTE *)(a2 + 9) = v15[0];
  if ( !WmipHexStringToDword(a1 + 48, v15, v8, 0) )
    return -1073741811;
  *(_BYTE *)(a2 + 10) = v15[0];
  if ( !WmipHexStringToDword(a1 + 52, v15, v9, 0) )
    return -1073741811;
  *(_BYTE *)(a2 + 11) = v15[0];
  if ( !WmipHexStringToDword(a1 + 56, v15, v10, 0) )
    return -1073741811;
  *(_BYTE *)(a2 + 12) = v15[0];
  if ( !WmipHexStringToDword(a1 + 60, v15, v11, 0) )
    return -1073741811;
  *(_BYTE *)(a2 + 13) = v15[0];
  if ( !WmipHexStringToDword(a1 + 64, v15, v12, 0) )
    return -1073741811;
  *(_BYTE *)(a2 + 14) = v15[0];
  if ( !WmipHexStringToDword(a1 + 68, v15, v13, 0) )
    return -1073741811;
  result = 0;
  *(_BYTE *)(a2 + 15) = v15[0];
  return result;
}
