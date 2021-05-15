// EtwpParsePoolTagFilter 
 
int __fastcall EtwpParsePoolTagFilter(int a1, int a2, int a3, int a4)
{
  unsigned __int16 *v4; // r6
  int v5; // r3
  int v6; // r4
  int v7; // r0
  unsigned int v8; // r2
  int v9; // r5
  int v10; // t1
  int v12[4]; // [sp+0h] [bp-10h] BYREF

  v12[0] = a4;
  v4 = *(unsigned __int16 **)(a1 + 4);
  v5 = 0;
  v6 = 1;
  v7 = *v4;
  v8 = 0;
  v9 = 0;
  v12[0] = 0;
  if ( !v7 )
    return 0;
  do
  {
    if ( v6 == 1 )
    {
      if ( v7 == 42 )
        v6 = 2;
      *((_BYTE *)v12 + v9) = v7;
      v9 = (__int16)(v9 + 1);
      v5 = v12[0];
      if ( v9 == 4 )
        v6 = 2;
    }
    else
    {
      if ( v7 != 59 || v8 >= 4 )
        return 0;
      *(_DWORD *)(a2 + 4 * v8) = v5;
      v8 = (unsigned __int16)(v8 + 1);
      v5 = 0;
      v9 = 0;
      v12[0] = 0;
      v6 = 1;
    }
    v10 = v4[1];
    ++v4;
    v7 = v10;
  }
  while ( v10 );
  if ( v6 != 2 || v8 >= 4 )
    return 0;
  *(_DWORD *)(a2 + 4 * v8) = v5;
  return (unsigned __int16)(v8 + 1);
}
