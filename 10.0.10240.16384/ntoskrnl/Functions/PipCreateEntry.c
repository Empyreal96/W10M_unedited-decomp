// PipCreateEntry 
 
_BYTE *__fastcall PipCreateEntry(unsigned __int16 *a1)
{
  _BYTE *v2; // r0
  _BYTE *v3; // r4
  __int16 v4; // r3

  v2 = (_BYTE *)ExAllocatePoolWithTag(1, *a1 + 28, 1852403792);
  v3 = v2;
  if ( !v2 )
    return 0;
  memset(v2, 0, 28);
  *((_WORD *)v3 + 10) = *a1;
  v4 = *a1;
  *((_DWORD *)v3 + 6) = v3 + 28;
  *((_WORD *)v3 + 11) = v4;
  memmove((int)(v3 + 28), *((_DWORD *)a1 + 1), *a1);
  return v3;
}
