// PiCMGetObjectPropertyKeys 
 
int __fastcall PiCMGetObjectPropertyKeys(unsigned int a1, unsigned int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v8; // r6
  int v9; // r5
  int v10; // r8
  int v11; // r4
  unsigned int v12; // r5
  int v13; // r0
  unsigned int v15; // r2
  unsigned int v16; // [sp+18h] [bp-40h]
  char v17[4]; // [sp+20h] [bp-38h] BYREF
  int v18; // [sp+24h] [bp-34h]
  int v19; // [sp+28h] [bp-30h]
  int v20; // [sp+2Ch] [bp-2Ch]
  int v21; // [sp+34h] [bp-24h]
  int v22; // [sp+38h] [bp-20h]

  *a6 = 0;
  v16 = 0;
  v8 = 0;
  v9 = PiCMCaptureObjectInputData(a1, a2, a3, (int)v17);
  if ( v9 < 0 )
    goto LABEL_31;
  v10 = v20;
  if ( !v20 || v18 || v21 )
  {
    v9 = -1073741811;
    goto LABEL_37;
  }
  if ( !a3 || a4 < 0x14 )
  {
    v9 = -1073741811;
    goto LABEL_28;
  }
  if ( (v19 & 0x7FFF0000) != 0 )
    goto LABEL_8;
  if ( (v19 & 0x80000000) == 0x80000000 )
  {
    v11 = (unsigned __int16)v19;
    if ( (unsigned __int16)v19 >= 0xBu )
      v11 = 0;
LABEL_20:
    if ( !v11 )
      goto LABEL_21;
    goto LABEL_22;
  }
  switch ( (unsigned __int16)v19 )
  {
    case 1u:
      v11 = 1;
      goto LABEL_20;
    case 2u:
      v11 = 2;
      break;
    case 3u:
      v11 = 4;
      break;
    case 4u:
      v11 = 3;
      break;
    default:
LABEL_8:
      v11 = 0;
LABEL_21:
      v9 = -1073741811;
      break;
  }
LABEL_22:
  if ( v9 < 0 )
  {
LABEL_28:
    v13 = PiCMReturnBufferResultData(v9, 20 * v16, 0, 0, 0, v22, a3, a4, a6);
    goto LABEL_29;
  }
  v12 = a4 - 20;
  if ( a4 - 20 < 0x14 )
    v12 = 0;
  if ( v12 )
  {
    v8 = ExAllocatePoolWithTag(1, v12, 879783504);
    if ( !v8 )
    {
      v9 = -1073741670;
      goto LABEL_28;
    }
    v15 = v12 / 0x14;
  }
  else
  {
    v8 = 0;
    v15 = 0;
  }
  v16 = v15;
  v9 = PnpGetObjectPropertyKeys(PiPnpRtlCtx, v10, v11, 0);
LABEL_37:
  if ( v9 < 0 )
    goto LABEL_28;
  v13 = PiCMReturnBufferResultData(v9, 20 * v16, 0, v8, 20 * v16, v22, a3, a4, a6);
LABEL_29:
  v9 = v13;
  if ( v8 )
    ExFreePoolWithTag(v8);
LABEL_31:
  PiCMReleaseObjectInputData((int)v17);
  return v9;
}
