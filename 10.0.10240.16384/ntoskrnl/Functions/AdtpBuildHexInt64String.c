// AdtpBuildHexInt64String 
 
int __fastcall AdtpBuildHexInt64String(int a1, int a2, int a3, int a4, int a5, _BYTE *a6)
{
  unsigned __int16 *v8; // r0
  unsigned __int16 *v9; // r4
  int result; // r0

  v8 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 38, 1799447891);
  v9 = v8;
  if ( !v8 )
    return -1073741801;
  *a6 = 1;
  if ( StringCchPrintfW(v8, 0x13u, (int)L"0x%I64X", *(_DWORD *)(a1 + 4)) >= 0 )
  {
    *(_WORD *)a2 = 2 * wcslen(v9);
    *(_WORD *)(a2 + 2) = 38;
    *(_DWORD *)(a2 + 4) = v9;
    result = 0;
  }
  else
  {
    if ( *a6 == 1 )
    {
      ExFreePoolWithTag((unsigned int)v9);
      *a6 = 0;
    }
    result = -1073741811;
  }
  return result;
}
