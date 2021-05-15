// KsepLoadShimProvider 
 
int __fastcall KsepLoadShimProvider(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r2
  _DWORD v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[2] = a4;
  v7[0] = 0;
  v7[1] = 0;
  if ( !a1 )
    return -1073741811;
  if ( (*(_DWORD *)(a1 + 40) & 2) == 0 )
    return -1073741637;
  v5 = *(_DWORD *)(a1 + 28);
  if ( !v5 )
    return -1073741823;
  v4 = KsepStringConcatenate(v7, L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\", v5, 0);
  if ( v4 >= 0 )
    v4 = ZwLoadDriver();
  KsepStringFree(v7);
  return v4;
}
