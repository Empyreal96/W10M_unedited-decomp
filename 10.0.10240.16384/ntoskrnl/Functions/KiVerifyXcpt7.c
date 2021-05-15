// KiVerifyXcpt7 
 
int __fastcall KiVerifyXcpt7(int a1, int a2)
{
  int v2; // r4
  unsigned int *v3; // r2
  unsigned int v4; // r1
  int result; // r0

  v2 = a1;
  if ( *(_DWORD *)(a1 + 4) == 1 )
  {
    v3 = *(unsigned int **)a1;
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 + 1, v3) );
    v2 = a1;
  }
  else
  {
    *(_DWORD *)(a1 + 8) = -1;
    *(_DWORD *)(a1 + 12) = 1;
  }
  result = *(_DWORD *)(v2 + 8);
  *(_QWORD *)(v2 + 16) += result;
  return result;
}
