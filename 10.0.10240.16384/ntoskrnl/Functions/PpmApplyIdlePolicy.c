// PpmApplyIdlePolicy 
 
int __fastcall PpmApplyIdlePolicy(int *a1)
{
  int v1; // r4
  int *v2; // r1
  int result; // r0

  v1 = *a1;
  v2 = &PpmCurrentProfile[44 * dword_61EC0C];
  *((_BYTE *)a1 + 52) = *((_BYTE *)v2 + 124);
  *((_BYTE *)a1 + 51) = *((_BYTE *)v2 + 132);
  *((_BYTE *)a1 + 50) = *((_BYTE *)v2 + 133);
  *((_BYTE *)a1 + 49) = *((_BYTE *)a1 + 51);
  *((_BYTE *)a1 + 48) = *((_BYTE *)a1 + 50);
  result = PpmConvertTimeFrom(v2[32], 0, 1000000, 0);
  *(_DWORD *)(v1 + 164) = result;
  return result;
}
