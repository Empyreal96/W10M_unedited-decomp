// ExInitializePoolDescriptor 
 
int *__fastcall ExInitializePoolDescriptor(int *result, int a2, int a3)
{
  int *v4; // r3

  v4 = result + 160;
  result[64] = a3;
  result[32] = 0;
  result[33] = 0;
  result[96] = 0;
  result[35] = 0;
  result[36] = 0;
  result[34] = 0;
  result[128] = 0;
  result[129] = 0;
  *result = a2;
  while ( v4 < result + 1184 )
  {
    *v4 = (int)v4;
    v4[1] = (int)v4;
    v4 += 2;
  }
  if ( (a2 & 1) != 0 )
    result = (int *)KeInitializeGuardedMutex((int)(result + 1));
  else
    result[1] = 0;
  if ( a2 == 33 )
  {
    result = &MmSessionSpace;
    if ( !ExpSessionPoolLookaside )
    {
      ExpSessionPoolLookaside = MmSessionSpace + 128;
      ExpSessionPoolTrackTable = MmSessionSpace + 12288;
      ExpSessionPoolTrackTableSize = 256;
      ExpSessionPoolTrackTableMask = 255;
      ExpSessionPoolSmallLists = 24;
    }
  }
  return result;
}
