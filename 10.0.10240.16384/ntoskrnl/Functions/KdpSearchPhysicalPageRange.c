// KdpSearchPhysicalPageRange 
 
int __fastcall KdpSearchPhysicalPageRange(int a1)
{
  int v2; // r3
  int v4; // r6
  int v5; // r2
  int v6; // r3
  int v7; // r3
  unsigned int v8; // r5
  unsigned int v9; // r3
  unsigned int v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r3

  v2 = KdpSearchInProgress;
  __dmb(0xBu);
  if ( !v2 )
    return 0;
  v4 = 0;
  v5 = KdpSearchEndPageFrame;
  __dmb(0xBu);
  v6 = KdpSearchStartPageFrame;
  __dmb(0xBu);
  if ( v5 == v6 )
  {
    v7 = KdpSearchEndPageFrame + 1;
    __dmb(0xBu);
    KdpSearchEndPageFrame = v7;
    v4 = 1;
  }
  v8 = KdpSearchStartPageFrame;
  __dmb(0xBu);
  v9 = KdpSearchEndPageFrame;
  __dmb(0xBu);
  if ( v8 < v9 )
  {
    do
    {
      v10 = KdpSearchAddressRangeEnd;
      __dmb(0xBu);
      v11 = KdpSearchAddressRangeStart;
      __dmb(0xBu);
      KdpSearchPhysicalPage(v8, v11, v10, v4, a1);
      v12 = KdpSearchEndPageFrame;
      ++v8;
      __dmb(0xBu);
    }
    while ( v8 < v12 );
  }
  return 1;
}
