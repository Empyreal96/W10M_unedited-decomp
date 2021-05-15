// KiSaveProcessorControlState 
 
int __fastcall KiSaveProcessorControlState(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r1
  int result; // r0
  int v13; // [sp+0h] [bp-8h]
  int v14; // [sp+0h] [bp-8h]
  int v15; // [sp+0h] [bp-8h]

  a1[43] = __mrc(15, 0, 1, 0, 0);
  a1[44] = __mrc(15, 0, 1, 0, 1);
  a1[45] = __mrc(15, 0, 1, 0, 2);
  v5 = __mrc(15, 0, 2, 0, 0);
  a1[47] = KiTbrConfiguration | v5 & 0xFFFFC000;
  a1[46] = __mrc(15, 0, 2, 0, 2);
  a1[48] = __mrc(15, 0, 2, 0, 1);
  a1[49] = __mrc(15, 0, 3, 0, 0);
  a1[50] = __mrc(15, 0, 5, 0, 0);
  a1[51] = __mrc(15, 0, 5, 0, 1);
  a1[52] = __mrc(15, 0, 6, 0, 0);
  a1[53] = __mrc(15, 0, 6, 0, 2);
  a1[123] = __mrc(15, 0, 10, 2, 0);
  a1[124] = __mrc(15, 0, 10, 2, 1);
  a1[126] = __mrc(15, 0, 13, 0, 1);
  a1[125] = __mrc(15, 0, 12, 0, 0);
  a1[7] = __mrc(15, 0, 13, 0, 2);
  a1[8] = __mrc(15, 0, 13, 0, 3);
  a1[9] = KeGetPcr();
  KiReadBankedRegisters(31, a1 + 31, a1 + 32, 0, a4);
  KiReadBankedRegisters(23, a1 + 33, a1 + 34, a1 + 35, v13);
  KiReadBankedRegisters(27, a1 + 36, a1 + 37, a1 + 38, v14);
  result = KiReadBankedRegisters(18, a1 + 39, a1 + 40, a1 + 41, v15);
  a1[28] = 0x40000000;
  a1[29] = 0;
  a1[30] = 0;
  if ( (a1[45] & 0xF00000) == 15728640 )
  {
    __asm { VMRS            R3, FPEXC }
    a1[28] = _R3;
    if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xA8C) & 0x20) != 0 )
      return sub_51B568(result);
  }
  if ( KiCP14DebugEnabled )
    result = KiReadHwDebugRegs(a1 + 10, a1 + 18, a1 + 26, a1 + 27);
  return result;
}
