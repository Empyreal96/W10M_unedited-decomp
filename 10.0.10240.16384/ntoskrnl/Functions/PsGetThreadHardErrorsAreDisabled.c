// PsGetThreadHardErrorsAreDisabled 
 
BOOL __fastcall PsGetThreadHardErrorsAreDisabled(int a1)
{
  return (*(_DWORD *)(a1 + 960) & 0x10) != 0;
}
