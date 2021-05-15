// PpmGetPlatformSelectionVetoCounts 
 
unsigned int __fastcall PpmGetPlatformSelectionVetoCounts(unsigned int result, _DWORD *a2, _DWORD *a3)
{
  *a2 = 0;
  a2[1] = 0;
  *a3 = 0;
  a3[1] = 0;
  if ( PpmPlatformStates )
  {
    if ( result < *(_DWORD *)PpmPlatformStates )
    {
      result = *(_DWORD *)(PpmPlatformStates + 32) + 992 * result;
      *a2 = *(_DWORD *)(result + 88);
      a2[1] = *(_DWORD *)(result + 92);
      *a3 = *(_DWORD *)(result + 80);
      a3[1] = *(_DWORD *)(result + 84);
    }
  }
  return result;
}
