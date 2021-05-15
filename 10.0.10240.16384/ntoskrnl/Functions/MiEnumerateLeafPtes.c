// MiEnumerateLeafPtes 
 
unsigned int __fastcall MiEnumerateLeafPtes(unsigned int result, unsigned int a2, int (__fastcall *a3)(int, unsigned int, unsigned int), int a4)
{
  int v4; // r7
  unsigned int v5; // r2
  unsigned int v6; // r8
  unsigned int v7; // r5
  unsigned int v8; // r6
  unsigned int v9; // r4
  unsigned int v10; // r6
  unsigned int v11; // r7
  unsigned int v13; // [sp+Ch] [bp-2Ch]
  int v15; // [sp+14h] [bp-24h] BYREF
  unsigned int v16; // [sp+18h] [bp-20h]

  v4 = a4;
  v5 = (a2 >> 10) & 0x3FFFFC;
  v6 = a2;
  v16 = a2;
  v7 = result;
  while ( 1 )
  {
    v8 = ((v7 >> 10) & 0x3FFFFC) - 0x40000000;
    if ( v6 > 0xC03FFFFF )
      break;
    v7 = v6;
    v9 = v5 - 0x40000000;
    v13 = v6;
    if ( v8 <= v5 - 0x40000000 )
    {
      do
      {
        result = MiGetNextPageTable(v8, v9, 1, 17, 1, &v15);
        v10 = result;
        if ( !result )
          break;
        if ( v15 )
        {
          result = a3(v4, ((result >> 10) & 0x3FFFFC) - 0x40000000, ((result >> 10) & 0x3FFFFC) - 0x40000000);
          v8 = v10 + 4096;
        }
        else
        {
          v11 = (result & 0xFFFFF000) + 4092;
          if ( v11 > v9 )
            v11 = v9;
          result = ((int (__fastcall *)(int, unsigned int, unsigned int, _DWORD))a3)(a4, result, v11, 0);
          v8 = v11 + 4;
          v4 = a4;
        }
      }
      while ( v8 <= v9 );
      v6 = v16;
      v7 = v13;
      v5 = (v16 >> 10) & 0x3FFFFC;
    }
    if ( v7 == v6 )
      return result;
  }
  return sub_53DE74(result, 1, v5, -1069547521);
}
