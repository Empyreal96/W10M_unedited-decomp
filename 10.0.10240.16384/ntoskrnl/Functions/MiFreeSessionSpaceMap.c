// MiFreeSessionSpaceMap 
 
void MiFreeSessionSpaceMap()
{
  int *v0; // r1

  v0 = *(int **)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  if ( v0[802] )
    KeBugCheckEx(186, v0[2], v0[803], 0, 0);
}
