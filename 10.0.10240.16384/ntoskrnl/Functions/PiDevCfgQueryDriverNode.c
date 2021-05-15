// PiDevCfgQueryDriverNode 
 
int __fastcall PiDevCfgQueryDriverNode(unsigned __int16 *a1, int a2, int a3, int a4, char a5, int a6)
{
  int v6; // r8
  _BYTE *v9; // r0
  _BYTE *v10; // r4
  unsigned __int16 *v11; // r1
  int v12; // r5
  int v13; // r2
  int v14; // r0
  int v15; // r0
  int v16; // r1
  int v17; // r0
  _DWORD *v18; // r1
  int v19; // r2
  unsigned __int16 *v20; // r0
  unsigned __int16 *v21; // r3
  int v22; // [sp+0h] [bp-F8h]
  int v23; // [sp+0h] [bp-F8h]
  unsigned __int16 *v24; // [sp+10h] [bp-E8h] BYREF
  int v25; // [sp+14h] [bp-E4h] BYREF
  unsigned __int16 *v26; // [sp+18h] [bp-E0h]
  char v27; // [sp+1Ch] [bp-DCh]
  int v28; // [sp+20h] [bp-D8h] BYREF
  int v29; // [sp+24h] [bp-D4h]
  int v30; // [sp+28h] [bp-D0h] BYREF
  int v31; // [sp+2Ch] [bp-CCh]
  __int16 v32[2]; // [sp+30h] [bp-C8h] BYREF
  const __int16 *v33; // [sp+34h] [bp-C4h]
  _DWORD v34[2]; // [sp+38h] [bp-C0h] BYREF
  int v35; // [sp+40h] [bp-B8h]
  int v36; // [sp+44h] [bp-B4h]
  unsigned __int16 *v37; // [sp+48h] [bp-B0h]
  _DWORD *v38; // [sp+4Ch] [bp-ACh]
  int v39; // [sp+50h] [bp-A8h]
  int v40; // [sp+54h] [bp-A4h]
  __int16 *v41; // [sp+58h] [bp-A0h]
  int v42; // [sp+5Ch] [bp-9Ch]
  int v43; // [sp+60h] [bp-98h]
  int v44; // [sp+64h] [bp-94h]
  int v45[36]; // [sp+68h] [bp-90h] BYREF

  v36 = a4;
  v37 = (unsigned __int16 *)a2;
  v6 = -16777216;
  v38 = (_DWORD *)a6;
  v28 = 0;
  v29 = 0;
  v30 = -16777216;
  v25 = 0;
  v26 = 0;
  v34[0] = 0;
  v34[1] = 0;
  v35 = a3;
  v27 = 0;
  v31 = 0;
  v24 = 0;
  if ( PiDevCfgGetDriverPackageId((int)a1, (int)&v28) < 0
    || PnpOpenObjectRegKey(PiPnpRtlCtx, v29, 7, 131097, 0, (int)&v25, 0, 0) < 0
    || (v45[0] = (int)DEVPKEY_DriverPackage_TargetComputerIds,
        v45[1] = 8210,
        v45[2] = (int)v34,
        v45[4] = 6,
        PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v29, 7, v25, v45, 1) < 0) )
  {
    JUMPOUT(0x7E343C);
  }
  if ( v45[5] >= 0 )
    return sub_7E32D0();
  if ( (a5 & 8) != 0 )
    JUMPOUT(0x7E330E);
  v9 = (_BYTE *)ExAllocatePoolWithTag(1, 240, 1667526736);
  v10 = v9;
  if ( !v9 )
    JUMPOUT(0x7E3316);
  memset(v9, 0, 240);
  *((_DWORD *)v10 + 32) = v10 + 128;
  *((_DWORD *)v10 + 33) = v10 + 128;
  *((_DWORD *)v10 + 30) = v10 + 120;
  *((_DWORD *)v10 + 31) = v10 + 120;
  *((_DWORD *)v10 + 52) = v10 + 208;
  *((_DWORD *)v10 + 53) = v10 + 208;
  if ( !RtlCreateUnicodeString((int)(v10 + 20), a1) )
    goto LABEL_52;
  if ( v29 )
    JUMPOUT(0x7E3320);
  *((_DWORD *)v10 + 8) = 0;
  v11 = v37;
  *((_DWORD *)v10 + 7) = v28;
  if ( !RtlCreateUnicodeString((int)(v10 + 36), v11) )
