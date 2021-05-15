// VfWmiVerifyNewRequest 
 
int *__fastcall VfWmiVerifyNewRequest(int *result, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r4

  v6 = *(_DWORD *)(*result + 24);
  if ( v6 != -1073741637 )
  {
    result = (int *)VfErrorReport1(528, a6, *result);
    if ( v6 < 0 )
      *(_DWORD *)(a5 + 4) |= 0x2000000u;
  }
  return result;
}
