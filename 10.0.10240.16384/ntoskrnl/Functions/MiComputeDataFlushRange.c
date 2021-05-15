// MiComputeDataFlushRange 
 
int __fastcall MiComputeDataFlushRange(unsigned int *a1, int a2, __int64 *a3, unsigned int a4, int a5, unsigned int **a6)
{
  unsigned int *v6; // r5
  unsigned int *v10; // r4
  int v11; // r9
  int v12; // r0
  int v13; // r9
  __int64 v14; // r2
  int v15; // r8
  int v16; // r0
  unsigned int *v17; // r6
  int v18; // r10
  int v19; // r9
  int result; // r0
  int v21; // r3
  unsigned int *v22; // r2
  unsigned int *v23; // r1
  int v24; // [sp+8h] [bp-28h]

  v6 = a1;
  if ( !a1[4] )
    goto LABEL_20;
  v10 = a1 + 20;
  if ( !a3 )
  {
    v13 = 0;
LABEL_17:
    v17 = (unsigned int *)MiFindLastSubsection((int)a1, 1);
    v18 = v17[7] - 1;
    goto LABEL_7;
  }
  v11 = *a3 >> 12;
  v12 = MiLocateSubsectionNode(a1, *a3, 1);
  v10 = (unsigned int *)v12;
  if ( !v12 )
  {
LABEL_20:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v6 + 9);
    }
    else
    {
      __dmb(0xBu);
      v6[9] = 0;
    }
    KfLowerIrql(a2);
    return 0;
  }
  v13 = v11 - *(_DWORD *)(v12 + 20);
  if ( !a4
    || (v14 = *a3 + a4 - 1, v15 = v14 >> 12, v16 = MiLocateSubsectionNode(v6, v14, 1), (v17 = (unsigned int *)v16) == 0) )
  {
    a1 = v6;
    goto LABEL_17;
  }
  v18 = v15 - *(_DWORD *)(v16 + 20);
LABEL_7:
  if ( !v10[16] || !MiReferenceSubsection((int)v10) )
  {
    if ( v10 != v17 )
      return sub_5469A8();
    goto LABEL_20;
  }
  v19 = v10[1] + 4 * v13;
  if ( !v17[16] || !MiReferenceSubsection((int)v17) )
  {
    v22 = (unsigned int *)v10[2];
    v23 = 0;
    if ( v22 == v17 )
      goto LABEL_25;
    do
    {
      if ( v22[16] && v22[1] )
        v23 = v22;
      v22 = (unsigned int *)v22[2];
    }
    while ( v22 != v17 );
    if ( !v23 )
LABEL_25:
      v17 = v10;
    else
      v17 = v23;
    MiReferenceSubsection((int)v17);
    v18 = v17[7] - 1;
  }
  ++v6[5];
  v24 = MiBuildWakeList(v6, 4);
  MiRemoveUnusedSegment(v6);
  if ( a5 == 1 )
    v6[7] |= 4u;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v6 + 9);
  }
  else
  {
    __dmb(0xBu);
    v6[9] = 0;
  }
  KfLowerIrql(a2);
  MiReleaseControlAreaWaiters(v24);
  result = 259;
  v21 = v17[1] + 4 * v18;
  a6[1] = (unsigned int *)v19;
  a6[2] = (unsigned int *)v21;
  *a6 = v6;
  a6[3] = v10;
  a6[4] = v17;
  a6[5] = 0;
  return result;
}
