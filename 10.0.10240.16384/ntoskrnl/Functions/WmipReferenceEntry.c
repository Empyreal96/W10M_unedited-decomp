// WmipReferenceEntry 
 
int __fastcall WmipReferenceEntry(int result)
{
  unsigned int *v1; // r2
  unsigned int v2; // r1
  signed int v3; // r1

  __dmb(0xBu);
  v1 = (unsigned int *)(result + 12);
  do
  {
    v2 = __ldrex(v1);
    v3 = v2 + 1;
  }
  while ( __strex(v3, v1) );
  __dmb(0xBu);
  if ( v3 <= 1 )
    sub_7D6458();
  return result;
}
