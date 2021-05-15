// PiPnpRtlEnumDevicesInContainerCallback 
 
int __fastcall PiPnpRtlEnumDevicesInContainerCallback(int a1, int a2, _BYTE *a3)
{
  int v5; // r4
  int v6; // r0

  *a3 = 0;
  v5 = 0;
  v6 = (*(int (__fastcall **)(_DWORD, _DWORD, _DWORD))(a2 + 4))(
         *(_DWORD *)a2,
         *(_DWORD *)(a1 + 12),
         *(_DWORD *)(a2 + 8));
  if ( v6 )
  {
    if ( v6 == 1 )
    {
      *(_BYTE *)(a2 + 12) = 1;
    }
    else if ( v6 != 2 )
    {
      if ( v6 == 3 )
        v5 = -1073741248;
      else
        v5 = -1073741595;
      return v5;
    }
    *a3 = 1;
  }
  return v5;
}
