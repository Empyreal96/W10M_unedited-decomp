// SeTokenIsWriteRestricted 
 
BOOL __fastcall SeTokenIsWriteRestricted(int a1)
{
  return (*(_DWORD *)(a1 + 176) & 8) != 0;
}
