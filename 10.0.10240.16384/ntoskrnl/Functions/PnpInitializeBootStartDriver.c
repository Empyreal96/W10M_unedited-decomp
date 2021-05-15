// PnpInitializeBootStartDriver 
 
int __fastcall PnpInitializeBootStartDriver(unsigned __int16 *a1, __int64 *a2, int a3, int a4, int a5, unsigned __int8 a6, int a7, int a8, int a9)
{
  int v11; // r0
  _BYTE *v13; // r0
  int v15; // r10
  __int64 v16; // r8
  int v17; // r0
  __int64 v18; // kr00_8
  int v19; // r5
  int v20; // r4
  int v21; // r3
  int v22; // r4
  int v23; // r3
  __int16 v24; // [sp+8h] [bp-A8h] BYREF
  __int64 *v25; // [sp+Ch] [bp-A4h] BYREF
  int v26; // [sp+10h] [bp-A0h] BYREF
  int v27; // [sp+14h] [bp-9Ch]
  int v28; // [sp+18h] [bp-98h]
  int v29; // [sp+1Ch] [bp-94h]
  __int64 v30[8]; // [sp+20h] [bp-90h] BYREF
  __int16 *v31; // [sp+60h] [bp-50h]
  int v32; // [sp+64h] [bp-4Ch]
  int v33; // [sp+68h] [bp-48h]
  int v34; // [sp+6Ch] [bp-44h]
  int v35; // [sp+70h] [bp-40h]
  int v36; // [sp+74h] [bp-3Ch]
  int v37; // [sp+78h] [bp-38h]
  int v38; // [sp+7Ch] [bp-34h]
  int *v39; // [sp+80h] [bp-30h]
  int v40; // [sp+84h] [bp-2Ch]
  int v41; // [sp+88h] [bp-28h]
  int v42; // [sp+8Ch] [bp-24h]

  v27 = a3;
  v28 = a5;
  v11 = 0;
  v25 = a2;
  v26 = 0;
  v29 = a9;
  if ( a7 )
  {
    v13 = memset(v30, 0, sizeof(v30));
    LODWORD(v30[0]) = 0;
    if ( !a4 )
      return sub_968EB4(v13);
    v30[1] = *(_QWORD *)(a4 + 36);
    HIDWORD(v30[0]) = *(_DWORD *)(a4 + 132) & 1;
    LODWORD(v30[6]) = *(_DWORD *)(a4 + 116);
    LODWORD(v30[7]) = *(_DWORD *)(a4 + 124);
    LODWORD(v30[5]) = *(_DWORD *)(a4 + 108);
    HIDWORD(v30[6]) = *(_DWORD *)(a4 + 120);
    HIDWORD(v30[7]) = *(_DWORD *)(a4 + 128);
    HIDWORD(v30[5]) = *(_DWORD *)(a4 + 112);
    v30[2] = *a2;
    v30[4] = *(_QWORD *)(a4 + 100);
    v30[3] = *(_QWORD *)(a4 + 92);
    PnpNotifyEarlyLaunchImageLoad(v30, &v26);
    v11 = v26;
  }
  if ( !PnpDoPolicyCheck(v11, 1) && a7 )
    return -1073741790;
  v15 = VfDriverInitStarting();
  v16 = PnpEtwHandle;
  if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_BootInit_Start) )
  {
    v20 = *a1;
    v24 = *a1 >> 1;
    v31 = &v24;
    v32 = 0;
    v33 = 2;
    v34 = 0;
    v21 = *((_DWORD *)a1 + 1);
    v37 = v20;
    v35 = v21;
    v36 = 0;
    v38 = 0;
    EtwWrite(v16, SHIDWORD(v16), (int)KMPnPEvt_BootInit_Start, 0);
  }
  v17 = IopInitializeBuiltinDriver(a1, v25, v27, a4, a6, v29);
  v18 = PnpEtwHandle;
  v19 = v17;
  v25 = (__int64 *)v17;
  if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_BootInit_Stop) )
  {
    v22 = *a1;
    v24 = *a1 >> 1;
    v31 = &v24;
    v32 = 0;
    v33 = 2;
    v34 = 0;
    v23 = *((_DWORD *)a1 + 1);
    v37 = v22;
    v35 = v23;
    v36 = 0;
    v38 = 0;
    v39 = (int *)&v25;
    v40 = 0;
    v41 = 4;
    v42 = 0;
    EtwWrite(v18, SHIDWORD(v18), (int)KMPnPEvt_BootInit_Stop, 0);
  }
  if ( v19 >= 0 )
    VfDriverInitSuccess(v15);
  return v19;
}
