// sub_506B9C 
 
int __fastcall sub_506B9C(int result)
{
  int v1; // r7
  int v2; // r2
  int v3; // r3
  unsigned int *v4; // r2
  unsigned int v5; // r1

  *(_DWORD *)(v1 + 4) = result;
  if ( result )
  {
    v2 = *(_DWORD *)(v1 + 40);
    v3 = *(_DWORD *)(v2 + 8) + 13;
    *(_DWORD *)(v2 + 8) = v3;
    if ( v3 == 26 )
      _jump_unwind(v1 + 48, (int)&loc_95DE02 + 1);
    v4 = *(unsigned int **)v2;
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 + 1, v4) );
  }
  return result;
}
