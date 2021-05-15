// PiCMQueryRemove 
 
int __fastcall PiCMQueryRemove(unsigned int a1, unsigned int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  unsigned __int16 *v6; // r5
  unsigned int v7; // r7
  int v8; // r8
  unsigned int v9; // r9
  unsigned int v10; // r10
  int v11; // r2
  int v12; // r4
  unsigned __int16 *v13; // r5
  int v14; // r6
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r4
  _WORD *v20; // r0
  int v21; // r6
  int v22; // r0
  int v23; // r2
  int v24; // r2
  char v25[4]; // [sp+18h] [bp-78h] BYREF
  unsigned int v26; // [sp+1Ch] [bp-74h] BYREF
  int v27; // [sp+20h] [bp-70h] BYREF
  int v28; // [sp+24h] [bp-6Ch]
  unsigned int v29; // [sp+28h] [bp-68h]
  int v30; // [sp+2Ch] [bp-64h]
  unsigned __int16 *v31; // [sp+30h] [bp-60h]
  int v32; // [sp+34h] [bp-5Ch] BYREF
  int v33; // [sp+38h] [bp-58h] BYREF
  int v34; // [sp+3Ch] [bp-54h] BYREF
  int v35; // [sp+40h] [bp-50h] BYREF
  int v36; // [sp+44h] [bp-4Ch] BYREF
  char v37[4]; // [sp+48h] [bp-48h] BYREF
  int v38; // [sp+4Ch] [bp-44h]
  int v39; // [sp+50h] [bp-40h]
  unsigned __int16 *v40; // [sp+54h] [bp-3Ch]
  int v41; // [sp+5Ch] [bp-34h]
  int v42; // [sp+60h] [bp-30h]
  int v43; // [sp+64h] [bp-2Ch] BYREF
  char v44[8]; // [sp+68h] [bp-28h] BYREF
  int v45[8]; // [sp+70h] [bp-20h] BYREF

  v29 = a4;
  v30 = a3;
  v6 = 0;
  *a6 = 0;
  v25[0] = 0;
  v32 = 0;
  v27 = 0;
  v28 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v26 = 0;
  v12 = PiCMCaptureObjectInputData(a1, a2, 0, (int)v37);
  if ( v12 >= 0 )
  {
    v13 = v40;
    v14 = v41;
    v31 = v40;
    if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x1000000) != 0 )
      return sub_7DE4D0(&Microsoft_Windows_Kernel_PnPHandle);
    if ( v40 && v39 == 1 )
    {
      if ( !v30 || v29 < 0x14 )
        goto LABEL_46;
      v19 = CmValidateDeviceName((int)&Microsoft_Windows_Kernel_PnPHandle, v40, v11, v29);
      if ( v19 >= 0 )
      {
        if ( CmIsRootDevice(v13, v16, v17, v18) )
        {
          v19 = -1073741773;
          goto LABEL_36;
        }
        v9 = v29 - 20;
        if ( v29 - 20 < 2 )
          v9 = 0;
        if ( v9 )
        {
          v20 = (_WORD *)ExAllocatePoolWithTag(1, v9, 879783504);
          v7 = (unsigned int)v20;
          if ( !v20 )
          {
            v19 = -1073741670;
            goto LABEL_36;
          }
          *v20 = 0;
        }
        else
        {
          v7 = 0;
        }
        if ( v14 == 1 )
        {
          if ( !PiAuDoesClientHaveAccess(32) || !PiAuDoesClientHavePrivilege(10) )
          {
            v19 = -1073741790;
            goto LABEL_20;
          }
          if ( (v38 & 0xFFFFFFFE) == 0 )
          {
            v8 = (v38 & 1) != 0;
LABEL_20:
            v21 = 0;
            goto LABEL_21;
          }
          goto LABEL_46;
        }
        if ( v14 != 2 )
        {
          if ( v14 != 3 )
            goto LABEL_46;
          if ( PiAuDoesClientHaveAccess(4) && PiAuDoesClientHavePrivilege(10) )
          {
            if ( !v38 )
            {
              v8 = 2;
              if ( CmGetDeviceStatus(PiPnpRtlCtx, v13, 0, &v35, v45, &v43) < 0 )
              {
                v19 = -1073741810;
              }
              else
              {
                if ( (v35 & 0x2000) != 0 )
                  goto LABEL_20;
                v19 = -1073741808;
              }
LABEL_36:
              v21 = 0;
              goto LABEL_25;
            }
LABEL_46:
            v19 = -1073741811;
            goto LABEL_36;
          }
LABEL_35:
          v19 = -1073741790;
          goto LABEL_36;
        }
        v36 = 4;
        v34 = 0;
        v19 = CmGetDeviceRegProp(PiPnpRtlCtx, (int)v13, 0, 16, (int)&v34, (int)&v33, (int)&v36);
        if ( v19 >= 0 )
        {
          if ( (v33 & 8) != 0 )
          {
            if ( !PiAuDoesClientHaveAccess(4) || !PiAuDoesClientHavePrivilege(25) )
              goto LABEL_35;
            v21 = 0;
LABEL_62:
            if ( v38 )
            {
              v19 = -1073741811;
              goto LABEL_25;
            }
            v8 = 8;
LABEL_21:
            if ( v19 >= 0 )
            {
              v19 = RtlInitUnicodeStringEx((int)v44, v13);
              if ( v19 >= 0 )
              {
                v26 = v9;
                v19 = PnpQueueQueryAndRemoveEvent(v44, &v27, v7, &v26, v8, 0);
                v10 = v26;
                if ( v19 != -2147483608 )
                {
                  v21 = v27;
                  goto LABEL_25;
                }
                v24 = v27;
                v28 = v27;
                if ( v7 )
                  *(_WORD *)(v7 + 2 * (v9 >> 1) - 2) = 0;
LABEL_72:
                if ( v10 <= v9 )
                {
                  v22 = PiCMReturnBufferResultData(-2147483608, v10, v24, v7, v10, v42, v30, v29, a6);
                  goto LABEL_26;
                }
                v21 = v28;
LABEL_25:
                v22 = PiCMReturnBufferResultData(v19, v10, v21, 0, 0, v42, v30, v29, a6);
LABEL_26:
                v12 = v22;
                if ( v7 )
                  ExFreePoolWithTag(v7);
                v6 = v31;
                goto LABEL_29;
              }
            }
LABEL_70:
            if ( v19 != -2147483608 )
              goto LABEL_25;
            v24 = v28;
            goto LABEL_72;
          }
          v19 = PnpGetCallerSessionId(&v32);
          if ( v19 < 0 )
          {
            v21 = 0;
          }
          else
          {
            v23 = MEMORY[0xFFFF92D8];
            __dmb(0xBu);
            v10 = v26;
            v21 = v27;
            v13 = v40;
            v28 = v27;
            if ( v32 == v23 )
              goto LABEL_62;
          }
          v19 = PiAuCheckClientInteractive(v25);
          if ( v19 < 0 || !v25[0] )
          {
            if ( !PiAuDoesClientHaveAccess(4) || !PiAuDoesClientHavePrivilege(10) )
            {
              v19 = -1073741790;
              goto LABEL_25;
            }
            v19 = 0;
          }
          goto LABEL_62;
        }
      }
    }
    else
    {
      v19 = -1073741811;
    }
    v21 = 0;
    goto LABEL_70;
  }
LABEL_29:
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x1000000) != 0 )
    Template_z(
      Microsoft_Windows_Kernel_PnPHandle,
      MEMORY[0x649E54],
      (int)KMPnPEvt_CfgMgr_QueryRemove_Stop,
      Microsoft_Windows_Kernel_PnPEnableBits,
      v6);
  PiCMReleaseObjectInputData((int)v37);
  return v12;
}
