// IoDecrementKeepAliveCount 
 
int __fastcall IoDecrementKeepAliveCount(int a1, int a2)
{
  int v2; // r7
  int v3; // r8
  unsigned int v4; // r1
  int v5; // r5
  int **v6; // r1
  int v8; // [sp+8h] [bp-20h] BYREF
  int var1C[9]; // [sp+Ch] [bp-1Ch] BYREF

  v2 = IopAdjustFileObjectKeepAliveCount(a1, a2, 0, &v8, var1C);
  if ( v2 >= 0 && !v8 )
  {
    v3 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)dword_631A78);
    }
    else
    {
      do
        v4 = __ldrex(dword_631A78);
      while ( __strex(1u, dword_631A78) );
      __dmb(0xBu);
      if ( v4 )
        KxWaitForSpinLockAndAcquire(dword_631A78);
    }
    v5 = var1C[0];
    KeQuerySystemTime((_DWORD *)(var1C[0] + 24));
    *(_QWORD *)(v5 + 24) += 50000000i64;
    --*(_DWORD *)(v5 + 16);
    if ( *(_BYTE *)(v5 + 8) )
    {
      if ( dword_631A94 )
        KeAlertThread(dword_631A94, 0);
    }
    else
    {
      v6 = (int **)dword_631A74;
      *(_DWORD *)v5 = &dword_631A70;
      *(_DWORD *)(v5 + 4) = v6;
      if ( *v6 != &dword_631A70 )
        __fastfail(3u);
      *v6 = (int *)v5;
      dword_631A74 = v5;
      *(_BYTE *)(v5 + 8) = 1;
      if ( !byte_631A90 )
      {
        byte_631A90 = 1;
        ExQueueWorkItem(&IopKeepAliveTracker, 1);
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(dword_631A78, var1C[8]);
    }
    else
    {
      __dmb(0xBu);
      dword_631A78[0] = 0;
    }
    KfLowerIrql(v3);
  }
  return v2;
}
