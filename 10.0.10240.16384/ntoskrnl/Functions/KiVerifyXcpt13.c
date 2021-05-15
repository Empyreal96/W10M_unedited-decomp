// KiVerifyXcpt13 
 
__int64 __fastcall KiVerifyXcpt13(__int64 a1)
{
  int v1; // r4
  unsigned int *v2; // r2
  unsigned int v3; // r1
  unsigned int *v4; // r2
  unsigned int v5; // r1
  __int64 v7; // [sp+0h] [bp-18h]

  v7 = a1;
  v1 = a1;
  if ( *(_DWORD *)(a1 + 4) == 1 )
  {
    v2 = *(unsigned int **)a1;
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 + 1, v2) );
    v4 = *(unsigned int **)a1;
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 + 1, v4) );
    v1 = a1;
  }
  else
  {
    *(_DWORD *)(a1 + 8) = -1;
    *(_DWORD *)(a1 + 12) = 1;
  }
  *(_QWORD *)(v1 + 16) += *(int *)(v1 + 8);
  return v7;
}
