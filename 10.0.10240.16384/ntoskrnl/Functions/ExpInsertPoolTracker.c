// ExpInsertPoolTracker 
 
int __fastcall ExpInsertPoolTracker(int a1)
{
  if ( (a1 & 0x7FFFFFFF) == PoolHitTag )
    __debugbreak();
  return sub_50B8A4();
}
