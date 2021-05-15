// MiFindContiguousMemoryInPool 
 
int __fastcall MiFindContiguousMemoryInPool(unsigned int a1, unsigned int a2, int a3, unsigned int a4, int a5)
{
  unsigned int v6; // r4
  _DWORD *v7; // r6
  unsigned int v8; // r2
  int v9; // r0
  unsigned int v11; // r3
  int v12; // [sp+10h] [bp-38h] BYREF
  _DWORD v13[6]; // [sp+18h] [bp-30h] BYREF
  char v14; // [sp+30h] [bp-18h]

  if ( a4 > 0x400000 )
    return 0;
  if ( MmProtectFreedNonPagedPool == 1 )
    return 0;
  v6 = ((a4 & 0xFFF) != 0) + (a4 >> 12);
  if ( v6 >= 0x400 )
    return 0;
  if ( a3 )
  {
    v11 = a3 & 0x3FF;
    if ( (a3 & 0x3FF) != 0 )
    {
      if ( v11 > 1024 - v11 )
        v11 = 1024 - v11;
      if ( v6 > v11 )
        return 0;
    }
  }
  v7 = (_DWORD *)(dword_6337E8 + 176 * a5);
  v8 = v7[26];
  if ( !v8 || a1 > v7[27] || a2 < v8 )
    return 0;
  v13[0] = 1;
  v13[1] = a2;
  v14 = 0;
  v13[2] = a1;
  v13[3] = a3;
  v9 = MiScanNonPagedPoolVa(v6, a5, 0, (int)v13);
  if ( v9 == -1 )
  {
    if ( MiExpandNonPagedPool(512, v6, a5, -1, 1, &v12) != -1 )
      return sub_554A78();
    return 0;
  }
  return v7[34] + (v9 << 12);
}
