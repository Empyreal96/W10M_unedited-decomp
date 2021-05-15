// _CmGetDeviceInterfaceRegKeyPath 
 
int __fastcall CmGetDeviceInterfaceRegKeyPath(int a1, unsigned __int16 *a2, int a3, int a4, int a5, unsigned __int16 *a6, unsigned int a7, unsigned int *a8)
{
  __int16 v9; // r6
  unsigned __int16 *v10; // r7
  int v12; // r5
  int v13; // r4
  unsigned __int16 *v14; // r0
  int v16; // r4
  int v17; // r10
  unsigned int v18; // r6
  unsigned int v19; // r0
  unsigned int v20; // r3
  int v21; // r0
  unsigned int v22; // [sp+24h] [bp-74h]
  unsigned __int16 v23[56]; // [sp+28h] [bp-70h] BYREF

  v9 = a3;
  v10 = 0;
  if ( !a3 || (a3 & 0xFFFFFCCC) != 0 )
    goto LABEL_41;
  v12 = (unsigned __int8)a3;
  if ( (unsigned __int8)a3 == 48 || (unsigned __int8)a3 == 50 )
  {
    v13 = 1;
LABEL_5:
    v22 = 2 * (wcslen(a2) + 3);
    v14 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v22, 1380994640);
    v10 = v14;
    if ( !v14 )
      return sub_7C6FF0();
    v16 = CmGetDeviceInterfaceSubkeyPath((int)v14, a2, v13, v23, v14, v22 >> 1);
    if ( v16 < 0 )
      goto LABEL_20;
    v17 = v9 & 0x200;
    if ( (v9 & 0x200) == 0 )
    {
      v18 = wcslen(v23) + 48;
LABEL_10:
      v19 = wcslen(v10);
      v20 = v19 + v18 + 1;
      if ( v12 < 48 )
        goto LABEL_31;
      if ( v12 <= 49 )
        goto LABEL_12;
      if ( v12 == 50 )
        v20 = v19 + v18 + 19;
      else
LABEL_31:
        v16 = -1073741811;
LABEL_12:
      if ( v16 >= 0 )
      {
        v16 = 0;
        if ( a8 )
          *a8 = v20;
        if ( v20 > a7 )
        {
          v16 = -1073741789;
        }
        else
        {
          if ( v17 )
          {
            if ( a4 )
            {
              if ( a4 == -1 )
                goto LABEL_19;
              v21 = RtlStringCchPrintfExW((int)a6, a7, 0, 0, 2048, L"%s\\%04u\\%s\\%s\\%s");
            }
            else
            {
              v21 = RtlStringCchPrintfExW((int)a6, a7, 0, 0, 2048, L"%s\\%s\\%s\\%s");
            }
          }
          else
          {
            v21 = RtlStringCchPrintfExW((int)a6, a7, 0, 0, 2048, L"%s\\%s\\%s");
          }
          v16 = v21;
          if ( v21 >= 0 )
          {
LABEL_19:
            if ( v12 == 50 )
            {
              v16 = RtlStringCchCatExW(a6, a7, L"\\");
              if ( v16 >= 0 )
                v16 = RtlStringCchCatExW(a6, a7, L"Device Parameters");
            }
            goto LABEL_20;
          }
        }
      }
LABEL_20:
      if ( v10 )
        ExFreePoolWithTag((unsigned int)v10);
      return v16;
    }
    if ( !a4 )
    {
      v18 = wcslen(v23) + 99;
      goto LABEL_10;
    }
    if ( a4 != -1 )
    {
      v18 = wcslen(v23) + 96;
      goto LABEL_10;
    }
LABEL_41:
    v16 = -1073741811;
    goto LABEL_20;
  }
  if ( (unsigned __int8)a3 == 49 )
  {
    v13 = 0;
    goto LABEL_5;
  }
  return -1073741811;
}
