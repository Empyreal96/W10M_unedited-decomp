// IoIncrementKeepAliveCount 
 
int __fastcall IoIncrementKeepAliveCount(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  int v7; // r7
  int v8; // r6
  unsigned int v9; // r1
  int v10; // r1
  int v11; // r0
  int v13; // [sp+8h] [bp-18h] BYREF
  int var14[7]; // [sp+Ch] [bp-14h] BYREF

  v13 = a3;
  var14[0] = a4;
  v6 = IopAdjustFileObjectKeepAliveCount(a1, a2, 1, var14, &v13);
  v7 = v6;
  if ( v6 >= 0 && var14[0] == 1 )
  {
    if ( KeGetCurrentIrql(v6) == 2 )
    {
      v8 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented((int)dword_631A78);
      }
      else
      {
        do
          v9 = __ldrex(dword_631A78);
        while ( __strex(1u, dword_631A78) );
        __dmb(0xBu);
        if ( v9 )
          KxWaitForSpinLockAndAcquire(dword_631A78);
      }
      v10 = v13;
      ++*(_DWORD *)(v13 + 16);
      if ( !*(_BYTE *)(v10 + 8) )
      {
        v11 = dword_631A70;
        *(_DWORD *)v10 = dword_631A70;
        *(_DWORD *)(v10 + 4) = &dword_631A70;
        if ( *(int **)(v11 + 4) != &dword_631A70 )
          __fastfail(3u);
        *(_DWORD *)(v11 + 4) = v10;
        dword_631A70 = v10;
        *(_BYTE *)(v10 + 8) = 1;
        if ( !byte_631A90 )
        {
          byte_631A90 = 1;
          ExQueueWorkItem(&IopKeepAliveTracker, 1);
        }
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(dword_631A78, var14[6]);
      }
      else
      {
        __dmb(0xBu);
        dword_631A78[0] = 0;
      }
      KfLowerIrql(v8);
    }
    else
    {
      ObfReferenceObjectWithTag(a2);
      PspAdjustKeepAliveCountProcess(a2, 1, a1, *(unsigned __int8 *)(v13 + 10));
    }
  }
  return v7;
}
