// PsImpersonateContainerOfProcess 
 
signed int __fastcall PsImpersonateContainerOfProcess(int a1)
{
  signed int result; // r0
  unsigned int v3; // r6
  int v4; // r4
  int v5; // r3

  result = ObfReferenceObjectWithTag(a1);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_DWORD *)(v3 + 0x420) )
  {
    v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v5 = *(_DWORD *)(v4 + 0x420);
    if ( v5 )
    {
      if ( (v5 & 1) != 0 )
        KeSetThreadChargeOnlySchedulingGroup(v4, 0);
      result = ObfDereferenceObjectWithTag(*(_DWORD *)(v4 + 1056) & 0xFFFFFFFE);
      *(_DWORD *)(v4 + 1056) = 0;
    }
  }
  *(_DWORD *)(v3 + 1056) = a1;
  return result;
}
