// PiCMEnumerateSubKeys 
 
int __fastcall PiCMEnumerateSubKeys(unsigned int a1, unsigned int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  unsigned int v8; // r6
  int v9; // r5
  int v10; // r4
  int v11; // r0
  int v12; // r0
  unsigned int v14; // r4
  int v15; // r1
  int v16; // [sp+18h] [bp-40h] BYREF
  unsigned int v17; // [sp+1Ch] [bp-3Ch] BYREF
  char v18[4]; // [sp+20h] [bp-38h] BYREF
  int v19; // [sp+24h] [bp-34h]
  int v20; // [sp+28h] [bp-30h]
  int v21; // [sp+2Ch] [bp-2Ch]
  int v22; // [sp+30h] [bp-28h]

  v16 = 0;
  *a6 = 0;
  v8 = 0;
  v9 = 0;
  v10 = PiCMCaptureEnumerateInputData(a1, a2, a3, (int)v18);
  if ( v10 < 0 )
    return v10;
  if ( v19 )
    goto LABEL_3;
  if ( !a3 || a4 < 0x14 )
  {
    v11 = -1073741811;
    goto LABEL_22;
  }
  v14 = a4 - 20;
  if ( a4 - 20 < 2 )
    goto LABEL_3;
  v9 = ExAllocatePoolWithTag(1, a4 - 20, 879783504);
  if ( !v9 )
  {
    v11 = -1073741670;
    goto LABEL_4;
  }
  v8 = v14 >> 1;
  v17 = v14 >> 1;
  if ( v20 == 1 )
  {
    v15 = 5;
    goto LABEL_19;
  }
  if ( v20 == 2 )
  {
    v15 = 7;
    goto LABEL_19;
  }
  if ( v20 != 3 )
  {
LABEL_3:
    v11 = -1073741811;
LABEL_4:
    v12 = PiCMReturnBufferResultData(v11, 2 * v8, 0, 0, 0, v22, a3, a4, a6);
    goto LABEL_5;
  }
  v15 = 8;
LABEL_19:
  v11 = PnpCtxGetCachedContextBaseKey((_DWORD *)PiPnpRtlCtx, v15, &v16);
  if ( v11 < 0 )
    goto LABEL_4;
  v11 = PnpCtxRegEnumKey(v11, v16, v21, v9, &v17);
  v8 = v17;
LABEL_22:
  if ( v11 < 0 )
    goto LABEL_4;
  v12 = PiCMReturnBufferResultData(v11, 2 * v8, 0, v9, 2 * v8, v22, a3, a4, a6);
LABEL_5:
  v10 = v12;
  if ( v9 )
    ExFreePoolWithTag(v9);
  return v10;
}
