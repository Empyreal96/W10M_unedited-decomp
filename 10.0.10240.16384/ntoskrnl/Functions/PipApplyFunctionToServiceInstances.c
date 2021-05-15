// PipApplyFunctionToServiceInstances 
 
int __fastcall PipApplyFunctionToServiceInstances(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r5
  int v8; // r4
  char *v9; // r6
  int i; // r7
  int v11; // r0
  int v12; // r4
  int v13; // [sp+10h] [bp-40h] BYREF
  int v14; // [sp+14h] [bp-3Ch] BYREF
  _DWORD *v15; // [sp+18h] [bp-38h] BYREF
  int v16; // [sp+1Ch] [bp-34h] BYREF
  unsigned __int16 v17[2]; // [sp+28h] [bp-28h] BYREF
  char *v18; // [sp+2Ch] [bp-24h]

  v6 = PipOpenServiceEnumKeys(a2, 131097, 0, &v14, 0);
  if ( v6 < 0 )
    return v6;
  v8 = 0;
  v6 = IopGetRegistryValue(v14, L"Count", 0, (int *)&v15);
  if ( v6 < 0 )
    return sub_8171D8();
  if ( v15[1] == 4 && v15[3] >= 4u )
    v8 = *(_DWORD *)((char *)v15 + v15[2]);
  ExFreePoolWithTag((unsigned int)v15);
  if ( !v8 )
    goto LABEL_21;
  v13 = 0;
  v9 = (char *)ExAllocatePoolWithTag(1, 512, 538996816);
  if ( !v9 )
  {
    v6 = -1073741670;
    goto LABEL_21;
  }
  for ( i = 0; ; ++i )
  {
    v11 = ZwEnumerateValueKey();
    if ( v11 < 0 )
      break;
    if ( *((_DWORD *)v9 + 1) == 1 )
    {
      v17[0] = 0;
      PnpRegSzToString(&v9[*((_DWORD *)v9 + 2)], *((_DWORD *)v9 + 3), &v16);
      v17[0] = v16;
      v17[1] = *((_DWORD *)v9 + 3);
      v18 = &v9[*((_DWORD *)v9 + 2)];
      if ( (_WORD)v16 )
      {
        if ( PnpUnicodeStringToWstr((int *)&v15, 0, v17) >= 0 )
        {
          v6 = CmOpenDeviceRegKey(PiPnpRtlCtx, (int)v15, 16, 0, 983103, 0, (int)&v13, 0);
          PnpUnicodeStringToWstrFree((unsigned int)v15, (int)v17);
          if ( v6 >= 0 )
          {
            v12 = PipAddDevicesToBootDriverWorker(v13, v17, a6);
            ZwClose();
            if ( !v12 )
              goto LABEL_20;
          }
        }
      }
    }
LABEL_17:
    ;
  }
  if ( v11 != -2147483622 )
    goto LABEL_17;
  v6 = 0;
LABEL_20:
  ExFreePoolWithTag((unsigned int)v9);
LABEL_21:
  ZwClose();
  return v6;
}
