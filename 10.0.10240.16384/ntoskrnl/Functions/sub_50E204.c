// sub_50E204 
 
void __fastcall sub_50E204(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  unsigned int *v12; // r6
  int v13; // r7
  int v14; // r8
  int v15; // r9
  _BYTE *v16; // r0
  _DWORD *v17; // r5
  unsigned int *v18; // r2
  unsigned int v19; // r1
  unsigned int *v20; // r4
  int v21; // r7
  unsigned int v22; // r2

  v16 = (_BYTE *)ExAllocatePoolWithTag(512, 24);
  v17 = v16;
  if ( v16 )
  {
    memset(v16, 0, 24);
    v17[1] = v15;
    v17[4] = v14;
    v17[5] = v13;
    KeQueryTickCount(v17 + 2);
    v20 = v12 + 13;
    v21 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)(v12 + 13));
    }
    else
    {
      do
        v22 = __ldrex(v20);
      while ( __strex(1u, v20) );
      __dmb(0xBu);
      if ( v22 )
        KxWaitForSpinLockAndAcquire(v12 + 13);
    }
    *v17 = v12[20];
    v12[20] = (unsigned int)v17;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v12 + 13, a12);
    }
    else
    {
      __dmb(0xBu);
      *v20 = 0;
    }
    KfLowerIrql(v21);
  }
  else
  {
    __dmb(0xBu);
    v18 = v12 + 14;
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 + 1, v18) );
    __dmb(0xBu);
  }
  JUMPOUT(0x4AB3F8);
}
