// CmpRemoveHiveFromMapping 
 
unsigned int __fastcall CmpRemoveHiveFromMapping(int a1)
{
  int v2; // r5
  int v3; // r0
  unsigned __int8 v4; // r6
  unsigned int v5; // r2
  unsigned int v6; // r5
  int v7; // r2
  unsigned int v8; // r0
  unsigned int v9; // r1

  v2 = KeAbPreAcquire((unsigned int)&CmpSIDMappingLock, 0, 0);
  v3 = KfRaiseIrql(1);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&CmpSIDMappingLock);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)&CmpSIDMappingLock) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    return sub_7D14DC();
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_6323C4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = 0;
  dword_6323DC = v3;
  if ( CmpSIDToHiveMappingCount )
  {
    v7 = CmpSIDToHiveMapping;
    while ( *(_DWORD *)(v7 + 12) != a1 )
    {
      ++v6;
      v7 += 16;
      if ( v6 >= CmpSIDToHiveMappingCount )
        goto LABEL_12;
    }
    v8 = *(_DWORD *)(CmpSIDToHiveMapping + 16 * v6 + 4);
    --CmpSIDToHiveMappingCount;
    ExFreePoolWithTag(v8);
    memmove(CmpSIDToHiveMapping + 16 * v6, CmpSIDToHiveMapping + 16 * v6 + 16, 16 * (CmpSIDToHiveMappingCount - v6));
    v4 = dword_6323DC;
  }
LABEL_12:
  dword_6323C4 = 0;
  __dmb(0xBu);
  do
    v9 = __ldrex(&CmpSIDMappingLock);
  while ( !v9 && __strex(1u, &CmpSIDMappingLock) );
  if ( v9 )
    ExpReleaseFastMutexContended(&CmpSIDMappingLock, v9);
  KfLowerIrql(v4);
  return KeAbPostRelease((unsigned int)&CmpSIDMappingLock);
}
