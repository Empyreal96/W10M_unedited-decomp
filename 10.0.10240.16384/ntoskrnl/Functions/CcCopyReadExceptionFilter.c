// CcCopyReadExceptionFilter 
 
int __fastcall CcCopyReadExceptionFilter(int **a1, _DWORD *a2)
{
  int v2; // r2

  v2 = **a1;
  *a2 = v2;
  if ( v2 == -1073741818 && (unsigned int)(*a1)[4] >= 3 )
    *a2 = (*a1)[7];
  return 1;
}
