// CcUnregisterExternalCache 
 
int __fastcall CcUnregisterExternalCache(int a1)
{
  int v2; // r7
  unsigned int v3; // r2
  __int64 v4; // r0
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&CcExternalCacheListLock);
  }
  else
  {
    do
      v3 = __ldrex((unsigned int *)&CcExternalCacheListLock);
    while ( __strex(1u, (unsigned int *)&CcExternalCacheListLock) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&CcExternalCacheListLock);
  }
  v4 = *(_QWORD *)(a1 + 16);
  if ( *(_DWORD *)(v4 + 4) != a1 + 16 || *(_DWORD *)HIDWORD(v4) != a1 + 16 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v4) = v4;
  *(_DWORD *)(v4 + 4) = HIDWORD(v4);
  if ( CcNumberOfExternalCaches - 1 >= (unsigned int)CcNumberOfExternalCaches )
    KeBugCheckEx(52, 4162, -1073740768, 0, 0);
  --CcNumberOfExternalCaches;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&CcExternalCacheListLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    CcExternalCacheListLock = 0;
  }
  KfLowerIrql(v2);
  CcDeductDirtyPagesFromExternalCache(a1, *(_DWORD *)(a1 + 4));
  return ExFreePoolWithTag(a1);
}
