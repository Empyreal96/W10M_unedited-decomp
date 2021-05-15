// MiPushCombineBlock 
 
int *__fastcall MiPushCombineBlock(int *result, int *a2)
{
  int v2; // r2

  v2 = *result;
  *a2 = *result;
  a2[1] = (int)result;
  if ( *(int **)(v2 + 4) != result )
    sub_53DE30();
  *(_DWORD *)(v2 + 4) = a2;
  *result = (int)a2;
  return result;
}
