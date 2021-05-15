// AuthzBasepSetAppContainerAccessReasons 
 
int __fastcall AuthzBasepSetAppContainerAccessReasons(int result, int a2, int a3, int *a4)
{
  int *v4; // r1
  int v5; // r4
  int v6; // r3

  v4 = a4;
  v5 = 1;
  if ( a4 )
  {
    while ( v5 )
    {
      if ( (v5 & result) != 0 )
      {
        v6 = *v4;
        if ( *v4 == 0x10000 || v6 == 196608 || v6 == 0x400000 )
          *v4 = a3 | 0x70000;
      }
      ++v4;
      v5 *= 2;
    }
  }
  return result;
}
