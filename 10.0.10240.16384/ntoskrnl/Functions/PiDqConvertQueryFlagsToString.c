// PiDqConvertQueryFlagsToString 
 
int __fastcall PiDqConvertQueryFlagsToString(int a1, _WORD *a2, unsigned int a3, unsigned int *a4)
{
  int result; // r0
  _WORD *v6; // r7
  unsigned int v8; // r6
  unsigned int v9; // r4
  unsigned int v10; // r1
  unsigned int v11; // [sp+8h] [bp-20h] BYREF
  _DWORD v12[7]; // [sp+Ch] [bp-1Ch] BYREF

  v11 = a3;
  v12[0] = a4;
  result = 0;
  v6 = a2;
  v8 = a3;
  if ( (a1 & 0xFFFFFFF8) != 0 )
    return -1073741811;
  v9 = 2;
  if ( a3 >= 2 )
    *a2 = 0;
  v11 = a3;
  v12[0] = a2;
  v10 = a3;
  if ( (a1 & 1) != 0 )
  {
    v9 = 54;
    a1 &= 0xFFFFFFFE;
    if ( a3 >= 0x36 )
    {
      result = RtlStringCbCopyExW(v6, a3, L"DevQueryFlagUpdateResults ", v12, &v11, 1024);
      if ( result < 0 )
        return result;
      v10 = v11;
      v6 = (_WORD *)v12[0];
    }
  }
  if ( (a1 & 2) != 0 )
  {
    v9 += 52;
    a1 &= 0xFFFFFFFD;
    if ( v9 <= v8 )
    {
      result = RtlStringCbCopyExW(v6, v10, L"DevQueryFlagAllProperties ", v12, &v11, 1024);
      if ( result < 0 )
        return result;
      v10 = v11;
      v6 = (_WORD *)v12[0];
    }
  }
  if ( (a1 & 4) != 0 )
  {
    v9 += 42;
    a1 &= 0xFFFFFFFB;
    if ( v9 <= v8 )
    {
      result = RtlStringCbCopyExW(v6, v10, L"DevQueryFlagLocalize ", v12, &v11, 1024);
      if ( result < 0 )
        return result;
      v10 = v11;
      v6 = (_WORD *)v12[0];
    }
  }
  if ( !a1
    || (v9 += 24, v9 > v8)
    || (result = RtlStringCbCopyExW(v6, v10, L"<more flags>", v12, &v11, 1024), result >= 0) )
  {
    if ( a4 )
      *a4 = v9;
    if ( v9 < v8 )
      result = -1073741789;
  }
  return result;
}
