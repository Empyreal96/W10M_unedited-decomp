// LZNT1FindMatchMaximum 
 
unsigned int __fastcall LZNT1FindMatchMaximum(unsigned __int8 *a1, unsigned int *a2)
{
  unsigned int v2; // r4
  unsigned int v3; // r9
  unsigned int v5; // r8
  unsigned int result; // r0
  unsigned int v7; // lr
  unsigned int v8; // r5
  unsigned __int8 *v9; // r7
  int v10; // r2
  int v11; // t1

  v3 = a2[1];
  v2 = *a2;
  v5 = a2[2];
  result = 0;
  if ( *a2 >= (unsigned int)a1 )
    return 0;
  v7 = v2 - (_DWORD)a1;
  do
  {
    v8 = 0;
    if ( v5 )
    {
      v9 = a1;
      do
      {
        if ( (unsigned int)v9 >= v3 )
          break;
        v10 = v9[v7];
        v11 = *v9++;
        if ( v11 != v10 )
          break;
        ++v8;
      }
      while ( v8 < v5 );
    }
    if ( v8 >= result )
    {
      result = v8;
      a2[3] = v2;
    }
    ++v2;
    ++v7;
  }
  while ( v2 < (unsigned int)a1 );
  if ( result < 3 )
    return 0;
  return result;
}
