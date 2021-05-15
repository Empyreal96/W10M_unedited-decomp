// RtlZeroMemory 
 
_BYTE *__fastcall RtlZeroMemory(_BYTE *a1, int a2)
{
  return memset(a1, 0, a2);
}
