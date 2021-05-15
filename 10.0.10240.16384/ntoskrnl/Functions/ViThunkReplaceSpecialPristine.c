// ViThunkReplaceSpecialPristine 
 
int __fastcall ViThunkReplaceSpecialPristine(_DWORD *a1)
{
  int result; // r0
  int *i; // r2
  int *j; // r1
  unsigned int v5; // lr
  unsigned int v6; // r7
  _DWORD *v7; // r5

  result = 0;
  for ( i = (int *)ViVerifierDriverAddedSpecialThunkListHead; i != &ViVerifierDriverAddedSpecialThunkListHead; i = (int *)*i )
  {
    for ( j = (int *)i[3]; j != i + 3; j = (int *)*j )
    {
      v5 = j[3];
      v6 = 0;
      v7 = j + 4;
      if ( v5 )
      {
        while ( *a1 != v7[1] )
        {
          ++v6;
          v7 += 2;
          if ( v6 >= v5 )
            goto LABEL_8;
        }
        result = 1;
        *a1 = *v7;
      }
LABEL_8:
      if ( result == 1 )
        return result;
    }
  }
  return result;
}
