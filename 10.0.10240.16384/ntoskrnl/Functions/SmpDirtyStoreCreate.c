// SmpDirtyStoreCreate 
 
int __fastcall SmpDirtyStoreCreate(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  bool v8; // zf
  int v9; // r3
  unsigned int v10; // r2
  unsigned int v11; // r1
  int result; // r0
  int v13[22]; // [sp+4h] [bp-58h] BYREF

  memset(v13, 0, 56);
  v13[0] = v13[0] & 0xFFFFFD06 | ((a3 & 1) << 9) | 0x106;
  v13[2] = 128;
  v13[3] = 0x20000;
  if ( a3 )
    v8 = (dword_636CC0 & 0xC) == 8;
  else
    v8 = (dword_636CC0 & 3) == 2;
  v9 = v8;
  v13[1] = ((v13[1] & 0xFFFEFF00 | ((dword_636CC0 & 0x10 | 0x40) << 12)) ^ (v9 << 17)) & 0x20000 ^ (v13[1] & 0xFFFEFF00 | ((dword_636CC0 & 0x10 | 0x40) << 12));
  v10 = (a2 << 10 >> 22) | (a2 >> 22 << 10);
  v11 = (8 * a2) & 0x7FFF | (v10 << 15);
  if ( v10 >> 17 || v11 >= 0x40000 )
    return sub_7BF654(0x20000, v11);
  v13[4] = (8 * a2) & 0x7FFF | (v10 << 15);
  result = SmProcessCreateRequest(a1, v13, 56, 0);
  if ( result >= 0 )
  {
    result = 0;
    *a4 = v13[13];
  }
  return result;
}
