// IopFreeRelationList 
 
_DWORD *__fastcall IopFreeRelationList(_DWORD *result)
{
  _DWORD *v1; // r4

  v1 = result;
  if ( result )
  {
    if ( *result )
    {
      PipFreeDeviceObjectList();
      *v1 = 0;
    }
    result = (_DWORD *)ExFreePoolWithTag((unsigned int)v1);
  }
  return result;
}
