// PpmProfileAcDcUpdate 
 
int __fastcall PpmProfileAcDcUpdate(int a1, int a2, unsigned int a3, int a4)
{
  int v4; // r7
  int v5; // r9
  unsigned int v6; // r2
  int v7; // r0
  unsigned int v8; // r2
  int v10; // r5
  int *v11; // r0
  int v12; // r1
  int v13; // r3
  unsigned int v14; // [sp+0h] [bp-20h] BYREF
  int v15; // [sp+4h] [bp-1Ch]

  v14 = a3;
  v15 = a4;
  v4 = 0;
  v5 = 0;
  PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = KeAbPreAcquire((unsigned int)&PpmIdlePolicyLock, 0, 0);
  do
    v8 = __ldrex((unsigned __int8 *)&PpmIdlePolicyLock);
  while ( __strex(v8 | 1, (unsigned __int8 *)&PpmIdlePolicyLock) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    return sub_81B198(v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  dword_61E89C = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = 2;
  v11 = PpmCurrentProfile;
  do
  {
    v12 = v11[53] | v4;
    v5 |= v11[52] | v11[8];
    v13 = v11[9];
    v11 += 2;
    --v10;
    v4 = v12 | v13;
  }
  while ( v10 );
  v15 = v4 & 0x3FF;
  v14 = v5 & 0xD8030FC0;
  return PpmCompareAndApplyPolicySettings(&v14);
}
