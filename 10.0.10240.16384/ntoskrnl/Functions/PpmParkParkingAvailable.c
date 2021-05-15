// PpmParkParkingAvailable 
 
int PpmParkParkingAvailable()
{
  int result; // r0
  unsigned int v1; // r5
  int v2; // r2
  unsigned int v3; // r4
  unsigned __int8 *v4; // r1
  unsigned int v5; // lr

  result = 0;
  v1 = 0;
  if ( PpmParkNumNodes )
  {
    v2 = PpmParkNodes;
    while ( !*(_BYTE *)(v2 + 70) && !*(_BYTE *)(v2 + 72) && !*(_DWORD *)(v2 + 20) && !dword_616318 )
    {
      v3 = 0;
      v4 = (unsigned __int8 *)v2;
      while ( 1 )
      {
        if ( v4[64] )
        {
          v5 = v4[68];
          if ( v4[66] < v5 || v5 < v4[64] )
            break;
        }
        ++v3;
        ++v4;
        if ( v3 >= 2 )
          goto LABEL_13;
      }
      result = 1;
LABEL_13:
      ++v1;
      v2 += 88;
      if ( v1 >= PpmParkNumNodes )
        goto LABEL_7;
    }
    result = 1;
  }
LABEL_7:
  PpmIsParkingEnabled = result;
  return result;
}
