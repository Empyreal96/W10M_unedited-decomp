// RaspClearCache 
 
int __fastcall RaspClearCache(int a1, int a2)
{
  if ( *(int **)(RaspBitmapCache + 4) != &RaspBitmapCache )
    JUMPOUT(0x8DFCF4);
  return sub_8DFCEC(RaspBitmapCache, a2, *(_DWORD *)RaspBitmapCache);
}
