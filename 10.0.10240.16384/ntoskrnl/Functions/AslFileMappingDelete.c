// AslFileMappingDelete 
 
unsigned int __fastcall AslFileMappingDelete(unsigned int result)
{
  unsigned int v1; // r4

  v1 = result;
  if ( result )
  {
    RtlFileMapFree((_BYTE *)(result + 520));
    if ( *(_DWORD *)(v1 + 556) )
    {
      result = sub_7CD3F4();
    }
    else
    {
      *(_DWORD *)(v1 + 556) = 0;
      result = ExFreePoolWithTag(v1);
    }
  }
  return result;
}
