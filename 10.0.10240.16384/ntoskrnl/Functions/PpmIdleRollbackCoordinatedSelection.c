// PpmIdleRollbackCoordinatedSelection 
 
int __fastcall PpmIdleRollbackCoordinatedSelection(int result, unsigned int a2)
{
  unsigned int i; // r4
  int v3; // r3

  for ( i = *(_DWORD *)(result + 4); i > a2; *(_DWORD *)(v3 + 188) = 0 )
  {
    v3 = PpmPlatformStates + (*(_DWORD *)(*(_DWORD *)(result + 12) + 4 * i - 4) << 8);
    __dmb(0xBu);
    --i;
  }
  *(_DWORD *)(result + 4) = a2;
  return result;
}
