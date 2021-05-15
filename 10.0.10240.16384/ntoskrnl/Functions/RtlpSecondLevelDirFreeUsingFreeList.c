// RtlpSecondLevelDirFreeUsingFreeList 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall RtlpSecondLevelDirFreeUsingFreeList(unsigned int a1)
{
  unsigned int v2; // r9
  unsigned int v3; // r5
  int *v4; // r7
  unsigned int v5; // r6
  int v6; // r10
  unsigned int v7; // r2
  unsigned int *v8; // r2
  int v9; // r2
  void **v10; // r2
  void ***v11; // r1 OVERLAPPED
  unsigned int i; // r2
  __int64 v13; // r0
  int result; // r0
  int v15; // [sp+0h] [bp-20h]
  int vars4; // [sp+24h] [bp+4h]

  v2 = a1 & 0xFFFFF000;
  v3 = a1 & 0xFFFFF000;
  v4 = 0;
  v5 = 0;
  v6 = 1;
  v15 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&dword_6416AC);
  }
  else
  {
    do
      v7 = __ldrex((unsigned int *)&dword_6416AC);
    while ( __strex(1u, (unsigned int *)&dword_6416AC) );
    __dmb(0xBu);
    if ( v7 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&dword_6416AC);
  }
  if ( v2 >= v2 + 4096 )
    goto LABEL_31;
  do
  {
    if ( v3 == a1 )
    {
      *(_DWORD *)(v3 + 8) = 0;
    }
    else if ( *(_DWORD *)(v3 + 8) )
    {
      v6 = 0;
    }
    else if ( v3 >= a1 )
    {
      if ( v3 > a1 && !v5 )
        v5 = v3;
    }
    else
    {
      v4 = (int *)v3;
    }
    v3 += 1024;
  }
  while ( v3 < v2 + 4096 );
  if ( v6 )
  {
LABEL_31:
    for ( i = v2; i < v2 + 4096; i += 1024 )
    {
      if ( i != a1 )
      {
        v13 = *(_QWORD *)i;
        if ( *(_DWORD *)(*(_DWORD *)i + 4) != i || *(_DWORD *)HIDWORD(v13) != i )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v13) = v13;
        *(_DWORD *)(v13 + 4) = HIDWORD(v13);
      }
    }
  }
  else if ( v5 )
  {
    v8 = *(unsigned int **)(v5 + 4);
    *(_DWORD *)a1 = v5;
    *(_DWORD *)(a1 + 4) = v8;
    if ( *v8 != v5 )
      __fastfail(3u);
    *v8 = a1;
    *(_DWORD *)(v5 + 4) = a1;
  }
  else if ( v4 )
  {
    v9 = *v4;
    *(_DWORD *)a1 = *v4;
    *(_DWORD *)(a1 + 4) = v4;
    if ( *(int **)(v9 + 4) != v4 )
      __fastfail(3u);
    *(_DWORD *)(v9 + 4) = a1;
    *v4 = a1;
  }
  else
  {
    v10 = &off_6178C8;
    v11 = (void ***)off_6178C8;
    *(_QWORD *)a1 = *(_QWORD *)&v11;
    if ( v11[1] != &off_6178C8 )
      __fastfail(3u);
    v11[1] = (void **)a1;
    off_6178C8 = (void *)a1;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_6416AC, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_6416AC = 0;
  }
  result = KfLowerIrql(v15);
  if ( v6 )
    result = ExFreePoolWithTag(v2);
  return result;
}
