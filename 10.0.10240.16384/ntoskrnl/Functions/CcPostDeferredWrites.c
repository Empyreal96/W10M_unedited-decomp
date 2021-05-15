// CcPostDeferredWrites 
 
// local variable allocation has failed, the output may be wrong!
int CcPostDeferredWrites()
{
  unsigned int v0; // r10
  int *v1; // r4
  int v2; // r8
  unsigned int v3; // r2
  int *v4; // r5
  unsigned int v5; // r8
  int *v6; // r1 OVERLAPPED
  int **v7; // r2 OVERLAPPED
  int result; // r0
  int v9; // r0
  int v10; // [sp+0h] [bp-20h]
  int vars4; // [sp+24h] [bp+4h]

  v0 = 0;
  while ( 1 )
  {
    v1 = 0;
    v2 = KfRaiseIrql(2);
    v10 = v2;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&CcDeferredWriteSpinLock);
    }
    else
    {
      do
        v3 = __ldrex((unsigned int *)&CcDeferredWriteSpinLock);
      while ( __strex(1u, (unsigned int *)&CcDeferredWriteSpinLock) );
      __dmb(0xBu);
      if ( v3 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&CcDeferredWriteSpinLock);
    }
    v4 = (int *)CcDeferredWrites;
    if ( (int *)CcDeferredWrites != &CcDeferredWrites )
    {
      while ( 1 )
      {
        v1 = v4 - 3;
        v5 = *(v4 - 1);
        if ( CcCanIWriteStream(*(v4 - 2), v5, v0, 2) )
          break;
        v4 = (int *)*v4;
        v1 = 0;
        if ( v4 == &CcDeferredWrites )
          goto LABEL_14;
      }
      *(_QWORD *)&v6 = *(_QWORD *)v4;
      v0 += v5;
      if ( *(int **)(*v4 + 4) != v4 || *v7 != v4 )
        __fastfail(3u);
      *v7 = v6;
      v6[1] = (int)v7;
LABEL_14:
      v2 = v10;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&CcDeferredWriteSpinLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      CcDeferredWriteSpinLock = 0;
    }
    result = KfLowerIrql(v2);
    if ( !v1 )
      return result;
    v9 = v1[5];
    if ( v9 )
    {
      KeSetEvent(v9, 0, 0);
    }
    else
    {
      ((void (__fastcall *)(int, int))v1[6])(v1[7], v1[8]);
      ExFreePoolWithTag(v1);
    }
  }
}
