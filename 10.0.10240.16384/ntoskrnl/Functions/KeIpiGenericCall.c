// KeIpiGenericCall 
 
int __fastcall KeIpiGenericCall(int (__fastcall *a1)(int), int a2, int a3, int a4)
{
  unsigned int v6; // r0
  unsigned int v7; // r5
  int v8; // r6
  unsigned int v10; // r2
  int v11; // r8
  unsigned int v12; // r2
  int v13; // r3
  int v14[8]; // [sp+8h] [bp-20h] BYREF

  v14[0] = a4;
  v6 = KeGetCurrentIrql(a1);
  v7 = v6;
  if ( v6 < 0xC )
    v6 = KfRaiseIrql(12);
  v8 = KeNumberProcessors_0;
  v14[0] = KeNumberProcessors_0;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_519AE0(v6);
  do
    v10 = __ldrex((unsigned int *)&KiReverseStallIpiLock);
  while ( __strex(1u, (unsigned int *)&KiReverseStallIpiLock) );
  __dmb(0xBu);
  if ( v10 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&KiReverseStallIpiLock);
  if ( v8 != 1 )
    KiIpiSendPacket(1, 0, (int)KiIpiGenericCallTarget, (int)a1, a2, (int)v14);
  while ( v14[0] != 1 )
  {
    __dmb(0xAu);
    __yield();
  }
  __dmb(0xBu);
  KfRaiseIrql(14);
  v14[0] = 0;
  v11 = a1(a2);
  if ( v8 != 1 )
  {
    if ( v7 <= 0xC )
      KfLowerIrql(12);
    v12 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    while ( 1 )
    {
      v13 = *(_DWORD *)(v12 + 2944);
      __dmb(0xBu);
      if ( !v13 )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KiReverseStallIpiLock);
  }
  else
  {
    __dmb(0xBu);
    KiReverseStallIpiLock = 0;
  }
  KfLowerIrql(v7);
  return v11;
}
