// SdbpOpenDatabaseInMemory 
 
int __fastcall SdbpOpenDatabaseInMemory(int a1, int a2)
{
  _DWORD *v4; // r0
  int v5; // r4
  int v7; // r3
  int v8[6]; // [sp+10h] [bp-18h] BYREF

  v4 = AslAlloc(a1, 1360);
  v5 = (int)v4;
  if ( !v4 )
    return sub_7CE11C();
  v7 = v4[4];
  v4[1] = a1;
  v4[2] = 0;
  v4[3] = a2;
  v4[4] = v7 | 1;
  *v4 = 0;
  if ( !SdbpReadMappedData((int)v4, 0, (int)v8, 0xCu) )
    JUMPOUT(0x7CE12C);
  if ( v8[2] != 1717724275 || v8[0] != 3 )
    JUMPOUT(0x7CE14E);
  if ( !SdbGetDatabaseID(v5, v5 + 20) )
    JUMPOUT(0x7CE13C);
  return v5;
}
