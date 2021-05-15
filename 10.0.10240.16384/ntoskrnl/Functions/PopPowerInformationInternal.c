// PopPowerInformationInternal 
 
int __fastcall PopPowerInformationInternal(int a1, int a2, unsigned int a3, int a4, int *a5, _DWORD *a6, _BYTE *a7)
{
  int v8; // r5
  int v9; // r0
  int v10; // r4
  int v12; // r0

  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) && (!a1 || a1 == 2) )
    return -1073741790;
  if ( a1 != 1 )
  {
    if ( a1 )
    {
      if ( a1 != 2 )
        return -1073741811;
      PopUmpoSendReapplyBrightnessSettings();
      return 0;
    }
    if ( a3 >= 0x14 && a4 )
    {
      v12 = ExAllocatePoolWithTag(1, 8, 544040269);
      v8 = v12;
      if ( v12 )
      {
        v9 = PopFxPlatformRegisterInterface(a2, v12);
        goto LABEL_8;
      }
      return -1073741670;
    }
    return -1073741789;
  }
  if ( !a4 )
    return -1073741789;
  v8 = ExAllocatePoolWithTag(1, 8, 544040269);
  if ( !v8 )
    return -1073741670;
  v9 = PopS0LowPowerIdleInfo();
LABEL_8:
  v10 = v9;
  if ( v9 < 0 )
    return sub_7F2C98();
  *a5 = v8;
  *a6 = 8;
  *a7 = 1;
  return v10;
}
