// ExInitializeNls 
 
int ExInitializeNls()
{
  int result; // r0

  result = ZwCreateDirectoryObject();
  if ( result >= 0 )
  {
    ZwClose();
    NlsSectionLock = 0;
    NlsDefaultCasingTableSize = InitNlsTableSize - InitUnicodeCaseTableDataOffset;
    dword_92037C = 0;
    result = 0;
  }
  return result;
}
