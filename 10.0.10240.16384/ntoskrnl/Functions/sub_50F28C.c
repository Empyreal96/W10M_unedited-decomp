// sub_50F28C 
 
void __fastcall sub_50F28C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22)
{
  int v22; // r5
  unsigned int v23; // r9
  unsigned int *v24; // r4
  int v25; // r8
  unsigned int v26; // r2

  if ( (a3 & 0x40000000) != 0 )
  {
    v24 = (unsigned int *)(v22 + 80);
    v25 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v22 + 80);
    }
    else
    {
      do
        v26 = __ldrex(v24);
      while ( __strex(1u, v24) );
      __dmb(0xBu);
      if ( v26 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v22 + 80));
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented((_DWORD *)(v22 + 80), a22);
    }
    else
    {
      __dmb(0xBu);
      *v24 = v23;
    }
    KfLowerIrql(v25);
  }
  JUMPOUT(0x4EEB9E);
}
