// sub_51EEA8 
 
void __fastcall sub_51EEA8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18)
{
  unsigned int *v18; // r4
  int v19; // r5
  int v20; // r9
  unsigned int *v21; // r7
  unsigned int v22; // r2
  unsigned int *v23; // r8
  unsigned int *v24; // r6
  unsigned int v25; // r3
  unsigned int *v26; // r6
  unsigned int v27; // r2
  signed int v28; // r2
  unsigned int v29; // r2
  int v30; // [sp+0h] [bp+0h]

  v20 = 0;
  v21 = v18 + 13;
  v30 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)(v18 + 13));
  }
  else
  {
    do
      v22 = __ldrex(v21);
    while ( __strex(1u, v21) );
    __dmb(0xBu);
    if ( v22 )
      KxWaitForSpinLockAndAcquire(v18 + 13);
  }
  v23 = (unsigned int *)v18[20];
  v24 = v23;
  KeQueryTickCount(&a7);
  if ( v23 )
  {
    do
    {
      if ( v20 || v24[1] != v19 )
      {
        v23 = v24;
        v24 = (unsigned int *)*v24;
      }
      else
      {
        v20 = 1;
        v25 = *v24;
        if ( v24 == (unsigned int *)v18[20] )
        {
          v18[20] = v25;
          ExFreePoolWithTag(v24, 0);
          v24 = (unsigned int *)v18[20];
        }
        else
        {
          *v23 = v25;
          ExFreePoolWithTag(v24, 0);
          v24 = (unsigned int *)*v23;
        }
      }
    }
    while ( v24 );
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v18 + 13, a18);
  }
  else
  {
    __dmb(0xBu);
    *v21 = 0;
  }
  KfLowerIrql(v30);
  if ( !v20 )
  {
    __dmb(0xBu);
    v26 = v18 + 14;
    do
    {
      v27 = __ldrex(v26);
      v28 = v27 - 1;
    }
    while ( __strex(v28, v26) );
    __dmb(0xBu);
    if ( v28 < 0 && ((MmVerifierData & 0x800) == 0 || !VfRemLockReportBadReleaseTag(v18, v19)) )
    {
      __dmb(0xBu);
      do
        v29 = __ldrex(v26);
      while ( __strex(v29 + 1, v26) );
      __dmb(0xBu);
    }
  }
  JUMPOUT(0x44E630);
}
