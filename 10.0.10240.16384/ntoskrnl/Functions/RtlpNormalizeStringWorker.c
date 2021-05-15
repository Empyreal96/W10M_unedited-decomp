// RtlpNormalizeStringWorker 
 
int __fastcall RtlpNormalizeStringWorker(int a1, unsigned __int16 *a2, int a3, unsigned int a4, int *a5)
{
  int v6; // r7
  int v7; // r5

  v6 = *a5;
  *a5 = 0;
  v7 = a3;
  if ( a3 == -1 )
    v7 = wcslen(a2) + 1;
  if ( v6 > 0 && a4 )
  {
    if ( a4 >= (unsigned int)&a2[v7] || a4 + 2 * v6 <= (unsigned int)a2 )
      return Normalization__Normalize(a1, (int)a2, v7, a4, v6, a5);
  }
  else if ( a2 && v7 >= 0 )
  {
    *a5 = 0;
    *a5 = Normalization__GuessCharCountBySize(a1, v7);
    return 0;
  }
  return -1073741811;
}
