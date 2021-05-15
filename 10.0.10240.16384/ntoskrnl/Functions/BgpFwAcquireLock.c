// BgpFwAcquireLock 
 
unsigned int __fastcall BgpFwAcquireLock(unsigned int result)
{
  char v1; // r5
  unsigned int v2; // r2

  if ( (dword_619018 & 0xC00) != 3072 )
  {
    result = KeGetCurrentIrql(result);
    v1 = result;
    if ( result <= 2 )
    {
      if ( dword_637098 )
        return sub_54D828();
      result = KfRaiseIrql(2);
      v1 = result;
    }
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = KiAcquireSpinLockInstrumented(&dword_637098);
    }
    else
    {
      do
        v2 = __ldrex((unsigned int *)&dword_637098);
      while ( __strex(1u, (unsigned int *)&dword_637098) );
      __dmb(0xBu);
      if ( v2 )
        result = KxWaitForSpinLockAndAcquire((unsigned int *)&dword_637098);
    }
    byte_6416C4 = v1;
  }
  return result;
}
