// MiDeleteStaleCacheMaps 
 
int MiDeleteStaleCacheMaps()
{
  int v0; // r7
  int result; // r0

  if ( (int *)dword_634890 != &dword_634890 )
  {
    __dmb(0xFu);
    v0 = KiCacheFlushTimeStamp;
    __dmb(0xBu);
    if ( (unsigned int)(v0 - dword_634898) > 2 || (dword_634898 & 1) == 0 && (unsigned int)(v0 - dword_634898) >= 2 )
      result = sub_5168F8();
  }
  return result;
}
