// RtlNtStatusToDosError 
 
unsigned int __fastcall RtlNtStatusToDosError(unsigned int a1, int a2)
{
  int v2; // r3

  if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) != 0
    || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
  {
    v2 = 0;
  }
  else
  {
    v2 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x9C);
  }
  if ( v2 )
    *(_DWORD *)(v2 + 3060) = a1;
  return RtlNtStatusToDosErrorNoTeb(a1);
}
