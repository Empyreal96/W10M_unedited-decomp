// ExpGetDeviceDataInformation 
 
int __fastcall ExpGetDeviceDataInformation(int a1, unsigned int a2, int a3, int a4)
{
  int v6; // r10
  int v7; // r6
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r2
  unsigned int v12; // r3
  int v13; // r4
  int v14; // r5
  unsigned int v15; // r8
  int v16; // r0
  unsigned int v17; // r2
  int v19; // [sp+8h] [bp-50h] BYREF
  int v20; // [sp+Ch] [bp-4Ch]
  int v21; // [sp+10h] [bp-48h] BYREF
  int v22; // [sp+14h] [bp-44h]
  int v23; // [sp+18h] [bp-40h]
  _DWORD v24[2]; // [sp+20h] [bp-38h] BYREF
  _DWORD v25[2]; // [sp+28h] [bp-30h] BYREF
  int v26; // [sp+30h] [bp-28h] BYREF
  int v27; // [sp+34h] [bp-24h] BYREF
  unsigned int v28; // [sp+38h] [bp-20h]
  int varg_r0; // [sp+60h] [bp+8h]
  unsigned int varg_r1; // [sp+64h] [bp+Ch]
  int varg_r2; // [sp+68h] [bp+10h]
  int varg_r3; // [sp+6Ch] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  varg_r1 = a2;
  v20 = a1;
  varg_r0 = a1;
  v19 = 0;
  v6 = 0;
  v21 = 0;
  v7 = 0;
  v23 = 0;
  if ( !a2 || a3 != 28 )
    return -1073741820;
  if ( (a2 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  if ( a2 + 28 > MmUserProbeAddress || a2 + 28 < a2 )
    *(_BYTE *)MmUserProbeAddress = 0;
  v8 = *(_DWORD *)(a2 + 4);
  v9 = *(_DWORD *)(a2 + 8);
  v10 = *(_DWORD *)(a2 + 12);
  v24[0] = *(_DWORD *)a2;
  v24[1] = v8;
  v25[0] = v9;
  v25[1] = v10;
  v11 = *(_DWORD *)(a2 + 20);
  v12 = *(_DWORD *)(a2 + 24);
  v26 = *(_DWORD *)(a2 + 16);
  v27 = v11;
  v28 = v12;
  v13 = ExpStringCapture(&v19, v24);
  v22 = v13;
  if ( v13 < 0 )
  {
    v14 = v19;
    goto LABEL_24;
  }
  if ( a1 == 136 )
  {
    v13 = ExpStringCapture(&v21, v25);
    v22 = v13;
    if ( v13 < 0 )
    {
      v14 = v19;
      v6 = v21;
      goto LABEL_24;
    }
    v6 = v21;
  }
  v15 = v27;
  if ( !v27 )
    goto LABEL_19;
  if ( !v28 )
  {
    v13 = -1073741811;
    v22 = -1073741811;
    v14 = v19;
    goto LABEL_24;
  }
  ProbeForWrite(v28, v27, 2);
  v7 = ExAllocatePoolWithQuotaTag(9u, v15, 1313424452);
  v23 = v7;
  if ( v7 )
  {
LABEL_19:
    v14 = v19;
    if ( v20 == 136 )
      v16 = KseQueryDeviceData(v19, v6, &v26, (int)&v27);
    else
      v16 = KseQueryDeviceDataList(v19, v7, v15, &v27);
    v13 = v16;
    v17 = v27;
    *(_DWORD *)(a2 + 20) = v27;
    *(_DWORD *)(a2 + 16) = v26;
    if ( v16 >= 0 )
      memmove(v28, v7, v17);
    goto LABEL_24;
  }
  v13 = -1073741801;
  v22 = -1073741801;
  v14 = v19;
LABEL_24:
  ExpStringFree(v14);
  ExpStringFree(v6);
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v13;
}
