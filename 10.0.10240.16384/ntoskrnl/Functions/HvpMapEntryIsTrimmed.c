// HvpMapEntryIsTrimmed 
 
BOOL __fastcall HvpMapEntryIsTrimmed(int a1)
{
  return (*(_DWORD *)(a1 + 4) & 4) != 0;
}
