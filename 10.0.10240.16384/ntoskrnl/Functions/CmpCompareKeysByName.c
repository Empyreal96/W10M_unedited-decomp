// CmpCompareKeysByName 
 
int __fastcall CmpCompareKeysByName(int a1, int a2, int a3, int a4)
{
  __int16 v4; // r3
  int result; // r0
  unsigned __int16 v6; // r2
  unsigned __int16 v7; // r2
  int v8; // [sp+0h] [bp-10h] BYREF
  int v9; // [sp+4h] [bp-Ch]
  int v10; // [sp+8h] [bp-8h] BYREF
  int v11; // [sp+Ch] [bp-4h]

  v8 = a1;
  v9 = a2;
  v10 = a3;
  v11 = a4;
  v4 = *(_WORD *)(a2 + 2);
  if ( (*(_WORD *)(a1 + 2) & 0x20) != 0 )
  {
    if ( (v4 & 0x20) != 0 )
    {
      result = CmpCompareTwoCompressedNames(
                 (unsigned __int8 *)(a1 + 76),
                 *(_WORD *)(a1 + 72),
                 (unsigned __int8 *)(a2 + 76),
                 *(_WORD *)(a2 + 72));
    }
    else
    {
      v9 = a2 + 76;
      v6 = *(_WORD *)(a1 + 72);
      LOWORD(v8) = *(_WORD *)(a2 + 72);
      HIWORD(v8) = v8;
      result = -CmpCompareCompressedName((unsigned __int16 *)&v8, (unsigned __int8 *)(a1 + 76), v6, 0);
    }
  }
  else if ( (v4 & 0x20) != 0 )
  {
    v11 = a1 + 76;
    v7 = *(_WORD *)(a2 + 72);
    LOWORD(v10) = *(_WORD *)(a1 + 72);
    HIWORD(v10) = v10;
    result = CmpCompareCompressedName((unsigned __int16 *)&v10, (unsigned __int8 *)(a2 + 76), v7, 0);
  }
  else
  {
    v9 = a2 + 76;
    LOWORD(v8) = *(_WORD *)(a2 + 72);
    HIWORD(v8) = v8;
    v11 = a1 + 76;
    LOWORD(v10) = *(_WORD *)(a1 + 72);
    HIWORD(v10) = v10;
    result = CmpCompareUnicodeString(&v10, &v8, 0);
  }
  return result;
}
