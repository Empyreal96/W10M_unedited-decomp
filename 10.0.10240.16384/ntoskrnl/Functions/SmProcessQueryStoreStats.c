// SmProcessQueryStoreStats 
 
int __fastcall SmProcessQueryStoreStats(int a1, _DWORD *a2, _DWORD *a3, int a4)
{
  int result; // r0
  int v7; // r7
  _DWORD *v8; // r2
  int v9; // r1
  int v10; // r4
  _DWORD v11[388]; // [sp-4h] [bp-610h] BYREF

  result = SmpProcessQueryStoreStats(a1, (int)v11, (int)a3, a4);
  if ( result >= 0 )
  {
    if ( a2 )
    {
      v7 = v11[3];
      v8 = v11;
      *a2 = 0;
      v9 = 8;
      do
      {
        v10 = v8[10];
        v8 += 2;
        --v9;
        *a2 += v10 * v7;
      }
      while ( v9 );
    }
    if ( a3 )
      *a3 = v11[8] << 12;
  }
  return result;
}
