// sub_80FB7C 
 
void sub_80FB7C()
{
  unsigned int v0; // r4
  unsigned int v1; // r7

  if ( v0 <= v1 )
    MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 0, v0);
  JUMPOUT(0x79BB22);
}
