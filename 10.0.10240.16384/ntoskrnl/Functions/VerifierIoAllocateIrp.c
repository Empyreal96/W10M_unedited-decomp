// VerifierIoAllocateIrp 
 
int __fastcall VerifierIoAllocateIrp(char a1, int a2)
{
  int v3; // r5
  int v4; // r2
  int v5; // r2
  __int16 v6; // r3
  int result; // r0
  int vars4; // [sp+1Ch] [bp+4h]

  v3 = a1;
  if ( a2 && (MmVerifierData & 8) != 0 )
  {
    v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    if ( v4 == PsIdleProcess )
      VerifierBugCheckIfAppropriate(196, 266, 0);
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v5 = 0;
    }
    else
    {
      __disable_irq();
      v5 = 1;
    }
    v6 = *(_WORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v5 )
      __enable_irq();
    if ( (v6 & 1) != 0 )
      VerifierBugCheckIfAppropriate(196, 267, 0);
  }
  if ( VfFaultsInjectResourceFailure(0) )
    result = 0;
  else
    result = pXdvIoAllocateIrp(0, v3, a2, vars4, IovAllocateIrp);
  return result;
}
