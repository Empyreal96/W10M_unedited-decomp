// KdReleaseDebuggerLock 
 
int __fastcall KdReleaseDebuggerLock(int a1)
{
  int vars4; // [sp+Ch] [bp+4h]

  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KdDebuggerLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    KdDebuggerLock = 0;
  }
  return KfLowerIrql(a1);
}
