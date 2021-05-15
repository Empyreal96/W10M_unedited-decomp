// PiDevCfgRequestDriverConfigurations 
 
int __fastcall PiDevCfgRequestDriverConfigurations(_DWORD *a1, int a2)
{
  int v4; // r0
  int v5; // r4
  unsigned __int16 *i; // r5
  int *v7; // r6
  unsigned __int16 *v8; // t1
  int v9; // r0
  int v11; // [sp+4h] [bp-3Ch]
  int v12; // [sp+20h] [bp-20h] BYREF
  int v13; // [sp+24h] [bp-1Ch]

  v12 = 0;
  v13 = 0;
  v4 = PiDevCfgQueryDriverConfiguration((_DWORD *)a2);
  v5 = v4;
  if ( v4 == -1073741637 || v4 >= 0 )
  {
    v5 = PiDevCfgAppendMultiSz((unsigned __int16 *)&v12, (unsigned __int16 *)(a2 + 224), 0, 1);
    if ( v5 >= 0 )
    {
      v8 = *(unsigned __int16 **)(a2 + 120);
      v7 = (int *)(a2 + 120);
      for ( i = v8; i != (unsigned __int16 *)v7; i = *(unsigned __int16 **)i )
      {
        v9 = PiDevCfgQueryDriverConfiguration(i);
        v5 = v9;
        if ( v9 != -1073741637 && v9 < 0 )
          goto LABEL_13;
        v5 = PiDevCfgAppendMultiSz((unsigned __int16 *)&v12, i + 112, 0, 1);
        if ( v5 < 0 )
          goto LABEL_13;
      }
      if ( v13 )
        v5 = PiDevCfgSetObjectProperty(
               PiPnpRtlCtx,
               a1,
               a1[1],
               1,
               a1[2],
               v11,
               (int)DEVPKEY_Device_RequestConfigurationIds,
               8210,
               v13,
               (unsigned __int16)v12);
      else
        v5 = -1073741637;
    }
  }
LABEL_13:
  RtlFreeAnsiString(&v12);
  return v5;
}
