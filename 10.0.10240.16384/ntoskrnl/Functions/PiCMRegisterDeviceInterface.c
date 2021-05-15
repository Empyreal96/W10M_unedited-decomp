// PiCMRegisterDeviceInterface 
 
int __fastcall PiCMRegisterDeviceInterface(unsigned int a1, unsigned int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  _DWORD *v6; // r5
  unsigned int v9; // r10
  unsigned __int16 *v10; // r7
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r8
  int v15; // r0
  int v16; // r2
  unsigned __int16 *v17; // r6
  int v18; // r4
  _WORD *v19; // r5
  int v20; // r0
  int v21; // r3
  unsigned int v22; // r3
  int v23; // r4
  unsigned __int16 *v25; // [sp+18h] [bp-60h] BYREF
  _DWORD *v26; // [sp+1Ch] [bp-5Ch]
  int v27; // [sp+20h] [bp-58h]
  char v28[4]; // [sp+28h] [bp-50h] BYREF
  int v29; // [sp+2Ch] [bp-4Ch]
  char v30[16]; // [sp+30h] [bp-48h] BYREF
  unsigned __int16 *v31; // [sp+40h] [bp-38h]
  _WORD *v32; // [sp+48h] [bp-30h]
  unsigned int v33; // [sp+4Ch] [bp-2Ch]
  int v34; // [sp+50h] [bp-28h]

  v6 = a6;
  *a6 = 0;
  v9 = 0;
  v10 = 0;
  v26 = a6;
  v27 = a3;
  v25 = 0;
  v14 = PiCMCaptureRegisterInterfaceInputData(a1, a2, a3, (int)v28);
  if ( v14 < 0 )
  {
    v19 = v32;
    v17 = v31;
    goto LABEL_26;
  }
  v15 = PiAuDoesClientHaveAccess(2, v11, v12, v13);
  v17 = v31;
  if ( !v15 )
  {
    v18 = -1073741790;
LABEL_4:
    v19 = v32;
LABEL_5:
    v20 = PiCMReturnBufferResultData(v18, 2 * v9, 0, 0, 0, v34, v27, a4, v26);
    goto LABEL_6;
  }
  if ( !v31 || (v21 = v29) != 0 )
  {
    v18 = -1073741811;
  }
  else
  {
    v19 = v32;
    if ( v32 && (v21 = v33, v33 < 2) || !a3 || a4 < 0x14 || a4 - 20 < 2 )
    {
      v18 = -1073741811;
      goto LABEL_5;
    }
    v18 = CmValidateDeviceName(v15, v31, v16, v21);
    if ( v18 < 0 )
      goto LABEL_5;
    v18 = IopRegisterDeviceInterface(v17, (int)v30, v19, 1, (unsigned int *)&v25, 0);
    v10 = v25;
    if ( v18 < 0 )
    {
      v17 = v31;
      goto LABEL_4;
    }
    v9 = wcslen(v25) + 1;
    v17 = v31;
    if ( 2 * v9 > a4 - 20 )
    {
      v18 = -1073741789;
      goto LABEL_4;
    }
    v6 = v26;
  }
  if ( v18 < 0 )
    goto LABEL_4;
  v20 = PiCMReturnBufferResultData(v18, 2 * v9, 0, (int)v10, 2 * v9, v34, v27, a4, v6);
  v19 = v32;
LABEL_6:
  v14 = v20;
  if ( v10 )
    ExFreePoolWithTag((unsigned int)v10);
LABEL_26:
  v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v23 = *(char *)(v22 + 346);
  if ( v17 && *(_BYTE *)(v22 + 346) )
    ExFreePoolWithTag((unsigned int)v17);
  if ( v19 && v23 )
    ExFreePoolWithTag((unsigned int)v19);
  return v14;
}
