// -CompareLangIDs@@YAHPBX0@Z 
 
int __fastcall CompareLangIDs(const void *a1, const void *a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r2

  v2 = *(unsigned __int16 *)a1;
  v3 = *(unsigned __int16 *)a2;
  if ( v2 == v3 )
    return 0;
  if ( v2 > v3 )
    return 1;
  return -1;
}
