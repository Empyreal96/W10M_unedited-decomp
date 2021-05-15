// WmipInitializeAllocs 
 
__int64 WmipInitializeAllocs()
{
  __int64 v1; // [sp+0h] [bp-18h]

  ExInitializePagedLookasideList((int)&WmipDSChunkInfoLookaside, 0, 0, 0, 64, 1396993367, 0);
  ExInitializePagedLookasideList((int)&WmipGEChunkInfoLookaside, 0, 0, 0, 112, 1162308951, 0);
  ExInitializePagedLookasideList((int)&WmipISChunkInfoLookaside, 0, 0, 0, 52, 1397321047, 0);
  ExInitializePagedLookasideList((int)&WmipMRChunkInfoLookaside, 0, 0, 0, 28, 1380805975, 0);
  return v1;
}
