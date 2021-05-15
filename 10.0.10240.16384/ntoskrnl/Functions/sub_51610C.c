// sub_51610C 
 
void sub_51610C(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int v6; // r4
  unsigned int v7; // r0
  unsigned int v8; // r10
  unsigned int v9; // r5
  int v10; // r0
  unsigned int *v11; // r1
  int v12; // r8
  unsigned int v13; // r3
  int v14; // r6
  int v15; // r0
  _DWORD *v16; // r5
  int v17; // r6
  unsigned __int8 *v18; // r1
  unsigned int v19; // r2
  int v20; // r3
  int v21; // r2
  int v22; // r3
  unsigned int *v23; // r2
  unsigned int v24; // r0
  unsigned int v25; // r0
  int v26; // r6
  unsigned int v27; // r5
  va_list v28; // r7
  int v29; // r8
  int v30; // t1
  _DWORD *v31; // r4
  unsigned int *v32; // r5
  unsigned int v33; // r1
  unsigned int *v34; // r2
  unsigned int v35; // r0
  int v36; // [sp+8h] [bp+8h] BYREF
  va_list va; // [sp+8h] [bp+8h]
  int v38; // [sp+Ch] [bp+Ch]
  _DWORD *v39; // [sp+10h] [bp+10h]
  int v40; // [sp+14h] [bp+14h]
  int v41; // [sp+18h] [bp+18h] BYREF
  va_list va1; // [sp+18h] [bp+18h]
  int v43; // [sp+1Ch] [bp+1Ch]
  va_list va2; // [sp+20h] [bp+20h] BYREF

  va_start(va2, a6);
  va_start(va1, a6);
  va_start(va, a6);
  v36 = va_arg(va1, _DWORD);
  v38 = va_arg(va1, _DWORD);
  v39 = va_arg(va1, _DWORD *);
  v40 = va_arg(va1, _DWORD);
  va_copy(va2, va1);
  v41 = va_arg(va2, _DWORD);
  v43 = va_arg(va2, _DWORD);
  v38 = *(unsigned __int16 *)(v6 + 114);
  v7 = ((int (*)(void))MiMakeOutswappedPageResident)();
  v8 = v7 >> 12;
  v9 = v7;
  v10 = MiMapPageInHyperSpaceWorker(v7 >> 12, (int)va, 0x80000000);
  v11 = (unsigned int *)(v10 + 3072);
  v12 = v10;
  if ( (unsigned int)(v10 + 1073744896) > 0x3FFFFF )
  {
    *v11 = v9;
  }
  else
  {
    v13 = *v11;
    v14 = 0;
    __dmb(0xBu);
    *v11 = v9;
    if ( (v13 & 2) == 0 && (v9 & 2) != 0 )
      v14 = 1;
    if ( (unsigned int)(v10 + 1070599168) <= 0xFFF )
    {
      v15 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v15, (_DWORD *)(v15 + 4 * ((unsigned __int16)v11 & 0xFFF)), v9);
    }
    if ( v14 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  MiUnmapPageInHyperSpaceWorker(v12, (unsigned __int8)v36, 0x80000000);
  v16 = (_DWORD *)(MmPfnDatabase + 24 * v8);
  v17 = KfRaiseIrql(2);
  v18 = (unsigned __int8 *)v16 + 15;
  do
    v19 = __ldrex(v18);
  while ( __strex(v19 | 0x80, v18) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v19 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v20 = v16[3];
      __dmb(0xBu);
    }
    while ( (v20 & 0x80000000) != 0 );
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 | 0x80, v18) );
  }
  v21 = v16[3];
  *v16 = v6;
  v22 = v16[5];
  v16[3] = v21 & 0xC0000000 | (v21 + 1) & 0x3FFFFFFF;
  v16[5] = v22 & 0xFFF00000 | v8 & 0xFFFFF;
  v16[1] = -1070593024;
  __dmb(0xBu);
  v23 = v16 + 3;
  do
    v24 = __ldrex(v23);
  while ( __strex(v24 & 0x7FFFFFFF, v23) );
  v25 = KfLowerIrql(v17);
  v26 = 2;
  v43 = -1070591992;
  v27 = v8;
  va_copy(v28, va1);
  v41 = -1070593020;
  v29 = 2;
  do
  {
    v30 = (int)*v28++;
    v25 = MiMakeOutswappedPageResident(v25, v30, v30 & 0xFFF, v27);
    v27 = v25 >> 12;
    *(_DWORD *)(MmPfnDatabase + 24 * (v25 >> 12)) = v26--;
    --v29;
  }
  while ( v29 );
  v31 = v39;
  v39[62] = v25 >> 12;
  v31[136] = 1;
  v31[137] = 1;
  v31[138] = 3;
  v31[139] = 3;
  MiReinitializeDirectoryTableBase(v31, v31 + 6, v8);
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)va2);
  if ( (v31[48] & 0x800000) != 0 )
  {
    v32 = v31 + 48;
    do
    {
      __dmb(0xBu);
      do
        v33 = __ldrex(v32);
      while ( __strex(v33 & 0xFF7FFFFF, v32) );
      __dmb(0xBu);
      KeReleaseInStackQueuedSpinLock((int)va2);
      MiUpdateSystemPdes(v31);
      KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)va2);
    }
    while ( (v31[48] & 0x800000) != 0 );
  }
  MiReturnWsToExpansionList(v31 + 123, 0);
  __dmb(0xBu);
  v34 = v31 + 48;
  do
    v35 = __ldrex(v34);
  while ( __strex(v35 & 0xFFFFFF7F, v34) );
  __dmb(0xBu);
  KeReleaseInStackQueuedSpinLock((int)va2);
  if ( (dword_682604 & 0x800) != 0 )
    EtwTraceInswapProcess(v31);
  JUMPOUT(0x435416);
}
