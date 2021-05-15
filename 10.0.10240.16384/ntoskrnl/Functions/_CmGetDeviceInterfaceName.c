// _CmGetDeviceInterfaceName 
 
int __fastcall CmGetDeviceInterfaceName(int a1, unsigned __int16 *a2, unsigned __int16 *a3, _WORD *a4, char a5, _WORD *a6, unsigned int a7, unsigned int *a8)
{
  int v11; // r0
  int v12; // r2
  int v13; // r3
  unsigned int v14; // r4
  unsigned int v15; // r3
  unsigned int v16; // r3
  int result; // r0
  const __int16 *v18; // r2
  unsigned __int16 *v19; // r2
  int v20; // r3
  int v21; // t1
  unsigned int v22; // r0
  int v23; // r3
  _WORD *v24; // r2
  int v25; // t1
  unsigned __int16 *v26; // [sp+8h] [bp-20h] BYREF
  _WORD *v27[7]; // [sp+Ch] [bp-1Ch] BYREF

  v26 = a3;
  v27[0] = a4;
  v11 = CmValidateInstallerClassName(a1, a2);
  if ( v11 < 0 || CmValidateDeviceName(v11, a3, v12, v13) < 0 )
    return -1073741811;
  if ( a4 )
  {
    v22 = wcslen(a4);
    v14 = v22;
    if ( v22 && v22 < 0x104 )
    {
      v23 = (unsigned __int16)*a4;
      v24 = a4;
      while ( v23 )
      {
        if ( v23 == 92 || v23 == 47 )
          return -1073741773;
        v25 = (unsigned __int16)v24[1];
        ++v24;
        v23 = v25;
      }
      goto LABEL_5;
    }
    return -1073741811;
  }
  v14 = 0;
LABEL_5:
  v15 = wcslen(a3) + 43;
  if ( v14 )
    v15 = v14 + 1;
  v16 = v15 + 1;
  if ( a8 )
    *a8 = v16;
  if ( v16 > a7 )
    return sub_7C7558();
  if ( a5 )
    v18 = L"\\??\\";
  else
    v18 = L"\\\\?\\";
  result = RtlStringCchCopyExW(a6, a7, v18, v27, &v26, 2304);
  if ( result >= 0 )
  {
    result = RtlStringCchCopyExW(v27[0], (int)v26, a3, v27, &v26, 2304);
    if ( result >= 0 )
    {
      result = RtlStringCchCopyExW(v27[0], (int)v26, L"#", v27, &v26, 2304);
      if ( result >= 0 )
      {
        result = RtlStringCchCopyExW(v27[0], (int)v26, a2, v27, &v26, 2304);
        if ( result >= 0 )
        {
          v19 = a6 + 4;
          if ( a6[4] )
          {
            do
            {
              v20 = *v19;
              if ( v20 == 92 || v20 == 47 )
                *v19 = 35;
              v21 = v19[1];
              ++v19;
            }
            while ( v21 );
          }
          if ( v14 )
          {
            result = RtlStringCchCopyExW(v27[0], (int)v26, L"\\", v27, &v26, 2304);
            if ( result >= 0 )
              result = RtlStringCchCopyExW(v27[0], (int)v26, a4, v27, &v26, 2304);
          }
        }
      }
    }
  }
  return result;
}
