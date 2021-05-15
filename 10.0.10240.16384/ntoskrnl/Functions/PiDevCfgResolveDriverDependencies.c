// PiDevCfgResolveDriverDependencies 
 
int __fastcall PiDevCfgResolveDriverDependencies(_DWORD *a1, _BYTE *a2)
{
  int v4; // r1
  int v5; // r3
  int v6; // r4
  int v8; // r0
  _DWORD *i; // r5
  _DWORD *v10; // r7
  _DWORD *v11; // t1
  int v12; // [sp+4h] [bp-74h]
  int v13; // [sp+4h] [bp-74h]
  char v14[7]; // [sp+21h] [bp-57h] BYREF
  int v15; // [sp+28h] [bp-50h] BYREF
  int v16; // [sp+2Ch] [bp-4Ch]
  int v17[14]; // [sp+40h] [bp-38h] BYREF

  v15 = 0;
  v16 = 0;
  *a2 = 0;
  memset(v17, 0, 24);
  v17[1] = 8210;
  v17[2] = (int)&v15;
  v17[4] = 6;
  v4 = a1[8];
  v5 = a1[2];
  v17[0] = (int)DEVPKEY_DriverPackage_FirmwareDependencies;
  v6 = PiDevCfgQueryObjectProperties(PiPnpRtlCtx, v4, 7, v5, v17, 1);
  if ( v6 >= 0 )
  {
    if ( v17[5] != -1073741275 )
      return sub_7E14A0();
    RtlInitUnicodeString((unsigned int)&v15, 0);
    v8 = v16;
    if ( !v16 || (unsigned __int16)v15 < 2u )
    {
      *a2 = 1;
LABEL_6:
      if ( v8 )
      {
        PiDevCfgSetObjectProperty(
          PiPnpRtlCtx,
          0,
          a1[8],
          7,
          a1[2],
          v12,
          DEVPKEY_DriverPackage_FirmwareDependencies,
          0,
          0,
          0);
        PiDevCfgSetObjectProperty(
          PiPnpRtlCtx,
          0,
          a1[8],
          7,
          a1[2],
          v13,
          DEVPKEY_DriverPackage_FirmwareDependencyBootSession,
          0,
          0,
          0);
      }
      v11 = (_DWORD *)a1[30];
      v10 = a1 + 30;
      for ( i = v11; i != v10; i = (_DWORD *)*i )
      {
        v6 = PiDevCfgResolveDriverDependencies(i, v14);
        if ( v6 < 0 )
          break;
        if ( !v14[0] )
          *a2 = 0;
      }
      goto LABEL_9;
    }
    v6 = PnpCheckDriverDependencies();
    if ( v6 >= 0 && *a2 )
    {
      v8 = v16;
      goto LABEL_6;
    }
    v6 = 0;
  }
LABEL_9:
  RtlFreeAnsiString(&v15);
  return v6;
}
