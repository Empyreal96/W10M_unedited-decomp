// KiWriteDebugRegs 
 
int __fastcall KiWriteDebugRegs(int result)
{
  int v1; // r4
  int v2; // r0

  v1 = result;
  if ( KiCP14DebugEnabled )
  {
    if ( (*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 3) & 0xFB) != 0 )
    {
      KiWriteHwDebugRegs(result + 24, result + 56, result + 88, result + 92);
      v2 = KiIsArmedForDebug((int *)(v1 + 56), (int *)(v1 + 92));
      result = KiUpdateDbgdscr(v2);
    }
  }
  return result;
}
