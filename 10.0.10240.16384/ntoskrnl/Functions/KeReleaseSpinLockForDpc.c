// KeReleaseSpinLockForDpc 
 
_DWORD *__fastcall KeReleaseSpinLockForDpc(_DWORD *result, int a2)
{
  int vars4; // [sp+Ch] [bp+4h]

  if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C) & 0x10000) != 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(result, vars4);
    }
    else
    {
      __dmb(0xBu);
      *result = 0;
    }
    result = (_DWORD *)KfLowerIrql(a2);
  }
  else if ( (dword_682604 & 0x10000) != 0 )
  {
    result = (_DWORD *)KiReleaseSpinLockInstrumented(result, vars4);
  }
  else
  {
    __dmb(0xBu);
    *result = 0;
  }
  return result;
}
