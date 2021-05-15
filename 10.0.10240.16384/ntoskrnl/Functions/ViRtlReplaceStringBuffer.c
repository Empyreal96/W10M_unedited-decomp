// ViRtlReplaceStringBuffer 
 
unsigned int __fastcall ViRtlReplaceStringBuffer(unsigned int result, _DWORD *a2)
{
  unsigned int v2; // r4
  unsigned int v3; // r6
  int v5; // r0
  int v6; // r5

  v2 = result;
  v3 = *(unsigned __int16 *)(result + 2);
  if ( (MmVerifierData & 9) != 0 && *(_WORD *)(result + 2) )
  {
    v5 = VeAllocatePoolWithTagPriority(129, v3, 1920226134, 32);
    v6 = v5;
    if ( v5 )
      memmove(v5, *(_DWORD *)(v2 + 4), v3);
    else
      *a2 = -1073741801;
    result = ExFreePoolWithTag(*(_DWORD *)(v2 + 4));
    *(_DWORD *)(v2 + 4) = v6;
  }
  return result;
}
