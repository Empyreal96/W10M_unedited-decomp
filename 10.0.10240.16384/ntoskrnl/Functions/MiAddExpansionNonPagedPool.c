// MiAddExpansionNonPagedPool 
 
int __fastcall MiAddExpansionNonPagedPool(int result, int a2)
{
  unsigned int v2; // r8
  int v3; // r6
  _DWORD *v4; // r9
  unsigned int v5; // r5
  unsigned int v6; // r10
  int v7; // r4
  unsigned int *v8; // r7
  _DWORD *v9; // r4
  int v10; // r3
  unsigned __int8 *v11; // r1
  unsigned int v12; // r2
  int v13; // r3
  int v14; // r1
  int v15; // r3
  int v16; // r2
  unsigned int v17; // r1
  _DWORD *v18; // r4
  int v19; // r3
  int v20; // [sp+0h] [bp-30h]
  char v21[40]; // [sp+8h] [bp-28h] BYREF

  if ( a2 )
  {
    v2 = 0;
    v3 = 0;
    v4 = 0;
    v5 = MmPfnDatabase + 24 * result;
    v6 = v5 + 24 * a2;
    v7 = -1;
    v8 = (unsigned int *)(v5 + 12);
    do
    {
      if ( (unsigned __int16)v7 != *(_DWORD *)(v5 + 20) >> 28 )
      {
        if ( v3 )
        {
          v9 = (_DWORD *)(dword_6337E8 + 176 * v7);
          KeAcquireInStackQueuedSpinLock(v9 + 32, (unsigned int)v21);
          *v4 = v9[33];
          v10 = v9[31];
          v9[33] = v2;
          v9[31] = v10 + v3;
          KeReleaseInStackQueuedSpinLock((int)v21);
          v3 = 0;
          v2 = 0;
          v4 = 0;
        }
        v7 = *(_DWORD *)(v5 + 20) >> 28;
      }
      v20 = KfRaiseIrql(2);
      v11 = (unsigned __int8 *)v8 + 3;
      do
        v12 = __ldrex(v11);
      while ( __strex(v12 | 0x80, v11) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v12 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v13 = *v8;
          __dmb(0xBu);
        }
        while ( v13 < 0 );
        do
          v12 = __ldrex(v11);
        while ( __strex(v12 | 0x80, v11) );
      }
      v14 = *(_BYTE *)(v5 + 18) & 0xC7;
      *(_WORD *)(v5 + 16) = 1;
      v15 = *(_DWORD *)(v5 + 12);
      *(_BYTE *)(v5 + 18) = v14;
      *(_DWORD *)(v5 + 12) = v15 & 0xC0000000 | 1;
      *(_DWORD *)(v5 + 8) = 128;
      v16 = *(_DWORD *)(v5 + 20);
      *(_BYTE *)(v5 + 19) = *(_BYTE *)(v5 + 19) & 0xCF | 0x10;
      *(_DWORD *)(v5 + 20) = v16 & 0xF0F00000;
      if ( (v14 & 0xFFFFFFC0) != 64 )
        MiChangePageAttribute(v5, 1, 3);
      *(_DWORD *)(v5 + 4) = -4;
      *(_BYTE *)(v5 + 18) = *(_BYTE *)(v5 + 18) & 0xF8 | 6;
      __dmb(0xBu);
      do
        v17 = __ldrex(v8);
      while ( __strex(v17 & 0x7FFFFFFF, v8) );
      KfLowerIrql(v20);
      if ( !v4 )
        v4 = (_DWORD *)v5;
      *(_DWORD *)v5 = v2;
      v5 += 24;
      ++v3;
      v8 += 6;
      v2 = v5 - 24;
    }
    while ( v5 < v6 );
    v18 = (_DWORD *)(dword_6337E8 + 176 * v7);
    KeAcquireInStackQueuedSpinLock(v18 + 32, (unsigned int)v21);
    *v4 = v18[33];
    v19 = v18[31];
    v18[33] = v2;
    v18[31] = v19 + v3;
    result = KeReleaseInStackQueuedSpinLock((int)v21);
  }
  return result;
}
