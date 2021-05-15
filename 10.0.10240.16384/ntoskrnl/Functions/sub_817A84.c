// sub_817A84 
 
void sub_817A84()
{
  int v0; // r4

  if ( !*(_DWORD *)(v0 + 1332) )
  {
    AslLogCallPrintf(1, (int)"SdbpGetMappedStringFromTable", 732, "No stringtable in DB");
    JUMPOUT(0x7B0A52);
  }
  JUMPOUT(0x7B0A38);
}
