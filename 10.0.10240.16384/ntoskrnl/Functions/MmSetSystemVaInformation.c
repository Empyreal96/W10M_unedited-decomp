// MmSetSystemVaInformation 
 
int __fastcall MmSetSystemVaInformation(int a1, unsigned int a2, char a3)
{
  int v5; // r4
  unsigned int v6; // r10
  unsigned int v7; // r9
  int v8; // r6
  unsigned int v9; // r1
  int *v10; // r6
  int *v11; // r0
  int v12; // lr
  unsigned int v13; // r2
  unsigned int v14; // r3
  int v15; // t1
  unsigned int v16; // r0
  int v17; // r0
  __int16 v18; // r3
  int v20[5]; // [sp+8h] [bp-94h] BYREF
  int v21; // [sp+1Ch] [bp-80h] BYREF
  int v22; // [sp+2Ch] [bp-70h] BYREF

  v20[0] = 5;
  v20[1] = 6;
  v20[2] = 8;
  v20[3] = 9;
  v20[4] = 1;
  if ( !SeSinglePrivilegeCheck(SeIncreaseQuotaPrivilege, dword_922794, a3, (int)&SeIncreaseQuotaPrivilege) )
    return -1073741727;
  if ( a2 < 0x60 )
    return -1073741820;
  if ( byte_634C8D == 1 )
    return -1073741431;
  v5 = 0;
  memmove((int)&v21, a1, 0x60u);
  v6 = -dword_63389C;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 310);
  v8 = KeAbPreAcquire((unsigned int)&dword_63378C, 0, 0);
  do
    v9 = __ldrex((unsigned __int8 *)&dword_63378C);
  while ( __strex(v9 | 1, (unsigned __int8 *)&dword_63378C) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_63378C, v8, (unsigned int)&dword_63378C);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v10 = v20;
  v11 = &v22;
  v12 = 5;
  do
  {
    v13 = v11[2];
    if ( v13 < v6 )
    {
      v14 = (v13 + 0x3FFFFF) & 0xFFC00000;
      v11[2] = v14;
    }
    else
    {
      v14 = 0;
      v11[2] = 0;
    }
    v15 = *v10++;
    MiState[v15 + 2566] = v14 >> 22;
    v11 += 4;
    --v12;
  }
  while ( v12 );
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&dword_63378C);
  while ( __strex(v16 - 1, (unsigned int *)&dword_63378C) );
  if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&dword_63378C);
  v17 = KeAbPostRelease((unsigned int)&dword_63378C);
  v18 = *(_WORD *)(v7 + 310) + 1;
  *(_WORD *)(v7 + 310) = v18;
  if ( !v18 && *(_DWORD *)(v7 + 100) != v7 + 100 )
    KiCheckForKernelApcDelivery(v17);
  return v5;
}
