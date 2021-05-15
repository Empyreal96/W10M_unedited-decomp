// KiStartProfileTarget 
 
int __fastcall KiStartProfileTarget(int *a1)
{
  int v2; // r4
  int v3; // r7
  unsigned int *v4; // r2
  unsigned int v5; // r1
  unsigned int v6; // r1
  int v7; // r3
  int *v8; // r1
  int **v9; // r0
  int v10; // r2
  int v11; // r1
  int v12; // r0
  unsigned int v13; // r0
  unsigned int v14; // r2
  int v15; // r3
  int v16; // r3
  unsigned int *v17; // r1
  unsigned int v18; // r2
  unsigned int v19; // r1

  v2 = *a1;
  v3 = KfRaiseIrql((unsigned __int8)KiProfileIrql);
  __dmb(0xBu);
  v4 = (unsigned int *)(a1 + 1);
  do
  {
    v5 = __ldrex(v4);
    v6 = v5 - 1;
  }
  while ( __strex(v6, v4) );
  __dmb(0xBu);
  if ( !v6 )
  {
    if ( *(_BYTE *)(v2 + 50) )
    {
      *((_BYTE *)a1 + 28) = 0;
    }
    else
    {
      v7 = *(_DWORD *)(v2 + 12);
      *(_BYTE *)(v2 + 50) = 1;
      if ( v7 )
      {
        v8 = (int *)(v7 + 16);
        v9 = *(int ***)(v7 + 20);
        v10 = v2 + 4;
        *(_DWORD *)(v2 + 4) = v7 + 16;
        *(_DWORD *)(v2 + 8) = v9;
        if ( *v9 != (int *)(v7 + 16) )
          __fastfail(3u);
      }
      else
      {
        v8 = &KiProfileListHead;
        v10 = v2 + 4;
        v9 = (int **)dword_624F14;
        *(_DWORD *)(v2 + 4) = &KiProfileListHead;
        *(_DWORD *)(v2 + 8) = v9;
        if ( *v9 != &KiProfileListHead )
          __fastfail(3u);
      }
      *v9 = (int *)v10;
      v8[1] = v10;
      v11 = KiProfileSourceListHead;
      if ( (int *)KiProfileSourceListHead == &KiProfileSourceListHead )
      {
LABEL_14:
        v11 = a1[6];
        a1[6] = 0;
        *(_DWORD *)(v11 + 8) = *(__int16 *)(v2 + 48);
        *(_WORD *)(v11 + 12) = 1;
        *(_WORD *)(v11 + 14) = 1;
        *(_DWORD *)(v11 + 16) = 0;
        *(_DWORD *)(v11 + 20) = 0;
        v12 = KiProfileSourceListHead;
        *(_DWORD *)v11 = KiProfileSourceListHead;
        *(_DWORD *)(v11 + 4) = &KiProfileSourceListHead;
        if ( *(int **)(v12 + 4) != &KiProfileSourceListHead )
          __fastfail(3u);
        *(_DWORD *)(v12 + 4) = v11;
        KiProfileSourceListHead = v11;
        if ( *(_WORD *)(v2 + 48) == 1 )
          KiProfileAlignmentFixup = 1;
      }
      else
      {
        while ( *(_DWORD *)(v11 + 8) != *(__int16 *)(v2 + 48) )
        {
          v11 = *(_DWORD *)v11;
          if ( (int *)v11 == &KiProfileSourceListHead )
            goto LABEL_14;
        }
      }
      v13 = *(_DWORD *)(v2 + 44);
      while ( v13 )
      {
        v14 = __clz(__rbit(v13));
        v13 &= ~(1 << v14);
        ++*(_DWORD *)(v11 + 24 + 4 * v14);
      }
      v15 = *(_DWORD *)(v2 + 44) & ~*(_DWORD *)(v11 + 20);
      if ( a1 != (int *)-12 )
      {
        *((_WORD *)a1 + 7) = 1;
        *((_WORD *)a1 + 6) = 1;
        a1[4] = 0;
        a1[5] = v15;
      }
      __dmb(0xFu);
      v16 = *(_DWORD *)(v2 + 44) | *(_DWORD *)(v11 + 20);
      if ( v11 != -12 )
      {
        *(_WORD *)(v11 + 14) = 1;
        *(_WORD *)(v11 + 12) = 1;
        *(_DWORD *)(v11 + 16) = 0;
        *(_DWORD *)(v11 + 20) = v16;
      }
      *((_BYTE *)a1 + 28) = 1;
    }
  }
  __dmb(0xBu);
  v17 = (unsigned int *)(a1 + 2);
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 - 1, v17) );
  __dmb(0xBu);
  while ( (int)*v17 > 0 )
  {
    __dmb(0xAu);
    __yield();
  }
  __dmb(0xBu);
  v19 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( (a1[*(unsigned __int8 *)(v19 + 2460) + 5] & *(_DWORD *)(v19 + 2456)) != 0 )
    HalStartProfileInterrupt(*(__int16 *)(v2 + 48));
  return KfLowerIrql(v3);
}
