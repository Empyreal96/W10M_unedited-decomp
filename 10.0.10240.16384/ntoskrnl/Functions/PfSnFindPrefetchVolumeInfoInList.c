// PfSnFindPrefetchVolumeInfoInList 
 
int *__fastcall PfSnFindPrefetchVolumeInfoInList(_WORD *a1, int **a2, int a3)
{
  int *v4; // r4
  int v7; // r5
  __int64 v8; // kr00_8
  int v9; // r3

  v4 = *a2;
  v7 = 0;
  while ( v4 != (int *)a2 )
  {
    v8 = *((_QWORD *)v4 + 1);
    if ( !wcsncmp(a1, (unsigned __int16 *)v8, v4[3]) )
    {
      v9 = (unsigned __int16)a1[HIDWORD(v8)];
      if ( a3 ? v9 == 0 : v9 == 92 )
        return v4;
    }
    v4 = (int *)*v4;
  }
  return (int *)v7;
}
