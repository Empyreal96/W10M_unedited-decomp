// PiDcHandleContainerEvent 
 
int __fastcall PiDcHandleContainerEvent(_DWORD *a1)
{
  unsigned int v1; // r8
  int v2; // r6
  int v3; // r7
  _DWORD *v4; // r5
  _DWORD *i; // r4

  v1 = a1[11];
  v2 = 0;
  v3 = 0;
  v4 = a1;
  if ( v1 )
  {
    for ( i = a1;
          i[17]
       || i[18]
       || i[16] != 55
       || memcmp((unsigned int)(i + 12), (unsigned int)DEVPKEY_DeviceContainer_IsConnected, 16);
          i += 7 )
    {
      if ( ++v3 >= v1 )
        return v2;
    }
    v2 = PiDcGenerateConfigNotificationIfContainerRequiresConfiguration(*(_DWORD *)(v4[2] + 12));
  }
  return v2;
}
