// PopFxUpdateDeviceAccountingEnhanced 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopFxUpdateDeviceAccountingEnhanced(int a1, unsigned int a2, int a3)
{
  int v3; // r4
  int v6; // r7
  unsigned int v8; // r2
  int v9; // r3
  unsigned int v10; // r3
  unsigned __int64 v11; // r0
  unsigned int v12; // r5 OVERLAPPED
  unsigned int v13; // r6 OVERLAPPED
  __int64 v14; // r0

  v3 = a1 + 344;
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54B334();
  do
    v8 = __ldrex((unsigned int *)v3);
  while ( __strex(1u, (unsigned int *)v3) );
  __dmb(0xBu);
  if ( v8 )
    KxWaitForSpinLockAndAcquire((unsigned int *)v3);
  v9 = *(_DWORD *)(v3 + 12);
  if ( !v9 || v9 < 0 )
  {
    v10 = *(_DWORD *)(v3 + 8);
    if ( v10 != 5 )
    {
      if ( a3 )
      {
        if ( a2 >= v10 )
        {
          LODWORD(v11) = KeQueryInterruptTime();
          *(_QWORD *)&v12 = *(_QWORD *)(v3 + 16);
          if ( *(_BYTE *)(v3 + 4) && v11 >= __PAIR64__(v13, v12) )
            *(_QWORD *)(v3 + 32) = *(_QWORD *)(v3 + 32) - __PAIR64__(v13, v12) + v11;
          *(_BYTE *)(v3 + 4) = 0;
        }
      }
      else if ( a2 == 1 && !*(_BYTE *)(v3 + 4) )
      {
        LODWORD(v14) = KeQueryInterruptTime();
        *(_BYTE *)(v3 + 4) = 1;
        *(_QWORD *)(v3 + 16) = v14;
      }
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v3);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v3 = 0;
  }
  return KfLowerIrql(v6);
}
