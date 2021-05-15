// VerifierPortExAllocatePoolWithQuotaTag 
 
int __fastcall VerifierPortExAllocatePoolWithQuotaTag(int a1, int a2, int a3)
{
  int v6; // r5
  int v7; // r2
  __int16 v8; // r3
  int v9; // r5
  int result; // r0

  if ( (MmVerifierData & 8) != 0 )
  {
    v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    if ( v6 == PsIdleProcess )
      VerifierBugCheckIfAppropriate(196, 266, 0, 0, 0);
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
      VerifierBugCheckIfAppropriate(196, 267, 0, 0, 0);
  }
  if ( (a1 & 8) != 0 )
  {
    v9 = 0;
    a1 &= 0xFFFFFFF7;
  }
  else
  {
    v9 = 1;
  }
  result = pXdvExAllocatePoolWithTagPriority(a1 | 0x80, a2, a3, 32);
  if ( !result && v9 == 1 )
    RtlRaiseStatus(-1073741670);
  return result;
}
