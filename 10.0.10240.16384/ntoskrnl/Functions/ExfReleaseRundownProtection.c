// ExfReleaseRundownProtection 
 
unsigned __int8 *__fastcall ExfReleaseRundownProtection(unsigned __int8 *result)
{
  unsigned int v1; // r1
  unsigned int v2; // r4
  unsigned int v3; // r2
  unsigned int v4; // r2
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1

  __pld(result);
  v1 = *(_DWORD *)result;
  if ( (*(_DWORD *)result & 1) != 0 )
  {
LABEL_7:
    result = (unsigned __int8 *)(v1 & 0xFFFFFFFE);
    __dmb(0xBu);
    do
    {
      v3 = __ldrex((unsigned int *)result);
      v4 = v3 - 1;
    }
    while ( __strex(v4, (unsigned int *)result) );
    __dmb(0xBu);
    if ( !v4 )
    {
      __dmb(0xBu);
      v5 = result + 20;
      do
        v6 = __ldrex(v5);
      while ( __strex(v6 & 0xFE, v5) );
      __dmb(0xBu);
      if ( (v6 & 1) == 0 )
        result = (unsigned __int8 *)KeSetEvent((int)(result + 4), 0, 0);
    }
  }
  else
  {
    while ( 1 )
    {
      __dmb(0xBu);
      do
        v2 = __ldrex((unsigned int *)result);
      while ( v2 == v1 && __strex(v1 - 2, (unsigned int *)result) );
      __dmb(0xBu);
      if ( v2 == v1 )
        break;
      v1 = v2;
      if ( (v2 & 1) != 0 )
        goto LABEL_7;
    }
  }
  return result;
}
