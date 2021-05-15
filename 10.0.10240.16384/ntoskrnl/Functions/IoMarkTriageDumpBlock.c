// IoMarkTriageDumpBlock 
 
char *IoMarkTriageDumpBlock()
{
  unsigned int v0; // r6
  const void **v1; // r5
  char *result; // r0

  v0 = 0;
  if ( IopNumTriageDumpDataBlocks )
  {
    v1 = (const void **)&IopTriageDumpDataBlocks;
    do
    {
      result = PoSetHiberRange(0, 0x10000, *v1, (const void *)((_BYTE *)v1[1] - (_BYTE *)*v1), 1114664260);
      ++v0;
      v1 += 2;
    }
    while ( v0 < IopNumTriageDumpDataBlocks );
  }
  return result;
}
