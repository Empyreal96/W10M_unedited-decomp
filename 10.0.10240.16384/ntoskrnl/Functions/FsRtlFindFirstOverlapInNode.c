// FsRtlFindFirstOverlapInNode 
 
int *__fastcall FsRtlFindFirstOverlapInNode(int **a1, int a2, _DWORD *a3)
{
  int *result; // r0
  __int64 v5; // r6
  unsigned __int64 v6; // r4
  __int64 v7; // r2

  result = *a1;
  if ( !result )
    return 0;
  while ( 1 )
  {
    v6 = *((_QWORD *)result + 5);
    if ( v6 >= *(_QWORD *)a2 && (*((_QWORD *)result + 1) || *((_QWORD *)result + 2)) )
      break;
    if ( __PAIR64__(v6, HIDWORD(v6)) == __PAIR64__(*a3, a3[1]) )
    {
      LODWORD(v7) = result[3];
      HIDWORD(v7) = result[2];
      LODWORD(v5) = *(_DWORD *)(a2 + 4);
      HIDWORD(v5) = *(_DWORD *)a2;
      if ( v7 == v5 )
        return result;
    }
    result = (int *)*result;
    if ( !result )
      return 0;
  }
  if ( *((_QWORD *)result + 1) > *(_QWORD *)a3 )
    return 0;
  return result;
}
