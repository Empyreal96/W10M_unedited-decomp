// PiCMGetDeviceIdList 
 
int __fastcall PiCMGetDeviceIdList(int a1, int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  unsigned int v6; // r6
  _WORD *v8; // r7
  int v9; // r4
  unsigned int v10; // r9
  __int16 v11; // r8
  unsigned int v13; // r6
  int v14; // r4
  int v15; // r5
  int v16; // r0
  int v17; // r3
  int v18; // [sp+18h] [bp-50h] BYREF
  unsigned int v19; // [sp+1Ch] [bp-4Ch]
  int v20; // [sp+20h] [bp-48h] BYREF
  int v21; // [sp+24h] [bp-44h]
  char v22[16]; // [sp+28h] [bp-40h] BYREF
  int v23; // [sp+3Ch] [bp-2Ch]
  unsigned int v24; // [sp+40h] [bp-28h]
  int v25; // [sp+48h] [bp-20h]

  v6 = a4;
  v19 = a4;
  v21 = a3;
  *a6 = 0;
  v18 = 0;
  v20 = 0;
  v8 = 0;
  v9 = PiCMCaptureDeviceListInputData();
  v10 = v24;
  if ( v9 >= 0 )
  {
    v11 = v23;
    if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x1000000) != 0 )
      return sub_7E916C();
    if ( !a3 || v6 < 0x14 )
    {
      v15 = -1073741811;
      v14 = v18;
LABEL_20:
      if ( v15 >= 0 )
      {
        v16 = PiCMReturnBufferResultData(v15, 2 * v14, 0, (int)v8, 2 * v14, v25, v21, v6, a6);
        goto LABEL_22;
      }
LABEL_32:
      v16 = PiCMReturnBufferResultData(v15, 2 * v14, 0, 0, 0, v25, v21, v19, a6);
LABEL_22:
      v9 = v16;
      if ( v8 )
        ExFreePoolWithTag((unsigned int)v8);
      goto LABEL_24;
    }
    v13 = v6 - 20;
    if ( v13 < 2 )
      v13 = 0;
    if ( v13 )
    {
      v8 = (_WORD *)ExAllocatePoolWithTag(1, v13, 879783504);
      if ( !v8 )
      {
        v15 = -1073741670;
        goto LABEL_36;
      }
      v14 = v13 >> 1;
    }
    else
    {
      v8 = 0;
      v14 = 0;
    }
    v18 = v14;
    v15 = PiCMConvertDeviceListFilters(v23, &v20);
    if ( v15 < 0 )
      goto LABEL_32;
    if ( v11 != 4 && v11 != 8 && v11 != 16 && v11 != 32 && v11 != 64 )
    {
      SeCaptureSubjectContext(v22);
      v15 = CmGetMatchingFilteredDeviceList(PiPnpRtlCtx, v10, v20, PiCMMandatoryFilterCallback, v22, v8, v18, &v18);
      SeReleaseSubjectContext((int)v22);
      if ( v15 < 0 )
      {
        v14 = v18;
LABEL_19:
        v6 = v19;
        goto LABEL_20;
      }
LABEL_18:
      v14 = v18;
      if ( !v18 )
      {
        v14 = 1;
        v18 = 1;
        if ( v13 < 2 )
        {
          v15 = -1073741789;
          goto LABEL_32;
        }
        *v8 = 0;
        v14 = v18;
      }
      goto LABEL_19;
    }
    if ( !v10 )
    {
      v15 = -1073741811;
      goto LABEL_32;
    }
    v15 = CmGetDeviceRelationsList(PiPnpRtlCtx, v10, v20 & 0xFFFFFEFF, v8, v14, &v18);
    if ( v15 >= 0 )
      goto LABEL_18;
LABEL_36:
    v14 = v18;
    goto LABEL_32;
  }
LABEL_24:
  v17 = __mrc(15, 0, 13, 0, 3);
  if ( v10 && *(_BYTE *)((v17 & 0xFFFFFFC0) + 0x15A) )
    ExFreePoolWithTag(v10);
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x1000000) != 0 )
    Template_q(Microsoft_Windows_Kernel_PnPHandle, dword_649E54, (int)KMPnPEvt_CfgMgr_DeviceList_Stop);
  return v9;
}
