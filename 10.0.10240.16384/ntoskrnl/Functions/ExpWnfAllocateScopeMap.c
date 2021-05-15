// ExpWnfAllocateScopeMap 
 
int __fastcall ExpWnfAllocateScopeMap(_DWORD *a1)
{
  _BYTE *v2; // r0
  _WORD *v3; // r4
  int v4; // r2
  _DWORD *v5; // r3

  v2 = (_BYTE *)ExAllocatePoolWithTag(1, 56, 543583831);
  v3 = v2;
  if ( !v2 )
    return -1073741670;
  memset(v2, 0, 56);
  *v3 = 2305;
  v3[1] = 56;
  v4 = 4;
  v5 = v3 + 6;
  do
  {
    *v5 = v5;
    v5[1] = v5;
    *(v5 - 1) = 0;
    v5 += 3;
    --v4;
  }
  while ( v4 );
  *a1 = v3;
  return 0;
}
