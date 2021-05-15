// AdtpBuildGuidString 
 
int __fastcall AdtpBuildGuidString(int *a1, int a2, int a3, int a4, int a5, _BYTE *a6)
{
  _WORD *v9; // r0
  unsigned int v10; // r5

  if ( !a2 )
    return -1073741811;
  v9 = (_WORD *)ExAllocatePoolWithTag(1, 78, 1799447891);
  v10 = (unsigned int)v9;
  if ( !v9 )
    return -1073741801;
  *a6 = 1;
  if ( StringCchPrintfW(v9, 0x27u, (int)L"{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}", *a1) < 0 )
  {
    if ( *a6 == 1 )
    {
      ExFreePoolWithTag(v10);
      *a6 = 0;
    }
    return -1073741811;
  }
  *(_WORD *)a2 = 76;
  *(_WORD *)(a2 + 2) = 78;
  *(_DWORD *)(a2 + 4) = v10;
  return 0;
}
