// RtlFillMemory 
 
_BYTE *__fastcall RtlFillMemory(_BYTE *a1, int a2, int a3)
{
  return memset(a1, a3, a2);
}
