// FsRtlpHeatUnregisterVolume 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall FsRtlpHeatUnregisterVolume(unsigned int a1, int a2, int a3, int a4)
{
  int *i; // r4
  int v7; // r3
  int *v8; // r1 OVERLAPPED
  int **v9; // r2 OVERLAPPED

  ExAcquireResourceExclusiveLite((int)&algn_631E04[4], 1, a3, a4);
  for ( i = (int *)FsRtlTieringHeatData; i != &FsRtlTieringHeatData; i = (int *)*i )
  {
    if ( !memcmp((unsigned int)(i + 3), a1, 16) )
    {
      v7 = i[2] - 1;
      i[2] = v7;
      if ( !v7 )
      {
        *(_QWORD *)&v8 = *(_QWORD *)i;
        if ( *(int **)(*i + 4) != i || *v9 != i )
          __fastfail(3u);
        *v9 = v8;
        v8[1] = (int)v9;
        ExFreePoolWithTag((unsigned int)i);
      }
      return ExReleaseResourceLite((int)&algn_631E04[4]);
    }
  }
  return ExReleaseResourceLite((int)&algn_631E04[4]);
}
