// PopLockGetDoDevicePowerState 
 
int __fastcall PopLockGetDoDevicePowerState(int a1)
{
  int v2; // r7
  unsigned int v3; // r2
  int v4; // r5
  int vars4; // [sp+14h] [bp+4h]

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&PopIrpSerialLock);
  }
  else
  {
    do
      v3 = __ldrex((unsigned int *)&PopIrpSerialLock);
    while ( __strex(1u, (unsigned int *)&PopIrpSerialLock) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PopIrpSerialLock);
  }
  v4 = *(_DWORD *)(a1 + 8);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PopIrpSerialLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    PopIrpSerialLock = 0;
  }
  KfLowerIrql(v2);
  return (unsigned __int8)v4 >> 4;
}
