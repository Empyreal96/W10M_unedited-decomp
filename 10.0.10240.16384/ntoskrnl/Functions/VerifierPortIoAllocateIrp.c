// VerifierPortIoAllocateIrp 
 
int __fastcall VerifierPortIoAllocateIrp(char a1, int a2, int a3)
{
  int v4; // r7
  int v6; // r4
  int v7; // r2
  __int16 v8; // r3
  int result; // r0

  v4 = a1;
  if ( a2 && (MmVerifierData & 8) != 0 )
  {
    v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    if ( v6 == PsIdleProcess )
      VerifierBugCheckIfAppropriate(196, 266, 0);
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v7 = 0;
    }
    else
    {
      __disable_irq();
      v7 = 1;
    }
    v8 = *(_WORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v7 )
      __enable_irq();
    if ( (v8 & 1) != 0 )
      VerifierBugCheckIfAppropriate(196, 267, 0);
  }
  if ( VfFaultsInjectResourceFailure(0) )
    result = 0;
  else
    result = pXdvIoAllocateIrp(0, v4, a2, a3, IovAllocateIrp);
  return result;
}
