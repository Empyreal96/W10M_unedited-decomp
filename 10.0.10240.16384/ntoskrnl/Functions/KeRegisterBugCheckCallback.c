// KeRegisterBugCheckCallback 
 
int __fastcall KeRegisterBugCheckCallback(int a1, int a2, int a3, int a4, int a5)
{
  int v7; // r9
  unsigned int v9; // r2
  int v10; // r6
  __int64 v11; // r2
  int v12; // r2

  v7 = KfRaiseIrql(15);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_551570();
  do
    v9 = __ldrex((unsigned int *)&KeBugCheckCallbackLock);
  while ( __strex(1u, (unsigned int *)&KeBugCheckCallbackLock) );
  __dmb(0xBu);
  if ( v9 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&KeBugCheckCallbackLock);
  v10 = 0;
  if ( !*(_BYTE *)(a1 + 28) && !KiCheckForDuplicateBugCheckCallback(&KeBugCheckCallbackListHead, a1) )
  {
    LODWORD(v11) = a5;
    *(_DWORD *)(a1 + 12) = a3;
    *(_DWORD *)(a1 + 16) = a4;
    HIDWORD(v11) = a3 + a2 + a4 + a5;
    *(_QWORD *)(a1 + 20) = v11;
    *(_BYTE *)(a1 + 28) = 1;
    *(_DWORD *)(a1 + 8) = a2;
    v12 = KeBugCheckCallbackListHead;
    *(_DWORD *)a1 = KeBugCheckCallbackListHead;
    *(_DWORD *)(a1 + 4) = &KeBugCheckCallbackListHead;
    if ( *(int **)(v12 + 4) != &KeBugCheckCallbackListHead )
      __fastfail(3u);
    *(_DWORD *)(v12 + 4) = a1;
    KeBugCheckCallbackListHead = a1;
    v10 = 1;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KeBugCheckCallbackLock);
  }
  else
  {
    __dmb(0xBu);
    KeBugCheckCallbackLock = 0;
  }
  KfLowerIrql(v7);
  return v10;
}
