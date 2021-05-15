// ExNotifyWithProcessing 
 
int __fastcall ExNotifyWithProcessing(int result, int a2, int a3, int a4)
{
  int v4; // r5
  int v7; // r8
  unsigned int *v8; // r6
  int v9; // r0
  int v10; // r9
  unsigned int v11; // r2
  int *v12; // r4
  int v13; // r5
  unsigned int v14; // r2
  int v15; // r2
  int v16; // r3
  void (__fastcall *v17)(int, int, int, _DWORD, _DWORD); // r5
  void (__fastcall *v18)(int, int, int, _DWORD, _DWORD); // r5
  int v20; // [sp+Ch] [bp-24h]

  v4 = result;
  if ( result )
  {
    v7 = result + 8;
    if ( *(_DWORD *)(result + 8) != result + 8 )
    {
      v8 = (unsigned int *)(result + 4);
      v9 = KfRaiseIrql(2);
      v10 = v9;
      v20 = v9;
      if ( (dword_682604 & 0x210000) != 0 )
      {
        result = sub_516804();
      }
      else
      {
        do
          v11 = __ldrex(v8);
        while ( __strex(1u, v8) );
        __dmb(0xBu);
        if ( v11 )
          JUMPOUT(0x51680C);
        v12 = *(int **)(v4 + 8);
        if ( v9 == 2 )
        {
          if ( v12 != (int *)v7 )
          {
            do
            {
              if ( a4 && *(_DWORD *)a4 )
                (*(void (__fastcall **)(int, int, int, _DWORD, _DWORD))a4)(
                  v12[4],
                  a2,
                  a3,
                  *(_DWORD *)(a4 + 8),
                  *(_DWORD *)(a4 + 12));
              ((void (__fastcall *)(int, int, int))v12[3])(v12[4], a2, a3);
              if ( a4 )
              {
                v17 = *(void (__fastcall **)(int, int, int, _DWORD, _DWORD))(a4 + 4);
                if ( v17 )
                  v17(v12[4], a2, a3, *(_DWORD *)(a4 + 8), *(_DWORD *)(a4 + 12));
              }
              v12 = (int *)*v12;
            }
            while ( v12 != (int *)v7 );
            v10 = v20;
          }
        }
        else
        {
          for ( ; v12 != (int *)v7; v12 = (int *)*v12 )
          {
            if ( !*((_BYTE *)v12 + 24) )
            {
              ++v12[5];
              if ( (dword_682604 & 0x10000) != 0 )
              {
                KiReleaseSpinLockInstrumented(v8);
              }
              else
              {
                __dmb(0xBu);
                *v8 = 0;
              }
              KfLowerIrql(v10);
              if ( a4 && *(_DWORD *)a4 )
                (*(void (__fastcall **)(int, int, int, _DWORD, _DWORD))a4)(
                  v12[4],
                  a2,
                  a3,
                  *(_DWORD *)(a4 + 8),
                  *(_DWORD *)(a4 + 12));
              ((void (__fastcall *)(int, int, int))v12[3])(v12[4], a2, a3);
              if ( a4 )
              {
                v18 = *(void (__fastcall **)(int, int, int, _DWORD, _DWORD))(a4 + 4);
                if ( v18 )
                  v18(v12[4], a2, a3, *(_DWORD *)(a4 + 8), *(_DWORD *)(a4 + 12));
              }
              v13 = KfRaiseIrql(2);
              if ( (dword_682604 & 0x210000) != 0 )
              {
                KiAcquireSpinLockInstrumented(v8);
              }
              else
              {
                do
                  v14 = __ldrex(v8);
                while ( __strex(1u, v8) );
                __dmb(0xBu);
                if ( v14 )
                  KxWaitForSpinLockAndAcquire(v8);
              }
              v10 = v13;
              v15 = v12[5] - 1;
              v16 = *((unsigned __int8 *)v12 + 24);
              v12[5] = v15;
              if ( v16 && !v15 )
                KeSetEvent(&ExpCallbackEvent, 0, 0);
            }
          }
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v8);
        }
        else
        {
          __dmb(0xBu);
          *v8 = 0;
        }
        result = KfLowerIrql(v10);
      }
    }
  }
  return result;
}
