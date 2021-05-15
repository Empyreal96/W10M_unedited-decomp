// IopFreeReqList 
 
unsigned int __fastcall IopFreeReqList(unsigned int result)
{
  unsigned int v1; // r4
  unsigned int v2; // r6
  unsigned int v3; // r5

  v1 = result;
  if ( result )
  {
    v2 = 0;
    if ( *(_DWORD *)(result + 20) )
    {
      v3 = result;
      do
      {
        IopFreeReqAlternative(*(_DWORD *)(v3 + 24));
        *(_DWORD *)(v3 + 24) = 0;
        ++v2;
        v3 += 4;
      }
      while ( v2 < *(_DWORD *)(v1 + 20) );
    }
    result = ExFreePoolWithTag(v1);
  }
  return result;
}
