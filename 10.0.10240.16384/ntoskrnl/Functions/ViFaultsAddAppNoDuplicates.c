// ViFaultsAddAppNoDuplicates 
 
int __fastcall ViFaultsAddAppNoDuplicates(int a1, int a2)
{
  unsigned int v2; // r7
  int v4; // r6
  int v5; // r0
  unsigned int v6; // r5
  int v7; // r3
  int v8; // r8
  unsigned int v9; // r2
  int **v10; // r1
  int vars4; // [sp+24h] [bp+4h]

  v2 = 2 * a2;
  v4 = 0;
  v5 = ExAllocatePoolWithTag(512, 2 * a2 + 18, 1095132758);
  v6 = v5;
  if ( !v5 )
    return -1073741670;
  memmove(v5 + 16, a1, v2);
  *(_WORD *)(v2 + v6 + 16) = 0;
  RtlInitUnicodeString(v6 + 8, (unsigned __int16 *)(v6 + 16));
  RtlUpcaseUnicodeString((unsigned __int16 *)(v6 + 8), (unsigned __int16 *)(v6 + 8), 0, v7);
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&ViFaultInjectionLock);
  }
  else
  {
    do
      v9 = __ldrex((unsigned int *)&ViFaultInjectionLock);
    while ( __strex(1u, (unsigned int *)&ViFaultInjectionLock) );
    __dmb(0xBu);
    if ( v9 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&ViFaultInjectionLock);
  }
  ViFaultLockOwner = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( ViFaultsIsAppTarget(v6 + 8) )
  {
    ExFreePoolWithTag(v6);
  }
  else
  {
    v10 = (int **)dword_61CEBC;
    *(_DWORD *)v6 = &ViFaultApplicationsList;
    *(_DWORD *)(v6 + 4) = v10;
    if ( *v10 != &ViFaultApplicationsList )
      __fastfail(3u);
    *v10 = (int *)v6;
    dword_61CEBC = v6;
  }
  ViFaultLockOwner = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&ViFaultInjectionLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    ViFaultInjectionLock = 0;
  }
  KfLowerIrql(v8);
  return v4;
}
