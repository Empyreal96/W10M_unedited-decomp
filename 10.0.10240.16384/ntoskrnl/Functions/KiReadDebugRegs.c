// KiReadDebugRegs 
 
int __fastcall KiReadDebugRegs(int result)
{
  unsigned int v1; // r4
  int v2; // r0
  int v3; // r1

  if ( KiCP14DebugEnabled )
  {
    *(_BYTE *)(result + 18) = 1;
    v1 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    KiReadHwDebugRegs(
      (_DWORD *)(result + 24),
      (_DWORD *)(result + 56),
      (_DWORD *)(result + 88),
      (_DWORD *)(result + 92));
    KiWriteHwDebugRegs(v1 + 1480, v1 + 1512, v1 + 1544, v1 + 1548);
    v2 = KiIsArmedForDebug((int *)(v1 + 1512), (int *)(v1 + 1548));
    result = KiUpdateDbgdscr(v2, v3);
  }
  return result;
}
