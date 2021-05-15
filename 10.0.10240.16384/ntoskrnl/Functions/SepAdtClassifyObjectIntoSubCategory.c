// SepAdtClassifyObjectIntoSubCategory 
 
int __fastcall SepAdtClassifyObjectIntoSubCategory(int a1, unsigned __int16 *a2)
{
  int v4; // r0

  if ( a1 )
  {
    v4 = a1 - 24;
    if ( (void *)ObTypeIndexTable[*(unsigned __int8 *)(v4 + 12) ^ BYTE1(v4) ^ (unsigned __int8)ObHeaderCookie] == CmKeyObjectType )
      return 117;
    if ( (void *)ObTypeIndexTable[*(unsigned __int8 *)(v4 + 12) ^ BYTE1(v4) ^ (unsigned __int8)ObHeaderCookie] == IoFileObjectType )
    {
      if ( SepAuditingEnabledForSubcategory(128) == 1 && SepIsRemovableStorageDevice(*(_DWORD *)(a1 + 4)) == 1 )
        return 128;
      return 116;
    }
    if ( ObTypeIndexTable[*(unsigned __int8 *)(v4 + 12) ^ BYTE1(v4) ^ (unsigned __int8)ObHeaderCookie] == IoDeviceObjectType
      && SepAuditingEnabledForSubcategory(128) == 1
      && SepIsRemovableStorageDevice(a1) == 1 )
    {
      return 128;
    }
  }
  else if ( a2 )
  {
    if ( !RtlCompareUnicodeString(a2, (unsigned __int16 *)&SepFileTypeName, 0) )
      return 116;
    if ( !RtlCompareUnicodeString(a2, (unsigned __int16 *)&SepRegistryTypeName, 0) )
      return 117;
  }
  return 118;
}
