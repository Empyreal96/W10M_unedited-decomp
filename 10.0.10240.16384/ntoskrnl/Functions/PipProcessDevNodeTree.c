// PipProcessDevNodeTree 
 
int __fastcall PipProcessDevNodeTree(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r5
  int v8; // r7
  int v10; // lr
  int v11; // r9
  _DWORD *v13; // r4
  int v14; // r6
  int v15; // r2
  int v16; // r5
  int v17; // r2
  int v19; // r2
  int v20; // r3
  unsigned int v21; // r4
  int v22; // r0
  int v23; // r1
  int v24; // r0
  int v25; // r0
  int v26; // r0
  int v27; // r3
  int v28; // [sp+10h] [bp-1E8h]
  int v29; // [sp+14h] [bp-1E4h] BYREF
  int v30; // [sp+18h] [bp-1E0h]
  int v31; // [sp+1Ch] [bp-1DCh] BYREF
  int v32; // [sp+20h] [bp-1D8h]
  int v33; // [sp+24h] [bp-1D4h]
  int v34; // [sp+28h] [bp-1D0h]
  int v35; // [sp+2Ch] [bp-1CCh]
  int v36; // [sp+30h] [bp-1C8h]
  int v37; // [sp+34h] [bp-1C4h]
  char v38[8]; // [sp+38h] [bp-1C0h] BYREF
  unsigned __int16 v39[220]; // [sp+40h] [bp-1B8h] BYREF

  v7 = a4;
  v8 = a1;
  v33 = a4;
  v34 = a3;
  v28 = a1;
  if ( a2 && a4 != 1 && !*(_BYTE *)(a2 + 16) && !a7 && PiCollapseEnumRequests((_DWORD *)a2) )
    v8 = IopRootDeviceNode;
  v37 = 0;
  v10 = 0;
  v30 = 0;
  v11 = 0;
  v35 = 0;
  v32 = 0x80000000;
  do
  {
    if ( !a7 )
    {
      if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) != 0 )
        return sub_7CADD4(&Microsoft_Windows_Kernel_PnPHandle, &Microsoft_Windows_Kernel_PnPEnableBits);
      v29 = 0;
      v35 = PnpProcessAssignResources(v8, a5, &v29);
      if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) != 0 )
        Template_z(
          Microsoft_Windows_Kernel_PnPHandle,
          dword_649E54,
          (int)KMPnPEvt_AssignResources_Stop,
          (int)&Microsoft_Windows_Kernel_PnPHandle,
          *(unsigned __int16 **)(v8 + 24));
      if ( v29 && PipProcessDevNodeTree(IopRootDeviceNode, a2, v34, v7, 0, 0, 1) == -1073741106 )
      {
        v10 = 1;
        v30 = 1;
      }
      else
      {
        v10 = v30;
      }
    }
    v29 = 0;
    v36 = 1;
    v13 = (_DWORD *)v8;
    do
    {
      v14 = 1;
      if ( !v10 )
      {
        if ( v13[43] != 769 && (v13[67] & 0x6000) == 0 && PnpCheckForActiveDependencies(v13, 2) )
          PipSetDevNodeProblem(v13, 51, 0);
        v15 = v13[67];
        if ( (v15 & 0x6000) != 0 )
        {
LABEL_27:
          if ( !a7 && (v13[114] & 1) != 0 )
            PpDevCfgTraceDeviceStart(v13);
          if ( v11 && v14 && (PnpAsyncOptions & v32) == 0 )
            v14 = 1;
          if ( v14 == 1 )
          {
LABEL_34:
            while ( v13 != (_DWORD *)v8 )
            {
              if ( *v13 )
              {
                v13 = (_DWORD *)*v13;
                goto LABEL_37;
              }
              if ( v11 && PnpAsyncOptions && (PnpAsyncOptions & v32) == 0 )
              {
                v27 = v13[2];
                if ( v27 )
                  v13 = *(_DWORD **)(v27 + 4);
                goto LABEL_67;
              }
              if ( v13[2] )
                v13 = (_DWORD *)v13[2];
            }
            if ( !v11 )
              v36 = 0;
LABEL_67:
            v29 = 1;
          }
          else if ( v14 == 2 )
          {
            if ( !v13[1] )
              goto LABEL_34;
            v13 = (_DWORD *)v13[1];
          }
LABEL_37:
          v17 = v28;
          goto LABEL_38;
        }
        switch ( v13[43] )
        {
          case 0x301:
            if ( v7 == 3 && (v15 & 0x2000000) != 0 || a7 )
              goto LABEL_22;
            if ( PnpCheckForActiveDependencies(v13, 1) )
            {
              PipSetDevNodeProblem(v13, 51, 0);
              goto LABEL_22;
            }
            v16 = PiProcessNewDeviceNode((int)v13);
            goto LABEL_74;
          case 0x302:
            if ( a7 )
              goto LABEL_22;
            v16 = PipCallDriverAddDevice(v13, v34);
            if ( v16 >= 0 )
            {
              PoFxPrepareDevice((int)v13, 0, v19, v20);
              v14 = 0;
              v35 = 1;
            }
            goto LABEL_50;
          case 0x304:
            if ( a7 )
              goto LABEL_22;
            PoFxActivateDevice(v13[4]);
            v13[114] |= 0x200u;
            v26 = PipProcessStartPhase1(v13, a6, v11);
LABEL_85:
            v16 = v26;
            if ( v26 != 259 )
              goto LABEL_75;
            v11 = 1;
            goto LABEL_22;
          case 0x306:
            v25 = PipProcessStartPhase2(v13);
            goto LABEL_81;
          case 0x307:
            if ( (v15 & v32) != 0 )
              goto LABEL_95;
            v25 = PipProcessStartPhase3(v13, v7 != 1);
LABEL_81:
            v16 = v25;
            if ( v25 >= 0 )
              goto LABEL_75;
            v16 = -1073741106;
            goto LABEL_50;
          case 0x308:
            if ( v7 == 1 && v13 != (_DWORD *)v8 )
              goto LABEL_22;
            v14 = 2;
            if ( a7 || (v15 & 8) == 0 )
              goto LABEL_22;
            v16 = PipEnumerateDevice((int)v13, a6, v11);
            if ( v16 == 259 )
            {
              v11 = 1;
LABEL_95:
              v14 = 1;
            }
            else
            {
LABEL_74:
              if ( v16 >= 0 )
LABEL_75:
                v14 = 0;
LABEL_50:
              if ( v16 == -1073741106 )
                goto LABEL_51;
            }
LABEL_22:
            v31 = 0;
            v16 = PnpDeviceCompletionProcessCompletedRequests(0, 0, &v31);
            if ( v16 != -1073741106 )
            {
              if ( !v31 )
              {
                if ( v29 )
                {
                  v29 = 0;
                  v16 = PnpDeviceCompletionProcessCompletedRequests(0, 1, &v31);
                  if ( !v31 )
                    v11 = 0;
                }
              }
              if ( v16 != -1073741106 )
                goto LABEL_26;
            }
LABEL_51:
            if ( a7 )
            {
              v37 = v16;
LABEL_26:
              v7 = v33;
              goto LABEL_27;
            }
            v7 = v33;
            break;
          case 0x30A:
            v26 = PipProcessRestartPhase1(v13, a6, v11);
            goto LABEL_85;
          case 0x30B:
            v25 = PipProcessRestartPhase2(v13);
            goto LABEL_81;
          case 0x30D:
            if ( (v13[114] & 0x200) != 0 )
            {
              PoFxIdleDevice(v13[4]);
              v13[114] &= 0xFFFFFDFF;
            }
            v16 = PipEnumerateCompleted(v13);
            v14 = 2;
            goto LABEL_50;
          default:
            goto LABEL_22;
        }
      }
      v30 = 0;
      PnpDeviceCompletionProcessCompletedRequests(1, 1, &v31);
      v11 = 0;
      PipProcessDevNodeTree(IopRootDeviceNode, a2, v34, v7, a5, a6, 1);
      v21 = *(unsigned __int16 *)(v8 + 20) >> 1;
      memmove((int)v39, *(_DWORD *)(v8 + 24), v21 * 2);
      if ( v21 >= 201 )
        _report_rangecheckfailure();
      v39[v21] = 0;
      ObfDereferenceObject(*(_DWORD *)(v28 + 16));
      v22 = PpDevNodeUnlockTree(1);
      PnpSynchronizeDeviceEventQueue(v22);
      PpDevNodeLockTree(1, v23);
      RtlInitUnicodeString((unsigned int)v38, v39);
      v24 = PnpDeviceObjectFromDeviceInstance((int)v38);
      if ( !v24 )
        return -1073741823;
      v8 = *(_DWORD *)(*(_DWORD *)(v24 + 176) + 20);
      v17 = v8;
      v28 = v8;
      v13 = (_DWORD *)v8;
LABEL_38:
      v10 = v30;
    }
    while ( v36 );
    v10 = v30;
  }
  while ( v35 );
  if ( !a7 )
    ObfDereferenceObject(*(_DWORD *)(v17 + 16));
  return v37;
}
