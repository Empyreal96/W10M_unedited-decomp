// MiReturnPhysicalPoolPages 
 
int __fastcall MiReturnPhysicalPoolPages(int *a1)
{
  int *v2; // r5
  unsigned int v3; // r6
  int v5; // r7
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r2
  unsigned int *v9; // r2
  unsigned int v10; // r0
  unsigned __int8 *v11; // r1
  int v12; // r3
  unsigned int v13; // r2
  int v14[3]; // [sp+20h] [bp-30h] BYREF
  int v15; // [sp+2Ch] [bp-24h]

  v14[0] = 0;
  v14[1] = 0;
  v14[2] = 0;
  v15 = 0;
  do
  {
    v2 = (int *)*a1;
    v3 = (int)((unsigned __int64)(715827883i64 * ((int)a1 - MmPfnDatabase)) >> 32) >> 2;
    if ( (*((_BYTE *)a1 + 19) & 0x10) != 0 )
      return sub_54C114();
    v5 = KfRaiseIrql(2);
    v6 = (unsigned __int8 *)a1 + 15;
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 0x80, v6) );
    __dmb(0xBu);
    if ( v7 >> 7 )
    {
      v11 = (unsigned __int8 *)a1 + 15;
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v12 = a1[3];
          __dmb(0xBu);
        }
        while ( (v12 & 0x80000000) != 0 );
        do
          v13 = __ldrex(v11);
        while ( __strex(v13 | 0x80, v11) );
        __dmb(0xBu);
      }
      while ( v13 >> 7 );
    }
    v8 = a1[3] & 0xC0000000;
    *((_WORD *)a1 + 8) = 0;
    a1[3] = v8;
    MiInsertPageInFreeOrZeroedList(v3 + (v3 >> 31), 2);
    __dmb(0xBu);
    v9 = (unsigned int *)(a1 + 3);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 & 0x7FFFFFFF, v9) );
    KfLowerIrql(v5);
    ++v15;
    ++v14[0];
    a1 = v2;
  }
  while ( v2 );
  return MiReturnNonPagedPoolCharges(v14);
}
