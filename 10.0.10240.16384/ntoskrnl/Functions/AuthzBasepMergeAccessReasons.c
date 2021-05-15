// AuthzBasepMergeAccessReasons 
 
int *__fastcall AuthzBasepMergeAccessReasons(int *result, int a2, int a3)
{
  int v3; // r5
  int v4; // r4
  int v5; // r3

  v3 = a2 - (_DWORD)result;
  v4 = 32;
  do
  {
    v5 = *(int *)((char *)result + v3);
    if ( (v5 & 0xFF0000) != 0 || (v5 & a3) != 0 )
    {
      if ( a3 )
        v5 = *result | v5 & a3;
      *result = v5;
    }
    ++result;
    --v4;
  }
  while ( v4 );
  return result;
}
