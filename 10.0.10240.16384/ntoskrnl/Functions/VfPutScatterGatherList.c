// VfPutScatterGatherList 
 
int __fastcall VfPutScatterGatherList(int a1, int *a2, int a3)
{
  int v5; // r6
  unsigned int *v6; // r4
  unsigned int v7; // r2
  int *i; // r3
  int *v9; // r5
  __int64 v10; // r0
  int v11; // r7
  int result; // r0
  int v13; // [sp+8h] [bp-28h]
  int (__fastcall *v15)(int, int *, int); // [sp+10h] [bp-20h]
  int vars4; // [sp+34h] [bp+4h]

  v15 = (int (__fastcall *)(int, int *, int))ViGetRealDmaOperation(a1, 48);
  v5 = ViGetAdapterInformationInternal(a1, 1);
  if ( !v5 || (VF_ASSERT_IRQL(2), *(_DWORD *)(v5 + 32) == v5 + 32) )
  {
LABEL_23:
    result = v15(a1, a2, a3);
    if ( v5 )
      result = DECREMENT_SCATTER_GATHER_LISTS(v5);
  }
  else
  {
    v6 = (unsigned int *)(v5 + 40);
    v13 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v5 + 40);
    }
    else
    {
      do
        v7 = __ldrex(v6);
      while ( __strex(1u, v6) );
      __dmb(0xBu);
      if ( v7 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v5 + 40));
    }
    for ( i = *(int **)(v5 + 32); ; i = (int *)*i )
    {
      v9 = i - 10;
      if ( (int *)(v5 + 32) == i )
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented((_DWORD *)(v5 + 40), vars4);
        }
        else
        {
          __dmb(0xBu);
          *v6 = 0;
        }
        KfLowerIrql(v13);
        goto LABEL_23;
      }
      if ( (int *)*(i - 1) == a2 )
        break;
    }
    v10 = *(_QWORD *)i;
    v11 = *a2;
    if ( *(int **)(*i + 4) != i || *(int **)HIDWORD(v10) != i )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v10) = v10;
    *(_DWORD *)(v10 + 4) = HIDWORD(v10);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented((_DWORD *)(v5 + 40), vars4);
    }
    else
    {
      __dmb(0xBu);
      *v6 = 0;
    }
    KfLowerIrql(v13);
    VF_UNMARK_SCATTER_GATHER_LIST((int)a2, v9[13]);
    v15(a1, a2, a3);
    SUBTRACT_MAP_REGISTERS(v5, v11);
    DECREMENT_SCATTER_GATHER_LISTS(v5);
    ViFlushDoubleBuffer(v9[13], v9[2], v9[3], v9[4], a3);
    ViFreeMapRegisterFile(v5);
    result = ExFreeToNPagedLookasideList((int)&ViHalWaitBlockLookaside, v9);
  }
  return result;
}
