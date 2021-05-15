// NtUnmapViewOfSection 
 
int __fastcall NtUnmapViewOfSection(int a1, int a2)
{
  return NtUnmapViewOfSectionEx(a1, a2, 0);
}
