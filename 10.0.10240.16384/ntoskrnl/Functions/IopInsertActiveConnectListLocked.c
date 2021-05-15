// IopInsertActiveConnectListLocked 
 
// local variable allocation has failed, the output may be wrong!
int *__fastcall IopInsertActiveConnectListLocked(int *result)
{
  int *v1; // r1 OVERLAPPED
  int *v2; // r2
  int **v3; // r2 OVERLAPPED
  int **v4; // r4

  v1 = &ActiveConnectList;
  v2 = (int *)ActiveConnectList;
  if ( (int *)ActiveConnectList == &ActiveConnectList )
    goto LABEL_2;
  while ( v2[2] <= (unsigned int)result[2] )
  {
    v2 = (int *)*v2;
    if ( v2 == &ActiveConnectList )
      goto LABEL_11;
  }
  v4 = (int **)v2[1];
  *result = (int)v2;
  result[1] = (int)v4;
  if ( *v4 != v2 )
    sub_7DF05C();
  *v4 = result;
  v2[1] = (int)result;
LABEL_11:
  if ( v2 == &ActiveConnectList )
  {
LABEL_2:
    v3 = (int **)dword_630CCC;
    *(_QWORD *)result = *(_QWORD *)&v1;
    if ( *v3 != &ActiveConnectList )
      __fastfail(3u);
    *v3 = result;
    dword_630CCC = (int)result;
  }
  return result;
}
