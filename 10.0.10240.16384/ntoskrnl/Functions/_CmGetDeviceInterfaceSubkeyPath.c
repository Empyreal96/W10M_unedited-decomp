// _CmGetDeviceInterfaceSubkeyPath 
 
int __fastcall CmGetDeviceInterfaceSubkeyPath(int a1, unsigned __int16 *a2, int a3, unsigned __int16 *a4, _WORD *a5, unsigned int a6)
{
  int result; // r0
  _WORD *v10; // r0
  unsigned __int16 *v11; // r5
  unsigned int v12; // r4
  int v13; // r3
  unsigned int v14; // r4
  unsigned int v15; // r0
  unsigned int v16[2]; // [sp+10h] [bp-48h] BYREF
  unsigned __int16 v17[4]; // [sp+18h] [bp-40h] BYREF
  int v18; // [sp+20h] [bp-38h]
  char v19[48]; // [sp+28h] [bp-30h] BYREF

  result = CmValidateDeviceInterfaceName(a1, a2);
  if ( result >= 0 )
  {
    v10 = wcschr(a2 + 4, 92);
    if ( v10 )
    {
      v11 = v10 + 1;
      v12 = v10 - a2;
    }
    else
    {
      v11 = 0;
      v12 = wcslen(a2);
    }
    v13 = v12;
    v18 = v12;
    if ( v12 < 0x30 )
    {
      result = -1073741773;
    }
    else
    {
      v14 = v12 + 1;
      if ( a3 )
      {
        v14 += 2;
        if ( v11 )
        {
          v15 = wcslen(v11);
          v13 = v18;
          v14 += v15;
        }
      }
      if ( !a4
        || (result = RtlStringCchCopyNExW(a4, 0x27u, (int)&a2[v13 - 38], 38, 0, 0, 2048), result >= 0)
        && (result = RtlInitUnicodeStringEx((int)v17, a4), result >= 0)
        && (result = RtlGUIDFromString(v17, v19), result >= 0) )
      {
        if ( v14 > a6 )
        {
          result = -1073741789;
        }
        else
        {
          result = RtlStringCchCopyNExW(a5, a6, (int)a2, v18, v17, v16, 2048);
          if ( result >= 0 )
          {
            qmemcpy(a5, "##?#", 8);
            if ( a3 )
            {
              result = RtlStringCchCopyExW(*(_WORD **)v17, v16[0], L"\\#", v17, v16, 2048);
              if ( v11 )
              {
                if ( result >= 0 )
                  result = RtlStringCchCopyExW(*(_WORD **)v17, v16[0], v11, v17, v16, 2048);
              }
            }
          }
        }
      }
    }
  }
  return result;
}
