// ExpCheckForWorker 
 
void *__fastcall ExpCheckForWorker(void *result, int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r4
  unsigned int v4; // r7
  unsigned int v5; // r6
  int v6; // r2
  int v7; // r3
  unsigned int v8; // r8
  int v9; // r5
  unsigned __int8 **v10; // r9
  unsigned __int8 *v11; // r4
  unsigned __int8 *v12; // t1
  int v13; // r0
  unsigned int v14; // r2
  int v15; // r1
  _DWORD **v16; // r3
  _DWORD *i; // r2
  unsigned int v18; // r1
  int v19; // [sp+8h] [bp-20h]

  v2 = 0;
  v19 = a2;
  v3 = (unsigned __int16)KeNumberNodes;
  v4 = (unsigned int)result;
  if ( KeNumberNodes )
  {
    result = &KiNodeInit;
    v5 = 0;
    do
    {
      v6 = (int)*(&KeNodeBlock + v2);
      if ( (_UNKNOWN *)v6 != (_UNKNOWN *)((char *)&KiNodeInit + 384 * v5) && v6 )
      {
        v7 = *(_DWORD *)(v6 + 1016);
        __dmb(0xBu);
        if ( (v7 & 2) != 0 )
        {
          v8 = v4 + a2;
          v9 = 0;
          v10 = (unsigned __int8 **)(v6 + 384);
          do
          {
            v12 = *v10++;
            v11 = v12;
            if ( ((unsigned __int8)v12 & 1) == 0 && v11 )
            {
              v13 = KfRaiseIrql(2);
              do
                v14 = __ldrex(v11);
              while ( __strex(v14 | 0x80, v11) );
              while ( 1 )
              {
                __dmb(0xBu);
                if ( !(v14 >> 7) )
                  break;
                do
                {
                  __dmb(0xAu);
                  __yield();
                }
                while ( (*(_DWORD *)v11 & 0x80) != 0 );
                do
                  v14 = __ldrex(v11);
                while ( __strex(v14 | 0x80, v11) );
              }
              v15 = 0;
              v16 = (_DWORD **)(v11 + 16);
              do
              {
                for ( i = *v16; i != v16; i = (_DWORD *)*i )
                {
                  if ( (unsigned int)i >= v4 && (unsigned int)i < v8 )
                    KeBugCheckEx(228, 0, (int)i, v4, v8);
                }
                ++v15;
                v16 += 2;
              }
              while ( v15 < 32 );
              __dmb(0xBu);
              do
                v18 = __ldrex((unsigned int *)v11);
              while ( __strex(v18 & 0xFFFFFF7F, (unsigned int *)v11) );
              KfLowerIrql(v13);
            }
            ++v9;
          }
          while ( v9 < 8 );
          a2 = v19;
          result = &KiNodeInit;
        }
        v3 = (unsigned __int16)KeNumberNodes;
      }
      v2 = (unsigned __int16)(v5 + 1);
      v5 = v2;
    }
    while ( v2 < v3 );
  }
  return result;
}
