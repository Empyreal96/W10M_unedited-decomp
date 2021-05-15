// sub_80C584 
 
void sub_80C584()
{
  int v0; // r4
  char *v1; // r6

  if ( !wcscmp(*(char **)(v0 + 24), v1) )
  {
    WmipReferenceEntry(v0);
    JUMPOUT(0x79359A);
  }
  JUMPOUT(0x793594);
}
