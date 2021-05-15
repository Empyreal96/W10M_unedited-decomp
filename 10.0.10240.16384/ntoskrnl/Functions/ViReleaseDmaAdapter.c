// ViReleaseDmaAdapter 
 
unsigned int __fastcall ViReleaseDmaAdapter(unsigned int a1)
{
  int v2; // r8
  unsigned int *v3; // r4
  int v4; // r9
  unsigned int v5; // r2
  unsigned int v6; // r6
  unsigned int *v7; // r7
  int v8; // r4
  unsigned int v9; // r0
  unsigned int v10; // t1
  int v11; // r0
  int v12; // r6
  int vars4; // [sp+24h] [bp+4h]

  v2 = *(_DWORD *)(a1 + 8);
  v3 = (unsigned int *)(a1 + 200);
  *(_DWORD *)(v2 + 4) = *(_DWORD *)(a1 + 28);
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v3);
  }
  else
  {
    do
      v5 = __ldrex(v3);
    while ( __strex(1u, v3) );
    __dmb(0xBu);
    if ( v5 )
      KxWaitForSpinLockAndAcquire(v3);
  }
  v6 = *(_DWORD *)(a1 + 188);
  *(_DWORD *)(a1 + 188) = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v3, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  KfLowerIrql(v4);
  if ( v6 )
  {
    v7 = (unsigned int *)v6;
    v8 = 32;
    do
    {
      v10 = *v7++;
      v9 = v10;
      if ( v10 )
        MmFreeContiguousMemory(v9);
      --v8;
    }
    while ( v8 );
    ExFreePoolWithTag(v6);
  }
  v11 = ObfDereferenceObject(v2);
  v12 = v11;
  if ( *(int *)(a1 + 20) > 0 && v11 && (v11 != 1 || !*(_BYTE *)(a1 + 18)) )
  {
    ViHalPreprocessOptions(
      &dword_6187CC,
      "Too many outstanding reference counts (%x) for adapter %p",
      0x11u,
      v11,
      v2,
      a1);
    VfReportIssueWithOptions(230, 17, v12, v2, a1, &dword_6187CC);
  }
  return ExFreePoolWithTag(a1);
}
