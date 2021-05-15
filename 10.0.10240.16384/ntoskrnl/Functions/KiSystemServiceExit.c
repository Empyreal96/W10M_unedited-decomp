// KiSystemServiceExit 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall __noreturn KiSystemServiceExit(int a1, int a2, int a3, int a4, unsigned int a5, int a6)
{
  int v6; // r0
  int v7; // r3
  int v8; // r2
  unsigned int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r12
  int v13; // r1
  unsigned int v14; // r3
  int v19; // r2
  _DWORD v20[32]; // [sp-1A0h] [bp-1A0h] BYREF
  int v21; // [sp-120h] [bp-120h]

  v20[24] = a1;
  v8 = __mrc(15, 0, 13, 0, 3);
  v9 = v8 & 0xFFFFFFC0;
  v10 = v8 & 0xF;
  v11 = *(unsigned __int8 *)(v9 + 362);
  if ( !(*(_DWORD *)(v9 + 308) | v10 | v11) )
  {
    __disable_irq();
    __clrex();
    while ( 1 )
    {
      v12 = __mrc(15, 0, 13, 0, 3);
      v13 = *(unsigned __int16 *)(v12 + 2);
      if ( !*(_BYTE *)(v12 + 122) )
        break;
      __mcr(15, 0, v12 | 1, 13, 0, 3);
      __enable_irq();
      KiInitiateUserApc(*(unsigned __int8 *)(v12 + 122), v13, v12 | 1, v11);
      KfLowerIrql(0);
      __disable_irq();
    }
    if ( (v13 & 1) != 0 )
    {
      KiCopyCounters((_DWORD *)v12);
      v12 = __mrc(15, 0, 13, 0, 3);
      LOWORD(v13) = *(_WORD *)(v12 + 2);
    }
    if ( (v13 & 0x100) != 0 )
    {
      KiWriteDebugRegs((int)v20);
      v12 = __mrc(15, 0, 13, 0, 3);
    }
    if ( (*(_BYTE *)(v12 + 3) & 4) != 0 )
      v14 = *(_DWORD *)(v12 + 1076);
    else
      v14 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
    __mcr(15, 0, v14, 13, 0, 3);
    __asm
    {
      CPS.W           #0x1F
      CPS.W           #0x12
    }
    a5 = v21 & 0xFFFFFFFE;
    a6 = (32 * (v21 & 1)) | 0x10;
    if ( (*(_BYTE *)(v12 + 3) & 4) == 0 && (*(_DWORD *)(v12 + 3) & 2) != 0 )
    {
      v19 = *(_DWORD *)(*(_DWORD *)(v12 + 116) + 160);
      if ( v19 )
      {
        v20[28] = v21;
        v21 = v19;
        a5 = v19 & 0xFFFFFFFE;
        __asm { RFEFD.W         SP }
      }
    }
    __asm { RFEFD.W         SP }
  }
  v6 = 74;
  v7 = 0;
  if ( !v10 )
  {
    v6 = 1;
    v10 = *(unsigned __int8 *)(v9 + 362);
    v7 = *(_DWORD *)(v9 + 308);
  }
  KiBugCheckDispatch(v6, v21, v10, v7);
}
