// AuthzBasepCompareIntegerOperands 
 
int __fastcall AuthzBasepCompareIntegerOperands(int a1, _DWORD *a2)
{
  int result; // r0
  int v4; // r4
  __int64 *v5; // r5
  int v6; // r6
  _DWORD *v7; // r2
  int v8; // r2
  __int64 v9; // [sp+8h] [bp-20h] BYREF
  __int64 v10; // [sp+10h] [bp-18h]

  result = 0;
  v4 = 2;
  v5 = &v9;
  v9 = -1i64;
  v10 = -1i64;
  v6 = 2;
  do
  {
    if ( a2[3] == 1 )
    {
      v7 = (_DWORD *)a2[6];
    }
    else
    {
      v4 = *(unsigned __int16 *)a2;
      v7 = *(_DWORD **)(a2[4] + 24);
    }
    a2 += 7;
    *(_DWORD *)v5 = *v7;
    *((_DWORD *)v5++ + 1) = v7[1];
    --v6;
  }
  while ( v6 );
  switch ( v4 )
  {
    case 1:
      return AuthzBasepCompareSigned(a1, a2, v9, HIDWORD(v9), v10, HIDWORD(v10));
    case 2:
      v8 = v9;
      break;
    case 6:
      a2 = (_DWORD *)HIDWORD(v9);
      v8 = v9;
      if ( v9 && v9 != 1 || v10 && v10 != 1 )
        return -1;
      break;
    default:
      return result;
  }
  return AuthzBasepCompareUnsigned(a1, a2, v8);
}
