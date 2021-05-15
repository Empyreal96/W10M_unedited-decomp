// SdbOpenDatabaseEx 
 
unsigned int *__fastcall SdbOpenDatabaseEx(unsigned __int16 *a1)
{
  unsigned int *v2; // r0
  unsigned int *v3; // r4
  int v4; // r0
  const char *v5; // r3
  int v6; // r2
  unsigned int v7; // r0
  int v9; // [sp+8h] [bp-18h] BYREF
  int v10; // [sp+10h] [bp-10h]

  v2 = (unsigned int *)AslAlloc((int)a1, 1360);
  v3 = v2;
  if ( !v2 )
  {
    AslLogCallPrintf(1, (int)"SdbOpenDatabaseEx", 489, "Failed to allocate DB structure");
    return 0;
  }
  memset(v2, 0, 1360);
  v4 = AslFileMappingCreate(v3, a1, 0, 0, 0);
  if ( v4 < 0 )
  {
    v5 = "Failed to create file mapping [%x]";
    v6 = 504;
LABEL_5:
    AslLogCallPrintf(1, (int)"SdbOpenDatabaseEx", v6, v5, v4);
LABEL_22:
    AslFileMappingDelete(*v3);
    ExFreePoolWithTag((unsigned int)v3);
    return 0;
  }
  if ( (unsigned __int64)(*(_QWORD *)(*v3 + 528) - 42i64) > 0x7FFFFFD5 )
  {
    AslLogCallPrintf(1, (int)"SdbOpenDatabaseEx", 513, "Failed to open SDB - File size too large or small.");
    goto LABEL_22;
  }
  v4 = AslFileMappingEnsureMappedAs();
  if ( v4 < 0 )
  {
    v5 = "Failed to map SDB [%x]";
    v6 = 519;
    goto LABEL_5;
  }
  v7 = *v3;
  v3[2] = 0;
  v3[3] = *(_DWORD *)(v7 + 528);
  v3[1] = AslFileMappingGetViewBase();
  if ( !SdbpReadMappedData((int)v3, 0, (int)&v9, 0xCu) )
  {
    AslLogCallPrintf(1, (int)"SdbOpenDatabaseEx", 531, "Failed to read database header");
    goto LABEL_22;
  }
  if ( v10 != 1717724275 )
  {
    AslLogCallPrintf(1, (int)"SdbOpenDatabaseEx", 543, "Magic does not match 0x%lx", v10);
    goto LABEL_22;
  }
  if ( v9 == 1 )
  {
    v3[332] |= 1u;
    goto LABEL_18;
  }
  if ( v9 == 2 )
  {
LABEL_18:
    v3[332] |= 2u;
    goto LABEL_19;
  }
  if ( v9 != 3 )
  {
    AslLogCallPrintf(
      1,
      (int)"SdbOpenDatabaseEx",
      564,
      "MajorVersion mismatch, MajorVersion 0x%lx Expected 0x%lx",
      v9,
      3);
    goto LABEL_22;
  }
LABEL_19:
  if ( !SdbGetDatabaseID((int)v3, (int)(v3 + 5)) )
    AslLogCallPrintf(1, (int)"SdbOpenDatabaseEx", 569, "Failed to get the database ID");
  return v3;
}
