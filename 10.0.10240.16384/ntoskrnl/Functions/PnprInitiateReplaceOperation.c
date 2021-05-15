// PnprInitiateReplaceOperation 
 
int PnprInitiateReplaceOperation()
{
  int v0; // r8
  int v1; // r4
  int v2; // r9
  _DWORD *v3; // r6
  int v4; // r0
  _DWORD *v5; // r0
  int v6; // r2
  int v7; // r4
  int v8; // r3
  int v9; // r3
  int v10; // r0
  int v11; // r3
  int v12; // r3
  int v13; // r7
  int v14; // r0
  int v15; // r2
  int v16; // r3
  int v17; // r3
  int v18; // r3
  int v19; // r2
  int v20; // r2
  int v21; // r0
  int v23[12]; // [sp+8h] [bp-30h] BYREF

  v0 = 0;
  v1 = PnprContext;
  v2 = 0;
  v3 = 0;
  KeInitializeEvent(PnprContext + 476, 0, 0);
  KeInitializeEvent(v1 + 492, 0, 0);
  KeInitializeEvent(v1 + 508, 0, 0);
  v4 = KeInitializeEvent(v1 + 524, 0, 0);
  if ( (*(_DWORD *)(v1 + 48) & 0x20) == 0 )
  {
    v5 = (_DWORD *)ExAllocatePoolWithTag(512, 16, 1366322768);
    v3 = v5;
    if ( !v5 )
    {
      v6 = PnprContext;
      v7 = -1073741670;
      v8 = *(_DWORD *)(PnprContext + 608);
      if ( !v8 )
        v8 = 1667;
      *(_DWORD *)(PnprContext + 608) = v8;
      v9 = *(_DWORD *)(v6 + 612);
      if ( !v9 )
        v9 = 10;
LABEL_7:
      *(_DWORD *)(v6 + 612) = v9;
      goto LABEL_37;
    }
    v5[2] = PnprQuiesceWorker;
    v5[3] = v5;
    *v5 = 0;
    v4 = ExQueueWorkItem(v5, 0);
  }
  v10 = PnprReplaceStart(v4);
  v7 = v10;
  v6 = PnprContext;
  if ( v10 < 0 )
  {
    v11 = *(_DWORD *)(PnprContext + 608);
    if ( !v11 )
      v11 = 1682;
    *(_DWORD *)(PnprContext + 608) = v11;
    v9 = *(_DWORD *)(v6 + 612);
    if ( !v9 )
      v9 = 1;
    goto LABEL_7;
  }
  v2 = 1;
  if ( *(_DWORD *)(*(_DWORD *)(PnprContext + 20) + 4) )
  {
    if ( (*(_DWORD *)(PnprContext + 48) & 8) == 0 )
    {
      v23[0] = (int)PnprStartMirroring;
      v23[1] = (int)PnprEndMirroring;
      v23[2] = (int)PnprMirrorPhysicalMemory;
      v23[3] = 0;
      v23[4] = 8;
      v7 = MmDuplicateMemory(v23);
      v6 = PnprContext;
      if ( v7 == 1073742484 )
        v7 = 0;
      goto LABEL_37;
    }
    v10 = (*(int (__fastcall **)(_DWORD))(PnprContext + 592))(*(_DWORD *)(PnprContext + 552));
    v7 = v10;
    if ( v10 < 0 )
    {
      v6 = PnprContext;
      v12 = *(_DWORD *)(PnprContext + 608);
      if ( !v12 )
        v12 = 1750;
      *(_DWORD *)(PnprContext + 608) = v12;
      v9 = *(_DWORD *)(v6 + 612);
      if ( !v9 )
        v9 = 8;
      goto LABEL_7;
    }
  }
  v13 = KeGetCurrentIrql(v10);
  v7 = PnprQuiesce();
  if ( v7 < 0 )
  {
    v18 = PnprContext;
    v19 = *(_DWORD *)(PnprContext + 608);
    if ( !v19 )
      v19 = 1783;
    *(_DWORD *)(PnprContext + 608) = v19;
    v20 = *(_DWORD *)(v18 + 612);
    if ( !v20 )
      v20 = 1;
    *(_DWORD *)(v18 + 612) = v20;
  }
  else
  {
    v0 = 1;
    v14 = PnprSwap();
    v7 = v14;
    if ( v14 < 0 )
    {
      v14 = ((int (__cdecl *)())off_6179EC)();
      v15 = PnprContext;
      v16 = *(_DWORD *)(PnprContext + 608);
      if ( !v16 )
        v16 = 1773;
      *(_DWORD *)(PnprContext + 608) = v16;
      v17 = *(_DWORD *)(v15 + 612);
      if ( !v17 )
        v17 = 1;
      *(_DWORD *)(v15 + 612) = v17;
    }
    PnprWakeProcessors(v14);
  }
  KfLowerIrql(v13);
  v6 = PnprContext;
LABEL_37:
  if ( (*(_DWORD *)(v6 + 48) & 0x20) != 0 )
  {
    if ( !v0 )
      goto LABEL_43;
    PnprCompleteWake();
  }
  else
  {
    if ( !v3 )
      goto LABEL_43;
    KeSetEvent(v6 + 508, 0, 0);
    KeWaitForSingleObject(PnprContext + 524, 0, 0, 0, 0);
  }
  v6 = PnprContext;
LABEL_43:
  if ( *(_DWORD *)(v6 + 548) )
  {
    off_6179F0();
    v6 = PnprContext;
  }
  if ( v2 )
  {
    if ( *(_DWORD *)(*(_DWORD *)(v6 + 20) + 4) )
    {
      v21 = (*(int (__fastcall **)(_DWORD))(v6 + 576))(*(_DWORD *)(v6 + 552));
      if ( v7 >= 0 )
        v7 = v21;
    }
  }
  return v7;
}
