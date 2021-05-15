// ViFaultsAddTagNoDuplicates 
 
int __fastcall ViFaultsAddTagNoDuplicates(__int16 *a1, unsigned int a2, int a3, int a4)
{
  int v5; // r6
  unsigned int i; // r1
  __int16 v7; // r2
  int *v8; // r5
  int v9; // r8
  int v10; // r9
  unsigned int v11; // r2
  int **v12; // r1
  int var20[10]; // [sp+0h] [bp-20h] BYREF

  var20[0] = a4;
  v5 = 0;
  if ( a2 > 4 )
    return -1073741811;
  for ( i = 0; i < 4; ++i )
  {
    if ( i < a2 )
      v7 = *a1;
    else
      LOBYTE(v7) = 32;
    *((_BYTE *)var20 + i) = v7;
    ++a1;
  }
  v8 = (int *)ExAllocatePoolWithTag(512, 12, 1413899862);
  if ( !v8 )
    return -1073741670;
  v9 = var20[0];
  v8[2] = var20[0];
  v10 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&ViFaultInjectionLock);
  }
  else
  {
    do
      v11 = __ldrex((unsigned int *)&ViFaultInjectionLock);
    while ( __strex(1u, (unsigned int *)&ViFaultInjectionLock) );
    __dmb(0xBu);
    if ( v11 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&ViFaultInjectionLock);
  }
  ViFaultLockOwner = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( ViFaultsIsTagPresentInList(v9) )
  {
    ExFreePoolWithTag((unsigned int)v8);
  }
  else
  {
    ViHaveFaultTags = 1;
    v12 = (int **)dword_61CECC;
    *v8 = (int)&ViFaultTagsList;
    v8[1] = (int)v12;
    if ( *v12 != &ViFaultTagsList )
      __fastfail(3u);
    *v12 = v8;
    dword_61CECC = (int)v8;
  }
  ViFaultLockOwner = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&ViFaultInjectionLock, var20[9]);
  }
  else
  {
    __dmb(0xBu);
    ViFaultInjectionLock = 0;
  }
  KfLowerIrql(v10);
  return v5;
}
