// SdbTagIDToTagRef 
 
int __fastcall SdbTagIDToTagRef(int a1, int a2, int a3, int *a4)
{
  int v4; // r4
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v4 = 0;
  v8[0] = -1;
  if ( SdbpFindLocalDatabaseByPDB(a1, a2, a3, v8) )
  {
    v4 = 1;
    *a4 = a3 | (v8[0] << 28);
  }
  else
  {
    AslLogCallPrintf(1, (int)"SdbTagIDToTagRef", 208, "Bad PDB");
    *a4 = 0;
  }
  return v4;
}
