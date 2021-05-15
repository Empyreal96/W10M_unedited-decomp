// EtwpFreeGuidEntry 
 
unsigned int __fastcall EtwpFreeGuidEntry(_DWORD *a1)
{
  unsigned int result; // r0
  int v3; // r0
  unsigned int v4; // r1

  ObDereferenceSecurityDescriptor(a1[9], 1);
  if ( a1[86] )
    return sub_7E968C();
  v3 = a1[87];
  if ( v3 )
    PspDereferenceSiloObject(v3);
  result = ExFreePoolWithTag((unsigned int)a1);
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&EtwpCounters);
  while ( __strex(v4 - 1, (unsigned int *)&EtwpCounters) );
  __dmb(0xBu);
  return result;
}
