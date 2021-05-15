// KiRestoreFromTrapFrame 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall __noreturn KiRestoreFromTrapFrame(int a1, int a2, int a3, int a4, unsigned int a5, unsigned int a6)
{
  int v11; // r12
  int v12; // r1
  unsigned int v13; // r3
  _DWORD v15[3]; // [sp-1A0h] [bp-1A0h] BYREF
  int v16; // [sp-194h] [bp-194h]
  int v17; // [sp-18Ch] [bp-18Ch]
  int v18; // [sp-120h] [bp-120h]
  int v19; // [sp-11Ch] [bp-11Ch]

  __disable_irq();
  __clrex();
  if ( (v19 & 0xF) != 0 )
  {
    if ( v17 )
    {
      _R3 = *(_DWORD *)(v17 + 4) & 0xFFC8FFFF;
      __asm { VMSR            FPSCR, R3 }
    }
    v16 = 0;
    __asm { CPS.W           #0x12 }
    v15[0] = v18 & 0xFFFFFFFE;
    v15[1] = v19 & 0xFFFFFFDF | (32 * (v18 & 1));
    __asm { RFEFD.W         SP }
  }
  while ( 1 )
  {
    v11 = __mrc(15, 0, 13, 0, 3);
    v12 = *(unsigned __int16 *)(v11 + 2);
    if ( !*(_BYTE *)(v11 + 122) )
      break;
    __mcr(15, 0, v11 | 1, 13, 0, 3);
    __enable_irq();
    KiInitiateUserApc(*(unsigned __int8 *)(v11 + 122), v12, v11 | 1, a4);
    KfLowerIrql(0);
    __disable_irq();
  }
  if ( (v12 & 1) != 0 )
  {
    KiCopyCounters((_DWORD *)v11);
    v11 = __mrc(15, 0, 13, 0, 3);
    LOWORD(v12) = *(_WORD *)(v11 + 2);
  }
  if ( (v12 & 0x100) != 0 )
  {
    KiWriteDebugRegs((int)v15);
    v11 = __mrc(15, 0, 13, 0, 3);
  }
  if ( (*(_BYTE *)(v11 + 3) & 4) != 0 )
    v13 = *(_DWORD *)(v11 + 1076);
  else
    v13 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  __mcr(15, 0, v13, 13, 0, 3);
  if ( v17 )
  {
    _R3 = *(_DWORD *)(v17 + 4) & 0xFFC8FFFF;
    __asm { VMSR            FPSCR, R3 }
  }
  v16 = 0;
  __asm
  {
    CPS.W           #0x1F
    CPS.W           #0x12
  }
  a5 = v18 & 0xFFFFFFFE;
  a6 = v19 & 0xFFFFFFDF | (32 * (v18 & 1));
  __asm { RFEFD.W         SP }
}
