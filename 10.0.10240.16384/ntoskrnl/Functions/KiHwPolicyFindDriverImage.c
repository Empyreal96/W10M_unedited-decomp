// KiHwPolicyFindDriverImage 
 
int __fastcall KiHwPolicyFindDriverImage(int a1, int a2, int a3, const __int16 *a4)
{
  _DWORD *v4; // r5
  _DWORD *v5; // r4
  int v6; // r2
  unsigned __int16 v8[2]; // [sp+0h] [bp-10h] BYREF
  const __int16 *v9; // [sp+4h] [bp-Ch]

  v9 = a4;
  v8[0] = 24;
  v8[1] = 26;
  v4 = (_DWORD *)(a1 + 32);
  v5 = *(_DWORD **)(a1 + 32);
  v9 = L"hwpolicy.sys";
  while ( 1 )
  {
    if ( v5 == v4 )
      return 0;
    v6 = v5[6];
    if ( v6 )
    {
      if ( (int)v5[7] >= 0 && !RtlCompareUnicodeString((unsigned __int16 *)(v6 + 44), v8, 1) )
        break;
    }
    v5 = (_DWORD *)*v5;
  }
  return *(_DWORD *)(v5[6] + 24);
}
