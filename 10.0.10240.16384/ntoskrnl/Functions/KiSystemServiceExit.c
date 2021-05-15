// KiSystemServiceExit 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall __noreturn KiSystemServiceExit(int a1, int a2, int a3, int a4, unsigned int a5, int a6)
{
  int v6; // r0
  int v7; // r3
  int v8; // r2
  unsigned int v9; // r1
  int v10; // r2
  int v11; // r12
  __int16 v12; // r1
  unsigned int v13; // r3
  int v18; // r2
  _DWORD v19[32]; // [sp-1A0h] [bp-1A0h] BYREF
  int v20; // [sp-120h] [bp-120h]

  v19[24] = a1;
  v8 = __mrc(15, 0, 13, 0, 3);
  v9 = v8 & 0xFFFFFFC0;
  v10 = v8 & 0xF;
  if ( !(*(_DWORD *)(v9 + 308) | v10 | *(unsigned __int8 *)(v9 + 362)) )
  {
    __disable_irq();
    __clrex();
    while ( 1 )
    {
      v11 = __mrc(15, 0, 13, 0, 3);
      v12 = *(_WORD *)(v11 + 2);
      if ( !*(_BYTE *)(v11 + 122) )
        break;
      __mcr(15, 0, v11 | 1, 13, 0, 3);
      __enable_irq();
      KiInitiateUserApc(*(_BYTE *)(v11 + 122));
      KfLowerIrql(0);
      __disable_irq();
    }
    if ( (v12 & 1) != 0 )
    {
      ((void (__fastcall *)(int))KiCopyCounters)(v11);
      v11 = __mrc(15, 0, 13, 0, 3);
      v12 = *(_WORD *)(v11 + 2);
    }
    if ( (v12 & 0x100) != 0 )
    {
      ((void (__fastcall *)(_DWORD *))KiWriteDebugRegs)(v19);
      v11 = __mrc(15, 0, 13, 0, 3);
    }
    if ( (*(_BYTE *)(v11 + 3) & 4) != 0 )
      v13 = *(_DWORD *)(v11 + 1076);
    else
      v13 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
    __mcr(15, 0, v13, 13, 0, 3);
    __asm
    {
      CPS.W           #0x1F
      CPS.W           #0x12
    }
    a5 = v20 & 0xFFFFFFFE;
    a6 = (32 * (v20 & 1)) | 0x10;
    if ( (*(_BYTE *)(v11 + 3) & 4) == 0 && (*(_DWORD *)(v11 + 3) & 2) != 0 )
    {
      v18 = *(_DWORD *)(*(_DWORD *)(v11 + 116) + 160);
      if ( v18 )
      {
        v19[28] = v20;
        v20 = v18;
        a5 = v18 & 0xFFFFFFFE;
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
  KiBugCheckDispatch(v6, v20, v10, v7);
}
