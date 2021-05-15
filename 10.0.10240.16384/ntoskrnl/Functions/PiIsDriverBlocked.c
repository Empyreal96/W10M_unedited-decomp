// PiIsDriverBlocked 
 
int __fastcall PiIsDriverBlocked(int a1, int a2, int a3, int a4)
{
  if ( SdbGetDatabaseMatch(a1, *(unsigned __int16 **)(a2 + 4), a3, a3, a4) )
    return sub_7CD494();
  PiUpdateDriverDBCache(a2, a3);
  return 0;
}
