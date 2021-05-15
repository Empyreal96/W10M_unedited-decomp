// KiIsTerminationRequested 
 
BOOL __fastcall KiIsTerminationRequested(int a1)
{
  return (*(_DWORD *)(a1 + 80) & 0x4000) != 0;
}
