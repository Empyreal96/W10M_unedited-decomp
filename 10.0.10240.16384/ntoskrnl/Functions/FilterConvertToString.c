// FilterConvertToString 
 
int __fastcall FilterConvertToString(unsigned int a1, _DWORD *a2, unsigned int a3, _WORD *a4, unsigned int *a5)
{
  unsigned int v5; // r6
  unsigned int v6; // r4
  _WORD *v7; // r8
  unsigned int v10; // r5
  int result; // r0
  unsigned int v12; // r2
  unsigned int v13; // [sp+0h] [bp-28h] BYREF
  unsigned int v14; // [sp+4h] [bp-24h]
  _WORD *v15; // [sp+8h] [bp-20h]

  v15 = a4;
  v5 = a3;
  v6 = 2;
  v7 = a4;
  v14 = a3;
  if ( a3 >= 2 )
    *a4 = 0;
  v10 = 0;
  if ( a1 )
  {
    while ( 1 )
    {
      result = ExpressionConvertToString(a2, v5, v7, &v13);
      if ( result < 0 && result != -1073741789 )
        break;
      v12 = v13 - 2;
      if ( v13 - 2 + v6 < v6 )
        return -1073741675;
      v6 += v13 - 2;
      if ( v5 >= v12 )
      {
        v5 = v5 - v13 + 2;
        v7 += v12 >> 1;
      }
      ++v10;
      a2 += 11;
      if ( v10 >= a1 )
      {
        a3 = v14;
        goto LABEL_11;
      }
    }
  }
  else
  {
LABEL_11:
    result = 0;
    if ( a5 )
      *a5 = v6;
    if ( v6 > a3 )
      result = -1073741789;
  }
  return result;
}
