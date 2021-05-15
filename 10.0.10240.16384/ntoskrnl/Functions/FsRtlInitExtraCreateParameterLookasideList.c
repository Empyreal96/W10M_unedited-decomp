// FsRtlInitExtraCreateParameterLookasideList 
 
__int64 __fastcall FsRtlInitExtraCreateParameterLookasideList(int a1, char a2, int a3, int a4)
{
  __int64 v5; // [sp+0h] [bp-10h]

  HIDWORD(v5) = a4;
  LODWORD(v5) = a3 + 52;
  if ( (a2 & 2) != 0 )
    ExInitializeNPagedLookasideList(a1, 0, 0, 512);
  else
    ExInitializePagedLookasideList(a1, 0, 0, 0, v5, a4, 0);
  return v5;
}
