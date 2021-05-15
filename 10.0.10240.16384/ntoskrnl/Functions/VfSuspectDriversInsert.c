// VfSuspectDriversInsert 
 
int *__fastcall VfSuspectDriversInsert(int *result)
{
  int **v1; // r1

  v1 = (int **)dword_61D36C;
  *result = (int)&VfSuspectDriversList;
  result[1] = (int)v1;
  if ( *v1 != &VfSuspectDriversList )
    __fastfail(3u);
  *v1 = result;
  dword_61D36C = (int)result;
  return result;
}
