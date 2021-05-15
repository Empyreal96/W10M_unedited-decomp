// MiZeroPageThread 
 
int __fastcall MiZeroPageThread(int a1)
{
  int result; // r0
  unsigned int v3; // r4
  unsigned int v4; // r7
  unsigned int v5; // r0
  _DWORD *v6; // r5
  int v7; // r8
  int v8; // r5
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int *v11; // r2
  unsigned int v12; // r0
  unsigned __int8 *v13; // r1
  int v14; // r3
  unsigned int v15; // r2
  int v16; // [sp+0h] [bp-40h]
  unsigned int v17; // [sp+4h] [bp-3Ch] BYREF
  unsigned int v18; // [sp+8h] [bp-38h] BYREF
  unsigned int v19; // [sp+Ch] [bp-34h]
  int v20; // [sp+10h] [bp-30h]
  int v21; // [sp+14h] [bp-2Ch]
  unsigned int v22[10]; // [sp+18h] [bp-28h] BYREF

  result = MiInitializeZeroPagePtes();
  if ( result )
  {
    v16 = 0;
    v20 = __mrc(15, 0, 13, 0, 3);
    v21 = KeSetActualBasePriorityThread(v20 & 0xFFFFFFC0, 0);
    v3 = 0;
    v4 = 256;
    v17 = 256;
    if ( !MiAcquireNonPagedResources(a1, 256) )
      return sub_54E53C();
    v19 = -1;
    while ( 1 )
    {
      while ( 1 )
      {
        v5 = MiWaitForFreePagesToZero(a1, v3);
        v3 = v5;
        v18 = v5;
        if ( v5 == -1 )
        {
          MiReleaseNonPagedResources(a1, 256);
          MiReleasePtes(&dword_634D58, *(_DWORD *)(a1 + 3256), 0x100u);
          return KeSetActualBasePriorityThread(v20 & 0xFFFFFFC0, v21);
        }
        v6 = 0;
        v7 = 0;
        if ( *(_DWORD *)(dword_63F718 + 104 * (v5 >> byte_6337F5) + 4) )
          break;
LABEL_7:
        v6 = (_DWORD *)MiGetIndividualPagesToZero(a1, (int *)&v18, 256, &v17);
        v4 = v17;
        v3 = v18;
        if ( v6 )
        {
LABEL_8:
          if ( v3 >> byte_6337F5 != v19 )
          {
            v19 = v3 >> byte_6337F5;
            KeQueryNodeActiveAffinity((unsigned __int16)(v3 >> byte_6337F5), v22, 0);
            if ( v22[0] )
              KeSetIdealProcessorThreadEx(v20 & 0xFFFFFFC0, 31 - __clz(v22[0]), 0);
          }
          if ( v7 )
          {
            MiZeroLargePage(v7, v16);
            v8 = KfRaiseIrql(2);
            v9 = (unsigned __int8 *)(v7 + 15);
            do
              v10 = __ldrex(v9);
            while ( __strex(v10 | 0x80, v9) );
            __dmb(0xBu);
            if ( v10 >> 7 )
            {
              v13 = (unsigned __int8 *)(v7 + 15);
              do
              {
                do
                {
                  __dmb(0xAu);
                  __yield();
                  v14 = *(_DWORD *)(v7 + 12);
                  __dmb(0xBu);
                }
                while ( v14 < 0 );
                do
                  v15 = __ldrex(v13);
                while ( __strex(v15 | 0x80, v13) );
                __dmb(0xBu);
              }
              while ( v15 >> 7 );
            }
            MiInsertLargePageInNodeList((v7 - MmPfnDatabase) / 24, 1024, 0);
            __dmb(0xBu);
            v11 = (unsigned int *)(v7 + 12);
            do
              v12 = __ldrex(v11);
            while ( __strex(v12 & 0x7FFFFFFF, v11) );
            KfLowerIrql(v8);
            MiDeleteZeroThreadContext(a1, v16);
            v16 = 0;
          }
          else
          {
            MiZeroPageChain(a1, (int)v6, v4);
            MiInsertZeroedPages(v6);
          }
        }
      }
      v16 = MiCreateZeroThreadContext(a1);
      if ( v16 )
      {
        v7 = MiUnlinkNodeLargePage(a1, v3 >> byte_6337F5, 1, 1);
        if ( v7 )
          goto LABEL_8;
        MiDeleteZeroThreadContext(a1, v16);
        v16 = 0;
        goto LABEL_7;
      }
      KeDelayExecutionThread(0, 0, (unsigned int *)MiHalfSecond);
    }
  }
  return result;
}
