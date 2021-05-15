// FsRtlNormalizeNtstatus 
 
int __fastcall FsRtlNormalizeNtstatus(int a1, int a2)
{
  int v3; // r4

  v3 = a1;
  if ( !FsRtlIsNtstatusExpected(a1) )
    v3 = a2;
  return v3;
}
