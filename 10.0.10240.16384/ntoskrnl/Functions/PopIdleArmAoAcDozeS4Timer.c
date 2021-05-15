// PopIdleArmAoAcDozeS4Timer 
 
int PopIdleArmAoAcDozeS4Timer()
{
  int v0; // r7
  int v1; // r8
  unsigned int v2; // r2
  unsigned int v3; // r2
  int v4; // r1
  __int64 v5; // r2
  int vars4; // [sp+2Ch] [bp+4h]

  v0 = 0;
  v1 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&PopIdleAoAcDozeS4Lock);
  }
  else
  {
    do
      v2 = __ldrex((unsigned int *)&PopIdleAoAcDozeS4Lock);
    while ( __strex(1u, (unsigned int *)&PopIdleAoAcDozeS4Lock) );
    __dmb(0xBu);
    if ( v2 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PopIdleAoAcDozeS4Lock);
  }
  if ( !byte_61E83C )
  {
    v3 = *(_DWORD *)(PopPolicy + 88);
    v4 = -v3;
    v5 = 4284967296i64 * v3;
    HIDWORD(v5) += v4;
    KeSetTimer2(PopIdleAoAcDozeS4Timer, v5, 0i64, 0);
    byte_61E83C = 1;
    v0 = 1;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PopIdleAoAcDozeS4Lock, vars4);
  }
  else
  {
    __dmb(0xBu);
    PopIdleAoAcDozeS4Lock = 0;
  }
  KfLowerIrql(v1);
  return v0;
}
