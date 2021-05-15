// AslStringSearchA 
 
int __fastcall AslStringSearchA(int a1, unsigned int a2, int a3, unsigned int a4)
{
  int result; // r0
  unsigned int v6; // r5
  unsigned int v7; // r7
  unsigned int v8; // r4

  result = 0;
  if ( a2 && a4 <= a2 )
  {
    v6 = 0;
    while ( 1 )
    {
      v7 = 0;
      v8 = v6;
      if ( a4 )
      {
        while ( v8 < a2 )
        {
          if ( !*(_BYTE *)(v8 + a1) && ++v8 >= a2 )
            return result;
          if ( *(char *)(v8 + a1) == *(char *)(v7 + a3) )
          {
            ++v7;
            ++v8;
            if ( v7 < a4 )
              continue;
          }
          break;
        }
      }
      if ( v7 == a4 )
        break;
      if ( ++v6 + a4 > a2 )
        return result;
    }
    result = v6 + a1;
  }
  return result;
}
