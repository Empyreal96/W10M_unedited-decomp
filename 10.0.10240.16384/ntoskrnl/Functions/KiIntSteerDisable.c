// KiIntSteerDisable 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiIntSteerDisable(int *a1, int a2)
{
  int *v2; // r7
  _DWORD *v4; // r5
  int v5; // r9
  unsigned int v7; // r2
  int v8; // t1
  int v9; // r1 OVERLAPPED
  _DWORD *v10; // r2 OVERLAPPED
  unsigned int *v11; // r4
  unsigned int *v12; // r1 OVERLAPPED
  unsigned int **v13; // r2 OVERLAPPED
  unsigned int *v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // [sp+0h] [bp-20h]

  v2 = a1;
  v4 = *(_DWORD **)(*a1 + 100);
  if ( v4 )
  {
    KiIntSteerLogState(*(_DWORD *)(*a1 + 100), PPM_ETW_INTERRUPT_STEERING_STATE_DISCONNECT);
    v5 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_50FA70();
    do
      v7 = __ldrex((unsigned int *)&KiIntTrackSpinlock);
    while ( __strex(1u, (unsigned int *)&KiIntTrackSpinlock) );
    __dmb(0xBu);
    if ( v7 )
      KxWaitForSpinLockAndAcquire(&KiIntTrackSpinlock);
    for ( ; a2; *(_DWORD *)(v8 + 100) = 0 )
    {
      v8 = *v2++;
      --a2;
    }
    *(_QWORD *)&v9 = *(_QWORD *)v4;
    v11 = (unsigned int *)v4[2];
    if ( *(_DWORD **)(*v4 + 4) != v4 || (_DWORD *)*v10 != v4 )
      __fastfail(3u);
    *v10 = v9;
    *(_DWORD *)(v9 + 4) = v10;
    ExFreePoolWithTag(v4, 1802654793);
    if ( (unsigned int *)v11[2] == v11 + 2 )
    {
      --KiIntTrackRootCount;
      *(_QWORD *)&v12 = *(_QWORD *)v11;
      if ( *(unsigned int **)(*v11 + 4) != v11 || *v13 != v11 )
        __fastfail(3u);
      *v13 = v12;
      v12[1] = (unsigned int)v13;
      if ( v11[24] == 2 )
        v14 = v11 + 11;
      else
        v14 = v11 + 30;
      v15 = *v14;
      while ( v15 )
      {
        v16 = __clz(__rbit(v15));
        v15 &= ~(1 << v16);
        --*((_DWORD *)*(&KiProcessorBlock + v16) + 818);
      }
      ExFreePoolWithTag(v11, 1802654793);
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&KiIntTrackSpinlock);
    }
    else
    {
      __dmb(0xBu);
      KiIntTrackSpinlock = 0;
    }
    KfLowerIrql(v5);
  }
  return 0;
}
