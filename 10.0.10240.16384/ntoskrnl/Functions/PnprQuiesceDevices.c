// PnprQuiesceDevices 
 
int __fastcall PnprQuiesceDevices(int *a1)
{
  int v2; // r5
  int v3; // r3
  int v4; // r2
  int v5; // r0
  int v6; // r3
  int v7; // r2

  *(_DWORD *)(PnprContext + 648) = PnprGetMillisecondCounter(0);
  memset(a1, 0, 60);
  *a1 = -2013265920;
  *((_QWORD *)a1 + 5) = 0x500000002i64;
  a1[12] = -2013265920;
  a1[8] = PoBlockConsoleSwitch(a1 + 9);
  v2 = PoStartPowerStateTasks(a1 + 9);
  if ( v2 >= 0 )
  {
    v5 = PoStartPartitionReplace(a1 + 9, a1[8]);
    a1[1] = 1;
    a1[2] = 5;
    a1[3] = 5;
    a1[4] = 1;
    v6 = *a1;
    a1[5] = 2;
    a1[6] = v6;
    v2 = PoInitializeBroadcast(v5);
    if ( v2 >= 0 )
    {
      *((_BYTE *)a1 + 30) = 3;
      PoBroadcastSystemState(a1 + 1);
      *((_BYTE *)a1 + 30) = 2;
      v2 = PoBroadcastSystemState(a1 + 1);
      if ( v2 >= 0 )
        goto LABEL_13;
      v3 = PnprContext;
      v4 = *(_DWORD *)(PnprContext + 608);
      if ( !v4 )
        v4 = 2016;
    }
    else
    {
      v3 = PnprContext;
      v4 = *(_DWORD *)(PnprContext + 608);
      if ( !v4 )
        v4 = 1998;
    }
  }
  else
  {
    v3 = PnprContext;
    v4 = *(_DWORD *)(PnprContext + 608);
    if ( !v4 )
      v4 = 1975;
  }
  *(_DWORD *)(v3 + 608) = v4;
  v7 = *(_DWORD *)(v3 + 612);
  if ( !v7 )
    v7 = 7;
  *(_DWORD *)(v3 + 612) = v7;
LABEL_13:
  *(_DWORD *)(PnprContext + 652) = PnprGetMillisecondCounter(0);
  return v2;
}
