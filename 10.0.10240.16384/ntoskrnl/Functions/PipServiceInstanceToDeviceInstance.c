// PipServiceInstanceToDeviceInstance 
 
int __fastcall PipServiceInstanceToDeviceInstance(int a1, int a2, int a3, unsigned __int16 *a4, int a5, int a6)
{
  int v9; // r4
  unsigned int v10; // r5
  unsigned __int16 v11; // [sp+10h] [bp-70h] BYREF
  __int16 v12; // [sp+12h] [bp-6Eh]
  const __int16 *v13; // [sp+14h] [bp-6Ch]
  int v14; // [sp+18h] [bp-68h]
  char *v15; // [sp+1Ch] [bp-64h] BYREF
  int v16[8]; // [sp+20h] [bp-60h] BYREF
  unsigned __int16 v17[32]; // [sp+40h] [bp-40h] BYREF

  v16[0] = 0;
  if ( !a1 )
    return sub_7EF510();
  v12 = 10;
  v11 = 8;
  v14 = 0;
  v16[2] = 24;
  v16[3] = a1;
  v16[4] = (int)&v11;
  v13 = L"Enum";
  v16[6] = 0;
  v16[7] = 0;
  v16[5] = 576;
  v9 = ZwOpenKey();
  if ( v9 >= 0 )
  {
    RtlStringCbPrintfW(v17, 0x28u, (int)L"%u", a3);
    v9 = IopGetRegistryValue(v14, v17, 100, (int *)&v15);
    ZwClose();
    if ( v9 >= 0 )
    {
      v10 = (unsigned int)v15;
      if ( *((_DWORD *)v15 + 1) == 1 )
      {
        PnpRegSzToString(&v15[*((_DWORD *)v15 + 2)], *((_DWORD *)v15 + 3), &v15);
        v11 = (unsigned __int16)v15;
        v12 = *(_DWORD *)(v10 + 12);
        v13 = (const __int16 *)(*(_DWORD *)(v10 + 8) + v10);
        if ( !(_WORD)v15 )
          v9 = -1073741766;
      }
      else
      {
        v9 = -1073741215;
      }
      if ( v9 >= 0 )
      {
        if ( !a5
          || (v9 = PnpUnicodeStringToWstr(v16, 0, &v11), v9 >= 0)
          && (v9 = CmOpenDeviceRegKey(PiPnpRtlCtx, v16[0], 16, 0, a6, 0, a5, 0),
              PnpUnicodeStringToWstrFree(v16[0], (int)&v11),
              v9 >= 0) )
        {
          if ( a4 )
          {
            v9 = PnpConcatenateUnicodeStrings(a4, &v11);
            if ( v9 < 0 )
            {
              if ( a5 )
                ZwClose();
            }
          }
        }
      }
      ExFreePoolWithTag(v10);
    }
  }
  return v9;
}
