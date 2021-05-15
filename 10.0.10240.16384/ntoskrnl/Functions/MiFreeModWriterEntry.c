// MiFreeModWriterEntry 
 
int __fastcall MiFreeModWriterEntry(int a1, int a2)
{
  int v3; // r5

  v3 = *(_DWORD *)(a1 + 120);
  ExFreePoolWithTag(a1, 0);
  return MiReleaseWriteInProgressCharges(v3, 1, a2);
}
