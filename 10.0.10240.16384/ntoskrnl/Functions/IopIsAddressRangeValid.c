// IopIsAddressRangeValid 
 
int __fastcall IopIsAddressRangeValid(int a1, int a2, int a3)
{
  unsigned int v3; // r3
  unsigned int v4; // r5
  unsigned int v5; // r4

  v3 = (a1 & 0xFFF) + a2 + 4095;
  v4 = v3 >> 12;
  v5 = a1 & 0xFFFFF000;
  if ( !(v3 >> 12) )
    return 1;
  while ( v5 >= 0x10000 && MiIsAddressValid(v5, 0, a3, v3) )
  {
    v5 += 4096;
    if ( !--v4 )
      return 1;
  }
  return 0;
}
