// IopGetMaxValidMemorySize 
 
unsigned int __fastcall IopGetMaxValidMemorySize(int a1, unsigned int a2, int a3)
{
  int v3; // r3
  unsigned int v5; // r4
  int v6; // r8
  unsigned int v7; // r7

  v3 = a1 & 0xFFF;
  v5 = 0;
  v6 = 4096 - v3;
  v7 = a1 & 0xFFFFF000;
  if ( !a2 )
    return a2;
  do
  {
    if ( !MiIsAddressValid(v7, 0, a3, v3) )
      break;
    v5 += v6;
    v7 += 4096;
    if ( !v7 )
      break;
    v6 = 4096;
  }
  while ( v5 < a2 );
  if ( v5 >= a2 )
    return a2;
  return v5;
}
