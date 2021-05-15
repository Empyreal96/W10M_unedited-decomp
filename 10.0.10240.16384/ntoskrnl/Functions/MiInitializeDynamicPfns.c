// MiInitializeDynamicPfns 
 
_BYTE *__fastcall MiInitializeDynamicPfns(int a1, int a2, char a3)
{
  int v5; // r9
  _BYTE *result; // r0
  unsigned int v7; // r6
  unsigned int *v8; // r7
  int v9; // r9
  unsigned __int8 *v10; // r1
  unsigned int v11; // r2
  int v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r3
  int v19; // [sp+4h] [bp-4Ch]
  int v20; // [sp+8h] [bp-48h]
  unsigned int v21; // [sp+10h] [bp-40h]
  _DWORD v22[5]; // [sp+1Ch] [bp-34h] BYREF

  v5 = a1;
  v19 = a1;
  result = memset(v22, 0, sizeof(v22));
  v20 = 0;
  if ( (a3 & 4) != 0 )
    return (_BYTE *)sub_54E6A4(result);
  v22[2] |= 0x80000000;
  HIWORD(v22[3]) = 5;
  v7 = MmPfnDatabase + 24 * v5;
  v21 = v7 + 24 * a2;
  if ( v7 < v21 )
  {
    v8 = (unsigned int *)(v7 + 12);
    do
    {
      if ( (a3 & 1) != 0 && (a3 & 2) == 0 )
        v20 = MiPageToNode();
      v9 = KfRaiseIrql(2);
      v10 = (unsigned __int8 *)v8 + 3;
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 | 0x80, v10) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v11 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v14 = *v8;
          __dmb(0xBu);
        }
        while ( (v14 & 0x80000000) != 0 );
        do
          v11 = __ldrex(v10);
        while ( __strex(v11 | 0x80, v10) );
      }
      if ( (a3 & 1) != 0 )
      {
        v12 = *(_DWORD *)(v7 + 20);
        *(_WORD *)(v7 + 18) = 5;
        *(_DWORD *)(v7 + 20) = v12 & 0xFFFFFFF | (v20 << 28);
        if ( (a3 & 2) != 0 )
          *(_DWORD *)(v7 + 12) &= 0xC0000000;
        *(_BYTE *)(v7 + 18) = *(_BYTE *)(v7 + 18) & 0x3F | 0x40;
      }
      else
      {
        v15 = v22[0];
        v16 = v22[1];
        v17 = v22[2];
        *(_DWORD *)v7 = 0;
        *(_DWORD *)(v7 + 4) = v15;
        *(_DWORD *)(v7 + 8) = v16;
        *(_DWORD *)(v7 + 12) = v17;
        v18 = v22[4];
        *(_DWORD *)(v7 + 16) = v22[3];
        *(_DWORD *)(v7 + 20) = v18;
        MiAbortCombineScan(v7);
      }
      __dmb(0xBu);
      do
        v13 = __ldrex(v8);
      while ( __strex(v13 & 0x7FFFFFFF, v8) );
      result = (_BYTE *)KfLowerIrql(v9);
      v7 += 24;
      v8 += 6;
      ++v19;
    }
    while ( v7 < v21 );
  }
  return result;
}
