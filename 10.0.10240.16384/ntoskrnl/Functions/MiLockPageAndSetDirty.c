// MiLockPageAndSetDirty 
 
int __fastcall MiLockPageAndSetDirty(int a1, int a2)
{
  __int16 *v2; // r7
  int v4; // r6
  unsigned __int8 *v5; // r1
  unsigned int v6; // r2
  int result; // r0
  unsigned int v8; // r1
  unsigned int *v9; // r2
  unsigned int v10; // r5
  int v11; // r3
  int v12; // r2
  unsigned __int8 *v13; // r1
  unsigned int v14; // r2
  int v15; // r3
  unsigned int v16; // r2

  v2 = 0;
  if ( a2 == 1 )
  {
    v4 = 17;
    v5 = (unsigned __int8 *)(a1 + 15);
    do
      v6 = __ldrex(v5);
    while ( __strex(v6 | 0x80, v5) );
    __dmb(0xBu);
    if ( v6 >> 7 )
      return sub_51A2F4();
  }
  else
  {
    v4 = KfRaiseIrql(2);
    v13 = (unsigned __int8 *)(a1 + 15);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
    __dmb(0xBu);
    if ( v14 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v15 = *(_DWORD *)(a1 + 12);
          __dmb(0xBu);
        }
        while ( (v15 & 0x80000000) != 0 );
        do
          v16 = __ldrex(v13);
        while ( __strex(v16 | 0x80, v13) );
        __dmb(0xBu);
      }
      while ( v16 >> 7 );
    }
  }
  result = 16;
  v8 = 0;
  if ( (*(_BYTE *)(a1 + 18) & 0x10) == 0 )
  {
    v11 = *(_DWORD *)(a1 + 8);
    if ( (v11 & 0x400) == 0 && (*(_BYTE *)(a1 + 18) & 8) == 0 )
    {
      v12 = *(_DWORD *)(a1 + 8);
      if ( (v11 & 0x10) != 0 )
      {
        *(_DWORD *)(a1 + 8) = v11 & 0xFFFFFFEF;
        v8 = v12 & 0xFFFFFFF7;
      }
      else
      {
        v8 = 0;
      }
    }
    *(_BYTE *)(a1 + 18) |= 0x10u;
    if ( v8 )
      v2 = MiSystemPartition;
  }
  __dmb(0xBu);
  v9 = (unsigned int *)(a1 + 12);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 & 0x7FFFFFFF, v9) );
  if ( v8 )
    result = MiReleasePageFileInfo(v2, v8, 1);
  if ( v4 != 17 )
    result = KfLowerIrql(v4);
  return result;
}
