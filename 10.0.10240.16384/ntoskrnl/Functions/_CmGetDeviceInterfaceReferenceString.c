// _CmGetDeviceInterfaceReferenceString 
 
int __fastcall CmGetDeviceInterfaceReferenceString(int a1, unsigned __int16 *a2, _WORD *a3, unsigned int a4, unsigned int *a5)
{
  int v8; // r4
  _WORD *v9; // r0
  _WORD *v10; // r5
  int v11; // r3
  _WORD *v12; // r2
  int v13; // t1
  unsigned int v14; // r3

  v8 = CmValidateDeviceInterfaceName(a1, a2);
  if ( v8 >= 0 )
  {
    v9 = wcschr(a2 + 4, 92);
    v10 = v9;
    if ( v9 )
    {
      v11 = (unsigned __int16)v9[1];
      v12 = v9 + 1;
      while ( v11 )
      {
        if ( v11 == 92 || v11 == 47 )
        {
          v8 = -1073741767;
          break;
        }
        v13 = (unsigned __int16)v12[1];
        ++v12;
        v11 = v13;
      }
      if ( v8 >= 0 )
      {
        v14 = wcslen(v9 + 1) + 1;
        if ( a5 )
          *a5 = v14;
        if ( v14 > a4 )
          v8 = -1073741789;
        else
          v8 = RtlStringCchCopyExW(a3, a4, v10 + 1);
      }
    }
    else
    {
      v8 = -1073741772;
    }
  }
  return v8;
}
