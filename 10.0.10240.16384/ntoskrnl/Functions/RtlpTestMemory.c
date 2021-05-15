// RtlpTestMemory 
 
int __fastcall RtlpTestMemory(int a1, int *a2)
{
  int *v2; // r2
  int v3; // t1

  v2 = a2 + 1024;
  do
  {
    if ( a2 >= v2 )
      return 1;
    v3 = *a2++;
  }
  while ( v3 == a1 );
  return 0;
}
