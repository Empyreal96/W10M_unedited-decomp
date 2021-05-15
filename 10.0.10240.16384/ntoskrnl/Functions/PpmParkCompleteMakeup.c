// PpmParkCompleteMakeup 
 
void PpmParkCompleteMakeup()
{
  int v0; // r2
  unsigned int v1; // r1
  unsigned __int16 v2; // r4
  int v3; // r0
  _DWORD *v4; // r2

  v0 = 0;
  v1 = PpmParkNumNodes;
  if ( PpmParkNumNodes )
  {
    v2 = 0;
    v3 = PpmParkNodes;
    do
    {
      v4 = (_DWORD *)(v3 + 88 * v0);
      v4[14] = v4[12];
      v4[15] = v4[13];
      v0 = ++v2;
    }
    while ( v2 < v1 );
  }
}
