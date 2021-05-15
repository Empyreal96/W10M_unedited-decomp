// PpmParkSnapNodeStatistics 
 
void PpmParkSnapNodeStatistics()
{
  int v0; // r2
  unsigned int v1; // r1
  unsigned __int16 v2; // r5
  int v3; // r0

  v0 = 0;
  v1 = PpmParkNumNodes;
  if ( PpmParkNumNodes )
  {
    v2 = 0;
    do
    {
      v3 = PpmParkNodes + 88 * v0;
      if ( *(_BYTE *)(v3 + 6) )
      {
        PpmIdleSnapConcurrency(
          *(_DWORD *)(v3 + 28),
          (_DWORD *)(v3 + 48),
          *(unsigned __int8 *)(v3 + 6) + 1,
          *(_DWORD *)(v3 + 32));
        v1 = PpmParkNumNodes;
      }
      v0 = ++v2;
    }
    while ( v2 < v1 );
  }
}
