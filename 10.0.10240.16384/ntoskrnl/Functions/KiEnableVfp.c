// KiEnableVfp 
 
int KiEnableVfp()
{
  int v0; // r6
  int v1; // lr
  int v2; // r6

  __mcr(15, 0, v0 | 0xF00000, 1, 0, 2);
  __isb(0xFu);
  v2 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x584);
  *(_BYTE *)(v2 + 133) = 1;
  _R7 = *(_DWORD *)(*(_DWORD *)(v2 + 320) + 4) & 0xFFC8FFFF;
  __asm { VMSR            FPSCR, R7 }
  return ((int (*)(void))(v1 - 2))();
}
