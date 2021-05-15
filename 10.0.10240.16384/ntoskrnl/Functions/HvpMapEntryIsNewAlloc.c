// HvpMapEntryIsNewAlloc 
 
BOOL __fastcall HvpMapEntryIsNewAlloc(int a1)
{
  return (*(_DWORD *)(a1 + 4) & 1) != 0;
}
