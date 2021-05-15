// SdbGetBinaryTagData 
 
int __fastcall SdbGetBinaryTagData(int a1, int a2, int a3, int a4)
{
  int v6; // r2
  int v7; // r3
  int v8; // r0

  v7 = SdbGetTagFromTagID(a1, a2, a3, a4) & 0xF000;
  if ( v7 == 36864 )
    return SdbpGetMappedTagData(a1, a2);
  v8 = SdbGetTagFromTagID(a1, a2, v6, v7);
  AslLogCallPrintf(1, (int)"SdbGetBinaryTagData", 820, "TagID 0x%08X, Tag %04X not BINARY type", a2, v8);
  return 0;
}
