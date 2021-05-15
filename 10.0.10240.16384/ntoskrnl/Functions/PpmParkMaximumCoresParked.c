// PpmParkMaximumCoresParked 
 
int PpmParkMaximumCoresParked()
{
  int result; // r0
  int v1; // r2
  unsigned __int16 v2; // r6
  int v3; // r1
  unsigned int v4; // r4

  result = 1;
  v1 = 0;
  if ( PpmParkNumNodes )
  {
    v2 = 0;
    do
    {
      v3 = PpmParkNodes + 88 * v1;
      v4 = 0;
      while ( *(unsigned __int8 *)(v3 + 79) <= (unsigned int)*(unsigned __int8 *)(v3 + 66) )
      {
        ++v4;
        ++v3;
        if ( v4 >= 2 )
          goto LABEL_8;
      }
      result = 0;
LABEL_8:
      v1 = ++v2;
    }
    while ( v2 < (unsigned int)PpmParkNumNodes );
  }
  return result;
}
