// ExpWnfFindStateName 
 
int *__fastcall ExpWnfFindStateName(int a1, unsigned __int64 a2)
{
  int *v3; // r1
  unsigned __int64 v4; // kr00_8
  int *result; // r0

  v3 = *(int **)(a1 + 32);
  if ( !v3 )
    goto LABEL_9;
  do
  {
    v4 = *((_QWORD *)v3 + 2);
    if ( a2 < v4 )
    {
      v3 = (int *)*v3;
    }
    else
    {
      if ( a2 <= v4 )
        break;
      v3 = (int *)v3[1];
    }
  }
  while ( v3 );
  if ( v3 )
    result = v3 - 2;
  else
LABEL_9:
    result = 0;
  return result;
}
