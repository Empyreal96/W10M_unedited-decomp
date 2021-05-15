// RtlGuardIsValidStackPointer 
 
BOOL __fastcall RtlGuardIsValidStackPointer(unsigned int a1)
{
  int v1; // r2

  if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) != 0
    || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
  {
    v1 = 0;
  }
  else
  {
    v1 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x9C);
  }
  return a1 >= *(_DWORD *)(v1 + 8) && a1 <= *(_DWORD *)(v1 + 4);
}
