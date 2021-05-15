// KiRestoreProcessorControlState 
 
unsigned int __fastcall KiRestoreProcessorControlState(unsigned int *a1)
{
  int *v1; // r4
  unsigned int result; // r0
  int v3; // r2
  unsigned int v9; // r7
  unsigned int v10; // r2
  unsigned int v11; // r9
  unsigned int v12; // r8
  unsigned int v13; // r3
  unsigned int v14; // r5
  unsigned int v15; // r1
  int *v16; // r2
  unsigned int v17; // r1
  unsigned int v18; // r2
  int v19; // r2
  int v20; // r1
  char v23; // r3
  unsigned int v24; // r3

  v1 = (int *)a1;
  __mcr(15, 0, a1[7], 13, 0, 2);
  __mcr(15, 0, a1[8], 13, 0, 3);
  __mcr(15, 0, a1[9], 13, 0, 4);
  KiWriteBankedRegisters(31, (int)(a1 + 31), (int)(a1 + 32), 0);
  KiWriteBankedRegisters(23, (int)(v1 + 33), (int)(v1 + 34), v1 + 35);
  KiWriteBankedRegisters(27, (int)(v1 + 36), (int)(v1 + 37), v1 + 38);
  KiWriteBankedRegisters(18, (int)(v1 + 39), (int)(v1 + 40), v1 + 41);
  result = __mrc(15, 0, 1, 0, 2);
  if ( (result & 0xF00000) == 0 )
    return sub_51B458();
  v3 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xA8C);
  _R3 = v1[28] | 0x40000000;
  __asm { VMSR            FPEXC, R3 }
  if ( (v3 & 0x20) != 0 )
  {
    _R3 = v1[29];
    __asm { VMSR            FPINST, R3 }
    if ( (v3 & 0x40) != 0 )
    {
      _R3 = v1[30];
      __asm { VMSR            FPINST2, R3 }
    }
  }
  if ( (result & 0xF00000) == 0 )
  {
    __mcr(15, 0, result, 1, 0, 2);
    __isb(0xFu);
  }
  if ( !KiCP14DebugEnabled )
    return result;
  v9 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  if ( (__mrc(14, 0, 1, 1, 4) & 2) != 0 )
  {
    __mcr(14, 0, 0, 1, 0, 4);
    __dsb(0xFu);
    __mrc(14, 0, 1, 1, 4);
  }
  if ( (__mrc(15, 0, 0, 1, 2) & 0xF) == 4 )
  {
    do
    {
      v23 = __mrc(14, 0, 1, 5, 4);
      __isb(0xFu);
    }
    while ( (v23 & 2) != 0 );
  }
  __mcr(14, 0, __mrc(14, 0, 0, 2, 2) | 0x1000, 0, 2, 2);
  __isb(0xFu);
  __mcr(14, 0, 0, 0, 7, 0);
  v10 = __mrc(14, 0, 0, 0, 0);
  v11 = (v10 >> 28) + 1;
  v12 = (HIBYTE(v10) & 0xF) + 1;
  KiSetHwDebugRegs(v12, &KiZeroedDebugRegs, &KiZeroedDebugRegs, v11, &KiZeroedDebugRegs, &KiZeroedDebugRegs);
  if ( !*(_DWORD *)(v9 + 1296) )
  {
    if ( v12 > 8 )
      v12 = 8;
    if ( v11 > 1 )
      v11 = 1;
    *(_DWORD *)(v9 + 1296) = v12;
    *(_DWORD *)(v9 + 1300) = v11;
  }
  v13 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  KiSetHwDebugRegs(*(_DWORD *)(v13 + 2704), v1 + 10, v1 + 18, *(_DWORD *)(v13 + 2708), v1 + 26, v1 + 27);
  v14 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  result = *(_DWORD *)(v14 + 1296);
  v15 = 0;
  if ( result )
  {
    v16 = v1;
    while ( (v16[18] & 1) == 0 )
    {
      ++v15;
      ++v16;
      if ( v15 >= result )
        goto LABEL_15;
    }
    goto LABEL_28;
  }
LABEL_15:
  v17 = *(_DWORD *)(v14 + 1300);
  v18 = 0;
  if ( v17 )
  {
    while ( (v1[27] & 1) == 0 )
    {
      ++v18;
      ++v1;
      if ( v18 >= v17 )
        goto LABEL_18;
    }
LABEL_28:
    v19 = 1;
    goto LABEL_19;
  }
LABEL_18:
  v19 = 0;
LABEL_19:
  if ( !KiCP14DebugEnabled )
    return result;
  v20 = __mrc(14, 0, 0, 2, 2);
  if ( !v19 )
  {
    if ( (v20 & 0x8000) == 0 )
      return result;
    v24 = v20 & 0xFFFF7FFF;
LABEL_36:
    __mcr(14, 0, v24, 0, 2, 2);
    __dsb(0xFu);
    return result;
  }
  if ( (v20 & 0x8000) == 0 )
  {
    v24 = v20 | 0x8000;
    goto LABEL_36;
  }
  return result;
}
