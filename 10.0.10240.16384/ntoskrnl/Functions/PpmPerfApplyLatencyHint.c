// PpmPerfApplyLatencyHint 
 
int __fastcall PpmPerfApplyLatencyHint(int a1)
{
  int v1; // r5
  int v2; // r1
  int v3; // r4
  int result; // r0
  unsigned int v5; // r1

  v1 = *(_DWORD *)(a1 + 3204);
  v2 = *(unsigned __int8 *)(a1 + 2986);
  v3 = *(_DWORD *)(a1 + 3200);
  result = *(_DWORD *)(v1 + 4);
  v5 = *((unsigned __int8 *)&PpmCurrentProfile[44 * dword_61EC0C + 24] + v2 + 1);
  if ( PpmCurrentProfile[44 * dword_61EC0C + 20] != 3 )
    return sub_5253EC(result, v5);
  if ( v5 >= *(_DWORD *)(v3 + 84) )
    v5 = *(_DWORD *)(v3 + 84);
  if ( v5 > *(_DWORD *)(v1 + 40) )
  {
    result = (*(int (__fastcall **)(int, unsigned int, _DWORD))(v3 + 68))(result, v5, *(_DWORD *)(v3 + 92));
    *(_DWORD *)(v1 + 40) = result;
  }
  return result;
}
