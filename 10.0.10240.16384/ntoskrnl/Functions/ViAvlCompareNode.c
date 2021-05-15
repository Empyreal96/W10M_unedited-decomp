// ViAvlCompareNode 
 
int __fastcall ViAvlCompareNode(int a1, unsigned int *a2, unsigned int *a3)
{
  unsigned int v3; // r0
  unsigned int v4; // r4

  v3 = *a2;
  v4 = *a3;
  if ( *a2 < *a3 )
  {
    if ( a2[1] + v3 <= v4 )
      return 0;
  }
  else if ( *a2 != *a3 && a3[1] + v4 <= v3 )
  {
    return 1;
  }
  return 2;
}
