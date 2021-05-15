// KiIntSteerDisable 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall KiIntSteerDisable(int *a1, int a2)
{
  int *v2; // r7
  _DWORD *v4; // r5
  int v5; // r9
  unsigned int v6; // r2
  int v7; // t1
  int v8; // r1 OVERLAPPED
  _DWORD *v9; // r2 OVERLAPPED
  unsigned int *v10; // r4
  unsigned int *v11; // r1 OVERLAPPED
  unsigned int **v12; // r2 OVERLAPPED
  unsigned int *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // [sp+0h] [bp-20h]
  int vars4; // [sp+24h] [bp+4h]

  v2 = a1;
  v4 = *(_DWORD **)(*a1 + 100);
  if ( v4 )
  {
    KiIntSteerLogState(*(_DWORD *)(*a1 + 100), (int)PPM_ETW_INTERRUPT_STEERING_STATE_DISCONNECT);
    v5 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      sub_50FA70();
    }
    else
    {
      do
        v6 = __ldrex((unsigned int *)&KiIntTrackSpinlock);
      while ( __strex(1u, (unsigned int *)&KiIntTrackSpinlock) );
      __dmb(0xBu);
      if ( v6 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&KiIntTrackSpinlock);
      for ( ; a2; *(_DWORD *)(v7 + 100) = 0 )
      {
        v7 = *v2++;
        --a2;
      }
      *(_QWORD *)&v8 = *(_QWORD *)v4;
      v10 = (unsigned int *)v4[2];
      if ( *(_DWORD **)(*v4 + 4) != v4 || (_DWORD *)*v9 != v4 )
        __fastfail(3u);
      *v9 = v8;
      *(_DWORD *)(v8 + 4) = v9;
      ExFreePoolWithTag((unsigned int)v4);
      if ( (unsigned int *)v10[2] == v10 + 2 )
      {
        --KiIntTrackRootCount;
        *(_QWORD *)&v11 = *(_QWORD *)v10;
        if ( *(unsigned int **)(*v10 + 4) != v10 || *v12 != v10 )
          __fastfail(3u);
        *v12 = v11;
        v11[1] = (unsigned int)v12;
        if ( v10[24] == 2 )
          v13 = v10 + 11;
        else
          v13 = v10 + 30;
        v14 = *v13;
        while ( v14 )
        {
          v15 = __clz(__rbit(v14));
          v14 &= ~(1 << v15);
          --*((_DWORD *)*(&KiProcessorBlock + v15) + 818);
        }
        ExFreePoolWithTag((unsigned int)v10);
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(&KiIntTrackSpinlock, vars4);
      }
      else
      {
        __dmb(0xBu);
        KiIntTrackSpinlock = 0;
      }
      KfLowerIrql(v5);
    }
  }
}
