// RtlEndEnumerationHashTable 
 
int __fastcall RtlEndEnumerationHashTable(int result, int *a2)
{
  int *v2; // r4
  int **v3; // r2

  --*(_DWORD *)(result + 28);
  v2 = (int *)*a2;
  if ( (int *)*a2 != a2 )
  {
    v3 = (int **)a2[1];
    if ( (int *)v2[1] != a2 || *v3 != a2 )
      sub_523F6C();
    *v3 = v2;
    v2[1] = (int)v3;
    if ( *(_DWORD *)a2[3] == a2[3] )
      --*(_DWORD *)(result + 24);
  }
  a2[3] = 0;
  return result;
}
