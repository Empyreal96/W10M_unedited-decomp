// IopExceptionFilter 
 
int __fastcall IopExceptionFilter(int **a1, _DWORD *a2)
{
  int v2; // r2

  v2 = **a1;
  *a2 = v2;
  if ( v2 == -1073741818 )
    return sub_52793C();
  if ( *a2 == -2147483646 )
    *a2 = -1073741115;
  return 1;
}
