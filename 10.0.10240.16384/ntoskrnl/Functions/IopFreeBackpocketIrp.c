// IopFreeBackpocketIrp 
 
_DWORD *__fastcall IopFreeBackpocketIrp(_DWORD *result, char a2)
{
  int v2; // r5
  unsigned int v3; // r0
  char *v4; // r0
  unsigned int v5; // r1

  v2 = a2;
  if ( result == (_DWORD *)dword_631928 )
  {
    dword_631930 = 0;
    __dmb(0xBu);
    do
      v3 = __ldrex((unsigned int *)&dword_63192C);
    while ( __strex(0, (unsigned int *)&dword_63192C) );
    __dmb(0xBu);
    v4 = &byte_631934;
    return (_DWORD *)KeSetEvent((int)v4, v2, 0);
  }
  if ( result == (_DWORD *)dword_631944 )
  {
    dword_63194C = 0;
    __dmb(0xBu);
    do
      v5 = __ldrex((unsigned int *)&dword_631948);
    while ( __strex(0, (unsigned int *)&dword_631948) );
    __dmb(0xBu);
    v4 = &byte_631950;
    return (_DWORD *)KeSetEvent((int)v4, v2, 0);
  }
  *result = dword_631960;
  dword_631960 = (int)result;
  return result;
}
