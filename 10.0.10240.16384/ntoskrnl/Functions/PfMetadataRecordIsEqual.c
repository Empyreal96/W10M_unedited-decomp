// PfMetadataRecordIsEqual 
 
BOOL __fastcall PfMetadataRecordIsEqual(int a1, _QWORD *a2, int a3)
{
  return *(_QWORD *)(a1 + 8) == *a2 && *(_DWORD *)(a1 + 16) == a3;
}
