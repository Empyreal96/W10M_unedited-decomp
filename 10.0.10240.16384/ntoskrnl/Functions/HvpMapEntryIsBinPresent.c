// HvpMapEntryIsBinPresent 
 
BOOL __fastcall HvpMapEntryIsBinPresent(int a1)
{
  return (*(_DWORD *)(a1 + 4) & 0xFFFFFFF0) != 0 || (*(_DWORD *)(a1 + 8) & 0xFFFFFFF0) != 0;
}
