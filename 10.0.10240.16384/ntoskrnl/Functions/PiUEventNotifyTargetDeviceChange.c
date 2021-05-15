// PiUEventNotifyTargetDeviceChange 
 
int __fastcall PiUEventNotifyTargetDeviceChange(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v10; // r10
  _BYTE *v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r3
  _BYTE *v16; // r0

  v10 = 0;
  v11 = (_BYTE *)memcmp(a1 + 44, (unsigned int)&GUID_TARGET_DEVICE_QUERY_REMOVE, 16);
  if ( v11 )
  {
    v11 = (_BYTE *)memcmp(a1 + 44, (unsigned int)&GUID_TARGET_DEVICE_REMOVE_CANCELLED, 16);
    if ( v11 )
    {
      v11 = (_BYTE *)memcmp(a1 + 44, (unsigned int)&GUID_DEVICE_REMOVE_PENDING, 16);
      if ( v11 )
      {
        v11 = (_BYTE *)memcmp(a1 + 44, (unsigned int)&GUID_TARGET_DEVICE_REMOVE_COMPLETE, 16);
        if ( v11 )
        {
          v11 = (_BYTE *)memcmp(a1 + 44, (unsigned int)&GUID_PNP_CUSTOM_NOTIFICATION, 16);
          if ( v11 )
            return v10;
        }
      }
    }
  }
  v14 = *(_DWORD *)(a1 + 60);
  if ( v14 != 1 && v14 != 3 )
    return v10;
  v15 = *(unsigned __int8 *)(a1 + 40);
  if ( *(_BYTE *)(a1 + 40) )
  {
    v16 = (_BYTE *)ExAllocatePoolWithTag(1, 4096, 1500540496);
    if ( !v16 )
      return -1073741670;
    v11 = memset(v16, 0, 4096);
  }
  return sub_7C1270((int)v11, v12, v13, v15, a5, a6, a7, a8, a9);
}
