// CmpGetMappingHiveForString 
 
int __fastcall CmpGetMappingHiveForString(unsigned __int16 *a1, _DWORD *a2)
{
  int v3; // r6
  int v4; // r4
  int v5; // r1
  unsigned int v6; // r2
  unsigned int v7; // r7
  int v8; // r8
  unsigned int v9; // r2
  unsigned __int16 *v10; // r4
  unsigned int v11; // r4
  unsigned __int16 *v12; // r6
  unsigned int v13; // r1
  int v15; // r3
  unsigned int v16; // [sp+0h] [bp-28h]
  int v18; // [sp+8h] [bp-20h]

  v3 = 0;
  v16 = CmpComputeHashKey(0, a1);
  v4 = KeAbPreAcquire((unsigned int)&CmpSIDMappingLock, 0, 0);
  v5 = KfRaiseIrql(1);
  v18 = v5;
  do
    v6 = __ldrex((unsigned __int8 *)&CmpSIDMappingLock);
  while ( __strex(v6 & 0xFE, (unsigned __int8 *)&CmpSIDMappingLock) );
  __dmb(0xBu);
  if ( (v6 & 1) == 0 )
  {
    ExpAcquireFastMutexContended((int)&CmpSIDMappingLock, v4);
    v5 = v18;
  }
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  dword_6323C4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = CmpSIDToHiveMappingCount;
  v8 = CmpSIDToHiveMapping;
  dword_6323DC = v5;
  if ( CmSIDMappingCacheHit >= 0 )
  {
    v9 = v16;
    if ( CmSIDMappingCacheHit >= CmpSIDToHiveMappingCount )
      goto LABEL_14;
    v10 = (unsigned __int16 *)(CmpSIDToHiveMapping + 16 * CmSIDMappingCacheHit);
    if ( *((_DWORD *)v10 + 2) != v16 )
      goto LABEL_14;
    if ( *v10 == *a1 && !CmpCompareUnicodeString(v10, a1, 0) )
    {
      *a2 = *((_DWORD *)v10 + 3);
      goto LABEL_22;
    }
  }
  v9 = v16;
LABEL_14:
  v11 = 0;
  if ( v7 )
  {
    v12 = (unsigned __int16 *)v8;
    do
    {
      if ( *((_DWORD *)v12 + 2) == v9 )
      {
        if ( *v12 == *a1 && !CmpCompareUnicodeString(v12, a1, 0) )
        {
          v15 = *(_DWORD *)(v8 + 16 * v11 + 12);
          CmSIDMappingCacheHit = v11;
          v3 = 0;
          *a2 = v15;
          goto LABEL_22;
        }
        v9 = v16;
      }
      ++v11;
      v12 += 8;
    }
    while ( v11 < v7 );
  }
  v3 = -1073741275;
LABEL_22:
  dword_6323C4 = 0;
  __dmb(0xBu);
  do
    v13 = __ldrex(&CmpSIDMappingLock);
  while ( !v13 && __strex(1u, &CmpSIDMappingLock) );
  if ( v13 )
    ExpReleaseFastMutexContended(&CmpSIDMappingLock, v13);
  KfLowerIrql((unsigned __int8)v18);
  KeAbPostRelease((unsigned int)&CmpSIDMappingLock);
  return v3;
}
