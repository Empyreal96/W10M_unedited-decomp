// ObpHashBoundaryFunction 
 
int __fastcall ObpHashBoundaryFunction(int a1, int a2)
{
  char *v2; // r4
  unsigned int v3; // r5
  char v4; // t1

  v2 = (char *)(a1 + 8);
  if ( *(_DWORD *)(a1 + 4) > 8u )
  {
    v3 = 8;
    do
    {
      v4 = *v2++;
      ++v3;
      *(_BYTE *)(a2 + 20) += v4;
    }
    while ( v3 < *(_DWORD *)(a1 + 4) );
  }
  return 1;
}
