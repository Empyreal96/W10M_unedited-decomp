// PpmParkComputeDiff 
 
int PpmParkComputeDiff()
{
  int v0; // r1
  int result; // r0
  int v2; // r2
  int v3; // r3

  PpmPerfNewCoreParkingMask = 1;
  word_616336 = 1;
  dword_616338 = 0;
  v0 = PpmParkNumNodes;
  result = 0;
  dword_61633C = 0;
  if ( PpmParkNumNodes )
  {
    v2 = PpmParkNodes;
    do
    {
      v3 = *(_DWORD *)(v2 + 20);
      v2 += 88;
      result |= v3;
      dword_61633C = result;
      --v0;
    }
    while ( v0 );
  }
  word_61632A = 1;
  PpmPerfChangedCoreParkingMask = 1;
  dword_61632C = 0;
  dword_616330 = dword_616318 ^ result;
  return result;
}
