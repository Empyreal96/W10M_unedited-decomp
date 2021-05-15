// KeCheckForTimer 
 
int __fastcall KeCheckForTimer(int result, int a2)
{
  unsigned int v2; // r4
  unsigned int v3; // r5
  int v4; // r9
  unsigned int v5; // r10
  void **i; // r2
  unsigned int *v7; // r7
  _DWORD **v8; // r6
  unsigned int v9; // r2
  _DWORD *v10; // r0
  int v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r2
  unsigned int v14; // r2
  unsigned int v15; // [sp+Ch] [bp-2Ch]
  int v16; // [sp+14h] [bp-24h]
  void **v17; // [sp+18h] [bp-20h]

  v2 = result;
  if ( (KeTimerCheckFlags & 1) != 0 )
  {
    v3 = result + a2;
    v4 = 0;
    v5 = KeNumberProcessors_0;
    if ( KeNumberProcessors_0 )
    {
      for ( i = &KiProcessorBlock; ; i = v17 )
      {
        v15 = 0;
        v7 = (unsigned int *)((char *)*i + 4352);
        v8 = (_DWORD **)((char *)*i + 4356);
        v17 = i + 1;
        do
        {
          v16 = KfRaiseIrql(2);
          while ( 1 )
          {
            do
              v9 = __ldrex(v7);
            while ( __strex(1u, v7) );
            __dmb(0xBu);
            if ( !v9 )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( *v7 );
          }
          v10 = *v8;
          if ( *v8 != v8 )
          {
            v11 = KiWaitNever;
            do
            {
              v12 = (unsigned int)(v10 - 6);
              v10 = (_DWORD *)*v10;
              if ( v12 > v2 - 48 && v12 < v3 )
                KeBugCheckEx(199, 0, v12, v2, v3);
              v13 = KiWaitAlways ^ bswap32(__ROR4__(v11 ^ *(_DWORD *)(v12 + 32), -(char)KiWaitNever) ^ v12);
              if ( v13 )
              {
                if ( v13 > v2 - 32 && v13 < v3 )
                  KeBugCheckEx(199, 1, v13, v2, v3);
                v14 = *(_DWORD *)(v13 + 12);
                if ( v14 >= v2 && v14 < v3 )
                  KeBugCheckEx(199, 2, v14, v2, v3);
              }
              v11 = KiWaitNever;
            }
            while ( v10 != v8 );
          }
          __dmb(0xBu);
          *v7 = 0;
          v7 += 6;
          result = KfLowerIrql(v16);
          v8 += 6;
          ++v15;
        }
        while ( v15 < 0x100 );
        if ( ++v4 >= v5 )
          break;
      }
    }
  }
  return result;
}
