// MmStealTopLevelPage 
 
int __fastcall MmStealTopLevelPage(int a1)
{
  unsigned int v2; // r2
  int v3; // r4
  int v5; // r9
  unsigned int *v6; // r6
  int v7; // r8
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  int v11; // r5
  int v12; // r4
  int v13; // r3
  unsigned int v14; // r1

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_DWORD *)(a1 + 20) != v2 )
    return 0;
  v5 = *(_DWORD *)(v2 + 116);
  v6 = (unsigned int *)(v5 + 492);
  v7 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) == 0 )
  {
    v8 = (unsigned __int8 *)(v5 + 495);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v5 + 492));
    while ( 1 )
    {
      v10 = *v6;
      if ( (*v6 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v10 & 0x40000000) == 0 )
      {
        do
          v14 = __ldrex(v6);
        while ( v14 == v10 && __strex(v10 | 0x40000000, v6) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    MiReplacePageTablePage((int **)a1);
    if ( *(int *)(a1 + 28) < 0 )
    {
      v3 = 0;
    }
    else
    {
      v11 = (*(_DWORD *)a1 >> 12) & 0x3FF;
      v12 = *(_DWORD *)(a1 + 12) << 12;
      v13 = *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4 * v11) & 0xFFF;
      MiArmWritePdeOtherProcess(*(_DWORD *)(a1 + 24), (_DWORD *)(*(_DWORD *)(a1 + 4) + 4 * v11), v13 | v12, v13);
      *(_DWORD *)(v5 + 24) = v12;
      v3 = 1;
    }
    MiUnlockWorkingSetExclusive(v5 + 492, v7);
    return v3;
  }
  return sub_551EB0();
}
