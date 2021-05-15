// MiReturnResidentAvailable 
 
unsigned int *__fastcall MiReturnResidentAvailable(int a1)
{
  unsigned int v2; // r3
  unsigned int *result; // r0
  int v4; // r1
  unsigned int v5; // r6
  unsigned int v6; // r2

  v2 = (unsigned int)KeGetPcr();
  result = (unsigned int *)((v2 & 0xFFFFF000) + 4992);
  v4 = *(_DWORD *)((v2 & 0xFFFFF000) + 0x1380);
  if ( v4 == -1 )
  {
    do
LABEL_9:
      result = (unsigned int *)__ldrex((unsigned int *)&dword_640600);
    while ( __strex((unsigned int)result + a1, (unsigned int *)&dword_640600) );
    return result;
  }
  if ( (unsigned int)(v4 + a1) > 0x100 )
  {
    if ( v4 > 192 )
    {
      do
        v6 = __ldrex(result);
      while ( v6 == v4 && __strex(0xC0u, result) );
      if ( v6 == v4 )
        a1 = v4 + a1 - 192;
    }
    goto LABEL_9;
  }
  do
    v5 = __ldrex(result);
  while ( v5 == v4 && __strex(v4 + a1, result) );
  if ( v5 != v4 )
    result = (unsigned int *)sub_50E668();
  return result;
}
