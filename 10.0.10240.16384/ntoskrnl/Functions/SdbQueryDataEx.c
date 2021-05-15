// SdbQueryDataEx 
 
int __fastcall SdbQueryDataEx(int a1, int a2)
{
  int v4; // [sp+10h] [bp-18h] BYREF
  _DWORD v5[5]; // [sp+14h] [bp-14h] BYREF

  v4 = 0;
  v5[0] = 0;
  v5[1] = 0;
  if ( SdbTagRefToTagID(a1, a2, v5, &v4) )
    return SdbQueryDataExTagID(v5[0], v4);
  AslLogCallPrintf(1, (int)"SdbQueryDataEx", 4884, "Failed to convert tagref 0x%x to tagid", a2);
  return 87;
}
