// PsImpersonateContainerOfThread 
 
signed int __fastcall PsImpersonateContainerOfThread(int a1)
{
  signed int result; // r0
  unsigned int v3; // r5
  int v4; // r3
  int v5; // r1

  result = ObfReferenceObjectWithTag(a1);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_DWORD *)(v3 + 0x420) )
    return sub_5273F4(result);
  *(_DWORD *)(v3 + 1056) = a1 | 1;
  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 336) + 288);
  __dmb(0xBu);
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 536);
    if ( v5 )
      result = KeSetThreadChargeOnlySchedulingGroup(v3, v5);
  }
  return result;
}
