// PpmPerfCalculateMinMaxStates 
 
int __fastcall PpmPerfCalculateMinMaxStates(int result)
{
  char *v1; // r2
  unsigned int v2; // r3
  unsigned int v3; // r2
  unsigned int v4; // r3

  v1 = (char *)&PpmCurrentProfile[44 * dword_61EC0C + 8] + *(unsigned __int8 *)(result + 28);
  *(_DWORD *)(result + 136) = (unsigned __int8)v1[26];
  v2 = (unsigned __int8)v1[28];
  v3 = *(_DWORD *)(result + 136);
  *(_DWORD *)(result + 132) = v2;
  if ( v2 < v3 )
    *(_DWORD *)(result + 132) = v3;
  v4 = *(_DWORD *)(result + 132);
  if ( v4 <= 1 )
    v4 = 1;
  *(_DWORD *)(result + 140) = v4;
  *(_DWORD *)(result + 144) = v3;
  return result;
}
