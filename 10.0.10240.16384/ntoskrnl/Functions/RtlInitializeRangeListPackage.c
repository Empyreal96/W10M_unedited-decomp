// RtlInitializeRangeListPackage 
 
__int64 RtlInitializeRangeListPackage()
{
  __int64 v1; // [sp+0h] [bp-10h]

  ExInitializePagedLookasideList((int)&RtlpRangeListEntryLookasideList, 0, 0, 256, 40, 1701597778, 16);
  return v1;
}
