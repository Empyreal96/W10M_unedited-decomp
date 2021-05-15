// MmSectionToSectionObjectPointers 
 
int __fastcall MmSectionToSectionObjectPointers(int a1)
{
  int v1; // r0
  int v2; // r5
  int v3; // r0
  int v4; // r4

  v1 = MiSectionControlArea(a1);
  v2 = v1;
  if ( !*(_DWORD *)(v1 + 32) )
    return 0;
  v3 = MI_REFERENCE_CONTROL_AREA_FILE(v1);
  v4 = *(_DWORD *)(v3 + 20);
  MI_DEREFERENCE_CONTROL_AREA_FILE(v2, v3);
  return v4;
}
