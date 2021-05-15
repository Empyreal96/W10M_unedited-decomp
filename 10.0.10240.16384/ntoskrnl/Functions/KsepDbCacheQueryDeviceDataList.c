// KsepDbCacheQueryDeviceDataList 
 
int __fastcall KsepDbCacheQueryDeviceDataList(int a1, int a2, unsigned int a3, _DWORD *a4)
{
  int *v4; // r5
  int *v6; // r7
  int v7; // r3
  int *i; // r4
  int v10; // r0
  int v11; // r4
  int result; // r0
  int v13; // r3

  v4 = *(int **)(a1 + 28);
  v6 = (int *)(a1 + 28);
  v7 = 0;
  for ( i = v4; i != v6; v7 += v10 )
  {
    v10 = *((unsigned __int16 *)i + 5);
    i = (int *)*i;
  }
  v11 = v7 + 2;
  if ( v7 + 2 <= a3 )
  {
    while ( v4 != v6 )
    {
      memmove(a2, v4[3], *((unsigned __int16 *)v4 + 5));
      v13 = *((unsigned __int16 *)v4 + 5);
      v4 = (int *)*v4;
      a2 += v13;
    }
    result = 0;
  }
  else
  {
    result = -1073741789;
  }
  *a4 = v11;
  return result;
}
