// KiGetTrapFrameMode 
 
BOOL __fastcall KiGetTrapFrameMode(int a1)
{
  return (*(_DWORD *)(a1 + 132) & 0x1F) != 19;
}
