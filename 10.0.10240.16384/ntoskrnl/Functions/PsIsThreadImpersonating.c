// PsIsThreadImpersonating 
 
BOOL __fastcall PsIsThreadImpersonating(int a1)
{
  return (*(_DWORD *)(a1 + 960) & 8) != 0;
}
