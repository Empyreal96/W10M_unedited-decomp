// PnpConvertDevpropcompkeyArrayToString 
 
int __fastcall PnpConvertDevpropcompkeyArrayToString(int a1, unsigned int a2, _WORD *a3, unsigned int a4, unsigned int *a5)
{
  unsigned int v6; // r2
  unsigned int v7; // r6
  unsigned int v8; // r4
  unsigned int v11; // r5
  int result; // r0
  unsigned int v13; // r2
  int v14; // [sp+0h] [bp-28h] BYREF
  unsigned int v15; // [sp+4h] [bp-24h]
  unsigned int v16; // [sp+8h] [bp-20h]

  v16 = a4;
  v6 = a4;
  v7 = a4;
  v8 = 2;
  v15 = a4;
  if ( a4 >= 2 )
    *a3 = 0;
  v11 = 0;
  if ( a2 )
  {
    while ( 1 )
    {
      result = ConvertDevpropcompkeyToString(a1, a3, v7, &v14);
      if ( result < 0 && result != -1073741789 )
        break;
      v13 = v14 - 2;
      if ( v14 - 2 + v8 < v8 )
        return -1073741675;
      v8 += v14 - 2;
      if ( v7 >= v13 )
      {
        v7 = v7 - v14 + 2;
        a3 += v13 >> 1;
      }
      ++v11;
      a1 += 28;
      if ( v11 >= a2 )
      {
        v6 = v15;
        goto LABEL_11;
      }
    }
  }
  else
  {
LABEL_11:
    result = 0;
    if ( a5 )
      *a5 = v8;
    if ( v8 > v6 )
      result = -1073741789;
  }
  return result;
}
