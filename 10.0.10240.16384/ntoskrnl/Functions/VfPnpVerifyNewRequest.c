// VfPnpVerifyNewRequest 
 
int *__fastcall VfPnpVerifyNewRequest(int *result, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r5
  int v7; // r2
  int v9; // r6
  unsigned __int16 *v10; // r4

  v6 = *result;
  v7 = -1073741637;
  v9 = *(_DWORD *)(*result + 24);
  if ( v9 != -1073741637 )
  {
    v7 = *(unsigned __int8 *)(a4 + 1);
    if ( v7 != 13 )
    {
      v7 = result[9];
      if ( (v7 & 0x20) == 0 )
        result = (int *)VfErrorReport1(526, a6, *result);
    }
    if ( v9 < 0 )
    {
      v7 = a5;
      *(_DWORD *)(a5 + 4) |= 0x2000000u;
    }
  }
  if ( *(_BYTE *)(a4 + 1) == 9 )
  {
    v10 = *(unsigned __int16 **)(a4 + 8);
    result = (int *)MmIsNonPagedSystemAddressValid((unsigned int)v10, a2, v7);
    if ( result )
    {
      if ( !v10[1] )
        result = (int *)VfErrorReport1(563, a6, v6);
      if ( *v10 < 0x40u )
        result = (int *)VfErrorReport1(564, a6, v6);
      if ( *((_DWORD *)v10 + 2) != -1 )
        result = (int *)VfErrorReport1(565, a6, v6);
      if ( *((_DWORD *)v10 + 3) != -1 )
        result = (int *)VfErrorReport1(566, a6, v6);
    }
  }
  return result;
}
