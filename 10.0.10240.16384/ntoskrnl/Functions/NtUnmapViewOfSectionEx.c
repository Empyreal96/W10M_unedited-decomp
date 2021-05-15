// NtUnmapViewOfSectionEx 
 
int __fastcall NtUnmapViewOfSectionEx(int a1, unsigned int a2, int a3)
{
  int v6; // r0
  int v7; // r4
  int v9[6]; // [sp+10h] [bp-18h] BYREF

  if ( (a3 & 0xFFFFFFFE) != 0 )
    return -1073741583;
  v6 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v6 == 1 && a2 > MmHighestUserAddress )
    return -1073741799;
  v7 = ObReferenceObjectByHandleWithTag(a1, 8, PsProcessType, v6, 2002152781, v9, 0);
  if ( v7 >= 0 )
  {
    v7 = MiUnmapViewOfSection(v9[0], a2, a3);
    ObfDereferenceObjectWithTag(v9[0]);
  }
  return v7;
}
