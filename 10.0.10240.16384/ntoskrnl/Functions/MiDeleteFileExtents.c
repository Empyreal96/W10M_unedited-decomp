// MiDeleteFileExtents 
 
int __fastcall MiDeleteFileExtents(int result, int a2, int a3, char a4)
{
  int v4; // r5
  int v6; // r2
  int v7; // r7
  int *v8; // r6
  int v9; // r4
  bool v10; // zf
  int v11; // r9
  int v12; // lr
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned __int8 *v15; // r1
  int v16; // r3
  unsigned int v17; // r2
  unsigned int *v18; // r2
  unsigned int v19; // r0
  char v20; // [sp+0h] [bp-28h]
  int v21; // [sp+4h] [bp-24h]

  v4 = 0;
  v6 = result;
  v7 = -1;
  v20 = a4;
  v21 = result;
  v8 = (int *)(result + 4 * (a2 + 1));
  if ( !a3 )
    goto LABEL_24;
  do
  {
    v9 = *v8;
    if ( *v8 != -1 )
    {
      if ( (a4 & 1) != 0 )
      {
        v10 = v9 >= 0;
        v9 &= 0x7FFFFFFFu;
        if ( v10 )
          v9 = -1;
      }
      if ( v9 != -1 )
      {
        v11 = MmPfnDatabase + 24 * v9;
        v12 = KfRaiseIrql(2);
        v13 = (unsigned __int8 *)(v11 + 15);
        do
          v14 = __ldrex(v13);
        while ( __strex(v14 | 0x80, v13) );
        __dmb(0xBu);
        if ( v14 >> 7 )
        {
          v15 = (unsigned __int8 *)(v11 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v16 = *(_DWORD *)(v11 + 12);
              __dmb(0xBu);
            }
            while ( (v16 & 0x80000000) != 0 );
            do
              v17 = __ldrex(v15);
            while ( __strex(v17 | 0x80, v15) );
            __dmb(0xBu);
          }
          while ( v17 >> 7 );
        }
        *v8 = -1;
        __dmb(0xBu);
        v18 = (unsigned int *)(v11 + 12);
        do
          v19 = __ldrex(v18);
        while ( __strex(v19 & 0x7FFFFFFF, v18) );
        result = KfLowerIrql(v12);
        if ( !v4 )
        {
          v7 = v9;
LABEL_28:
          ++v4;
          goto LABEL_20;
        }
        if ( v7 + v4 == v9 )
          goto LABEL_28;
      }
    }
    if ( v4 )
    {
      result = MiReturnFsDirectPages(v7, v4);
      v4 = 0;
      v7 = -1;
    }
LABEL_20:
    a4 = v20;
    ++v8;
    --a3;
  }
  while ( a3 );
  if ( v4 )
    result = MiReturnFsDirectPages(v7, v4);
  a4 = v20;
  v6 = v21;
LABEL_24:
  if ( (a4 & 2) != 0 )
    result = ExFreePoolWithTag(v6);
  return result;
}
