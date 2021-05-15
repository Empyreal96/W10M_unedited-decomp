// SeComputeAutoInheritByObjectTypeEx 
 
int __fastcall SeComputeAutoInheritByObjectTypeEx(int a1, int a2, int a3, int *a4, _DWORD *a5)
{
  int v5; // r6
  int v8; // r9
  int v9; // r3
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  int v13; // r1
  int *v14; // r2
  int v15; // t1
  int *v16; // r3
  int v17; // r2
  int result; // r0
  unsigned int v19; // r2
  int v20; // r0
  unsigned int v21; // r1
  __int16 v22; // r3
  int v23; // r0
  unsigned __int8 *v24; // r0
  int v25; // r3

  v5 = 0;
  v8 = 0;
  if ( a5 )
  {
    if ( *a5 != 8 )
      return -1073741811;
    a5[1] = -1;
  }
  v9 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v9 & 0xFFFFFFC0) + 0x134);
  v10 = KeAbPreAcquire(&SepMandatoryObjectTypePolicyLock, 0, 0);
  v11 = v10;
  do
    v12 = __ldrex((unsigned int *)&SepMandatoryObjectTypePolicyLock);
  while ( !v12 && __strex(0x11u, (unsigned int *)&SepMandatoryObjectTypePolicyLock) );
  __dmb(0xBu);
  if ( v12 )
    ExfAcquirePushLockSharedEx(&SepMandatoryObjectTypePolicyLock, v10, &SepMandatoryObjectTypePolicyLock);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  v13 = 0;
  if ( !SepMandatoryObjectTypePolicyCount )
    goto LABEL_20;
  v14 = SepMandatoryObjectTypePolicy;
  while ( 1 )
  {
    v15 = *v14;
    v14 += 5;
    if ( a1 == v15 )
      break;
    if ( ++v13 >= (unsigned int)SepMandatoryObjectTypePolicyCount )
      goto LABEL_20;
  }
  v16 = &SepMandatoryObjectTypePolicy[5 * v13];
  v17 = v16[1];
  if ( (v17 & 1) != 0 )
  {
    v5 = v16[3];
    v8 = v16[2];
  }
  if ( (v17 & 2) != 0 )
    return sub_52CFDC();
LABEL_20:
  __dmb(0xBu);
  do
    v19 = __ldrex((unsigned int *)&SepMandatoryObjectTypePolicyLock);
  while ( v19 == 17 && __strex(0, (unsigned int *)&SepMandatoryObjectTypePolicyLock) );
  if ( v19 != 17 )
    ExfReleasePushLockShared(&SepMandatoryObjectTypePolicyLock, 0);
  v20 = KeAbPostRelease(&SepMandatoryObjectTypePolicyLock);
  v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v22 = *(_WORD *)(v21 + 0x134) + 1;
  *(_WORD *)(v21 + 308) = v22;
  if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
    KiCheckForKernelApcDelivery(v20);
  if ( a2 && v8 )
  {
    if ( (*(_WORD *)(a2 + 2) & 0x10) != 0 )
    {
      if ( (*(_WORD *)(a2 + 2) & 0x8000) != 0 )
      {
        v25 = *(_DWORD *)(a2 + 12);
        v23 = v25 ? v25 + a2 : 0;
      }
      else
      {
        v23 = *(_DWORD *)(a2 + 12);
      }
    }
    else
    {
      v23 = 0;
    }
    v24 = RtlFindAceByType(v23, 17, 0);
    if ( v24 )
    {
      v5 = 0;
      *((_DWORD *)v24 + 1) |= v8;
    }
  }
  if ( a3 )
  {
    if ( (!a2 || (*(_WORD *)(a2 + 2) & 4) == 0) && (*(_WORD *)(a3 + 2) & 0x400) != 0 )
      v5 |= 1u;
    if ( (!a2 || (*(_WORD *)(a2 + 2) & 0x10) == 0) && (*(_WORD *)(a3 + 2) & 0x800) != 0 )
      v5 |= 2u;
  }
  result = 0;
  *a4 = v5;
  return result;
}
