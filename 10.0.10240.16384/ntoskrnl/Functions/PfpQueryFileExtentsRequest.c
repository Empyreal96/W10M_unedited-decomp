// PfpQueryFileExtentsRequest 
 
int __fastcall PfpQueryFileExtentsRequest(int a1, int a2, _DWORD *a3, int a4)
{
  int v4; // r5
  int v5; // r8
  unsigned __int16 *v6; // r6
  _DWORD *v7; // r10
  char v8; // r9
  char v9; // r2
  int v10; // r4
  int v11; // r1
  unsigned int v12; // r5
  int v13; // r0
  int v14; // r1
  unsigned int v15; // r5
  unsigned int v16; // r9
  unsigned int v17; // r4
  int v18; // r0
  int v19; // r8
  int v21; // [sp+18h] [bp-128h]
  char v22; // [sp+1Ch] [bp-124h]
  unsigned int v23; // [sp+1Ch] [bp-124h]
  unsigned int v24; // [sp+20h] [bp-120h]
  int v25; // [sp+30h] [bp-110h]
  int v28[6]; // [sp+40h] [bp-100h] BYREF
  int v29[6]; // [sp+58h] [bp-E8h] BYREF
  _BYTE v30[12]; // [sp+70h] [bp-D0h] BYREF
  unsigned int v31; // [sp+7Ch] [bp-C4h]
  int v32; // [sp+80h] [bp-C0h] BYREF
  unsigned int v33; // [sp+84h] [bp-BCh]
  unsigned int v34; // [sp+88h] [bp-B8h]
  unsigned int v35; // [sp+8Ch] [bp-B4h]
  int v36; // [sp+90h] [bp-B0h]
  int v37; // [sp+94h] [bp-ACh]
  int v38; // [sp+98h] [bp-A8h]
  unsigned int v39; // [sp+9Ch] [bp-A4h]
  unsigned int v40; // [sp+A0h] [bp-A0h]
  int v41; // [sp+A8h] [bp-98h]
  int v42; // [sp+ACh] [bp-94h]
  int v43; // [sp+B0h] [bp-90h]
  int v44; // [sp+B4h] [bp-8Ch]
  _DWORD _B8[37]; // [sp+B8h] [bp-88h] BYREF
  int varg_r1; // [sp+14Ch] [bp+Ch]
  _DWORD *varg_r2; // [sp+150h] [bp+10h]
  int varg_r3; // [sp+154h] [bp+14h]

  _B8[36] = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v4 = (char)a2;
  v25 = (char)a2;
  LOBYTE(varg_r1) = a2;
  v5 = a1;
  v6 = 0;
  v7 = 0;
  memset(_B8, 0, 80);
  _B8[6] = _B8;
  _B8[5] = PfpPrefetchSharedConflictNotify;
  KeInitializeEvent((int)&_B8[15], 0, 0);
  memset(v28, 0, 20);
  v8 = LOBYTE(v28[4]) | 2;
  v28[4] |= 2u;
  memset(v29, 0, 20);
  v9 = LOBYTE(v29[4]) | 2;
  v22 = LOBYTE(v29[4]) | 2;
  v29[4] |= 2u;
  v21 = 1;
  if ( *(_DWORD *)(v5 + 16) < 0x28u )
  {
    v10 = -1073741306;
    v11 = 1;
    goto LABEL_60;
  }
  if ( v4 )
    ProbeForWrite(*(_DWORD *)(v5 + 12), 40, 8);
  memmove((int)&v32, *(_DWORD *)(v5 + 12), 0x28u);
  v9 = v22;
  if ( v32 != 2 )
  {
    v10 = -1073741735;
LABEL_59:
    v11 = 1;
    goto LABEL_60;
  }
  v12 = v34;
  if ( (v34 & 1) != 0 || !v34 || v34 > 0x100000 || (v35 & 1) != 0 || !v35 || v35 >= v34 )
    goto LABEL_22;
  v13 = ExAllocatePoolWithTag(1, v34, 1883465296);
  v6 = (unsigned __int16 *)v13;
  if ( !v13 )
  {
    v10 = -1073741670;
LABEL_58:
    v9 = v22;
    goto LABEL_59;
  }
  v14 = v33;
  if ( v25 )
  {
    if ( (v33 & 1) != 0 )
      ExRaiseDatatypeMisalignment(v13);
    if ( v33 + v12 > MmUserProbeAddress || v33 + v12 < v33 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  memmove(v13, v14, v12);
  v9 = v22;
  if ( v6[(v12 >> 1) - 1] || (v15 = v35 >> 1, v6[v35 >> 1] != 92) )
  {
LABEL_22:
    v10 = -1073741811;
    goto LABEL_59;
  }
  _B8[7] = 15;
  _B8[8] = 150;
  v10 = PfpPrefetchSharedStart(_B8);
  if ( v10 < 0 )
    goto LABEL_58;
  v6[v15] = 0;
  v10 = RtlInitUnicodeStringEx((int)v30, v6);
  if ( v10 < 0 )
    goto LABEL_58;
  v10 = PfpOpenHandleCreate(v28, _B8, (int)v30, 0, 1048960, 32, 0, 0);
  if ( v10 < 0 || (v6[v15] = 92, v10 = RtlInitUnicodeStringEx((int)v30, v6), v10 < 0) )
  {
    v8 = v28[4];
    goto LABEL_58;
  }
  v10 = PfpOpenHandleCreate(v29, _B8, (int)v30, 0, 1048704, 32, 128, (int)v28);
  if ( v10 < 0 || (v10 = ZwQueryVolumeInformationFile(), (v10 & 0xC0000000) == -1073741824) )
  {
    v8 = v28[4];
    v9 = v29[4];
    goto LABEL_59;
  }
  v38 = _B8[22];
  v41 = 0;
  v42 = 0;
  v16 = v40;
  v24 = v40;
  if ( v40 <= 0x20 )
    v17 = 32;
  else
    v17 = v40;
  while ( 1 )
  {
    v23 = v17;
    if ( v17 > 0xA00000 )
    {
      v10 = -1073741306;
LABEL_35:
      v8 = v28[4];
      v9 = v29[4];
      v11 = 1;
      goto LABEL_60;
    }
    if ( v7 )
      ExFreePoolWithTag((unsigned int)v7);
    v7 = (_DWORD *)ExAllocatePoolWithTag(1, v17, 1699112528);
    if ( !v7 )
    {
      v10 = -1073741670;
      goto LABEL_35;
    }
    v18 = ZwFsControlFile();
    v10 = v18;
    if ( v18 >= 0 )
      break;
    if ( v18 == -1073741807 )
      goto LABEL_44;
    if ( v18 != -2147483643 )
      goto LABEL_35;
    v17 = 2 * v23;
  }
  v16 = v31;
  v40 = v31;
  if ( *v7 )
  {
    v10 = 0;
  }
  else
  {
LABEL_44:
    v10 = ZwQueryInformationFile();
    if ( v10 < 0 )
      goto LABEL_35;
    v36 = v43;
    v37 = v44;
    v10 = -1073741807;
  }
  memmove(*(_DWORD *)(a1 + 12), (int)&v32, 0x28u);
  if ( v10 == -1073741807 )
  {
    v21 = 0;
  }
  else if ( v24 >= v16 )
  {
    v19 = v39;
    if ( v25 )
      ProbeForWrite(v39, v16, 8);
    memmove(v19, (int)v7, v16);
  }
  else
  {
    v21 = 0;
    v10 = -1073741789;
    v28[5] = -1073741789;
  }
  v11 = v21;
  *a3 = 40;
  v8 = v28[4];
  v9 = v29[4];
LABEL_60:
  if ( v11 && (v10 == -1073741807 || v10 == -1073741789) )
    v10 = -1073741823;
  if ( (v9 & 4) != 0 )
    PfpOpenHandleClose(v29, (int)_B8);
  if ( (v8 & 4) != 0 )
    PfpOpenHandleClose(v28, (int)_B8);
  PfpPrefetchSharedCleanup(_B8);
  if ( v6 )
    ExFreePoolWithTag((unsigned int)v6);
  if ( v7 )
    ExFreePoolWithTag((unsigned int)v7);
  return v10;
}
