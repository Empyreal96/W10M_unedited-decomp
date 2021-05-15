// PnpRebalance 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PnpRebalance(int a1, int a2, int a3, int a4)
{
  int v5; // r7 OVERLAPPED
  int v6; // r8 OVERLAPPED
  unsigned int v9; // r5
  int v10; // r4
  int v11; // r0
  unsigned int v12; // r5
  int v13; // r7
  int v14; // r10
  int v15; // r2
  int *v16; // r1
  int v17; // t1
  int v18; // r1
  int v19; // r3
  unsigned int v21; // [sp+8h] [bp-70h] BYREF
  int v22; // [sp+Ch] [bp-6Ch]
  int v23; // [sp+10h] [bp-68h] BYREF
  int v24; // [sp+14h] [bp-64h]
  int v25; // [sp+18h] [bp-60h]
  _DWORD *v26[2]; // [sp+20h] [bp-58h] BYREF
  unsigned int *v27; // [sp+28h] [bp-50h]
  int v28; // [sp+2Ch] [bp-4Ch]
  int v29; // [sp+30h] [bp-48h]
  int v30; // [sp+34h] [bp-44h]
  int v31; // [sp+38h] [bp-40h]
  int v32; // [sp+3Ch] [bp-3Ch]
  unsigned int v33; // [sp+40h] [bp-38h]
  int v34; // [sp+44h] [bp-34h]
  int *v35; // [sp+48h] [bp-30h]
  int v36; // [sp+4Ch] [bp-2Ch]
  int v37; // [sp+50h] [bp-28h]
  int v38; // [sp+54h] [bp-24h]

  *(_QWORD *)&v5 = PnpEtwHandle;
  v23 = a2;
  v24 = a4;
  v22 = a1;
  if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_Rebalance_Start) )
  {
    v27 = &v21;
    v28 = 0;
    v29 = 2;
    v30 = 0;
    v9 = *(unsigned __int16 *)(a1 + 20);
    v31 = *(_DWORD *)(v22 + 24);
    v32 = 0;
    v33 = v9;
    v34 = 0;
    LOWORD(v21) = v9 >> 1;
    EtwWrite(v5, v6, (int)KMPnPEvt_Rebalance_Start, 0);
    *(_QWORD *)&v5 = PnpEtwHandle;
  }
  if ( PnpDisableRebalance )
  {
    v10 = -1073741637;
    goto LABEL_31;
  }
  v11 = ExAllocatePoolWithTag(1, 40 * IopNumberDeviceNodes, 812674640);
  v12 = v11;
  if ( !v11 )
  {
    v10 = -1073741670;
    goto LABEL_30;
  }
  if ( a3 )
    memmove(v11, a2, 40 * a3);
  v10 = 0;
  v13 = 0;
  v21 = 0;
  v14 = 0;
  while ( 1 )
  {
    v25 = v13;
    PnpFindRebalanceCandidates(v14, v22, v12 + 40 * a3, (int)&v21);
    v13 = v21;
    if ( !a3 && !v24 )
    {
      v15 = 0;
      if ( !v21 )
      {
LABEL_17:
        v10 = -1073741823;
LABEL_28:
        PnpCancelStopDeviceSubtree((int *)IopRootDeviceNode);
        goto LABEL_29;
      }
      v16 = (int *)v12;
      while ( 1 )
      {
        v17 = *v16;
        v16 += 10;
        if ( v17 == *(_DWORD *)(v22 + 16) )
          break;
        if ( ++v15 >= v21 )
          goto LABEL_17;
      }
    }
    if ( v25 == v21 )
    {
      if ( v10 != -1073739512 )
        v10 = -1073741823;
      goto LABEL_27;
    }
    v10 = PnpFindBestConfiguration(v12, a3 + v21, (int)v26);
    if ( v10 >= 0 )
      break;
LABEL_27:
    if ( (unsigned int)++v14 >= 2 )
      goto LABEL_28;
  }
  PnpStopDeviceSubtree(IopRootDeviceNode);
  IopCommitConfiguration(v26);
  if ( a3 )
    PnpBuildCmResourceLists(v12, v12 + 40 * a3, 0);
  PnpBuildCmResourceLists(v12 + 40 * a3, v12 + 40 * (a3 + v13), 1);
  if ( a3 )
    memmove(v23, v12, 40 * a3);
LABEL_29:
  PnpFreeResourceRequirementsForAssignTable(v12 + 40 * a3, v12 + 40 * (a3 + v13));
  ExFreePoolWithTag(v12);
LABEL_30:
  *(_QWORD *)&v5 = PnpEtwHandle;
LABEL_31:
  v23 = v10;
  if ( v5 | v6 && EtwEventEnabled(v5, v6, (int)KMPnPEvt_Rebalance_Stop) )
  {
    v18 = *(unsigned __int16 *)(v22 + 20);
    LOWORD(v21) = *(_WORD *)(v22 + 20) >> 1;
    v27 = &v21;
    v28 = 0;
    v29 = 2;
    v30 = 0;
    v19 = *(_DWORD *)(v22 + 24);
    v33 = v18;
    v31 = v19;
    v32 = 0;
    v34 = 0;
    v35 = &v23;
    v36 = 0;
    v37 = 4;
    v38 = 0;
    EtwWrite(v5, v6, (int)KMPnPEvt_Rebalance_Stop, 0);
  }
  return v10;
}
