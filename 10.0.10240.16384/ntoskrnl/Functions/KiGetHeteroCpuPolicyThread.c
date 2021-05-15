// KiGetHeteroCpuPolicyThread 
 
int __fastcall KiGetHeteroCpuPolicyThread(int a1, unsigned int a2)
{
  int result; // r0
  unsigned int v4; // r5
  int v5; // r0
  int v6; // r1
  int v7; // r3
  BOOL v8; // r3
  unsigned int v9; // r1

  result = *(unsigned __int8 *)(a1 + 85);
  v4 = a2;
  if ( result < 5 )
    return result;
  if ( (KiDynamicHeteroCpuPolicyMask & 1) == 0 || *(_BYTE *)(*(_DWORD *)(a1 + 336) + 606) != 2 )
  {
    if ( (KiDynamicHeteroCpuPolicyMask & 2) == 0 )
      return KiDefaultDynamicHeteroCpuPolicy;
    v5 = *(char *)(a1 + 123);
    if ( v5 < 16 && *(_DWORD *)(a1 + 68) )
    {
      if ( !a2 )
        v4 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
      v6 = *(_DWORD *)(a1 + 68);
      if ( !v6 || (v7 = *(_DWORD *)(v4 + 2352) + v6) == 0 )
      {
LABEL_15:
        if ( v5 >= KiDynamicHeteroCpuPolicyImportantPriority )
          goto LABEL_16;
        return KiDefaultDynamicHeteroCpuPolicy;
      }
      v8 = (*(_BYTE *)(v7 + 92) & 8) != 0;
    }
    else
    {
      v8 = 0;
    }
    if ( v8 )
      v5 = 1;
    goto LABEL_15;
  }
  if ( (KiDynamicHeteroCpuPolicyMask & 4) == 0 )
    goto LABEL_21;
LABEL_16:
  v9 = *(_DWORD *)(a1 + 56);
  if ( v9 <= *(_DWORD *)(a1 + 60) )
    v9 = *(_DWORD *)(a1 + 60);
  if ( v9 < KiDynamicHeteroCpuPolicyExpectedCycles )
    result = KiDynamicHeteroCpuPolicyImportantShort;
  else
LABEL_21:
    result = KiDynamicHeteroCpuPolicyImportant;
  return result;
}
