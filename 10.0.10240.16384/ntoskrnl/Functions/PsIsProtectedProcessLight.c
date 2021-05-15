// PsIsProtectedProcessLight 
 
BOOL __fastcall PsIsProtectedProcessLight(int a1)
{
  return (*(_BYTE *)(a1 + 734) & 7) == 1;
}
