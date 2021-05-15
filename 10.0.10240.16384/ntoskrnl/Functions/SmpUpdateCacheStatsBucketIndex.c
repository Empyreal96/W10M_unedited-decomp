// SmpUpdateCacheStatsBucketIndex 
 
int SmpUpdateCacheStatsBucketIndex()
{
  int result; // r0

  result = SmKmGetCacheStatsBucketIndex(SmGlobals, &dword_636EA8);
  dword_637090 = result;
  return result;
}
