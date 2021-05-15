// PiCMReleasePropertyInputData 
 
int __fastcall PiCMReleasePropertyInputData(int a1)
{
  int v2; // r3
  unsigned int v3; // r0
  unsigned int v4; // r3
  int v5; // r4
  unsigned int v6; // r0

  v2 = __mrc(15, 0, 13, 0, 3);
  v3 = *(_DWORD *)(a1 + 12);
  v4 = v2 & 0xFFFFFFC0;
  v5 = *(char *)(v4 + 346);
  if ( v3 && *(_BYTE *)(v4 + 346) )
    ExFreePoolWithTag(v3);
  v6 = *(_DWORD *)(a1 + 44);
  if ( v6 && v5 )
    ExFreePoolWithTag(v6);
  return 0;
}
