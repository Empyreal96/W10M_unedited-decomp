// RtlpAllocateAtom 
 
int __fastcall RtlpAllocateAtom(unsigned int a1, int a2)
{
  unsigned int v2; // r5
  int *v3; // r4
  int v4; // r0

  v2 = a1 + 8;
  if ( a1 + 8 < a1 )
    return 0;
  v3 = (int *)ExAllocatePoolWithTag(1, a1 + 8, a2);
  if ( !v3 )
    return (int)v3;
  v4 = PsChargeSharedPoolQuota(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v2, 0);
  *v3 = v4;
  if ( v4 )
  {
    v3[1] = v2;
    v3 += 2;
    return (int)v3;
  }
  return sub_7C03C8();
}
