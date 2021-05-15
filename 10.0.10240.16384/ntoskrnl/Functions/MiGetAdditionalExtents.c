// MiGetAdditionalExtents 
 
int __fastcall MiGetAdditionalExtents(int *a1)
{
  int v2; // r4
  int v3; // r0

  if ( !a1[1] )
    return 0;
  v2 = *a1;
  v3 = MI_REFERENCE_CONTROL_AREA_FILE(*a1);
  MI_DEREFERENCE_CONTROL_AREA_FILE(v2, v3);
  return -1073741637;
}
