// SmQueryStoreCommitUsage 
 
int __fastcall SmQueryStoreCommitUsage(int a1, _DWORD *a2, int a3, int a4)
{
  int result; // r0
  _DWORD *v6; // r1
  int v7; // r0
  int v8; // r2
  int v9; // r3
  _DWORD v10[384]; // [sp-4h] [bp-600h] BYREF

  result = SmpProcessQueryStoreStats(a1, (int)v10, a3, a4);
  if ( result >= 0 )
  {
    v6 = v10;
    *a2 = 0;
    v7 = 8;
    do
    {
      v8 = v6[10];
      v6 += 2;
      v9 = *a2 + v8;
      *a2 = v9;
      --v7;
    }
    while ( v7 );
    result = 0;
    *a2 = v9 * v10[3];
  }
  return result;
}
