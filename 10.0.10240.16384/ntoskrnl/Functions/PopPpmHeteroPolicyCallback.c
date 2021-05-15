// PopPpmHeteroPolicyCallback 
 
int __fastcall PopPpmHeteroPolicyCallback(unsigned int a1, int *a2, int a3, int a4)
{
  int v6; // r4
  int v7; // r0
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  HIWORD(v9[0]) = HIWORD(a3);
  v9[1] = a4;
  LOWORD(v9[0]) = 0;
  if ( memcmp((unsigned int)&GUID_PROCESSOR_HETEROGENEOUS_POLICY, a1, 16) || a3 != 4 || !a2 )
    return -1073741811;
  v6 = *a2;
  v7 = PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  if ( v6 == PpmHeteroPolicy )
    return sub_81C448(v7);
  PpmHeteroPolicy = v6;
  v9[0] |= 0x20u;
  PpmReapplyPerfPolicy(v9);
  return 0;
}
