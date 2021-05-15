// IoFreeErrorLogEntry 
 
int __fastcall IoFreeErrorLogEntry(int a1)
{
  int v2; // r0
  int v3; // r0
  int v4; // r4
  unsigned int v5; // r0

  v2 = *(_DWORD *)(a1 - 20);
  if ( v2 )
    ObfDereferenceObjectWithTag(v2);
  v3 = *(_DWORD *)(a1 - 16);
  if ( v3 )
    ObfDereferenceObjectWithTag(v3);
  __dmb(0xBu);
  v4 = -*(unsigned __int16 *)(a1 - 30);
  do
    v5 = __ldrex(&IopErrorLogAllocation);
  while ( __strex(v5 + v4, &IopErrorLogAllocation) );
  __dmb(0xBu);
  return ExFreePoolWithTag(a1 - 32);
}
