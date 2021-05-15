// HvAllocateCell 
 
int __fastcall HvAllocateCell(int a1, int a2)
{
  unsigned int v2; // r4
  unsigned int v3; // r1
  int v4; // r5
  int result; // r0

  v2 = (a2 + 11) & 0xFFFFFFF8;
  v3 = 0x4000;
  v4 = 0;
  if ( v2 > 0x4000 )
  {
    do
    {
      v3 *= 2;
      ++v4;
    }
    while ( v2 > v3 );
    if ( v4 )
      v2 = v3;
  }
  if ( v2 > 0x100000 )
    result = -1;
  else
    result = HvpDoAllocateCell();
  return result;
}
