// KiIsCommitFailTerminationRequested 
 
BOOL __fastcall KiIsCommitFailTerminationRequested(int a1)
{
  return (*(_DWORD *)(a1 + 80) & 0x20000) != 0;
}
