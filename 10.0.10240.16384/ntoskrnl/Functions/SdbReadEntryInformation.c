// SdbReadEntryInformation 
 
int __fastcall SdbReadEntryInformation(int a1, int a2, int a3)
{
  int v6; // r4
  int v7; // r6
  int v8; // r5
  int v10; // [sp+8h] [bp-48h] BYREF
  int v11; // [sp+Ch] [bp-44h] BYREF
  int v12[16]; // [sp+10h] [bp-40h] BYREF

  memset(v12, 0, 40);
  v6 = SdbTagRefToTagID(a1, a2, &v10, &v11);
  if ( !v6 )
  {
    AslLogCallPrintf(1, (int)"SdbReadEntryInformation", 4940, "Failed to convert tagref 0x%x to tagid", a2);
    return v6;
  }
  v7 = v11;
  v8 = SdbFindFirstTag(v10, v11, 36868);
  if ( !v8 )
  {
    AslLogCallPrintf(1, (int)"SdbReadEntryInformation", 4950, "Failed to read TAG_EXE_ID for tiExe 0x%x", v7);
    return 0;
  }
  v6 = SdbReadBinaryTag(v10, v8, (int)v12, 0x10u);
  if ( !v6 )
  {
    AslLogCallPrintf(1, (int)"SdbReadEntryInformation", 4960, "Failed to read GUID referenced by 0x%x", v8);
    return v6;
  }
  if ( !SdbGetDatabaseID(v10, (int)&v12[6]) )
  {
    AslLogCallPrintf(1, (int)"SdbReadEntryInformation", 4968, "Failed to read GUID of the database");
    return 0;
  }
  if ( !SdbGetEntryFlags(v12, &v12[4]) )
    v12[4] = 0;
  v12[5] = SdbFindFirstTag(v10, v7, 28687);
  if ( a3 )
    memmove(a3, (int)v12, 0x28u);
  return 1;
}
