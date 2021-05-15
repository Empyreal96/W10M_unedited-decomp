// VerifierExAllocatePoolWithQuota 
 
int __fastcall VerifierExAllocatePoolWithQuota(int a1, int a2)
{
  int v3; // r4
  int v4; // r2
  int v5; // r2
  __int16 v6; // r3
  int v7; // r5
  int result; // r0
  int vars4; // [sp+1Ch] [bp+4h]

  v3 = a1;
  VfCheckPoolType(a1, vars4);
  ++dword_620D9C;
  if ( (MmVerifierData & 8) != 0 )
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
  if ( (v3 & 8) != 0 )
  {
    v7 = 0;
    v3 &= 0xFFFFFFF7;
  }
  else
  {
    v7 = 1;
  }
  result = pXdvExAllocatePoolWithTagPriority(v3 | 0x80, a2, 1885434455, 32);
  if ( !result && v7 == 1 )
    RtlRaiseStatus(-1073741670);
  return result;
}
