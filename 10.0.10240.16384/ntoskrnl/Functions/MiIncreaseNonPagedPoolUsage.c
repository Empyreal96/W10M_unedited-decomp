// MiIncreaseNonPagedPoolUsage 
 
int __fastcall MiIncreaseNonPagedPoolUsage(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v6; // r3
  unsigned int v7; // r2
  unsigned int v8; // r3
  int v9; // r1

  if ( !a2 )
  {
    v6 = a3 + 1023;
    v7 = (a3 + a4) & 0xFFFFFC00;
    v8 = v6 & 0xFFFFFC00;
    v9 = a4;
    if ( v7 > v8 )
      v9 = v8 - v7 + a4;
    *(_DWORD *)(a1 + 120) += v9;
  }
  *(_DWORD *)(a1 + 112) += a4;
  if ( MiCountNonPagedPool(a4, 1) >= 0x300 )
    result = 0;
  else
    result = sub_548F60();
  return result;
}
