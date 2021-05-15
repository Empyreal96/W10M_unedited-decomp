// IopLiveDumpValidateParameters 
 
int __fastcall IopLiveDumpValidateParameters(_DWORD *a1, _DWORD *a2)
{
  int result; // r0
  int v5; // r2
  int v6; // r2
  int v7; // r3
  int v8; // r2
  int v9; // r4

  if ( !a2 )
    return -1073741811;
  if ( *a2 != 1 )
    return -1073741811;
  if ( a2[1] < 0x24u )
    return -1073741811;
  v5 = a2[5];
  if ( (v5 & 0xFFFFFFFE) != 0 )
    return -1073741811;
  a1[6] = v5;
  result = IopLiveDumpValidateSecondaryData(a2 + 6);
  if ( result < 0 )
    return result;
  v6 = a2[7];
  v7 = a2[8];
  a1[7] = a2[6];
  a1[8] = v6;
  a1[9] = v7;
  v8 = a2[4];
  if ( (v8 & 0xFFFFFFE0) != 0 )
    return -1073741811;
  if ( (v8 & 1) != 0 || (v8 & 2) != 0 )
    return -1073741822;
  a1[5] = v8;
  result = IopLiveDumpValidateDumpFileHandle(a2[2]);
  if ( result < 0 )
  {
    a1[10] = 0;
  }
  else
  {
    a1[10] = a2[2];
    v9 = a2[3];
    result = IopLiveDumpValidateCancelObject(v9);
    if ( result < 0 )
      a1[11] = 0;
    else
      a1[11] = v9;
  }
  return result;
}
