// PiControlGetPropertyData 
 
int __fastcall PiControlGetPropertyData(int a1, _DWORD *a2, int a3, char a4)
{
  unsigned int v5; // r2
  int *v6; // r6
  int v7; // r10
  unsigned int v8; // r8
  int v9; // r1
  int v10; // r4
  int v11; // r0
  int v12; // r9
  int *v14; // r7
  int v15; // r2
  __int16 v16; // r1
  int v17; // r0
  int v18; // r0
  int v19; // r0
  int v20; // r1
  int v21; // r0
  unsigned int v22; // r2
  int v23; // [sp+10h] [bp-30h] BYREF
  __int16 v24[2]; // [sp+18h] [bp-28h] BYREF
  int v25[9]; // [sp+1Ch] [bp-24h] BYREF

  v5 = *(unsigned __int16 *)a2;
  v6 = 0;
  v24[1] = v5;
  v24[0] = v5;
  v7 = a4;
  v8 = 0;
  if ( !v5 || v5 > 0x190 || (v5 & 1) != 0 )
    return -1073741811;
  v10 = PiControlMakeUserModeCallersCopy(v25, a2[1], v5, 2, a4, 1);
  if ( v10 >= 0 )
  {
    PpDevNodeLockTree(0, v9);
    v11 = PnpDeviceObjectFromDeviceInstance((int)v24);
    v12 = v11;
    if ( v7 )
      return sub_81298C();
    if ( v11 && (v14 = *(int **)(*(_DWORD *)(v11 + 176) + 20)) != 0 )
    {
      v15 = v14[43];
      if ( v15 == 788 || v15 == 787 )
      {
        v10 = -1073741738;
LABEL_18:
        if ( v10 < 0 )
          goto LABEL_21;
      }
      else
      {
        v8 = a2[4];
        if ( v8 )
          v6 = (int *)a2[3];
        else
          v6 = 0;
        v10 = 0;
        switch ( a2[2] )
        {
          case 1:
            v16 = 11;
            goto LABEL_15;
          case 2:
            v16 = 12;
            goto LABEL_15;
          case 3:
            v16 = 13;
            goto LABEL_15;
          case 4:
            v16 = 14;
            goto LABEL_15;
          case 5:
            v10 = PiControlGetDevicePowerData(v14, 0, v8, v6, a2 + 4);
            if ( v10 == -2147483643 )
              v10 = -1073741789;
            goto LABEL_18;
          case 6:
            v16 = 19;
            goto LABEL_15;
          case 7:
            v19 = CmGetDeviceRegProp(PiPnpRtlCtx, v14[6], 0, 34, (int)&v23, (int)v6, (int)(a2 + 4));
            v10 = v19;
            if ( v19 >= 0 && v23 != 4 )
            {
              v10 = -1073741584;
              goto LABEL_21;
            }
            if ( v19 == -1073741275 )
              v10 = -1073741772;
            goto LABEL_18;
          case 8:
            v16 = 16;
            goto LABEL_15;
          case 0xA:
            if ( v8 >= 4 )
            {
              PpHotSwapGetDevnodeRemovalPolicy(v14, 0, v6);
              v10 = 0;
            }
            else
            {
              v10 = -1073741789;
            }
            a2[4] = 4;
            goto LABEL_18;
          case 0xB:
            goto LABEL_41;
          case 0xD:
            a2[4] = 4;
            if ( v8 < 4 )
            {
              v10 = -1073741789;
              goto LABEL_21;
            }
            v10 = 0;
            *v6 = v14[111];
            break;
          case 0xE:
            v17 = PiControlGetDeviceStack(v14, v8, v6, a2 + 4);
            goto LABEL_17;
          case 0xF:
            v20 = 0;
            goto LABEL_51;
          case 0x10:
            v20 = 1;
LABEL_51:
            v21 = PnpGetDeviceDependencyList(v14, v20, v6, v8 >> 1, a2 + 4);
            v10 = v21;
            v22 = 2 * a2[4];
            a2[4] = v22;
            if ( (v21 >= 0 || v21 == -1073741789) && v22 <= 2 )
            {
              v10 = -1073741772;
              a2[4] = 0;
            }
            goto LABEL_18;
          default:
            v10 = -1073741811;
LABEL_41:
            v16 = 18;
LABEL_15:
            if ( v10 < 0 )
              goto LABEL_21;
            v17 = IoGetDeviceProperty(v11, v16, v8, v6, a2 + 4);
LABEL_17:
            v10 = v17;
            goto LABEL_18;
        }
      }
      v18 = PiControlMakeUserModeCallersCopy(a2 + 3, (int)v6, v8, 1, 0, 0);
      if ( v18 < 0 )
        v10 = v18;
    }
    else
    {
      v10 = -1073741810;
    }
LABEL_21:
    PpDevNodeUnlockTree(0);
    if ( v12 )
      ObfDereferenceObject(v12);
  }
  return v10;
}
