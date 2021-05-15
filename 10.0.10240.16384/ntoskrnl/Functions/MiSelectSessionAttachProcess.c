// MiSelectSessionAttachProcess 
 
int *__fastcall MiSelectSessionAttachProcess(_DWORD *a1)
{
  int *v1; // r4
  int *v2; // r5

  if ( !a1[845] )
    return 0;
  if ( (a1[1] & 2) != 0 )
    return 0;
  v1 = (int *)a1[4];
  v2 = a1 + 4;
  if ( v1 == a1 + 4 )
    return 0;
  while ( (*((_BYTE *)v1 + 373) & 1) != 0
       || (*(v1 - 10) & 0xC00u) < 0xC00
       || (*((_BYTE *)v1 + 375) & 0xC0) == 128
       || !ObReferenceObjectSafeWithTag(v1 - 58, 1953261124) )
  {
    v1 = (int *)*v1;
    if ( v1 == v2 )
      return 0;
  }
  return v1 - 58;
}
