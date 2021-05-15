// HvpFreeMap 
 
int __fastcall HvpFreeMap(int result, int a2, unsigned int a3, unsigned int a4)
{
  int v4; // r6
  int v5; // r5
  int *v6; // r4

  v4 = result;
  if ( a2 )
  {
    if ( a4 >= 0x400 )
      a4 = 1023;
    if ( a3 <= a4 )
    {
      v5 = a4 - a3 + 1;
      v6 = (int *)(a2 + 4 * a3);
      do
      {
        result = *v6;
        if ( *v6 )
        {
          result = (*(int (__fastcall **)(int, int))(v4 + 16))(result, 10240);
          *v6 = 0;
        }
        ++v6;
        --v5;
      }
      while ( v5 );
    }
  }
  return result;
}
