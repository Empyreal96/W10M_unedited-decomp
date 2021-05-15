// MiDisablePagingOfDriver 
 
int __fastcall MiDisablePagingOfDriver(int a1, int a2, unsigned int a3, unsigned int a4)
{
  int v5; // r6
  unsigned int v6; // r4
  int v7; // r0
  unsigned int v8; // r1
  unsigned int v9; // r5
  int v11; // [sp+0h] [bp-28h]
  unsigned int v12; // [sp+8h] [bp-20h] BYREF
  unsigned int v13[7]; // [sp+Ch] [bp-1Ch] BYREF

  v11 = a1;
  v12 = a3;
  v13[0] = a4;
  if ( (*(_DWORD *)(((*(_DWORD *)(a1 + 24) >> 20) & 0xFFC) - 1070596096) & 0x402) != 1026 )
  {
    v5 = 0;
    v6 = 0;
    do
    {
      v7 = MiSnapDriverRange(a1, v5, 4, 0, &v12, v13);
      v8 = v12;
      v5 = v7;
      if ( v12 )
      {
        if ( v6 && v12 < v6 )
        {
          v8 = v6;
          v12 = v6;
        }
        v9 = v13[0];
        if ( v8 <= v13[0] )
        {
          MiLockCode(a1, v8, v13[0], 2);
          v6 = v9 + 4;
        }
      }
    }
    while ( v5 );
  }
  return v11;
}
