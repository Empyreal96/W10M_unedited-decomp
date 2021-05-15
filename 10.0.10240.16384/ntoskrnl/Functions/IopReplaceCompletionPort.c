// IopReplaceCompletionPort 
 
int __fastcall IopReplaceCompletionPort(_DWORD *a1, int a2, int a3)
{
  int v4; // r6
  unsigned int *v5; // r5
  int v8; // r9
  unsigned int v9; // r2
  int *v10; // r0
  int v11; // r3
  int vars4; // [sp+24h] [bp+4h]

  v4 = -1073741823;
  v5 = a1 + 28;
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v5);
  }
  else
  {
    do
      v9 = __ldrex(v5);
    while ( __strex(1u, v5) );
    __dmb(0xBu);
    if ( v9 )
      KxWaitForSpinLockAndAcquire(v5);
  }
  v10 = (int *)a1[27];
  if ( v10 && (_DWORD *)a1[29] == a1 + 29 )
  {
    ObfDereferenceObjectWithTag(*v10);
    a1[11] &= 0xF1FFFFFF;
    if ( a2 )
    {
      ObfReferenceObjectWithTag(a2);
      *(_DWORD *)a1[27] = a2;
      *(_DWORD *)(a1[27] + 4) = a3;
    }
    else
    {
      ExFreePoolWithTag(a1[27]);
      v11 = a1[11];
      a1[27] = 0;
      a1[11] = v11 | 0x400;
    }
    v4 = 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v5, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v5 = 0;
  }
  KfLowerIrql(v8);
  return v4;
}
