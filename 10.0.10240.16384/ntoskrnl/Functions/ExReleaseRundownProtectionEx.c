// ExReleaseRundownProtectionEx 
 
char *__fastcall ExReleaseRundownProtectionEx(char *result, char *a2)
{
  unsigned int v2; // r4
  unsigned int v3; // r5
  unsigned int *v4; // r4
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1

  __pld(result);
  v2 = *(_DWORD *)result;
  if ( (*(_DWORD *)result & 1) != 0 )
  {
LABEL_7:
    v4 = (unsigned int *)(v2 & 0xFFFFFFFE);
    __dmb(0xBu);
    do
      result = (char *)__ldrex(v4);
    while ( __strex(result - a2, v4) );
    __dmb(0xBu);
    if ( result == a2 )
    {
      __dmb(0xBu);
      v5 = (unsigned __int8 *)(v4 + 5);
      do
        v6 = __ldrex(v5);
      while ( __strex(v6 & 0xFE, v5) );
      __dmb(0xBu);
      if ( (v6 & 1) == 0 )
        result = (char *)KeSetEvent((int)(v4 + 1), 0, 0);
    }
  }
  else
  {
    while ( 1 )
    {
      __dmb(0xBu);
      do
        v3 = __ldrex((unsigned int *)result);
      while ( v3 == v2 && __strex(v2 - 2 * (_DWORD)a2, (unsigned int *)result) );
      __dmb(0xBu);
      if ( v3 == v2 )
        break;
      v2 = v3;
      if ( (v3 & 1) != 0 )
        goto LABEL_7;
    }
  }
  return result;
}
