// PpLastGoodDoBootProcessing 
 
int PpLastGoodDoBootProcessing()
{
  unsigned int v0; // r0
  int result; // r0
  _BYTE v2[8]; // [sp+0h] [bp-28h] BYREF
  char v3[8]; // [sp+8h] [bp-20h] BYREF
  char v4[8]; // [sp+10h] [bp-18h] BYREF
  char v5[16]; // [sp+18h] [bp-10h] BYREF

  RtlInitUnicodeString((unsigned int)v3, L"\\SystemRoot\\LastGood");
  RtlInitUnicodeString((unsigned int)v2, L"\\Registry\\Machine\\System\\LastKnownGoodRecovery\\LastGood");
  RtlInitUnicodeString((unsigned int)v5, L"\\SystemRoot\\LastGood.Tmp");
  v0 = RtlInitUnicodeString((unsigned int)v4, L"\\Registry\\Machine\\System\\LastKnownGoodRecovery\\LastGood.Tmp");
  result = CmIsLastKnownGoodBoot(v0);
  if ( result )
    return sub_96EC98();
  if ( !InitSafeBootMode )
  {
    result = IopFileUtilRename(v3, v5, 0);
    if ( result >= 0 || result == -1073741772 )
      result = PiLastGoodCopyKeyContents(v2, v4);
  }
  return result;
}
