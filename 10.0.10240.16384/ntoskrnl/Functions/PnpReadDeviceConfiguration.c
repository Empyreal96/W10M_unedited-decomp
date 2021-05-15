// PnpReadDeviceConfiguration 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PnpReadDeviceConfiguration(int a1, int a2, int *a3, _DWORD *a4)
{
  int v4; // r8 OVERLAPPED
  __int16 *v7; // r1
  int v8; // r4
  unsigned int v9; // r5
  int v10; // r1
  int v11; // r0
  unsigned int *v12; // lr
  unsigned int v13; // r6
  _DWORD *v14; // r2
  int v15; // r7 OVERLAPPED
  int v16; // r0
  _DWORD *i; // r1
  int v18; // r2
  int v20[6]; // [sp+0h] [bp-18h] BYREF

  v20[0] = (int)a4;
  v4 = 0;
  *a3 = 0;
  *a4 = 0;
  if ( a2 == 2 )
  {
    v7 = L"ForcedConfig";
  }
  else
  {
    if ( a2 != 4 )
      return sub_815CF8();
    v7 = L"BootConfig";
  }
  v8 = IopGetRegistryValue(a1, (unsigned __int16 *)v7, 0, v20);
  if ( v8 >= 0 )
  {
    v9 = v20[0];
    if ( *(_DWORD *)(v20[0] + 4) == 8 )
    {
      v10 = *(_DWORD *)(v20[0] + 12);
      if ( v10 )
      {
        v11 = ExAllocatePoolWithTag(1, v10, 1970499664);
        *a3 = v11;
        if ( v11 )
        {
          *a4 = *(_DWORD *)(v9 + 12);
          memmove(*a3, *(_DWORD *)(v9 + 8) + v9, *(_DWORD *)(v9 + 12));
          v12 = (unsigned int *)*a3;
          v13 = 0;
          v14 = v12 + 1;
          if ( *v12 )
          {
            v15 = PnpDefaultInterfaceType;
            do
            {
              if ( *v14 == -1 )
                *(_QWORD *)v14 = *(_QWORD *)(&v4 - 1);
              v16 = v14[3];
              for ( i = v14 + 4; v16; --v16 )
              {
                v18 = 0;
                if ( *(_BYTE *)i == 5 )
                  v18 = i[1];
                i = (_DWORD *)((char *)i + v18 + 16);
              }
              ++v13;
              v14 = i;
            }
            while ( v13 < *v12 );
          }
        }
        else
        {
          v8 = -1073741670;
        }
      }
    }
    else
    {
      v8 = -1073741823;
    }
    ExFreePoolWithTag(v9);
  }
  return v8;
}
