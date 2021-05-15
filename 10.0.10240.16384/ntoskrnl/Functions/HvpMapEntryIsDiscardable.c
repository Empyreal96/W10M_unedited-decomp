// HvpMapEntryIsDiscardable 
 
BOOL __fastcall HvpMapEntryIsDiscardable(int a1)
{
  return (*(_DWORD *)(a1 + 4) & 2) != 0;
}
