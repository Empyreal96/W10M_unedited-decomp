// KeSetAffinityProcess 
 
int __fastcall KeSetAffinityProcess(int a1, char a2, _DWORD *a3)
{
  int v3; // r10
  int v7; // r3
  unsigned int *v8; // r6
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r0
  int v12; // r2
  int v13; // r3
  int v14; // r4
  unsigned __int16 v15; // r7
  int v16; // r3
  _DWORD *i; // r4
  int *v18; // r2
  _DWORD *v19; // r5
  unsigned int v20; // r4
  unsigned int v21; // r0
  unsigned int v22; // r1
  unsigned int v23; // r1
  _DWORD *v24; // [sp+0h] [bp-60h] BYREF
  int v25; // [sp+4h] [bp-5Ch]
  unsigned int v26; // [sp+8h] [bp-58h]
  unsigned int v27; // [sp+Ch] [bp-54h]
  __int16 v28; // [sp+10h] [bp-50h]
  __int16 v29; // [sp+12h] [bp-4Eh]
  int v30; // [sp+14h] [bp-4Ch]
  int v31; // [sp+18h] [bp-48h]
  int v32; // [sp+20h] [bp-40h] BYREF
  int v33; // [sp+24h] [bp-3Ch]
  int v34; // [sp+28h] [bp-38h]
  int v35; // [sp+30h] [bp-30h] BYREF
  int v36; // [sp+34h] [bp-2Ch]
  int v37; // [sp+38h] [bp-28h]

  v35 = 0;
  v36 = 0;
  v37 = 0;
  v3 = 0;
  v24 = 0;
  v28 = 1;
  v29 = 1;
  v30 = 0;
  v31 = 0;
  v25 = 0;
  if ( (a2 & 3) != 0 )
    return sub_554BB8();
  v7 = a3[2];
  if ( v7 )
  {
    v36 = 0;
    v35 = v7;
    v37 = 0;
  }
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v26 = KfRaiseIrql(2);
  v27 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v8 = (unsigned int *)(a1 + 48);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1 + 48);
  }
  else
  {
    v9 = (unsigned __int8 *)(a1 + 51);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | 0x80, v9) );
    __dmb(0xBu);
    if ( v10 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(a1 + 48));
    while ( 1 )
    {
      v11 = *v8;
      if ( (*v8 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v11 & 0x40000000) == 0 )
      {
        do
          v23 = __ldrex(v8);
        while ( v23 == v11 && __strex(v11 | 0x40000000, v8) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v12 = a3[1];
  v13 = a3[2];
  *(_DWORD *)(a1 + 64) = *a3;
  *(_DWORD *)(a1 + 68) = v12;
  *(_DWORD *)(a1 + 72) = v13;
  v14 = 0;
  if ( *(_WORD *)a3 )
  {
    v15 = 0;
    do
    {
      v16 = a3[v14 + 2];
      if ( v16 )
      {
        KiSetIdealNodeProcessByGroup(a1, 0, v14, v16);
        if ( !v3 )
        {
          v3 = 1;
          *(_WORD *)(a1 + 114) = *(_WORD *)(a1 + 2 * v14 + 112);
        }
      }
      v14 = ++v15;
    }
    while ( v15 < (unsigned int)*(unsigned __int16 *)a3 );
  }
  for ( i = *(_DWORD **)(a1 + 40); i != (_DWORD *)(a1 + 40); i = (_DWORD *)*i )
  {
    LOWORD(v33) = *((_WORD *)i - 62);
    v32 = *(_DWORD *)(a1 + 4 * (unsigned __int16)v33 + 72);
    if ( v32 )
      v18 = &v32;
    else
      v18 = &v35;
    KiSetAffinityThread((int)(i - 117), (int)&v24, (int)v18);
  }
  if ( !v25 )
  {
    v19 = (_DWORD *)(a1 + 100);
    __pld(v19);
    v20 = *v19;
    do
    {
      v21 = v20;
      __dmb(0xBu);
      do
        v22 = __ldrex(v19);
      while ( v22 == v20 && __strex(v20 | 0x100, v19) );
      v20 = v22;
      __dmb(0xBu);
    }
    while ( v22 != v21 );
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v8);
  }
  else
  {
    __dmb(0xBu);
    *v8 = 0;
  }
  KiProcessDeferredReadyList(v27 + 1408, &v24, v26);
  return 0;
}
