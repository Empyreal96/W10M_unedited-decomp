// IoUnregisterShutdownNotification 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IoUnregisterShutdownNotification(int a1)
{
  int v2; // r9
  int *i; // r4
  unsigned int v4; // r5
  int *v5; // r1 OVERLAPPED
  int **v6; // r2 OVERLAPPED
  int *j; // r4
  unsigned int v8; // r7
  int *v9; // r1 OVERLAPPED
  int **v10; // r2 OVERLAPPED
  int result; // r0

  MmLockPagableSectionByHandle(ExPageLockHandle);
  v2 = KeAcquireQueuedSpinLock(10);
  for ( i = (int *)IopNotifyShutdownQueueHead; i != &IopNotifyShutdownQueueHead; i = (int *)*i )
  {
    v4 = (unsigned int)i;
    if ( i[2] == a1 )
    {
      *(_QWORD *)&v5 = *(_QWORD *)i;
      if ( *(int **)(*i + 4) != i || *v6 != i )
        __fastfail(3u);
      *v6 = v5;
      v5[1] = (int)v6;
      i = (int *)i[1];
      ObfDereferenceObject(a1);
      ExFreePoolWithTag(v4);
    }
  }
  for ( j = (int *)IopNotifyLastChanceShutdownQueueHead; j != &IopNotifyLastChanceShutdownQueueHead; j = (int *)*j )
  {
    v8 = (unsigned int)j;
    if ( j[2] == a1 )
    {
      *(_QWORD *)&v9 = *(_QWORD *)j;
      if ( *(int **)(*j + 4) != j || *v10 != j )
        __fastfail(3u);
      *v10 = v9;
      v9[1] = (int)v10;
      j = (int *)j[1];
      ObfDereferenceObject(a1);
      ExFreePoolWithTag(v8);
    }
  }
  KeReleaseQueuedSpinLock(10, v2);
  result = MmUnlockPagableImageSection(ExPageLockHandle);
  *(_DWORD *)(a1 + 28) &= 0xFFFFF7FF;
  return result;
}
