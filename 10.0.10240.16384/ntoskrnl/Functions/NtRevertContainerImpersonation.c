// NtRevertContainerImpersonation 
 
int NtRevertContainerImpersonation()
{
  int v0; // r4
  int v1; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v1 = *(_DWORD *)(v0 + 0x420);
  if ( !v1 )
    return -1073741823;
  if ( (v1 & 1) != 0 )
    KeSetThreadChargeOnlySchedulingGroup(v0, 0);
  ObfDereferenceObjectWithTag(*(_DWORD *)(v0 + 1056) & 0xFFFFFFFE);
  *(_DWORD *)(v0 + 1056) = 0;
  return 0;
}
