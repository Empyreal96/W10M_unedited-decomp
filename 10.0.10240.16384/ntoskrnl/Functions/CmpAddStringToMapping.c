// CmpAddStringToMapping 
 
int __fastcall CmpAddStringToMapping(unsigned __int16 *a1, int a2)
{
  int v3; // r6
  int v4; // r5
  int v5; // r0
  unsigned int v6; // r2
  int v8; // r0
  int v9; // r0
  unsigned __int8 v10; // r5
  unsigned int v11; // r1
  unsigned int v12; // r8

  v3 = 0;
  v4 = KeAbPreAcquire((unsigned int)&CmpSIDMappingLock, 0, 0);
  v5 = KfRaiseIrql(1);
  do
    v6 = __ldrex((unsigned __int8 *)&CmpSIDMappingLock);
  while ( __strex(v6 & 0xFE, (unsigned __int8 *)&CmpSIDMappingLock) );
  __dmb(0xBu);
  if ( (v6 & 1) == 0 )
    return sub_7EA7DC(v5);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  dword_6323C4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_6323DC = v5;
  if ( CmpSIDToHiveMappingCount != -1 )
  {
    if ( CmpSIDToHiveMappingCount + 1 >= (unsigned int)CmpSIDToHiveMappingSize )
    {
      v12 = CmpSIDToHiveMapping;
      v8 = ExAllocatePoolWithTag(1, 16 * (CmpSIDToHiveMappingSize + 4), 1700154691);
      CmpSIDToHiveMapping = v8;
      if ( !v8 )
      {
        CmpSIDToHiveMapping = v12;
LABEL_21:
        v3 = -1073741670;
        goto LABEL_12;
      }
      CmpSIDToHiveMappingSize += 4;
      if ( !v12 )
      {
LABEL_10:
        *(_DWORD *)(v8 + 16 * CmpSIDToHiveMappingCount + 12) = a2;
        *(_WORD *)(16 * CmpSIDToHiveMappingCount + CmpSIDToHiveMapping) = *a1;
        *(_WORD *)(CmpSIDToHiveMapping + 16 * CmpSIDToHiveMappingCount + 2) = *a1;
        *(_DWORD *)(CmpSIDToHiveMapping + 16 * CmpSIDToHiveMappingCount + 4) = ExAllocatePoolWithTag(1, *a1, 1700154691);
        v9 = *(_DWORD *)(CmpSIDToHiveMapping + 16 * CmpSIDToHiveMappingCount + 4);
        if ( v9 )
        {
          memmove(v9, *((_DWORD *)a1 + 1), *a1);
          *(_DWORD *)(CmpSIDToHiveMapping + 16 * CmpSIDToHiveMappingCount++ + 8) = CmpComputeHashKey(0, a1);
          goto LABEL_12;
        }
        goto LABEL_21;
      }
      memmove(v8, v12, 16 * CmpSIDToHiveMappingCount);
      ExFreePoolWithTag(v12);
    }
    v8 = CmpSIDToHiveMapping;
    goto LABEL_10;
  }
  v3 = -1073741675;
LABEL_12:
  dword_6323C4 = 0;
  v10 = dword_6323DC;
  __dmb(0xBu);
  do
    v11 = __ldrex(&CmpSIDMappingLock);
  while ( !v11 && __strex(1u, &CmpSIDMappingLock) );
  if ( v11 )
    ExpReleaseFastMutexContended(&CmpSIDMappingLock, v11);
  KfLowerIrql(v10);
  KeAbPostRelease((unsigned int)&CmpSIDMappingLock);
  return v3;
}
