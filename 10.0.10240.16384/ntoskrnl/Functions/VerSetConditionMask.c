// VerSetConditionMask 
 
int __fastcall VerSetConditionMask(int a1, int a2, unsigned int a3, char a4)
{
  int v4; // r4
  char v6; // r3

  v4 = a4 & 7;
  if ( !a3 )
    return sub_5537F0();
  v6 = 0;
  do
  {
    a3 >>= 1;
    ++v6;
  }
  while ( a3 );
  return a1 | (v4 << (3 * v6 - 3));
}
