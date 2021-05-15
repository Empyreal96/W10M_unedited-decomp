// RtlReleasePrivilege 
 
unsigned int __fastcall RtlReleasePrivilege(_DWORD *a1)
{
  int v2; // r3
  unsigned int v4; // r0

  v2 = a1[4];
  if ( (v2 & 1) == 0 || (v2 & 2) != 0 )
    return sub_7EA4BC();
  if ( (a1[4] & 1) != 0 )
  {
    ZwSetInformationThread();
    if ( a1[1] )
      ZwClose();
  }
  v4 = a1[2];
  if ( (_DWORD *)v4 != a1 + 5 )
    ExFreePoolWithTag(v4);
  ZwClose();
  return ExFreePoolWithTag((unsigned int)a1);
}
