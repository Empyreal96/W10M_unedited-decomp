// PfLogFileDataAccess 
 
int __fastcall PfLogFileDataAccess(int a1, int a2, __int64 a3, int a4, int a5)
{
  unsigned int v5; // r5
  unsigned int v6; // r4
  unsigned int v8; // r1
  int v9[2]; // [sp+0h] [bp-30h] BYREF
  _DWORD v10[10]; // [sp+8h] [bp-28h] BYREF

  v5 = *(_DWORD *)(a2 + 336);
  v6 = (*(_DWORD *)(a2 + 960) >> 12) & 7;
  if ( (*(_DWORD *)(v5 + 192) & 0x100000) != 0 && v6 >= 2 )
    v6 = 2;
  if ( v6 < dword_634498 )
    return 0;
  v10[0] = a1;
  v10[1] = a3 >> 12;
  v8 = *(_DWORD *)(v5 + 200);
  v10[2] = a4 & 0x7FFFFFFF | (a5 << 31);
  v10[3] = (v8 >> 3) & 0x1C000000 ^ (*(_DWORD *)(v5 + 204) ^ v8 ^ v5) & 0x1FFFFFFF;
  v10[4] = dword_643B68;
  v10[5] = *(_DWORD *)(v5 + 176);
  KeQueryTickCount(v9);
  return PfLogEvent(
           10,
           ((__int64)((((unsigned int)v9[0] * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
                    + (((unsigned int)v9[1] * (unsigned __int64)MEMORY[0xFFFF9004]) << 8)) >> 10)
         + dword_63728C,
           (int)v10,
           0x18u);
}
