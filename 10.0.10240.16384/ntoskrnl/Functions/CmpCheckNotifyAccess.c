// CmpCheckNotifyAccess 
 
int __fastcall CmpCheckNotifyAccess(int a1, int a2, int a3)
{
  unsigned int *v3; // r5
  int v7; // r0
  int v8; // r6
  unsigned int v9; // r4
  int v11; // r0
  int v12; // r6
  int v13; // r1
  unsigned int v14; // r4
  unsigned int v15; // r2
  int v16; // [sp+18h] [bp-28h] BYREF
  int v17; // [sp+1Ch] [bp-24h] BYREF
  char v18[32]; // [sp+20h] [bp-20h] BYREF

  v3 = (unsigned int *)(a2 + 1928);
  v16 = 0;
  v7 = KeAbPreAcquire(a2 + 1928, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex(v3);
  while ( !v9 && __strex(0x11u, v3) );
  __dmb(0xBu);
  if ( v9 )
    ExfAcquirePushLockSharedEx(v3, v7, (unsigned int)v3);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  if ( !CmpFindSecurityCellCacheIndex(a2, *(_DWORD *)(a3 + 44), &v17) )
    return sub_7E7F90();
  v11 = SeAccessCheck(
          *(_DWORD *)(*(_DWORD *)(a2 + 2004) + 8 * v17 + 4) + 24,
          a1 + 28,
          0,
          16,
          0,
          0,
          (int)CmKeyObjectType + 52,
          1,
          (int)&v16,
          (int)v18);
  __pld(v3);
  v12 = v11;
  v13 = *v3;
  if ( (*v3 & 0xFFFFFFF0) > 0x10 )
    v14 = v13 - 16;
  else
    v14 = 0;
  if ( (v13 & 2) != 0 )
    goto LABEL_19;
  __dmb(0xBu);
  do
    v15 = __ldrex(v3);
  while ( v15 == v13 && __strex(v14, v3) );
  if ( v15 != v13 )
LABEL_19:
    ExfReleasePushLock(v3, v13);
  KeAbPostRelease((unsigned int)v3);
  return v12;
}
