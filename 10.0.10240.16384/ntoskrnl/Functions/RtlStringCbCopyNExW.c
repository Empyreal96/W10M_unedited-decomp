// RtlStringCbCopyNExW 
 
int __fastcall RtlStringCbCopyNExW(char *a1, unsigned int a2, char *a3, unsigned int a4)
{
  int result; // r0
  unsigned int v7; // r5
  unsigned int v8; // r3
  int v9; // r6
  unsigned int v10; // r1
  _WORD *v11; // r2

  result = 0;
  v7 = a2 >> 1;
  if ( !(a2 >> 1) )
    result = -1073741811;
  if ( result >= 0 )
  {
    v8 = a4 >> 1;
    if ( v8 >= 0x7FFFFFFF )
      return sub_50AF7C();
    result = 0;
    if ( v7 )
    {
      v9 = a3 - a1;
      v10 = a2 >> 1;
      v11 = a1;
      do
      {
        if ( !(v8 - v7 + v10) )
          break;
        if ( !*(_WORD *)((char *)v11 + v9) )
          break;
        *v11 = *(_WORD *)((char *)v11 + v9);
        ++v11;
        --v10;
      }
      while ( v10 );
      if ( !v10 )
      {
        --v11;
        result = -2147483643;
      }
      *v11 = 0;
      if ( result >= 0 )
        return result;
    }
    else
    {
      if ( !v8 || !*(_WORD *)a3 )
        return result;
      if ( a1 )
        result = -2147483643;
      else
        result = -1073741811;
    }
    if ( a2 )
    {
      if ( v7 )
        *(_WORD *)a1 = 0;
    }
  }
  return result;
}
