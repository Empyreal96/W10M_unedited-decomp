// KiInitializeCP14DebugState 
 
int KiInitializeCP14DebugState()
{
  unsigned int v0; // r4
  int result; // r0
  unsigned int v2; // r2
  unsigned int v3; // r5
  unsigned int v4; // r6

  v0 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( (__mrc(14, 0, 1, 1, 4) & 2) != 0 )
  {
    __mcr(14, 0, 0, 1, 0, 4);
    __dsb(0xFu);
    __mrc(14, 0, 1, 1, 4);
  }
  if ( (__mrc(15, 0, 0, 1, 2) & 0xF) == 4 )
    return sub_519478();
  __mcr(14, 0, __mrc(14, 0, 0, 2, 2) | 0x1000, 0, 2, 2);
  __isb(0xFu);
  __mcr(14, 0, 0, 0, 7, 0);
  v2 = __mrc(14, 0, 0, 0, 0);
  v3 = (HIBYTE(v2) & 0xF) + 1;
  v4 = (v2 >> 28) + 1;
  result = KiSetHwDebugRegs(v3, KiZeroedDebugRegs, KiZeroedDebugRegs, v4, KiZeroedDebugRegs, KiZeroedDebugRegs);
  if ( !*(_DWORD *)(v0 + 2704) )
  {
    if ( v3 > 8 )
      v3 = 8;
    if ( v4 > 1 )
      v4 = 1;
    *(_DWORD *)(v0 + 2704) = v3;
    *(_DWORD *)(v0 + 2708) = v4;
  }
  return result;
}
