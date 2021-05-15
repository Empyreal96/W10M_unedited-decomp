// MiDoneWithThisPageGetAnother 
 
int __fastcall MiDoneWithThisPageGetAnother(int *a1, _WORD *a2, int a3, int a4)
{
  int v6; // r7
  unsigned int *v7; // r4
  int v8; // r9
  int v9; // r2
  int v10; // r3
  int v11; // r8
  int result; // r0
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r1
  _WORD *v17; // [sp+0h] [bp-28h] BYREF
  int v18; // [sp+4h] [bp-24h]
  int v19; // [sp+8h] [bp-20h]

  v17 = a2;
  v18 = a3;
  v19 = a4;
  v6 = a4;
  if ( *a1 != -1 )
    MiFinishLastForkPageTable(a3);
  v7 = (unsigned int *)(a2 + 246);
  MI_INITIALIZE_COLOR_BASE((int)v7, 0, (int)&v17);
  v8 = HIWORD(v18);
  v9 = (unsigned __int16)(*v17 + 1);
  v10 = (unsigned __int16)v18;
  *v17 = v9;
  v11 = v9 & v10;
  while ( 1 )
  {
    result = MiGetPage((int)MiSystemPartition, v11 | v8, 194);
    *a1 = result;
    if ( result != -1 )
      break;
    MiUnlockWorkingSetExclusive((int)v7, v6);
    MiWaitForFreePage((int)MiSystemPartition);
    v6 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v7);
    }
    else
    {
      v13 = (unsigned __int8 *)v7 + 3;
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 | 0x80, v13) );
      __dmb(0xBu);
      if ( v14 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v7);
      while ( 1 )
      {
        v15 = *v7;
        if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v15 & 0x40000000) == 0 )
        {
          do
            v16 = __ldrex(v7);
          while ( v16 == v15 && __strex(v15 | 0x40000000, v7) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
  }
  return result;
}
