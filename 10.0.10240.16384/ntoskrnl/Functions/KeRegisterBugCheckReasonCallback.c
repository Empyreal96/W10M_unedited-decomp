// KeRegisterBugCheckReasonCallback 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeRegisterBugCheckReasonCallback(int a1, int a2, int a3, int a4)
{
  int v8; // r6
  unsigned int v10; // r2
  int *v11; // r2
  int *v12; // r2 OVERLAPPED
  int v13; // r1 OVERLAPPED
  int v14; // [sp+0h] [bp-20h]

  v8 = 1;
  v14 = KfRaiseIrql(15);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_551594();
  do
    v10 = __ldrex((unsigned int *)&KeBugCheckCallbackLock);
  while ( __strex(1u, (unsigned int *)&KeBugCheckCallbackLock) );
  __dmb(0xBu);
  if ( v10 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&KeBugCheckCallbackLock);
  if ( *(_BYTE *)(a1 + 24)
    || (a3 == 4 || a3 == 6 ? (v11 = &KeBugCheckAddRemovePagesCallbackListHead) : (v11 = &KeBugCheckReasonCallbackListHead),
        KiCheckForDuplicateBugCheckCallback(v11, a1)) )
  {
    v8 = 0;
  }
  else
  {
    *(_DWORD *)(a1 + 16) = a2 + a3 + a4;
    *(_DWORD *)(a1 + 20) = a3;
    *(_BYTE *)(a1 + 24) = 1;
    *(_DWORD *)(a1 + 8) = a2;
    *(_DWORD *)(a1 + 12) = a4;
    v13 = *v12;
    *(_QWORD *)a1 = *(_QWORD *)(&v12 - 1);
    if ( *(int **)(v13 + 4) != v12 )
      __fastfail(3u);
    *(_DWORD *)(v13 + 4) = a1;
    *v12 = a1;
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
  KfLowerIrql(v14);
  return v8;
}
