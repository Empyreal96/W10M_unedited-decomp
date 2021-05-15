// -SmKmProbeAndLockAddress@@YAJPAXKPAU_MDL@@@Z 
 
int __fastcall SmKmProbeAndLockAddress(__int64 a1, struct _MDL *a2)
{
  unsigned int v2; // r4
  int result; // r0

  v2 = a1 & 0xFFF;
  LODWORD(a1) = a1 & 0xFFFFF000;
  *(_QWORD *)&a2->StartVa = a1;
  a2->Size = 4 * (((v2 + HIDWORD(a1) + 4095) >> 12) + 7);
  a2->Next = 0;
  a2->MdlFlags = 0;
  a2->ByteOffset = v2;
  result = MmStoreProbeAndLockPages(a2);
  if ( result >= 0 )
    result = 0;
  return result;
}
