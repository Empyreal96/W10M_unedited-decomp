// MmGetFileObjectForSection 
 
int __fastcall MmGetFileObjectForSection(int a1)
{
  int v1; // r0

  v1 = MiSectionControlArea(a1);
  return MI_REFERENCE_CONTROL_AREA_FILE(v1);
}
