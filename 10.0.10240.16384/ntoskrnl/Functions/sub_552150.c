// sub_552150 
 
void sub_552150()
{
  int v0; // r4

  if ( *(_BYTE *)(v0 + 1) == 4 )
    memcmp(v0 + 4, (unsigned int)&ExpUnknownDeviceGuid, 16);
  JUMPOUT(0x4F0B54);
}
