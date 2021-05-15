// RtlInitializeCompression 
 
__int64 RtlInitializeCompression()
{
  ExInitializeNPagedLookasideList((int)&RtlLznt1DecompressChunkLookaside, 0, 0, 512);
  return 0x63647A6C0000002Ci64;
}
