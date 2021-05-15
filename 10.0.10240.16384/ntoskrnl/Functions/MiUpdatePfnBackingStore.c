// MiUpdatePfnBackingStore 
 
int *__fastcall MiUpdatePfnBackingStore(int a1, int a2, int a3, int a4)
{
  int v5; // r2
  char v6; // r6
  int v9; // r9
  unsigned __int8 *v10; // lr
  unsigned int v11; // r5
  int v12; // r3
  unsigned int v13; // r2
  int *v14; // r4
  int *result; // r0
  int v16; // r5
  int v17; // r3
  int v18; // r6
  int v19; // r0
  unsigned int *v20; // r2
  unsigned int v21; // r0
  int v22[8]; // [sp+8h] [bp-20h] BYREF

  v5 = a2;
  v6 = 1;
  v22[0] = a2;
  v9 = 0;
  if ( !a4 )
  {
    v9 = KfRaiseIrql(2);
    v10 = (unsigned __int8 *)(a1 + 15);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x80, v10) );
    __dmb(0xBu);
    if ( v11 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v12 = *(_DWORD *)(a1 + 12);
          __dmb(0xBu);
        }
        while ( v12 < 0 );
        do
          v13 = __ldrex(v10);
        while ( __strex(v13 | 0x80, v10) );
        __dmb(0xBu);
      }
      while ( v13 >> 7 );
    }
    v5 = v22[0];
  }
  v14 = (int *)(a1 + 8);
  if ( (*(_DWORD *)(a1 + 8) & 8) != 0 )
    v6 = 3;
  result = MI_SET_PAGING_FILE_INFO(v22, (_DWORD *)(a1 + 8), v5, a3, v6);
  v16 = v22[0];
  if ( (unsigned int)(a1 + 1073741832) > 0x3FFFFF )
  {
    *v14 = v22[0];
  }
  else
  {
    v17 = *v14;
    v18 = 0;
    __dmb(0xBu);
    *v14 = v16;
    if ( (v17 & 2) == 0 && (v16 & 2) != 0 )
      v18 = 1;
    if ( (unsigned int)(a1 + 1070596104) <= 0xFFF )
    {
      v19 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      result = (int *)MiArmWriteConvertedHardwarePde(v19, (_DWORD *)(v19 + 4 * ((unsigned __int16)v14 & 0xFFF)), v16);
    }
    if ( v18 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  if ( !a4 )
  {
    __dmb(0xBu);
    v20 = (unsigned int *)(a1 + 12);
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 & 0x7FFFFFFF, v20) );
    result = (int *)KfLowerIrql(v9);
  }
  return result;
}
