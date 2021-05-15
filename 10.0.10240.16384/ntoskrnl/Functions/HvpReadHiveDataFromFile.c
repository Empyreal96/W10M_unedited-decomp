// HvpReadHiveDataFromFile 
 
int __fastcall HvpReadHiveDataFromFile(_DWORD *a1, _DWORD *a2, unsigned int *a3)
{
  unsigned int v6; // r5
  int result; // r0

  *a2 = 0;
  *a3 = 0;
  v6 = a1[6] - a1[5];
  if ( v6 > a1[4] )
    v6 = a1[4];
  if ( !v6 )
    return -1073741807;
  if ( !(*(int (__fastcall **)(_DWORD, _DWORD, _DWORD *, _DWORD))(*a1 + 24))(*a1, a1[1], a1 + 2, a1[3]) )
    return -1073741491;
  a1[5] += v6;
  result = 0;
  *a2 = a1[3];
  *a3 = v6;
  return result;
}
