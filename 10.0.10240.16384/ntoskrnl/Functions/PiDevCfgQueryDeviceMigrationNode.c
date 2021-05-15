// PiDevCfgQueryDeviceMigrationNode 
 
int __fastcall PiDevCfgQueryDeviceMigrationNode(int a1, unsigned __int16 *a2, _DWORD *a3)
{
  int v4; // r6
  _BYTE *v5; // r0
  _BYTE *v6; // r4
  __int16 **v7; // r0
  int *v8; // r2
  int v9; // r5
  int v10; // r1
  int v11; // t1
  unsigned __int16 *v12; // r1
  _BYTE *v13; // r5
  int v14; // r7
  int v16; // [sp+10h] [bp-148h] BYREF
  int v17; // [sp+14h] [bp-144h]
  _DWORD *v18; // [sp+18h] [bp-140h]
  int v19[78]; // [sp+20h] [bp-138h] BYREF

  v16 = 0;
  v17 = 0;
  v18 = a3;
  v4 = PnpCtxRegOpenKey((int *)PiPnpRtlCtx, *(_DWORD *)(a1 + 4), (int)a2, 0);
  if ( v4 >= 0 )
  {
    v5 = (_BYTE *)ExAllocatePoolWithTag(1, 112, 1667526736);
    v6 = v5;
    if ( !v5 )
    {
      v4 = -1073741670;
      goto LABEL_31;
    }
    memset(v5, 0, 112);
    *((_DWORD *)v6 + 26) = -1;
    *((_DWORD *)v6 + 27) = -1;
    if ( !RtlCreateUnicodeString((int)(v6 + 12), a2) )
    {
      v4 = -1073741670;
LABEL_30:
      PiDevCfgFreeDeviceMigrationNode(v6);
      goto LABEL_31;
    }
    *((_DWORD *)v6 + 5) = 0;
    memset(v19, 0, 280);
    v7 = off_8C6D90;
    v8 = v19;
    v9 = 2;
    v10 = (int)(v6 + 24);
    do
    {
      v11 = (int)*v7++;
      v8[3] = v10;
      v8[4] = 117440512;
      v8[1] = 304;
      v8[2] = v11;
      v8 += 7;
      v10 += 8;
      --v9;
    }
    while ( v9 );
    v19[18] = 0x1000000;
    v19[16] = (int)L"ClassGuid";
    v19[17] = (int)&v16;
    v19[22] = 288;
    v19[23] = (int)L"Capabilities";
    v19[24] = (int)(v6 + 56);
    v19[25] = 0x4000000;
    v19[32] = 0x1000000;
    v19[39] = 0x1000000;
    v19[29] = 288;
    v19[30] = (int)L"BusDeviceDesc";
    v19[53] = 0x1000000;
    v12 = (unsigned __int16 *)*((_DWORD *)v6 + 5);
    v19[36] = 288;
    v19[37] = (int)L"LocationInfo";
    v19[15] = 288;
    v19[43] = 304;
    v19[44] = (int)L"LocationPaths";
    v19[50] = 288;
    v19[51] = (int)L"DriverInfName";
    v19[52] = (int)(v6 + 88);
    v19[60] = 0x4000000;
    v19[57] = 288;
    v19[58] = (int)L"Present";
    v19[59] = (int)(v6 + 96);
    v19[31] = (int)(v6 + 60);
    v19[38] = (int)(v6 + 68);
    v19[45] = (int)(v6 + 76);
    v19[46] = 117440512;
    v4 = RtlpQueryRegistryValues(-1073741824, v12, v19, 0, 131097, 1u);
    if ( v4 < 0 )
      goto LABEL_30;
    if ( !v17 || RtlGUIDFromString((unsigned __int16 *)&v16, v6 + 40) < 0 )
    {
      v4 = -1073741772;
      goto LABEL_30;
    }
    v13 = v6;
    v14 = 2;
    do
    {
      if ( *((unsigned __int16 *)v13 + 12) <= 2u && *((_DWORD *)v13 + 7) )
        RtlFreeAnsiString((_DWORD *)v13 + 6);
      v13 += 8;
      --v14;
    }
    while ( v14 );
    if ( !*((_WORD *)v6 + 30) && *((_DWORD *)v6 + 16) )
      RtlFreeAnsiString((_DWORD *)v6 + 15);
    if ( !*((_WORD *)v6 + 34) && *((_DWORD *)v6 + 18) )
      RtlFreeAnsiString((_DWORD *)v6 + 17);
    if ( *((unsigned __int16 *)v6 + 38) <= 2u && *((_DWORD *)v6 + 20) )
      RtlFreeAnsiString((_DWORD *)v6 + 19);
    if ( !*((_WORD *)v6 + 44) && *((_DWORD *)v6 + 23) )
      RtlFreeAnsiString((_DWORD *)v6 + 22);
    *v18 = v6;
  }
LABEL_31:
  RtlFreeAnsiString(&v16);
  return v4;
}
