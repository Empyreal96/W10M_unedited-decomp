// CmpParseCacheAllocEntry 
 
int __fastcall CmpParseCacheAllocEntry(_DWORD *a1, int a2, int a3, _DWORD *a4)
{
  int v7; // r4
  _DWORD *v9; // r5
  int v10; // r4

  v7 = -1073741670;
  v9 = (_DWORD *)ExAllocatePoolWithTag(1, 32, 1699761475);
  if ( v9 )
  {
    v9[3] = *a1;
    v10 = a1[1];
    *v9 = 0;
    v9[4] = v10;
    v9[5] = CmpParseCacheComputeRegHashKey(a1);
    v9[6] = a2;
    v9[7] = a3;
    *a4 = v9;
    v7 = 0;
  }
  return v7;
}
