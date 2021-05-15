// ExpTimerApcRoutine 
 
int __fastcall ExpTimerApcRoutine(int a1, _DWORD *a2)
{
  unsigned int v4; // r5
  unsigned int *v5; // r6
  int v6; // r9
  unsigned int v8; // r2
  unsigned int *v9; // r5
  unsigned int v10; // r2
  __int64 v11; // r0

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = (unsigned int *)(a1 - 4);
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5274F0();
  do
    v8 = __ldrex(v5);
  while ( __strex(1u, v5) );
  __dmb(0xBu);
  if ( v8 )
    KxWaitForSpinLockAndAcquire((unsigned int *)(a1 - 4));
  if ( (*(_BYTE *)(a1 + 92) & 1) != 0 && v4 == *(_DWORD *)(a1 + 8) )
  {
    if ( !*(_DWORD *)(a1 + 88) )
    {
      v9 = (unsigned int *)(v4 + 864);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v9);
      }
      else
      {
        do
          v10 = __ldrex(v9);
        while ( __strex(1u, v9) );
        __dmb(0xBu);
        if ( v10 )
          KxWaitForSpinLockAndAcquire(v9);
      }
      v11 = *(_QWORD *)(a1 + 80);
      if ( *(_DWORD *)(v11 + 4) != a1 + 80 || *(_DWORD *)HIDWORD(v11) != a1 + 80 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v11) = v11;
      *(_DWORD *)(v11 + 4) = HIDWORD(v11);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v9);
      }
      else
      {
        __dmb(0xBu);
        *v9 = 0;
      }
      *(_BYTE *)(a1 + 92) &= 0xFEu;
    }
  }
  else
  {
    *a2 = 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(a1 - 4);
  }
  else
  {
    __dmb(0xBu);
    *v5 = 0;
  }
  KfLowerIrql(v6);
  return ObfDereferenceObjectWithTag(a1 - 52);
}
