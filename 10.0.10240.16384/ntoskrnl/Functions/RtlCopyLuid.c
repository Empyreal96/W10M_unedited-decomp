// RtlCopyLuid 
 
_DWORD *__fastcall RtlCopyLuid(_DWORD *result, _DWORD *a2)
{
  *result = *a2;
  result[1] = a2[1];
  return result;
}
