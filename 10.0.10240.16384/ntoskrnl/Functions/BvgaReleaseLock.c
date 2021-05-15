// BvgaReleaseLock 
 
int BvgaReleaseLock()
{
  unsigned int v0; // r4
  int result; // r0
  int vars4; // [sp+Ch] [bp+4h]

  v0 = (unsigned __int8)BvgaOldIrql;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    result = KiReleaseSpinLockInstrumented(&BootDriverLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    BootDriverLock = 0;
  }
  if ( v0 <= 2 )
    result = KfLowerIrql(v0);
  return result;
}
