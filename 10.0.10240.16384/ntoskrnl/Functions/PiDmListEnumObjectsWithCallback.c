// PiDmListEnumObjectsWithCallback 
 
int __fastcall PiDmListEnumObjectsWithCallback(int a1, unsigned int *a2, int a3, int a4)
{
  int *v5; // r3
  int v6; // r0
  int v7; // r10
  _DWORD *v8; // r9
  int v9; // r6
  unsigned int v10; // r7
  unsigned int v11; // r4
  int v12; // r0
  unsigned int v13; // r4
  int v15; // r3
  _DWORD *v16; // r0
  int v17; // lr
  _DWORD *v18; // r4
  char *v19; // r3
  unsigned int *v20; // r2
  unsigned int v21; // r1
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  int v25; // r0
  unsigned int v26; // r1
  __int16 v27; // r3
  unsigned int v28; // r4
  int v29; // r8
  int (__fastcall *v30)(int, int, char *); // r9
  int *v31; // r5
  int v32; // t1
  int *v33; // r4
  int v34; // t1
  char v35[4]; // [sp+0h] [bp-30h] BYREF
  int *v36; // [sp+4h] [bp-2Ch]
  int v37; // [sp+8h] [bp-28h]
  int (__fastcall *v38)(int, int, char *); // [sp+Ch] [bp-24h]

  v37 = a4;
  v38 = (int (__fastcall *)(int, int, char *))a3;
  v5 = &PiDmListDefs[5 * a1];
  v6 = v5[1];
  v7 = 0;
  v36 = v5;
  v8 = (unsigned int *)((char *)a2 + v6);
  v9 = 0;
  v10 = 0;
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v11 + 308);
  v12 = KeAbPreAcquire((unsigned int)a2, 0, 0);
  do
    v13 = __ldrex(a2);
  while ( !v13 && __strex(0x11u, a2) );
  __dmb(0xBu);
  if ( v13 )
    return sub_7C61E8(v12);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  v15 = v8[2];
  if ( v15 )
  {
    v9 = ExAllocatePoolWithTag(1, 4 * v15, 1517317712);
    if ( v9 )
    {
      v16 = (_DWORD *)*v8;
      if ( (_DWORD *)*v8 != v8 )
      {
        v17 = (int)v36;
        v18 = (_DWORD *)v9;
        do
        {
          v19 = (char *)v16 - *(_DWORD *)(v17 + 12);
          *v18++ = v19;
          __dmb(0xBu);
          v20 = (unsigned int *)(v19 + 4);
          do
            v21 = __ldrex(v20);
          while ( __strex(v21 + 1, v20) );
          __dmb(0xBu);
          v16 = (_DWORD *)*v16;
          ++v10;
        }
        while ( v16 != v8 );
      }
    }
    else
    {
      v7 = -1073741670;
    }
  }
  __pld(a2);
  v22 = *a2;
  if ( (*a2 & 0xFFFFFFF0) > 0x10 )
    v23 = v22 - 16;
  else
    v23 = 0;
  if ( (v22 & 2) != 0 )
    goto LABEL_37;
  __dmb(0xBu);
  do
    v24 = __ldrex(a2);
  while ( v24 == v22 && __strex(v23, a2) );
  if ( v24 != v22 )
LABEL_37:
    ExfReleasePushLock(a2, v22);
  v25 = KeAbPostRelease((unsigned int)a2);
  v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v27 = *(_WORD *)(v26 + 0x134) + 1;
  *(_WORD *)(v26 + 308) = v27;
  if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
    KiCheckForKernelApcDelivery(v25);
  v28 = 0;
  if ( v10 )
  {
    v29 = v37;
    v30 = v38;
    v31 = (int *)v9;
    do
    {
      v32 = *v31++;
      v7 = v30(v32, v29, v35);
      if ( v7 < 0 )
        break;
      if ( v35[0] )
        break;
      ++v28;
    }
    while ( v28 < v10 );
  }
  if ( v9 )
  {
    if ( v10 )
    {
      v33 = (int *)v9;
      do
      {
        v34 = *v33++;
        PiDmObjectRelease(v34);
        --v10;
      }
      while ( v10 );
    }
    ExFreePoolWithTag(v9);
  }
  return v7;
}
