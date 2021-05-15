// CmpLazyWriteWorker 
 
int __fastcall CmpLazyWriteWorker(unsigned int *a1)
{
  BOOL v2; // r6
  unsigned int *v3; // r5
  int v4; // r7
  unsigned int v6; // r2
  int v7; // r7
  char *v8; // r1
  char v9[8]; // [sp+8h] [bp-30h] BYREF
  char var28[44]; // [sp+10h] [bp-28h] BYREF

  v2 = a1 == (unsigned int *)&CmpLazyWriterData;
  v3 = a1 + 24;
  while ( 1 )
  {
    KeWaitForSingleObject((unsigned int)(a1 + 20), 0, 1, 0, 0);
    v4 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      break;
    do
      v6 = __ldrex(v3);
    while ( __strex(1u, v3) );
    __dmb(0xBu);
    if ( v6 )
      KxWaitForSpinLockAndAcquire(a1 + 24);
    a1[26] = 2;
    a1[27] = 0;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(a1 + 24);
    }
    else
    {
      __dmb(0xBu);
      *v3 = 0;
    }
    KfLowerIrql(v4);
    v7 = ((int (__fastcall *)(char *, char *))a1[25])(v9, var28);
    if ( v2 && CmpCannotWriteConfiguration )
    {
      if ( v9[0] )
        CmpDiskFullWarning();
      else
        CmpCannotWriteConfiguration = 0;
    }
    if ( v7 )
      v8 = var28;
    else
      v8 = 0;
    CmpCompleteLazyWrite((int)a1, (int)v8);
  }
  return sub_553248();
}
