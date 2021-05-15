// CmpInitializeHive 
 
int __fastcall CmpInitializeHive(int a1, unsigned int a2, int a3, unsigned int a4, _DWORD *a5, _DWORD *a6, int a7, int a8, int a9, int a10, _BYTE *a11, int *a12)
{
  int v12; // r5
  int v15; // r3
  unsigned int v16; // r0
  unsigned int v17; // r2
  unsigned int v18; // r1
  _BYTE *v19; // r0
  int v20; // r4
  void **v21; // r8
  int v22; // r0
  int v23; // r3
  _DWORD *v24; // r3
  _DWORD *v25; // r3
  _DWORD *v26; // r0
  int v27; // r10
  int v28; // r0
  int v29; // r1
  int v30; // r5
  int v31; // r0
  int v32; // r0
  int *v33; // r3
  unsigned int v34; // r0
  unsigned int v35; // r1
  int v36; // r0
  __int16 v37; // r3
  int v39; // r0
  void ***v40; // r1
  unsigned int v41; // [sp+20h] [bp-40h] BYREF
  unsigned int v42; // [sp+24h] [bp-3Ch]
  int v43; // [sp+28h] [bp-38h] BYREF
  int *v44; // [sp+2Ch] [bp-34h]
  int v45[12]; // [sp+30h] [bp-30h] BYREF

  v12 = a3;
  v43 = a3;
  v44 = (int *)a1;
  if ( a2 == 4 || a2 == 3 || a2 > 5 )
    JUMPOUT(0x7D3788);
  if ( (a3 & 0xFFF97CEC) != 0 )
    return sub_7D3558(a1, a2, a3, a4, (int)a5, (int)a6, a7, a8);
  if ( a4 > 2 )
    JUMPOUT(0x7D355C);
  if ( a2 == 1 && !a5 )
    JUMPOUT(0x7D3560);
  if ( a6 )
  {
    if ( (a3 & 1) != 0 )
      JUMPOUT(0x7D3564);
    if ( !*a6 )
      JUMPOUT(0x7D3570);
    if ( !a4 && a6[1] )
      JUMPOUT(0x7D3580);
    if ( a4 != 2 && a6[2] )
      JUMPOUT(0x7D3584);
    if ( a6[3] )
      JUMPOUT(0x7D3588);
  }
  v15 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v15 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v16 = CmpShutdownRundown & 0xFFFFFFFE;
  v17 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v18 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v18 == v16 && __strex(v17, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v18 != v16 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
    JUMPOUT(0x7D3596);
  v41 = 1;
  v42 = 1;
  if ( a6 && *a6 )
  {
    if ( CmpGetVolumeClusterSize(*a6, &v41) < 0 )
      JUMPOUT(0x7D35C6);
    v12 = v43;
    v42 = v41;
  }
  v19 = (_BYTE *)CmpAllocate(3872, 0, 808537411);
  v20 = (int)v19;
  if ( !v19 )
    JUMPOUT(0x7D35FA);
  memset(v19, 0, 3872);
  __dmb(0xBu);
  *(_DWORD *)(v20 + 3320) = 1;
  *(_DWORD *)(v20 + 2520) = 0;
  *(_DWORD *)(v20 + 2524) = 0;
  *(_DWORD *)(v20 + 2528) = 0;
  *(_BYTE *)(v20 + 2532) = 0;
  *(_DWORD *)(v20 + 2536) = 0;
  *(_BYTE *)(v20 + 2560) = 0;
  *(_DWORD *)(v20 + 2564) = 0;
  *(_DWORD *)(v20 + 3268) = 0;
  *(_DWORD *)(v20 + 3272) = 0;
  *(_DWORD *)(v20 + 3280) = 0;
  *(_DWORD *)(v20 + 3284) = 0;
  __dmb(0xBu);
  v21 = (void **)(v20 + 1808);
  *(_DWORD *)(v20 + 3856) = 0;
  *(_DWORD *)(v20 + 3860) = 0;
  *(_DWORD *)(v20 + 2568) = v20 + 2568;
  *(_DWORD *)(v20 + 2572) = v20 + 2568;
  *(_DWORD *)(v20 + 1808) = v20 + 1808;
  *(_DWORD *)(v20 + 1812) = v20 + 1808;
  *(_DWORD *)(v20 + 1832) = 0;
  *(_DWORD *)(v20 + 1836) = v20 + 1836;
  *(_DWORD *)(v20 + 1840) = v20 + 1836;
  *(_DWORD *)(v20 + 1844) = 0;
  *(_DWORD *)(v20 + 2584) = 16;
  *(_DWORD *)(v20 + 1848) = 0;
  *(_DWORD *)(v20 + 1860) = 0;
  *(_DWORD *)(v20 + 2576) = 0;
  __dmb(0xBu);
  *(_DWORD *)(v20 + 2580) = 0;
  *(_DWORD *)(v20 + 3256) = 0;
  *(_DWORD *)(v20 + 3260) = 0;
  *(_DWORD *)(v20 + 3264) = 0;
  v22 = ExAllocatePoolWithTag(512, 120, 942951747);
  if ( !v22 )
    JUMPOUT(0x7D366E);
  *(_DWORD *)(v20 + 1868) = v22 + 32;
  *(_DWORD *)(v20 + 1872) = v22 + 64;
  *(_DWORD *)(v20 + 1864) = v22;
  *(_DWORD *)(v20 + 1972) = 0;
  *(_WORD *)(v20 + 1968) = 0;
  *(_WORD *)(v20 + 1970) = 0;
  *(_DWORD *)(v20 + 1980) = 0;
  *(_WORD *)(v20 + 1976) = 0;
  *(_WORD *)(v20 + 1978) = 0;
  *(_DWORD *)(v20 + 1988) = 0;
  *(_WORD *)(v20 + 1984) = 0;
  *(_WORD *)(v20 + 1986) = 0;
  if ( !a6 )
  {
    *(_DWORD *)(v20 + 1776) = 0;
    *(_DWORD *)(v20 + 1784) = 0;
    *(_DWORD *)(v20 + 1788) = 0;
    goto LABEL_51;
  }
  *(_DWORD *)(v20 + 1776) = *a6;
  v23 = a6[3];
  *(_DWORD *)(v20 + 1788) = 0;
  *(_DWORD *)(v20 + 1784) = v23;
  if ( !a4 )
  {
LABEL_51:
    *(_DWORD *)(v20 + 1780) = 0;
LABEL_52:
    *(_DWORD *)(v20 + 1792) = 0;
    *(_DWORD *)(v20 + 1796) = 0;
    goto LABEL_28;
  }
  if ( a4 == 1 )
  {
    *(_DWORD *)(v20 + 1780) = a6[1];
    goto LABEL_52;
  }
  *(_DWORD *)(v20 + 1780) = 0;
  *(_DWORD *)(v20 + 1792) = a6[1];
  *(_DWORD *)(v20 + 1796) = a6[2];
LABEL_28:
  v24 = *(_DWORD **)(v20 + 1864);
  *(_DWORD *)(v20 + 1800) = 0;
  *(_DWORD *)(v20 + 1804) = 0;
  v24[1] = 0;
  v24[2] = 0;
  *v24 = 1;
  KeInitializeEvent((int)(v24 + 3), 1, 0);
  v25 = *(_DWORD **)(v20 + 1868);
  *v25 = 1;
  v25[1] = 0;
  v25[2] = 0;
  KeInitializeEvent((int)(v25 + 3), 1, 0);
  ExInitializeResourceLite(*(_DWORD *)(v20 + 1872));
  *(_DWORD *)(v20 + 3288) = 0;
  *(_DWORD *)(v20 + 3292) = 0;
  *(_DWORD *)(v20 + 3296) = 0;
  *(_DWORD *)(v20 + 3300) = 0;
  *(_DWORD *)(v20 + 3304) = 0;
  *(_DWORD *)(v20 + 3308) = 0;
  *(_DWORD *)(v20 + 3312) = 0;
  *(_DWORD *)(v20 + 1876) = 0;
  *(_DWORD *)(v20 + 1880) = 0;
  *(_DWORD *)(v20 + 1884) = 0;
  *(_DWORD *)(v20 + 1888) = 0;
  *(_DWORD *)(v20 + 1892) = 0;
  *(_DWORD *)(v20 + 1904) = 0;
  *(_DWORD *)(v20 + 1908) = 0;
  *(_DWORD *)(v20 + 1912) = 0;
  *(_DWORD *)(v20 + 1916) = 0;
  *(_DWORD *)(v20 + 1920) = 0;
  *(_DWORD *)(v20 + 1924) = 0;
  *(_DWORD *)(v20 + 1928) = 0;
  *(_DWORD *)(v20 + 1932) = 0;
  *(_DWORD *)(v20 + 3228) = 0;
  if ( (a8 & 0x8000000) != 0 )
    *(_DWORD *)(v20 + 3228) = 128;
  if ( a8 < 0 )
    JUMPOUT(0x7D367C);
  *(_DWORD *)(v20 + 3232) = v20 + 3232;
  *(_DWORD *)(v20 + 3236) = v20 + 3232;
  *(_DWORD *)(v20 + 1816) = v20 + 1816;
  *(_DWORD *)(v20 + 1820) = v20 + 1816;
  *(_DWORD *)(v20 + 3240) = 0;
  *(_DWORD *)(v20 + 3244) = 0;
  *(_DWORD *)(v20 + 3248) = 0;
  *(_DWORD *)(v20 + 3252) = 0;
  *(_DWORD *)(v20 + 1944) = 0;
  *(_DWORD *)(v20 + 1948) = 0;
  *(_DWORD *)(v20 + 1936) = 0;
  *(_DWORD *)(v20 + 1952) = 0;
  *(_DWORD *)(v20 + 1956) = 0;
  *(_DWORD *)(v20 + 1960) = 0;
  *(_DWORD *)(v20 + 1964) = 0;
  *(_DWORD *)(v20 + 3316) = 0;
  *(_DWORD *)(v20 + 3852) = 0;
  v26 = CmpInitSecurityCache((_DWORD *)v20);
  v45[0] = (int)CmpAllocate;
  v45[1] = (int)CmpFree;
  v45[3] = (int)CmpFileWrite;
  v45[4] = (int)CmpFileRead;
  *(_DWORD *)(v20 + 28) = a12;
  *a12 = v20;
  v43 = 0;
  if ( HvInitializeHive((int)v26, a2, v12, a4, a5, v45, v42, a7, a9, a10, a11, &v43) < 0 )
    JUMPOUT(0x7D368C);
  if ( a2 == 5 || a2 == 2 || a2 == 1 )
  {
    v27 = a8;
    if ( CmCheckRegistry((_DWORD *)v20, a8) )
      JUMPOUT(0x7D3708);
  }
  else
  {
    v27 = a8;
  }
  v28 = CmpReorganizeHive(v20, a7);
  CmpLockRegistry(v28, v29);
  CmpLockHiveFlusherShared(v20);
  CmpLockHiveWriter(v20);
  if ( a2 )
  {
    v30 = HvCheckAndUpdateHiveBackupTimeStamp(v20);
  }
  else
  {
    *(_BYTE *)(v20 + 123) = 1;
    v30 = 0;
  }
  CmpUnlockHiveWriter(v20);
  v31 = CmpUnlockHiveFlusher(v20);
  v32 = CmpUnlockRegistry(v31);
  if ( v30 < 0 )
    JUMPOUT(0x7D373E);
  if ( (v27 & 0x1000000) != 0 )
  {
    *v21 = v21;
    *(_DWORD *)(v20 + 1812) = v20 + 1808;
  }
  else
  {
    v39 = CmpLockHiveListExclusive(v32);
    v40 = (void ***)off_92078C;
    *v21 = &CmpHiveListHead;
    *(_DWORD *)(v20 + 1812) = v40;
    if ( *v40 != &CmpHiveListHead )
      JUMPOUT(0x7D3774);
    *v40 = v21;
    off_92078C = (void *)(v20 + 1808);
    CmpUnlockHiveList(v39);
  }
  v33 = v44;
  *(_DWORD *)(v20 + 28) = 0;
  *v33 = v20;
  __pld(&CmpShutdownRundown);
  v34 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v35 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v35 == v34 && __strex(v34 - 2, (unsigned int *)&CmpShutdownRundown) );
  if ( v35 != v34 )
    ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v37 = *(_WORD *)(v36 + 0x134) + 1;
  *(_WORD *)(v36 + 308) = v37;
  if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
    KiCheckForKernelApcDelivery(v36);
  if ( (dword_682608 & 0x1000000) != 0 )
    JUMPOUT(0x7D3778);
  return 0;
}
