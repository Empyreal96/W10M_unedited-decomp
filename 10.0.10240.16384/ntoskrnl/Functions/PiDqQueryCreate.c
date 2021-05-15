// PiDqQueryCreate 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PiDqQueryCreate(int a1, _DWORD *a2)
{
  int v3; // r4
  _BYTE *v4; // r0
  _BYTE *v5; // r5
  unsigned __int64 v6; // kr00_8

  v3 = 0;
  v4 = (_BYTE *)ExAllocatePoolWithTag(512, 128, 1483763280);
  v5 = v4;
  if ( !v4 )
    return -1073741670;
  memset(v4, 0, 128);
  __dmb(0xBu);
  *((_DWORD *)v5 + 28) = 1;
  __dmb(0xBu);
  do
    v6 = __ldrexd(PiDqSequenceNumber);
  while ( __strexd(v6 + 1, PiDqSequenceNumber) );
  __dmb(0xBu);
  *((_DWORD *)v5 + 8) = 0;
  *((_QWORD *)v5 + 15) = v6 + 1;
  RtlInitializeGenericTableAvl(
    (int)(v5 + 36),
    (unsigned int)PiDqCompareAddresses,
    (unsigned int)PiDqAllocateGenericTableEntry,
    (int)PiDqFreeGenericTableEntry,
    0);
  *((_DWORD *)v5 + 25) = v5 + 100;
  *((_DWORD *)v5 + 26) = v5 + 100;
  SeCaptureSubjectContext(v5 + 16);
  *a2 = v5;
  return v3;
}
