// Normalization__CanCombinableCharactersCombine 
 
int __fastcall Normalization__CanCombinableCharactersCombine(_DWORD *a1, int a2, int a3, int a4)
{
  int v7; // r0
  unsigned __int16 *v8; // r3
  unsigned int v9; // r1
  __int16 v10; // r10
  int v11; // r3
  unsigned __int16 *v12; // r5
  int v13; // r7
  int v14; // r1
  int v15; // r2
  int v16; // r2
  int v17; // r3
  int v18; // r2
  unsigned int v20; // [sp+0h] [bp-28h]
  int i; // [sp+4h] [bp-24h]

  if ( (a2 & 0x1F0000) == 0 )
    a4 = 1;
  if ( (a2 & 0x1F0000) != 0 )
    a4 = 0;
  if ( a4 == ((a3 & 0x1F0000) == 0) )
  {
    v7 = a1[12];
    if ( v7 )
    {
      v8 = (unsigned __int16 *)(a1[13] + 2 * (unsigned __int16)((a2 + 12541 * a3) % v7));
      v9 = *v8;
      v10 = *v8;
      v20 = v8[1];
      if ( v9 < v20 )
      {
        v11 = a1[14];
        for ( i = v11; ; v11 = i )
        {
          v12 = (unsigned __int16 *)(v11 + 2 * v9);
          v13 = *v12;
          if ( a2 == v13 && a3 == v12[1] )
            return *(unsigned __int16 *)(a1[14] + 2 * v9 + 4);
          if ( IsSurrogate(*v12) )
          {
            if ( a2 > 0xFFFF )
            {
              v16 = a2 - v15;
              v17 = v16 / 1024;
              v18 = v16 % 1024;
              if ( v13 == (unsigned __int16)(v17 - 10240)
                && v12[1] == (unsigned __int16)(v18 - 9216)
                && v12[2] == (unsigned __int16)((a3 - 0x10000) / 1024 - 10240)
                && v12[3] == (unsigned __int16)((a3 - 0x10000) % 1024 - 9216) )
              {
                return *(unsigned __int16 *)(a1[14] + 2 * v14 + 10)
                     + ((*(unsigned __int16 *)(a1[14] + 2 * v14 + 8) - 55287) << 10);
              }
            }
            LOWORD(v14) = v10 + 3;
          }
          v9 = (unsigned __int16)(v14 + 3);
          v10 = v9;
          if ( v9 >= v20 )
            return 0;
        }
      }
    }
  }
  return 0;
}
