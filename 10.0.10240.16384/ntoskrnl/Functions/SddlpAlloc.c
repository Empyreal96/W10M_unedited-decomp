// SddlpAlloc 
 
_BYTE *__fastcall SddlpAlloc(int a1)
{
  _BYTE *v2; // r0
  _BYTE *v3; // r4

  v2 = (_BYTE *)ExAllocatePoolWithTag(1, a1, 1683187027);
  v3 = v2;
  if ( v2 )
    memset(v2, 0, a1);
  return v3;
}
