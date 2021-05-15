// PsIsThreadTerminating 
 
BOOL __fastcall PsIsThreadTerminating(int a1)
{
  return (*(_DWORD *)(a1 + 960) & 1) != 0;
}
