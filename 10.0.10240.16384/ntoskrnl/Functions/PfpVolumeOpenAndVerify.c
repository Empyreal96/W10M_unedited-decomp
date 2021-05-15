// PfpVolumeOpenAndVerify 
 
int __fastcall PfpVolumeOpenAndVerify(_DWORD *a1, _DWORD *a2, int a3)
{
  int v5; // r6
  char v6; // r10
  int v7; // r4
  int v8; // r0
  int v9; // r0
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  _DWORD *v14; // r5
  int v15; // r1
  int v16; // r2
  int v17; // r3
  __int16 v19[2]; // [sp+20h] [bp-B0h] BYREF
  int v20; // [sp+24h] [bp-ACh]
  int v21; // [sp+28h] [bp-A8h] BYREF
  __int16 v22[2]; // [sp+30h] [bp-A0h] BYREF
  int v23; // [sp+34h] [bp-9Ch]
  int v24[6]; // [sp+38h] [bp-98h] BYREF
  int v25[5]; // [sp+50h] [bp-80h] BYREF
  int v26; // [sp+64h] [bp-6Ch] BYREF
  _DWORD *v27; // [sp+68h] [bp-68h]
  _DWORD v28[2]; // [sp+70h] [bp-60h] BYREF
  int v29[6]; // [sp+78h] [bp-58h] BYREF
  _DWORD v30[2]; // [sp+90h] [bp-40h] BYREF
  int v31; // [sp+98h] [bp-38h] BYREF
  __int64 v32; // [sp+9Ch] [bp-34h]

  v27 = a2;
  memset(v24, 0, 20);
  LOBYTE(v5) = LOBYTE(v24[4]) | 2;
  v24[4] |= 2u;
  memset(v25, 0, sizeof(v25));
  v6 = LOBYTE(v25[4]) | 2;
  v20 = 0;
  v21 = 0;
  v23 = *(_DWORD *)(a3 + 24);
  v22[0] = 2 * *(_DWORD *)(a3 + 20);
  v22[1] = v22[0] + 2;
  v29[0] = 24;
  v29[1] = 0;
  v29[3] = 576;
  v29[2] = (int)v22;
  v29[4] = 0;
  v29[5] = 0;
  v25[4] |= 2u;
  v7 = NtCreateFile((int)&v21, 1048704, (int)v29, (int)v28, 0, 0, 7, 1, 32, 0, 0);
  if ( v7 < 0 )
    goto LABEL_16;
  v8 = NtQueryVolumeInformationFile(v21, v28, v30, 8u, 4u);
  v7 = v8;
  if ( (v8 & 0xC0000000) == -1073741824 )
    goto LABEL_16;
  if ( v8 == 259 )
    sub_80F0E8();
  if ( PfVolumeSupportedForPrefetch(v30) )
  {
    v7 = -1073741637;
    goto LABEL_16;
  }
  if ( (*(_DWORD *)(a3 + 12) & 1) != 0 )
  {
    v7 = NtGetDevicePowerState(v21, &v26);
    if ( v7 < 0 )
      goto LABEL_16;
    if ( v26 && v26 != 1 )
    {
      v7 = -2147483633;
      goto LABEL_16;
    }
  }
  NtClose();
  v21 = 0;
  v7 = PfpOpenHandleCreate(v24, a1, (int)v22, 0, 1048960, 32, 0, 0);
  if ( v7 < 0 )
    goto LABEL_26;
  if ( *(_QWORD *)a3 || *(_DWORD *)(a3 + 8) )
  {
    v9 = NtQueryVolumeInformationFile(v24[0], v28, &v31, 0x18u, 1u);
    v7 = v9;
    if ( (v9 & 0xC0000000) == -1073741824 )
      goto LABEL_26;
    if ( v9 == 259 )
      KeBugCheckEx(401, 4934, 0, 0, 0);
    if ( v31 != *(_DWORD *)a3 || v32 != *(_QWORD *)(a3 + 4) )
    {
      v7 = -1073741735;
      goto LABEL_26;
    }
  }
  v19[0] = v22[0] + 2;
  v19[1] = v22[0] + 4;
  v10 = ExAllocatePoolWithTag(1, (unsigned __int16)(v22[0] + 4), 1146250832);
  v20 = v10;
  if ( v10 )
  {
    memmove(v10, v23, (unsigned __int16)v22[0]);
    *(_WORD *)(v20 + 2 * ((unsigned __int16)v22[0] >> 1)) = 92;
    *(_WORD *)(v20 + 2 * ((unsigned __int16)v19[0] >> 1)) = 0;
    v7 = PfpOpenHandleCreate(v25, a1, (int)v19, 0, 1179785, 33, 128, (int)v24);
    if ( v7 >= 0 )
    {
      v11 = v24[1];
      v12 = v24[2];
      v13 = v24[3];
      v14 = v27;
      *v27 = v24[0];
      v14[1] = v11;
      v14[2] = v12;
      v14[3] = v13;
      v14[4] = v24[4];
      memset(v24, 0, 20);
      v14 += 5;
      v5 = v24[4] | 2;
      v15 = v25[1];
      v16 = v25[2];
      v17 = v25[3];
      *v14 = v25[0];
      v14[1] = v15;
      v14[2] = v16;
      v14[3] = v17;
      v24[4] = v5;
      v14[4] = v25[4];
      memset(v25, 0, sizeof(v25));
      v7 = 0;
      v6 = LOBYTE(v25[4]) | 2;
      v25[4] |= 2u;
LABEL_16:
      v10 = v20;
      goto LABEL_17;
    }
    v6 = v25[4];
LABEL_26:
    LOBYTE(v5) = v24[4];
    goto LABEL_16;
  }
  v7 = -1073741670;
  LOBYTE(v5) = v24[4];
LABEL_17:
  if ( v21 )
  {
    NtClose();
    v10 = v20;
  }
  if ( (v6 & 4) != 0 )
  {
    PfpOpenHandleClose(v25, (int)a1);
    v10 = v20;
  }
  if ( (v5 & 4) != 0 )
  {
    PfpOpenHandleClose(v24, (int)a1);
    v10 = v20;
  }
  if ( v10 )
    ExFreePoolWithTag(v10);
  return v7;
}