LABEL_52:
    JUMPOUT(0x7E331A);
  memset(v45, 0, 96);
  v45[0] = (int)DEVPKEY_DriverPackage_DriverDate;
  v45[1] = 16;
  v45[2] = (int)(v10 + 64);
  v45[3] = 8;
  v45[6] = (int)DEVPKEY_DriverPackage_DriverVersion;
  v45[7] = 9;
  v45[8] = (int)(v10 + 72);
  v45[9] = 8;
  v45[20] = (int)(v10 + 104);
  v45[12] = (int)DEVPKEY_DriverPackage_SignerScore;
  v45[13] = 7;
  v45[14] = (int)&v30;
  v45[15] = 4;
  v45[18] = (int)DEVPKEY_DriverPackage_ExtensionId;
  v45[19] = 13;
  v45[21] = 16;
  v12 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v29, 7, v25, v45, 4);
  if ( v12 < 0 )
    goto LABEL_48;
  if ( v45[5] < 0 )
    JUMPOUT(0x7E334E);
  if ( v45[11] < 0 )
    JUMPOUT(0x7E3358);
  if ( v45[17] < 0 )
    JUMPOUT(0x7E3362);
  v13 = v30;
  if ( v45[23] < 0 )
  {
    *((_DWORD *)v10 + 26) = 0;
    *((_DWORD *)v10 + 27) = 0;
    *((_DWORD *)v10 + 28) = 0;
    *((_DWORD *)v10 + 29) = 0;
    v13 = v30;
  }
  if ( (a5 & 4) != 0 )
  {
    *((_DWORD *)v10 + 14) = -1;
  }
  else
  {
    if ( (a5 & 1) != 0 )
      v6 = -268435456;
    *((_DWORD *)v10 + 14) = (unsigned __int16)v35 | v13 & v6 | v36 & 0xFF0000;
  }
  if ( (a5 & 2) != 0 )
    JUMPOUT(0x7E336C);
  v32[1] = 24;
  v32[0] = 22;
  v33 = L"Descriptors";
  v31 = 0;
  v39 = 24;
  v40 = v25;
  v41 = v32;
  v42 = 576;
  v43 = 0;
  v44 = 0;
  v14 = ZwOpenKey();
  v12 = v14;
  if ( v14 == -1073741772 )
    goto LABEL_58;
  if ( v14 < 0 )
    goto LABEL_48;
  v26 = 0;
  v39 = 24;
  v40 = v31;
  v41 = (__int16 *)(v10 + 36);
  v43 = 0;
  v44 = 0;
  v42 = 576;
  v15 = ZwOpenKey();
  v12 = v15;
  if ( v15 == -1073741772 )
LABEL_58:
    JUMPOUT(0x7E33C8);
  if ( v15 >= 0 )
  {
    memset(v45, 0, 112);
    v45[2] = (int)L"Configuration";
    v45[3] = (int)(v10 + 44);
    v45[4] = 0x1000000;
    v45[1] = 288;
    v12 = RtlpQueryRegistryValues(-1073741824, v26, v45, 0, v22, 1u);
    if ( v12 >= 0 )
    {
      if ( !*((_WORD *)v10 + 22) )
        JUMPOUT(0x7E33CE);
      v16 = *((_DWORD *)v10 + 12);
      if ( !v16 )
        goto LABEL_34;
      v17 = PiDevCfgOpenDriverConfiguration(v25, v16, &v24);
      v12 = v17;
      if ( v17 == -1073741772 )
      {
        v12 = 0;
LABEL_34:
        if ( PnpBootMode )
          JUMPOUT(0x7E33EA);
        v18 = v38;
        v19 = 0;
        *((_DWORD *)v10 + 2) = v25;
        v20 = 0;
        *((_DWORD *)v10 + 3) = v26;
        *((_DWORD *)v10 + 4) = v24;
        v21 = 0;
        *v18 = v10;
        v25 = 0;
        v26 = 0;
        v24 = 0;
        v10 = 0;
        goto LABEL_36;
      }
      if ( v17 >= 0 )
      {
        memset(v45, 0, 112);
        v45[2] = (int)L"DriverDate";
        v45[3] = (int)(v10 + 64);
        v45[0] = (int)PiDevCfgQueryDriverVersionValueCallback;
        v45[17] = (int)(v10 + 88);
        v45[9] = (int)L"DriverVersion";
        v45[10] = (int)(v10 + 72);
        v45[7] = (int)PiDevCfgQueryDriverVersionValueCallback;
        v45[16] = (int)L"ExcludeIds";
        v45[18] = 117440512;
        v45[15] = 304;
        v12 = RtlpQueryRegistryValues(-1073741824, v24, v45, 0, v23, 1u);
        if ( v12 >= 0 )
        {
          if ( *((unsigned __int16 *)v10 + 44) <= 2u && *((_DWORD *)v10 + 23) )
            JUMPOUT(0x7E33E0);
          goto LABEL_34;
        }
      }
    }
  }
LABEL_48:
  v19 = v25;
  v21 = v26;
  v20 = v24;
LABEL_36:
  if ( v10 )
    JUMPOUT(0x7E3436);
  if ( v19 )
  {
    ZwClose();
    v21 = v26;
    v20 = v24;
  }
  if ( v21 )
  {
    ZwClose();
    v20 = v24;
  }
  if ( v31 )
  {
    ZwClose();
    v20 = v24;
  }
  if ( v20 )
    ZwClose();
  RtlFreeAnsiString(&v28);
  RtlFreeAnsiString(v34);
  return v12;
}
