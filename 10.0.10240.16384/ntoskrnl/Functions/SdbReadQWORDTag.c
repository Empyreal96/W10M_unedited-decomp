// SdbReadQWORDTag 
 
__int64 __fastcall SdbReadQWORDTag(int a1, int a2, __int64 a3)
{
  __int64 v3; // r4
  int v6; // r2
  int v7; // r3
  int v8; // r0
  __int64 v10[3]; // [sp+8h] [bp-18h] BYREF

  v3 = a3;
  v10[0] = a3;
  v7 = SdbGetTagFromTagID(a1, a2, a3, SHIDWORD(a3)) & 0xF000;
  if ( v7 == 20480 )
  {
    if ( SdbpReadTagData(a1, a2, (int)v10, 8u) )
      v3 = v10[0];
  }
  else
  {
    v8 = SdbGetTagFromTagID(a1, a2, v6, v7);
    AslLogCallPrintf(1, (int)"SdbReadQWORDTag", 136, "TagID 0x%X, Tag 0x%X not of the expected type", a2, v8);
  }
  return v3;
}
