// sub_7D0984 
 
void sub_7D0984()
{
  unsigned int v0; // r4

  if ( v0 <= 0xC0300FFF )
    MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 0, v0);
  JUMPOUT(0x78A8DE);
}
