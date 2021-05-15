// PpmResetDripsAccountingSnapshot 
 
void PpmResetDripsAccountingSnapshot()
{
  int v0; // r2
  int *v1; // r1
  int *v2; // r2
  int v3; // r0
  int v4; // r3

  v0 = dword_635500;
  __dmb(0xBu);
  if ( PpmPlatformStates && v0 != -1 )
  {
    v1 = PpmDripsAccountingSnapshot;
    v2 = (int *)(*(_DWORD *)(PpmPlatformStates + 32) + 992 * v0 + 184);
    v3 = 26;
    do
    {
      *v1 = *v2;
      v4 = v2[1];
      v2 += 8;
      v1[1] = v4;
      v1 += 2;
      --v3;
    }
    while ( v3 );
  }
}
