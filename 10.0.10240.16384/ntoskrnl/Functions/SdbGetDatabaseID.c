// SdbGetDatabaseID 
 
int __fastcall SdbGetDatabaseID(int a1, int a2)
{
  int v3; // r5
  int v5; // r0
  int v7; // r0
  int v8; // r6

  v3 = 0;
  if ( (*(_DWORD *)(a1 + 16) & 2) != 0 )
    goto LABEL_7;
  v5 = SdbFindFirstTag(a1, 0, 28673);
  if ( !v5 )
    return sub_7CD728();
  v7 = SdbFindFirstTag(a1, v5, 36871);
  v8 = v7;
  if ( !v7 )
    JUMPOUT(0x7CD72E);
  if ( SdbReadBinaryTag(a1, v7, a1 + 20, 16) )
  {
    *(_DWORD *)(a1 + 16) |= 2u;
LABEL_7:
    if ( (*(_DWORD *)(a1 + 16) & 2) != 0 )
    {
      memmove(a2, a1 + 20, 0x10u);
      v3 = 1;
    }
    return v3;
  }
  AslLogCallPrintf(1, "SdbGetDatabaseID", 246, "Failed to read database id 0x%lx", v8);
  return v3;
}
