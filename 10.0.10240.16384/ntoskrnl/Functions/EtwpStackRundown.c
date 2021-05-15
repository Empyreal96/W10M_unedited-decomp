// EtwpStackRundown 
 
int __fastcall EtwpStackRundown(int result, int a2)
{
  int v2; // r6
  unsigned int v3; // r7
  _DWORD *v4; // r5
  int v5; // r9
  int v6; // r0
  _DWORD *v7; // r4
  int v8; // r8
  char *v9; // lr
  unsigned int *v10; // r2
  unsigned int v11; // r1
  char *v12; // r8
  _DWORD *v13; // t1
  char var30[52]; // [sp+8h] [bp-30h] BYREF
  int vars4; // [sp+3Ch] [bp+4h]

  v2 = result;
  v3 = 0;
  if ( *(_DWORD *)(result + 4) )
  {
    v4 = (_DWORD *)(result + 16);
    do
    {
      if ( (_DWORD *)*v4 != v4 )
      {
        v5 = 0;
        v6 = EtwpLockStackCacheBucket((int)v4);
        v7 = (_DWORD *)*v4;
        v8 = v6;
        if ( (_DWORD *)*v4 != v4 )
        {
          v9 = var30;
          do
          {
            __dmb(0xBu);
            v10 = v7 + 3;
            do
              v11 = __ldrex(v10);
            while ( __strex(v11 + 1, v10) );
            __dmb(0xBu);
            *(_DWORD *)v9 = v7;
            v9 += 4;
            v7 = (_DWORD *)*v7;
            ++v5;
          }
          while ( v7 != v4 );
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v4 + 2, vars4);
        }
        else
        {
          __dmb(0xBu);
          v4[2] = 0;
        }
        result = KfLowerIrql(v8);
        if ( v5 )
        {
          v12 = var30;
          do
          {
            v13 = *(_DWORD **)v12;
            v12 += 4;
            EtwpTraceCachedStack(a2, 6180, v13);
            result = EtwpDereferenceStackEntry(v13, v2);
            --v5;
          }
          while ( v5 );
        }
      }
      ++v3;
      v4 += 3;
    }
    while ( v3 < *(_DWORD *)(v2 + 4) );
  }
  return result;
}
