// sub_7E78A4 
 
void __fastcall sub_7E78A4(int a1, int a2, unsigned int a3)
{
  unsigned int v3; // r5
  char v4; // lr
  int v5; // r3

  v3 = 0;
  v4 = 25;
  do
  {
    do
    {
      v4 += 7;
      v5 = 1 << (v4 - 32);
      ++v3;
    }
    while ( a2 > v5 );
  }
  while ( a2 >= v5 && a3 > 1 << v4 );
  if ( v3 >= CcMaxVacbLevelsSeen )
    CcMaxVacbLevelsSeen = v3 + 1;
  JUMPOUT(0x6F7444);
}
