// SeRegisterObjectTypeMandatoryPolicy 
 
int __fastcall SeRegisterObjectTypeMandatoryPolicy(int a1, int a2)
{
  int v4; // r8
  unsigned int v5; // r2
  int v6; // r0
  unsigned int v7; // r2
  unsigned int v9; // r2
  int v10; // r1
  int *v11; // r4
  int v12; // t1
  int *v13; // r3
  int *v14; // r2
  int v15; // r3
  int v16; // r4
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r1
  int v20; // r3

  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire(&SepMandatoryObjectTypePolicyLock, 0, 0);
  do
    v7 = __ldrex((unsigned __int8 *)&SepMandatoryObjectTypePolicyLock);
  while ( __strex(v7 | 1, (unsigned __int8 *)&SepMandatoryObjectTypePolicyLock) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    return sub_50B53C(v6);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v9 = 0;
  v10 = SepMandatoryObjectTypePolicyCount;
  if ( !SepMandatoryObjectTypePolicyCount )
    goto LABEL_13;
  v11 = SepMandatoryObjectTypePolicy;
  while ( 1 )
  {
    v12 = *v11;
    v11 += 5;
    if ( a1 == v12 )
      break;
    if ( ++v9 >= SepMandatoryObjectTypePolicyCount )
      goto LABEL_11;
  }
  v4 = 1;
LABEL_11:
  if ( v9 < 0x20 )
  {
    if ( v4 )
    {
LABEL_14:
      v14 = &SepMandatoryObjectTypePolicy[5 * v9];
      v15 = v14[1];
      v14[2] = a2;
      v14[1] = v15 | 1;
      if ( (a2 & 1) != 0 )
        v14[3] |= 0x100u;
      if ( (a2 & 2) != 0 )
        v14[3] |= 0x200u;
      if ( (a2 & 4) != 0 )
        v14[3] |= 0x400u;
      v16 = 0;
      goto LABEL_21;
    }
LABEL_13:
    SepMandatoryObjectTypePolicy[5 * v9] = a1;
    v13 = &SepMandatoryObjectTypePolicy[5 * v9];
    v13[3] = 0;
    v13[1] = 0;
    SepMandatoryObjectTypePolicyCount = v10 + 1;
    goto LABEL_14;
  }
  v16 = -1073741823;
LABEL_21:
  __dmb(0xBu);
  do
    v17 = __ldrex((unsigned int *)&SepMandatoryObjectTypePolicyLock);
  while ( __strex(v17 - 1, (unsigned int *)&SepMandatoryObjectTypePolicyLock) );
  if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
    ExfTryToWakePushLock(&SepMandatoryObjectTypePolicyLock);
  v18 = KeAbPostRelease(&SepMandatoryObjectTypePolicyLock);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = (__int16)(*(_WORD *)(v19 + 0x134) + 1);
  *(_WORD *)(v19 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
    KiCheckForKernelApcDelivery(v18);
  return v16;
}
