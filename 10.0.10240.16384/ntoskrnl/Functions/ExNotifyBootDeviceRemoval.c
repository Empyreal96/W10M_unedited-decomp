// ExNotifyBootDeviceRemoval 
 
int __fastcall ExNotifyBootDeviceRemoval(_DWORD *a1)
{
  unsigned int *v2; // r2
  unsigned int v3; // r1
  unsigned int v4; // r1
  unsigned int v5; // r1
  unsigned int v6; // r1

  if ( *a1 != 1347306562 )
    return 0;
  __dmb(0xBu);
  v2 = a1 + 1;
  do
  {
    v3 = __ldrex(v2);
    v4 = v3 + 1;
  }
  while ( __strex(v4, v2) );
  __dmb(0xBu);
  if ( v4 == 1 )
  {
    __dmb(0xBu);
    do
    {
      v5 = __ldrex((unsigned int *)&ExNumMissingBootDevices);
      v6 = v5 + 1;
    }
    while ( __strex(v6, (unsigned int *)&ExNumMissingBootDevices) );
    __dmb(0xBu);
    if ( v6 == 1 )
      KeSetEvent((int)&ExBootDevicesRemovedEvent, 0, 0);
  }
  return 1;
}
