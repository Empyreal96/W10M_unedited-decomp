// MiDeletePageFileSectionNodes 
 
unsigned int __fastcall MiDeletePageFileSectionNodes(unsigned int result)
{
  int v1; // r4

  v1 = result + 80;
  do
  {
    if ( *(_DWORD *)(v1 + 4) )
    {
      MiUpdatePageFileSectionList(v1, 0);
      result = ExFreePoolWithTag(*(_DWORD *)(v1 + 4));
    }
    v1 = *(_DWORD *)(v1 + 8);
  }
  while ( v1 );
  return result;
}
