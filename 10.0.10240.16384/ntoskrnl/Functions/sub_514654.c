// sub_514654 
 
void sub_514654()
{
  int v0; // r5
  unsigned int v1; // r8
  unsigned int v2; // r10
  int v3; // r9
  int v4; // r4
  unsigned int *v5; // r2
  unsigned int v6; // r0
  _DWORD *v7; // r4
  int v8; // r0
  unsigned int *v9; // r2
  unsigned int v10; // r0
  unsigned int *v11; // r2
  unsigned int v12; // r1

  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v0 + 6272);
  }
  else
  {
    v4 = *(_DWORD *)(v0 + 6272) & 0x7FFFFFFF;
    v5 = (unsigned int *)(v0 + 6272);
    do
      v6 = __ldrex(v5);
    while ( v6 == v4 && __strex(v4 + 1, v5) );
    __dmb(0xBu);
    if ( v6 != v4 )
      ExpWaitForSpinLockSharedAndAcquire((unsigned int *)(v0 + 6272));
  }
  v7 = *(_DWORD **)(v0 + 6280);
  while ( v7 )
  {
    v8 = MiCombineCompareThread(v1, (int)v7);
    if ( v8 >= 0 )
    {
      if ( v8 <= 0 )
        break;
      v7 = (_DWORD *)v7[1];
    }
    else
    {
      v7 = (_DWORD *)*v7;
    }
  }
  if ( v7 && v7[5] != ((v2 >> 10) & 0x3FFFFC) - 0x40000000 )
    v7 = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v0 + 6272);
  }
  else
  {
    __dmb(0xBu);
    v9 = (unsigned int *)(v0 + 6272);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 & 0xBFFFFFFF, v9) );
    __dmb(0xBu);
    v11 = (unsigned int *)(v0 + 6272);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 - 1, v11) );
  }
  KfLowerIrql(v3);
  if ( !v7 )
    JUMPOUT(0x431202);
  JUMPOUT(0x431204);
}
