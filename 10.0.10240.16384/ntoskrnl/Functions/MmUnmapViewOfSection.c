// MmUnmapViewOfSection 
 
int __fastcall MmUnmapViewOfSection(int a1, int a2)
{
  return MiUnmapViewOfSection(a1, a2, 0);
}
