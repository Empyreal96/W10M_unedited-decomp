// PpmCheckCoordinatedStateInitiator 
 
int __fastcall PpmCheckCoordinatedStateInitiator(int a1, unsigned int a2, _DWORD *a3)
{
  int result; // r0
  unsigned int i; // r5
  unsigned int v8; // r7
  int v9; // r6
  int v10; // r1

  result = 0;
  for ( i = 0; i < a2; a3 += 3 )
  {
    if ( *a3 == -1 || *a3 == a1 )
    {
      v8 = 0;
      if ( a3[1] )
      {
        v9 = 0;
        do
        {
          v10 = a3[2] + v9;
          if ( *(_BYTE *)(v10 + 1) )
          {
            if ( *a3 != -1 )
              return 1;
            result = PpmCheckCoordinatedStateInitiator(a1, *(_DWORD *)(v10 + 8), *(_DWORD *)(v10 + 12));
            if ( result )
              return result;
          }
          ++v8;
          v9 += 16;
        }
        while ( v8 < a3[1] );
      }
    }
    ++i;
  }
  return result;
}
