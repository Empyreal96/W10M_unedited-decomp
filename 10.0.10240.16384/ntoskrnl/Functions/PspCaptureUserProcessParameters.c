// PspCaptureUserProcessParameters 
 
int __fastcall PspCaptureUserProcessParameters(unsigned int **a1, int a2, int a3, int a4)
{
  unsigned int v5; // r1
  int v6; // r4
  unsigned int v7; // r10
  unsigned int v8; // r9
  unsigned int v9; // r10
  int v10; // r0
  unsigned int v11; // r3
  unsigned int v12; // r1
  int v13; // r4
  int v14; // r0
  unsigned int *v15; // r5
  int v16; // r6
  unsigned int v17; // r3
  bool v18; // zf
  unsigned int *v19; // r6
  unsigned int v20; // r10
  int v21; // r10
  unsigned int *v23; // [sp+0h] [bp-98h] BYREF
  unsigned int v24; // [sp+4h] [bp-94h] BYREF
  int v25; // [sp+8h] [bp-90h]
  int v26; // [sp+Ch] [bp-8Ch]
  unsigned int v27; // [sp+10h] [bp-88h]
  unsigned int v28; // [sp+14h] [bp-84h]
  unsigned int v29; // [sp+18h] [bp-80h]
  unsigned int v30; // [sp+1Ch] [bp-7Ch]
  int v31; // [sp+20h] [bp-78h]
  unsigned int **v32; // [sp+24h] [bp-74h]
  int v33; // [sp+28h] [bp-70h]
  unsigned int v34; // [sp+2Ch] [bp-6Ch]
  unsigned int v35; // [sp+30h] [bp-68h]
  unsigned int v36; // [sp+34h] [bp-64h]
  _DWORD v37[2]; // [sp+38h] [bp-60h] BYREF
  unsigned int v38; // [sp+40h] [bp-58h]
  int v39; // [sp+44h] [bp-54h]
  _WORD v40[4]; // [sp+48h] [bp-50h] BYREF
  _WORD v41[4]; // [sp+50h] [bp-48h] BYREF
  _WORD v42[4]; // [sp+58h] [bp-40h] BYREF
  _WORD v43[4]; // [sp+60h] [bp-38h] BYREF
  _WORD v44[4]; // [sp+68h] [bp-30h] BYREF
  _WORD _70[22]; // [sp+70h] [bp-28h] BYREF
  unsigned int **varg_r0; // [sp+A0h] [bp+8h]
  int varg_r1; // [sp+A4h] [bp+Ch]
  int varg_r2; // [sp+A8h] [bp+10h]
  int varg_r3; // [sp+ACh] [bp+14h]

  varg_r3 = a4;
  v25 = a3;
  varg_r2 = a3;
  varg_r1 = a2;
  v32 = a1;
  varg_r0 = a1;
  if ( (a2 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  v5 = *(_DWORD *)(a2 + 8) & 0xFFFFBFFF;
  v35 = v5;
  v34 = v5;
  if ( ((v5 ^ 1) & 0xFF810E11) != 0 )
  {
    v6 = -1073741811;
    v31 = -1073741811;
    v26 = v29;
    return v6;
  }
  if ( ((unsigned __int8)((v5 & 0xE0) - 1) & (unsigned __int8)v5 & 0x60) != 0 )
  {
    v6 = -1073741811;
    v31 = -1073741811;
    v26 = v29;
    return v6;
  }
  v7 = *(_DWORD *)(a2 + 72);
  v26 = v7;
  v29 = v7;
  v8 = *(_DWORD *)(a2 + 656);
  v24 = v8;
  if ( !v8 || (v8 & 1) != 0 )
  {
    v6 = -1073741811;
    v31 = -1073741811;
    return v6;
  }
  if ( v8 + v7 > MmUserProbeAddress || v8 + v7 < v7 )
    *(_BYTE *)MmUserProbeAddress = 0;
  if ( (v25 & 1) != 0 )
  {
    v37[0] = PsProtectedCurrentDirectory;
    v37[1] = dword_920AC4;
    v38 = 0;
    v27 = 0;
    v33 = 0;
    v28 = 0;
    if ( (v25 & 2) == 0 )
    {
      v26 = dword_920ABC;
      v29 = dword_920ABC;
      v8 = (unsigned __int16)word_920ABA;
      v24 = (unsigned __int16)word_920ABA;
    }
    v30 = HIWORD(v37[0]);
    v23 = (unsigned int *)HIWORD(v27);
    v9 = (unsigned __int16)v27;
  }
  else
  {
    v10 = PspCaptureAndValidateUnicodeString(a2 + 36, v37);
    v36 = v10;
    if ( v10 < 0 )
      return v10;
    v30 = 520;
    if ( LOWORD(v37[0]) >= 0x208u )
      return -1073741811;
    HIWORD(v37[0]) = 520;
    v27 = *(_DWORD *)(a2 + 136);
    v11 = *(_DWORD *)(a2 + 140);
    v33 = v11;
    v28 = v11;
    v9 = (unsigned __int16)v27;
    if ( v11 )
    {
      v23 = (unsigned int *)(unsigned __int16)v27;
      HIWORD(v27) = v27;
      if ( (_WORD)v27 && ((unsigned __int16)v27 + v11 > MmUserProbeAddress || (unsigned __int16)v27 + v11 < v11) )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    else
    {
      if ( (_WORD)v27 )
        return -1073741811;
      v27 = 0;
      v23 = 0;
    }
    v38 = v27;
  }
  v6 = PspCaptureAndValidateUnicodeString(a2 + 48, v40);
  if ( v6 < 0 )
    return v6;
  v6 = PspCaptureAndValidateUnicodeString(a2 + 56, v42);
  if ( v6 < 0 )
    return v6;
  v6 = PspCaptureAndValidateUnicodeString(a2 + 64, v44);
  if ( v6 < 0 )
    return v6;
  v6 = PspCaptureAndValidateUnicodeString(a2 + 112, v41);
  if ( v6 < 0 )
    return v6;
  v6 = PspCaptureAndValidateUnicodeString(a2 + 120, v43);
  if ( v6 < 0 )
    return v6;
  v6 = PspCaptureAndValidateUnicodeString(a2 + 128, _70);
  if ( v6 < 0 )
    return v6;
  v30 = ((unsigned int)v23 + v40[1] + v43[1] + _70[1] + v41[1] + v44[1] + v42[1] + v30 + 677) & 0xFFFFFFFE;
  v36 = v30;
  v12 = v30 + v8;
  if ( v30 + v8 < v30 )
  {
    v12 = -1;
    v13 = -1073741675;
  }
  else
  {
    v13 = 0;
  }
  if ( v13 < 0 )
    return -1073741811;
  v14 = ExAllocatePoolWithQuotaTag(0x208u, v12, 1649439568);
  v15 = (unsigned int *)v14;
  v39 = v14;
  if ( !v14 )
    return -1073741670;
  memmove(v14, a2, 0x2A4u);
  v16 = v33;
  v17 = v30;
  v15[2] = v35;
  v15[1] = v17;
  *v15 = v17;
  v23 = v15 + 169;
  v6 = PspCopyUnicodeString(v37, v15 + 9, &v23);
  if ( v6 < 0 )
    goto LABEL_63;
  v6 = PspCopyUnicodeString(v40, v15 + 12, &v23);
  if ( v6 < 0 )
    goto LABEL_63;
  v6 = PspCopyUnicodeString(v42, v15 + 14, &v23);
  if ( v6 < 0 )
    goto LABEL_63;
  v6 = PspCopyUnicodeString(v44, v15 + 16, &v23);
  if ( v6 < 0 )
    goto LABEL_63;
  v6 = PspCopyUnicodeString(v41, v15 + 28, &v23);
  if ( v6 < 0 )
    goto LABEL_63;
  v6 = PspCopyUnicodeString(v43, v15 + 30, &v23);
  if ( v6 < 0 )
    goto LABEL_63;
  v6 = PspCopyUnicodeString(_70, v15 + 32, &v23);
  if ( v6 < 0 )
    goto LABEL_63;
  v15[34] = v38;
  v15[35] = v16;
  v18 = v16 == 0;
  v19 = v23;
  if ( !v18 )
  {
    v15[35] = (unsigned int)v23;
    memmove((int)v19, v33, v9);
    if ( v19 )
    {
      v19 = (unsigned int *)((char *)v19 + v9);
      v23 = v19;
    }
    v20 = (char *)v15 - (char *)v19 + v30;
    if ( v20 )
    {
      memset(v19, 0, (char *)v15 - (char *)v19 + v30);
      if ( v19 )
      {
        v19 = (unsigned int *)((char *)v19 + v20);
        v23 = v19;
      }
    }
  }
  memmove((int)v19, v26, v8);
  v21 = v25 & 1;
  if ( (v25 & 1) != 0 && (v25 & 2) == 0 )
    goto LABEL_60;
  v6 = PspValidateEnvironmentBlock(v19, &v24);
  if ( v6 < 0 )
  {
LABEL_63:
    ExFreePoolWithTag((unsigned int)v15);
    return v6;
  }
  v8 = v24;
LABEL_60:
  if ( v21 )
  {
    v15[4] = 0;
    v15[6] = 0;
    v15[7] = 0;
    v15[8] = 0;
  }
  v15[18] = (unsigned int)v19;
  v15[164] = v8;
  v15[165] = 0;
  *v32 = v15;
  return 0;
}
