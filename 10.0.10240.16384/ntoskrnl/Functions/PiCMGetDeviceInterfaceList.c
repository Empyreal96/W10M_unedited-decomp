// PiCMGetDeviceInterfaceList 
 
int __fastcall PiCMGetDeviceInterfaceList(int a1, int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  unsigned __int16 *v7; // r5
  int v8; // r8
  int v9; // r4
  int v10; // r6
  int v12; // r3
  int v13; // r0
  int v14; // r0
  int v15; // r3
  unsigned __int16 *v17; // [sp+1Ch] [bp-5Ch] BYREF
  unsigned int v18; // [sp+20h] [bp-58h] BYREF
  _DWORD *v19; // [sp+24h] [bp-54h]
  char v20[8]; // [sp+28h] [bp-50h] BYREF
  int v21; // [sp+34h] [bp-44h]
  char v22[16]; // [sp+38h] [bp-40h] BYREF
  unsigned __int16 *v23; // [sp+48h] [bp-30h]
  int v24; // [sp+50h] [bp-28h]

  v19 = a6;
  *a6 = 0;
  v7 = 0;
  v17 = 0;
  v18 = 0;
  v8 = 0;
  v9 = PiCMCaptureInterfaceAliasInputData();
  if ( v9 >= 0 )
  {
    v10 = v21;
    if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x1000000) != 0 )
      return sub_7C8FD8();
    v12 = a3;
    if ( a3 && a4 >= 0x14 )
    {
      if ( (v21 & 0xFFFE0000) != 0 )
      {
        v9 = -1073741811;
        goto LABEL_24;
      }
      if ( (_WORD)v21 )
        v9 = -1073741811;
      if ( v9 < 0 )
        goto LABEL_24;
      v9 = RtlInitUnicodeStringEx((int)v20, v23);
      if ( v9 < 0 )
        goto LABEL_24;
      v13 = IopGetDeviceInterfaces((int)v22, (int)v20, (v10 & 0x10000) == 0, 1, &v17, (int)&v18);
      v7 = v17;
      v8 = v18;
      v9 = v13;
      v12 = a3;
      if ( a4 - 20 < v18 )
        v9 = -1073741789;
    }
    else
    {
      v9 = -1073741811;
    }
    if ( v9 >= 0 )
    {
      v14 = PiCMReturnBufferResultData(v9, v8, 0, (int)v7, v8, v24, v12, a4, v19);
      goto LABEL_15;
    }
LABEL_24:
    v14 = PiCMReturnBufferResultData(v9, v8, 0, 0, 0, v24, a3, a4, v19);
LABEL_15:
    v9 = v14;
    if ( v7 )
      ExFreePoolWithTag((unsigned int)v7);
  }
  v15 = __mrc(15, 0, 13, 0, 3);
  if ( v23 && *(_BYTE *)((v15 & 0xFFFFFFC0) + 0x15A) )
    ExFreePoolWithTag((unsigned int)v23);
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x1000000) != 0 )
    Template_q(Microsoft_Windows_Kernel_PnPHandle, dword_649E54, (int)KMPnPEvt_CfgMgr_DeviceInterfaceList_Stop);
  return v9;
}
