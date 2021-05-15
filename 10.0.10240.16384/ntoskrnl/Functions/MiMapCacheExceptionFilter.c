// MiMapCacheExceptionFilter 
 
int __fastcall MiMapCacheExceptionFilter(int *a1, int **a2)
{
  int *v2; // r1
  int v3; // r2

  v2 = *a2;
  v3 = *v2;
  if ( *v2 == -1073741818 )
  {
    if ( (unsigned int)v2[4] < 3 )
      goto LABEL_6;
    v3 = v2[7];
  }
  if ( v3 == -1073741819 )
    v3 = -1073741592;
LABEL_6:
  *a1 = v3;
  return 1;
}
