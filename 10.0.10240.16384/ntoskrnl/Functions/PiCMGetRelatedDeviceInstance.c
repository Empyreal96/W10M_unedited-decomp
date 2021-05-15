// PiCMGetRelatedDeviceInstance 
 
int __fastcall PiCMGetRelatedDeviceInstance(unsigned int a1, unsigned int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v7; // r7
  unsigned int v8; // r5
  _WORD *v9; // r6
  __int16 *v10; // r9
  int v11; // r0
  int v12; // r2
  int v13; // r4
  unsigned __int16 *v14; // r8
  int v15; // r3
  unsigned int v16; // r5
  int v17; // r1
  int v18; // r2
  int v19; // r0
  int v21; // r7
  int v22; // r0
  unsigned int v23; // [sp+18h] [bp-50h]
  unsigned int v24; // [sp+1Ch] [bp-4Ch] BYREF
  int v25; // [sp+20h] [bp-48h]
  char v26[8]; // [sp+28h] [bp-40h] BYREF
  char v27[4]; // [sp+30h] [bp-38h] BYREF
  int v28; // [sp+34h] [bp-34h]
  int v29; // [sp+38h] [bp-30h]
  unsigned __int16 *v30; // [sp+3Ch] [bp-2Ch]
  int v31; // [sp+44h] [bp-24h]
  int v32; // [sp+48h] [bp-20h]

  v7 = a3;
  *a6 = 0;
  v8 = 0;
  v25 = a3;
  v9 = 0;
  v23 = 0;
  v10 = 0;
  v11 = PiCMCaptureObjectInputData(a1, a2, 0, (int)v27);
  v13 = v11;
  if ( v11 < 0 )
    goto LABEL_24;
  v14 = v30;
  if ( v30 && !v28 && (v15 = v29, v29 == 1) )
  {
    if ( !v7 || a4 < 0x14 )
      goto LABEL_18;
    v16 = a4 - 20;
    if ( a4 - 20 < 2 )
      v16 = 0;
    if ( v16 )
    {
      v11 = ExAllocatePoolWithTag(1, v16, 879783504);
      v9 = (_WORD *)v11;
      if ( !v11 )
        v13 = -1073741670;
    }
    else
    {
      v9 = 0;
    }
    if ( v13 < 0 )
      goto LABEL_19;
    v13 = CmValidateDeviceName(v11, v14, v12, v15);
    if ( v13 < 0 )
      goto LABEL_19;
    if ( v31 == 1 )
    {
      v24 = v16 >> 1;
      v22 = CmGetDeviceParent(PiPnpRtlCtx, v14, v9, &v24);
      v8 = v24;
      v13 = v22;
      v23 = v24;
    }
    else
    {
      if ( v31 == 2 )
      {
        v21 = 2;
      }
      else
      {
        if ( v31 != 3 )
        {
LABEL_18:
          v13 = -1073741811;
          goto LABEL_19;
        }
        if ( CmIsRootDevice(v14, v17, v18, 3) )
        {
          v13 = -1073741810;
          goto LABEL_19;
        }
        v21 = 3;
      }
      v13 = RtlInitUnicodeStringEx((int)v26, v14);
      if ( v13 < 0 )
        goto LABEL_19;
      v24 = 400;
      v10 = (__int16 *)ExAllocatePoolWithTag(1, 400, 879783504);
      if ( !v10 )
      {
        v13 = -1073741670;
        goto LABEL_19;
      }
      v13 = PiGetRelatedDevice((int)v26, (int)v10, &v24, v21);
      if ( v13 < 0 )
        goto LABEL_19;
      v13 = RtlStringCbCopyExW(v9, v16, v10, 0, 0, 2048);
      if ( v13 == -2147483643 )
        v13 = -1073741789;
      v7 = v25;
      v8 = (v24 >> 1) + 1;
      v23 = v8;
    }
  }
  else
  {
    v13 = -1073741811;
  }
  if ( v13 >= 0 )
  {
    v19 = PiCMReturnBufferResultData(v13, 2 * v8, 0, (int)v9, 2 * v8, v32, v7, a4, a6);
    goto LABEL_20;
  }
LABEL_19:
  v19 = PiCMReturnBufferResultData(v13, 2 * v23, 0, 0, 0, v32, v25, a4, a6);
LABEL_20:
  v13 = v19;
  if ( v9 )
    ExFreePoolWithTag((unsigned int)v9);
  if ( v10 )
    ExFreePoolWithTag((unsigned int)v10);
LABEL_24:
  PiCMReleaseObjectInputData((int)v27);
  return v13;
}
