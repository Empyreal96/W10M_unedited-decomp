// PsInsertVirtualizedTimer 
 
int __fastcall PsInsertVirtualizedTimer(int a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // r8
  unsigned int *v6; // r6
  int v7; // r4
  int result; // r0
  unsigned int v9; // r2
  _DWORD *v10; // r1
  unsigned __int64 v11; // r4
  int v12; // r1
  int v13; // r1
  int v14; // [sp+8h] [bp-30h]
  unsigned __int64 v15[5]; // [sp+10h] [bp-28h] BYREF

  v3 = *(_DWORD **)(a1 + 288);
  __dmb(0xBu);
  v6 = v3 + 173;
  v7 = KfRaiseIrql(2);
  v14 = v7;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_547BD8();
  do
    v9 = __ldrex(v6);
  while ( __strex(1u, v6) );
  __dmb(0xBu);
  if ( v9 )
    KxWaitForSpinLockAndAcquire(v3 + 173);
  v10 = (_DWORD *)v3[175];
  *a2 = v3 + 174;
  a2[1] = v10;
  if ( (_DWORD *)*v10 != v3 + 174 )
    __fastfail(3u);
  *v10 = a2;
  v3[175] = a2;
  if ( v3[102] )
  {
    LODWORD(v11) = KeQueryInterruptTime();
    HIDWORD(v11) = v12;
    KeQuerySystemTime(v15);
    ExpTimerPause((int)(a2 - 41), v13, v15[0], v11);
    v7 = v14;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v3 + 173);
  }
  else
  {
    __dmb(0xBu);
    *v6 = 0;
  }
  result = KfLowerIrql(v7);
  *a3 = v3;
  return result;
}
