// SeTokenIsRestricted 
 
BOOL __fastcall SeTokenIsRestricted(int a1)
{
  return (*(_DWORD *)(a1 + 176) & 0x10) != 0;
}
