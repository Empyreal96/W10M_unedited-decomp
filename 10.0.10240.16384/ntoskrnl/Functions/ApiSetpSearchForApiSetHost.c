// ApiSetpSearchForApiSetHost 
 
int __fastcall ApiSetpSearchForApiSetHost(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  int v6; // r5
  int v7; // lr
  int v8; // r4
  int v9; // r10
  int v10; // r7
  int v11; // r0

  v4 = 1;
  v6 = *(_DWORD *)(a1 + 16) + a4;
  v7 = a3;
  v8 = *(_DWORD *)(a1 + 20) - 1;
  if ( v8 >= 1 )
  {
    v9 = *(_DWORD *)(a1 + 16);
    do
    {
      v10 = (v8 + v4) >> 1;
      v11 = RtlCompareUnicodeStrings(
              a2,
              v7,
              *(_DWORD *)(v9 + 20 * v10 + a4 + 4) + a4,
              *(_DWORD *)(v9 + 20 * v10 + a4 + 8) >> 1);
      if ( v11 >= 0 )
      {
        if ( v11 <= 0 )
          return v9 + 20 * v10 + a4;
        v4 = v10 + 1;
      }
      else
      {
        v8 = v10 - 1;
      }
      v7 = a3;
    }
    while ( v4 <= v8 );
  }
  return v6;
}
