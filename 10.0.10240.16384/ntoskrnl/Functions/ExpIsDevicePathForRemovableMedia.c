// ExpIsDevicePathForRemovableMedia 
 
int __fastcall ExpIsDevicePathForRemovableMedia(_BYTE *a1)
{
  _BYTE *v1; // r4
  int v2; // r3

  v1 = a1;
  v2 = *a1 & 0x7F;
  if ( v2 == 127 )
    return 0;
  while ( v2 != 1 )
  {
    v1 += (unsigned __int8)v1[2] | ((unsigned __int8)v1[3] << 8);
    v2 = *v1 & 0x7F;
    if ( v2 == 127 )
      return 0;
  }
  return sub_552150();
}
