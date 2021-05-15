// IopBuildGlobalSymbolicLinkString 
 
int __fastcall IopBuildGlobalSymbolicLinkString(unsigned __int16 *a1, unsigned __int16 *a2, int a3)
{
  unsigned int v5; // r5
  int v6; // r4
  int v7; // r0
  int v8; // r0
  unsigned int v10; // r2
  int v11; // r2
  int v12; // r3
  int v13; // r2
  int v14; // r3
  unsigned __int16 *v15; // r0
  unsigned __int16 *v16; // [sp+4h] [bp-1Ch]
  int v17; // [sp+8h] [bp-18h] BYREF
  unsigned int v18[5]; // [sp+Ch] [bp-14h] BYREF

  v16 = a2;
  v17 = a3;
  v5 = 0;
  v18[0] = 0;
  v6 = PnpUnicodeStringToWstr((int *)v18, 0, a1);
  if ( v6 >= 0 )
  {
    v17 = 512;
    v7 = ExAllocatePoolWithTag(1, 1024, 538996816);
    v5 = v7;
    if ( !v7 )
    {
      v6 = -1073741670;
      goto LABEL_10;
    }
    v8 = CmGetDeviceInterfaceSymbolicLinkName(v7, v18[0], v7, 512, &v17, v16);
    v6 = v8;
    if ( v8 == -1073741789 )
      return sub_7C8A74();
    if ( v8 < 0 )
    {
      if ( v8 == -1073741773 )
        v6 = -1073741811;
      goto LABEL_10;
    }
    v10 = 2 * (v17 + 10);
    if ( v10 > 0xFFFF )
    {
      v6 = -1073741675;
      goto LABEL_10;
    }
    v6 = IopAllocateUnicodeString(a2, (unsigned __int16)v10);
    if ( v6 >= 0 )
    {
      v6 = RtlAppendUnicodeToString(a2, (int)L"\\GLOBAL??\\", v11, v12);
      v15 = a2;
      if ( v6 >= 0 )
      {
        v6 = RtlAppendUnicodeToString(a2, v5, v13, v14);
        if ( v6 >= 0 )
          goto LABEL_10;
        v15 = a2;
      }
      RtlFreeAnsiString(v15);
      goto LABEL_10;
    }
  }
LABEL_10:
  PnpUnicodeStringToWstrFree(v18[0], (int)a1);
  if ( v5 )
    ExFreePoolWithTag(v5);
  return v6;
}
