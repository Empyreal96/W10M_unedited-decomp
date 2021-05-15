// PiCMGetObjectList 
 
int __fastcall PiCMGetObjectList(unsigned int a1, unsigned int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v8; // r6
  int v9; // r5
  int v10; // r4
  unsigned int v11; // r5
  int v12; // r0
  int v14; // r2
  int v15; // [sp+18h] [bp-40h] BYREF
  char v16[4]; // [sp+20h] [bp-38h] BYREF
  int v17; // [sp+24h] [bp-34h]
  int v18; // [sp+28h] [bp-30h]
  int v19; // [sp+2Ch] [bp-2Ch]
  int v20; // [sp+30h] [bp-28h]
  int v21; // [sp+34h] [bp-24h]
  int v22; // [sp+38h] [bp-20h]

  v15 = 0;
  *a6 = 0;
  v8 = 0;
  v9 = PiCMCaptureObjectInputData(a1, a2, a3, (int)v16);
  if ( v9 < 0 )
    goto LABEL_34;
  if ( v19 || v20 || v17 || v21 )
  {
    v9 = -1073741811;
    goto LABEL_40;
  }
  if ( !a3 || a4 < 0x14 || (v18 & 0x7FFF0000) != 0 )
    goto LABEL_38;
  if ( (v18 & 0x80000000) == 0x80000000 )
  {
    v10 = (unsigned __int16)v18;
    if ( (unsigned __int16)v18 >= 0xBu )
      v10 = 0;
LABEL_20:
    if ( v10 )
    {
      if ( v10 != 1 && v10 != 3 && v10 != 5 )
        goto LABEL_25;
      goto LABEL_24;
    }
    goto LABEL_38;
  }
  switch ( (unsigned __int16)v18 )
  {
    case 1u:
      v10 = 1;
      goto LABEL_20;
    case 2u:
      v10 = 2;
      break;
    case 3u:
      v10 = 4;
      break;
    case 4u:
      v10 = 3;
LABEL_24:
      v9 = -1073741637;
      break;
    default:
LABEL_38:
      v9 = -1073741811;
      goto LABEL_31;
  }
LABEL_25:
  if ( v9 < 0 )
  {
LABEL_31:
    v12 = PiCMReturnBufferResultData(v9, 2 * v15, 0, 0, 0, v22, a3, a4, a6);
    goto LABEL_32;
  }
  v11 = a4 - 20;
  if ( a4 - 20 < 2 )
    v11 = 0;
  if ( v11 )
  {
    v8 = ExAllocatePoolWithTag(1, v11, 879783504);
    if ( !v8 )
    {
      v9 = -1073741670;
      goto LABEL_31;
    }
    v14 = v11 >> 1;
  }
  else
  {
    v8 = 0;
    v14 = 0;
  }
  v15 = v14;
  v9 = PnpGetObjectList(PiPnpRtlCtx, v10, v14, (int)&PiPnpRtlCtx, v8, v14, (int)&v15, 0);
LABEL_40:
  if ( v9 < 0 )
    goto LABEL_31;
  v12 = PiCMReturnBufferResultData(v9, 2 * v15, 0, v8, 2 * v15, v22, a3, a4, a6);
LABEL_32:
  v9 = v12;
  if ( v8 )
    ExFreePoolWithTag(v8);
LABEL_34:
  PiCMReleaseObjectInputData((int)v16);
  return v9;
}
