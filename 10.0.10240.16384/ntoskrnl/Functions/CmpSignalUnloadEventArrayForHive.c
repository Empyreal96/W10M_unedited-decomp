// CmpSignalUnloadEventArrayForHive 
 
unsigned int __fastcall CmpSignalUnloadEventArrayForHive(unsigned int result)
{
  unsigned int v1; // r5
  unsigned int i; // r4

  v1 = 0;
  for ( i = result; v1 < *(_DWORD *)(i + 2520); ++v1 )
  {
    KeSetEvent(*(_DWORD *)(*(_DWORD *)(i + 2524) + 4 * v1), 0, 0);
    result = ObfDereferenceObject(*(_DWORD *)(*(_DWORD *)(i + 2524) + 4 * v1));
  }
  if ( *(_DWORD *)(i + 2520) )
    result = ExFreePoolWithTag(*(_DWORD *)(i + 2524));
  return result;
}
