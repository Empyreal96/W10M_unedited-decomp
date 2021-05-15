// ViThunkFindNextSpecialTable 
 
int *__fastcall ViThunkFindNextSpecialTable(int *a1, unsigned int a2, int *a3)
{
  int *result; // r0
  int v5; // r5
  int *v6; // r6
  int v7; // t1

  result = 0;
  if ( !a3 )
    a3 = (int *)ViVerifierDriverAddedSpecialThunkListHead;
  while ( a3 != &ViVerifierDriverAddedSpecialThunkListHead )
  {
    v5 = 0;
    if ( a2 )
    {
      v6 = a1;
      do
      {
        v7 = *v6++;
        if ( v7 == a3[2] )
          return a3;
      }
      while ( ++v5 < a2 );
    }
    a3 = (int *)*a3;
  }
  return result;
}
