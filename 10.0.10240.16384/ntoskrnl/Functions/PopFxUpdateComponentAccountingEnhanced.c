// PopFxUpdateComponentAccountingEnhanced 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopFxUpdateComponentAccountingEnhanced(int a1, int a2, unsigned int a3, int a4)
{
  int v6; // r4
  int v7; // r7
  unsigned int v9; // r2
  int v10; // r3
  unsigned int v11; // r3
  __int64 v12; // r0
  unsigned __int64 v13; // r0
  unsigned int v14; // r5 OVERLAPPED
  unsigned int v15; // r6 OVERLAPPED

  v6 = *(_DWORD *)(*(_DWORD *)(a1 + 392) + 4 * a2) + 144;
  v7 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54B298();
  do
    v9 = __ldrex((unsigned int *)v6);
  while ( __strex(1u, (unsigned int *)v6) );
  __dmb(0xBu);
  if ( v9 )
    KxWaitForSpinLockAndAcquire((unsigned int *)v6);
  v10 = *(_DWORD *)(v6 + 12);
  if ( !v10 || v10 < 0 )
  {
    v11 = *(_DWORD *)(v6 + 8);
    if ( v11 != -1 )
    {
      if ( a4 )
      {
        if ( a3 >= v11 )
        {
          LODWORD(v13) = KeQueryInterruptTime();
          *(_QWORD *)&v14 = *(_QWORD *)(v6 + 16);
          if ( *(_BYTE *)(v6 + 4) && v13 >= __PAIR64__(v15, v14) )
            *(_QWORD *)(v6 + 32) = *(_QWORD *)(v6 + 32) - __PAIR64__(v15, v14) + v13;
          *(_BYTE *)(v6 + 4) = 0;
        }
      }
      else if ( !a3 && !*(_BYTE *)(v6 + 4) )
      {
        LODWORD(v12) = KeQueryInterruptTime();
        *(_BYTE *)(v6 + 4) = 1;
        *(_QWORD *)(v6 + 16) = v12;
      }
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v6);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v6 = 0;
  }
  return KfLowerIrql(v7);
}
