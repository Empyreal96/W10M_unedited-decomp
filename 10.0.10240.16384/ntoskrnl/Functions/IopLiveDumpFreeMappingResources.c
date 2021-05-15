// IopLiveDumpFreeMappingResources 
 
unsigned int __fastcall IopLiveDumpFreeMappingResources(unsigned int result)
{
  unsigned int v1; // r4
  unsigned int v2; // r5
  _DWORD *v3; // r6
  int v4; // r0

  v1 = result;
  if ( *(_DWORD *)(result + 312) )
  {
    v2 = 0;
    if ( *(_DWORD *)(result + 308) )
    {
      do
      {
        v3 = (_DWORD *)(*(_DWORD *)(v1 + 312) + 8 * v2);
        if ( *v3 )
          MmReleaseDumpHibernateResources(*v3, 0x10000);
        v4 = v3[1];
        if ( v4 )
          IoFreeMdl(v4);
        ++v2;
      }
      while ( v2 < *(_DWORD *)(v1 + 308) );
    }
    result = ExFreePoolWithTag(*(_DWORD *)(v1 + 312));
    *(_DWORD *)(v1 + 308) = 0;
    *(_DWORD *)(v1 + 312) = 0;
  }
  return result;
}
