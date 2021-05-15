// sub_527110 
 
void sub_527110()
{
  int v0; // r4
  int v1; // r0

  v1 = MiMarkFileExtentsDeleted(v0);
  if ( v1 )
    MiDeleteFileExtents(v1, 0, *(_DWORD *)(v0 + 28), 2);
  JUMPOUT(0x4629A2);
}
