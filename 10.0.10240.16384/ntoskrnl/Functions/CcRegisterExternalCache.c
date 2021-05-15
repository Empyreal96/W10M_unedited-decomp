// CcRegisterExternalCache 
 
int __fastcall CcRegisterExternalCache(int a1, _DWORD *a2)
{
  int v2; // r5
  _BYTE *v5; // r0
  _DWORD *v6; // r6
  int v7; // r8
  unsigned int v8; // r2
  int **v9; // r0
  int vars4; // [sp+24h] [bp+4h]

  v2 = 0;
  if ( !CcInitializationComplete )
    KeBugCheckEx(52, 6344, -1073740768, 0, 0);
  v5 = (_BYTE *)ExAllocatePoolWithTag(512, 24);
  v6 = v5;
  if ( !v5 )
    return -1073741670;
  memset(v5, 0, 24);
  *v6 = a1;
  v7 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&CcExternalCacheListLock);
  }
  else
  {
    do
      v8 = __ldrex((unsigned int *)&CcExternalCacheListLock);
    while ( __strex(1u, (unsigned int *)&CcExternalCacheListLock) );
    __dmb(0xBu);
    if ( v8 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&CcExternalCacheListLock);
  }
  v9 = (int **)dword_6327FC;
  v6[4] = &CcExternalCacheList;
  v6[5] = v9;
  if ( *v9 != &CcExternalCacheList )
    __fastfail(3u);
  *v9 = v6 + 4;
  dword_6327FC = (int)(v6 + 4);
  if ( CcNumberOfExternalCaches + 1 <= (unsigned int)CcNumberOfExternalCaches )
    KeBugCheckEx(52, 4147, -1073740768, 0, 0);
  ++CcNumberOfExternalCaches;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&CcExternalCacheListLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    CcExternalCacheListLock = 0;
  }
  KfLowerIrql(v7);
  *a2 = v6;
  return v2;
}
