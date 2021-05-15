// PiDevCfgResolveDeviceDependencies 
 
int __fastcall PiDevCfgResolveDeviceDependencies(int a1, _BYTE *a2)
{
  int v4; // r1
  int v5; // r3
  int v6; // r4
  int v8; // [sp+30h] [bp-50h] BYREF
  int v9; // [sp+34h] [bp-4Ch]
  int v10[14]; // [sp+48h] [bp-38h] BYREF

  v8 = 0;
  v9 = 0;
  *a2 = 0;
  memset(v10, 0, 24);
  v10[1] = 8210;
  v10[2] = (int)&v8;
  v10[4] = 6;
  v4 = *(_DWORD *)(a1 + 4);
  v5 = *(_DWORD *)(a1 + 8);
  v10[0] = (int)DEVPKEY_Device_FirmwareDependencies;
  v6 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v4, 1, v5, v10, 1u);
  if ( v6 < 0 )
    goto LABEL_7;
  v6 = v10[5];
  if ( v10[5] == -1073741275 )
  {
    RtlInitUnicodeString((unsigned int)&v8, 0);
  }
  else if ( v10[5] < 0 )
  {
    goto LABEL_7;
  }
  if ( v9 )
    return sub_819AA8();
  *a2 = 1;
  v6 = 0;
LABEL_7:
  RtlFreeAnsiString(&v8);
  return v6;
}
