// RtlEthernetStringToAddressA 
 
int __fastcall RtlEthernetStringToAddressA(_BYTE *a1, _DWORD *a2, int a3)
{
  int *v6; // r8
  int v7; // r7
  char v8; // r9
  char v9; // r3
  char v10; // r3
  unsigned int v11; // r6
  int v12; // r3
  int result; // r0
  int v14; // [sp+0h] [bp-28h] BYREF
  __int16 v15; // [sp+4h] [bp-24h] BYREF
  char v16; // [sp+6h] [bp-22h] BYREF

  v6 = &v14;
  while ( 1 )
  {
    v7 = 0;
    v8 = 0;
    while ( 1 )
    {
      v11 = (char)*a1;
      if ( !*a1 )
        break;
      if ( _isascii((char)*a1) && isdigit(v11) )
      {
        v9 = v11 + 16 * (v8 + 13);
      }
      else
      {
        if ( !_isascii(v11) || !isxdigit(v11) )
          break;
        if ( _isascii(v11) && islower(v11) )
          v10 = 97;
        else
          v10 = 65;
        v9 = 16 * v8 - v10 + v11 + 10;
      }
      v8 = v9;
      if ( v7 == 2 )
        goto LABEL_20;
      ++a1;
      ++v7;
    }
    v12 = (char)*a1;
    if ( v12 != 45 && v12 != 58 )
      break;
    if ( v6 < (int *)((char *)&v15 + 1) )
    {
      ++a1;
      *(_BYTE *)v6 = v8;
      v6 = (int *)((char *)v6 + 1);
      if ( v7 == 2 )
        continue;
    }
LABEL_20:
    *a2 = a1;
    return -1073741811;
  }
  *a2 = a1;
  if ( v7 != 2 )
    return -1073741811;
  *(_BYTE *)v6 = v8;
  if ( (char *)v6 + 1 != &v16 )
    return -1073741811;
  result = 0;
  *(_DWORD *)a3 = v14;
  *(_WORD *)(a3 + 4) = v15;
  return result;
}
