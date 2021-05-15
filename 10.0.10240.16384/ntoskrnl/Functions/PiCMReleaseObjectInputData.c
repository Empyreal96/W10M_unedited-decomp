// PiCMReleaseObjectInputData 
 
int __fastcall PiCMReleaseObjectInputData(int a1)
{
  int v1; // r3
  unsigned int v2; // r0

  v1 = __mrc(15, 0, 13, 0, 3);
  v2 = *(_DWORD *)(a1 + 12);
  if ( v2 && *(_BYTE *)((v1 & 0xFFFFFFC0) + 0x15A) )
    ExFreePoolWithTag(v2);
  return 0;
}
