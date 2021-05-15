// SdbpMatchOsVersion 
 
BOOL __fastcall SdbpMatchOsVersion(int a1, int a2)
{
  BOOL v4; // r5
  int v5; // r1
  int v6; // r2
  int v7; // r3
  unsigned int v8; // r2
  unsigned int v9; // r7
  unsigned int v10; // r4
  unsigned int v11; // r8
  int v12; // r0
  __int64 v13; // r0
  int v14; // r0
  __int64 v15; // r0
  int v16; // r0
  __int64 v17; // r0
  int v19[78]; // [sp+0h] [bp-138h] BYREF

  v4 = 1;
  memset(v19, 0, 284);
  v19[0] = 284;
  RtlGetVersion(v19, v5, v6, v7);
  v8 = v19[2] | (v19[1] << 16);
  v9 = HIWORD(v8) | (HIWORD(v19[1]) << 16);
  v10 = v19[3] | (v8 << 16);
  v11 = HIWORD(v10);
  v12 = SdbFindFirstTag(a1, a2, 20509);
  if ( v12 )
  {
    v13 = SdbReadQWORDTag(a1, v12, 0, 0);
    if ( !SdbpCheckVersion(v13, HIDWORD(v13), v10 << 16, v11 | (v9 << 16)) )
      v4 = 0;
  }
  v14 = SdbFindFirstTag(a1, a2, 20511);
  if ( v14 )
  {
    v15 = SdbReadQWORDTag(a1, v14, 0, 0);
    v4 = v4 && SdbpCheckFromVersion(v15, HIDWORD(v15), v10 << 16, v11 | (v9 << 16));
  }
  v16 = SdbFindFirstTag(a1, a2, 20510);
  if ( v16 )
  {
    v17 = SdbReadQWORDTag(a1, v16, 0, 0);
    v4 = v4 && SdbpCheckUptoVersion(v17, HIDWORD(v17), v10 << 16, v11 | (v9 << 16));
  }
  return v4;
}
