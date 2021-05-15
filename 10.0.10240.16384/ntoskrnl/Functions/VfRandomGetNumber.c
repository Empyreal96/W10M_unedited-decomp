// VfRandomGetNumber 
 
unsigned int __fastcall VfRandomGetNumber(unsigned int a1, unsigned int a2)
{
  unsigned int v4; // r1

  v4 = ViRandomEx();
  if ( a2 >= a1 )
  {
    if ( a2 - a1 == -1 )
      __brkdiv0();
    v4 = v4 % (a2 - a1 + 1) + a1;
  }
  return v4;
}
