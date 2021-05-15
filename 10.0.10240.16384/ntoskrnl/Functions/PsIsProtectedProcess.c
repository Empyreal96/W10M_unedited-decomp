// PsIsProtectedProcess 
 
BOOL __fastcall PsIsProtectedProcess(int a1)
{
  return (*(_BYTE *)(a1 + 734) & 7) != 0;
}
