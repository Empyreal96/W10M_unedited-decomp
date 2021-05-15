// IoWriteErrorLogEntry 
 
int __fastcall IoWriteErrorLogEntry(int a1)
{
  int v1; // r6
  int v3; // r0
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r5

  v1 = a1 - 32;
  if ( !IopErrorLogDisabledThisBoot )
    return sub_55549C();
  v3 = *(_DWORD *)(a1 - 20);
  if ( v3 )
    ObfDereferenceObjectWithTag(v3);
  v4 = *(_DWORD *)(v1 + 16);
  if ( v4 )
    ObfDereferenceObjectWithTag(v4);
  __dmb(0xBu);
  v5 = -*(unsigned __int16 *)(v1 + 2);
  do
    v6 = __ldrex(&IopErrorLogAllocation);
  while ( __strex(v6 + v5, &IopErrorLogAllocation) );
  __dmb(0xBu);
  return ExFreePoolWithTag(v1, 0);
}
