// PiCMGetRegistryProperty 
 
int __fastcall PiCMGetRegistryProperty(int a1, int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v8; // r6
  int v9; // r4
  int v10; // r8
  int v12; // r5
  int v13; // r0
  unsigned int v14; // [sp+18h] [bp-58h] BYREF
  int v15; // [sp+1Ch] [bp-54h] BYREF
  int v16; // [sp+20h] [bp-50h] BYREF
  char v17[4]; // [sp+28h] [bp-48h] BYREF
  int v18; // [sp+2Ch] [bp-44h]
  int v19; // [sp+30h] [bp-40h]
  int v20; // [sp+34h] [bp-3Ch]
  int v21; // [sp+3Ch] [bp-34h]
  int v22; // [sp+40h] [bp-30h]
  int v23; // [sp+44h] [bp-2Ch]
  int v24; // [sp+48h] [bp-28h]
  int v25; // [sp+4Ch] [bp-24h]

  *a6 = 0;
  v15 = 0;
  v16 = 0;
  v14 = 0;
  v8 = 0;
  v9 = PiCMCaptureRegistryPropertyInputData(a1, a2, a3, v17);
  if ( v9 < 0 )
    goto LABEL_21;
  v10 = v20;
  if ( !v20 || v18 || v23 || v24 || v22 )
  {
    v9 = -1073741811;
    goto LABEL_17;
  }
  if ( !a3 || a4 < 0x14 )
  {
    v9 = -1073741811;
LABEL_25:
    v12 = v14;
    goto LABEL_22;
  }
  if ( a4 == 20 )
  {
    v8 = 0;
  }
  else
  {
    v8 = ExAllocatePoolWithTag(1, a4 - 20, 879783504);
    if ( !v8 )
      v9 = -1073741670;
  }
  if ( v9 < 0 )
    goto LABEL_25;
  v9 = PiCMConvertRegistryProperty(v21, &v16);
  if ( v9 < 0 )
    goto LABEL_25;
  v14 = a4 - 20;
  if ( v19 != 1 )
    return sub_811A50();
  v9 = CmGetDeviceRegProp(PiPnpRtlCtx, v10, 0, v16, (int)&v15, v8, (int)&v14);
LABEL_17:
  v12 = v14;
  if ( v9 >= 0 )
  {
    v13 = PiCMReturnBufferResultData(v9, v14, v15, v8, v14, v25, a3, a4, a6);
    goto LABEL_19;
  }
LABEL_22:
  v13 = PiCMReturnBufferResultData(v9, v12, v15, 0, 0, v25, a3, a4, a6);
LABEL_19:
  v9 = v13;
  if ( v8 )
    ExFreePoolWithTag(v8);
LABEL_21:
  PiCMReleaseRegistryPropertyInputData(v17);
  return v9;
}
