// CmpSecConvKey 
 
int __fastcall CmpSecConvKey(unsigned int a1, int *a2)
{
  int v2; // r3
  unsigned int v3; // r4
  int v4; // t1

  v2 = 0;
  v3 = a1 >> 2;
  if ( !(a1 >> 2) )
    return 0;
  do
  {
    v4 = *a2++;
    --v3;
    v2 = v4 + __ROR4__(v2, 29);
  }
  while ( v3 );
  return v2;
}
