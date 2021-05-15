// KiWriteHwDebugRegs 
 
int __fastcall KiWriteHwDebugRegs(unsigned int *a1, unsigned int *a2, unsigned int *a3, unsigned int *a4)
{
  unsigned int v7; // r0

  v7 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  return KiSetHwDebugRegs(*(_DWORD *)(v7 + 2704), a1, a2, *(_DWORD *)(v7 + 2708), a3, a4);
}
