// VmpFlushTb 
 
int __fastcall VmpFlushTb(int result, int a2, unsigned int a3, int a4)
{
  _DWORD *v4; // r8
  unsigned int *v5; // r4
  int v6; // r10
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r1
  _DWORD *v10; // r5
  int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r9
  _DWORD *v14; // r7
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r1
  unsigned int v18; // r3
  unsigned int v19; // r3
  unsigned int v20; // [sp+0h] [bp-28h] BYREF
  unsigned int v21; // [sp+4h] [bp-24h]
  int v22; // [sp+8h] [bp-20h]
  int vars4; // [sp+2Ch] [bp+4h]

  v20 = a2;
  v21 = a3;
  v22 = a4;
  v4 = (_DWORD *)a3;
  v5 = (unsigned int *)result;
  v6 = -1;
  if ( a2 )
  {
    v10 = 0;
    v21 = a3 + 4 * a2;
    if ( a3 >= v21 )
      return result;
    do
    {
      if ( *v4 <= (unsigned int)MmHighestUserAddress )
      {
        if ( v6 == -1 )
        {
          v6 = KfRaiseIrql(15);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            result = ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v5);
          }
          else
          {
            v15 = (unsigned __int8 *)v5 + 3;
            do
              v16 = __ldrex(v15);
            while ( __strex(v16 | 0x80, v15) );
            __dmb(0xBu);
            if ( v16 >> 7 )
              ExpWaitForSpinLockExclusiveAndAcquire(v5);
            while ( 1 )
            {
              result = *v5;
              if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
                break;
              if ( (result & 0x40000000) == 0 )
              {
                do
                  v17 = __ldrex(v5);
                while ( v17 == result && __strex(result | 0x40000000, v5) );
                __dmb(0xBu);
              }
              __dmb(0xAu);
              __yield();
            }
          }
        }
        v11 = (*v4 & 0x7FF) + 1;
        if ( (*v4 & 0x800) != 0 )
          v11 <<= 10;
        v12 = *v4 >> 12;
        v13 = v11 + v12 - 1;
        v20 = v12;
        if ( v12 <= v13 )
        {
          do
          {
            if ( !v10 || v12 < v10[8] || v12 > v10[9] )
            {
              v10 = (_DWORD *)v5[3];
              v14 = 0;
              if ( v10 )
              {
                while ( 1 )
                {
                  result = VmpProcessMemoryRangeCompareVpn(&v20, v10);
                  if ( !result )
                    break;
                  if ( result < 0 )
                  {
                    v14 = v10;
                    v10 = (_DWORD *)*v10;
                  }
                  else
                  {
                    v10 = (_DWORD *)v10[1];
                  }
                  if ( !v10 )
                  {
                    v12 = v20;
                    goto LABEL_42;
                  }
                }
                v12 = v20;
              }
              else
              {
LABEL_42:
                v10 = v14;
              }
            }
            if ( !v10 )
              break;
            v18 = v10[8];
            if ( v12 < v18 )
            {
              if ( v13 < v18 )
                break;
              v20 = v10[8];
            }
            v19 = v10[9];
            if ( v13 <= v19 )
              v19 = v13;
            v12 = v19 + 1;
            v20 = v19 + 1;
          }
          while ( v19 + 1 <= v13 );
        }
      }
      ++v4;
    }
    while ( (unsigned int)v4 < v21 );
  }
  else
  {
    v6 = KfRaiseIrql(15);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v5);
    }
    else
    {
      v7 = (unsigned __int8 *)v5 + 3;
      do
        v8 = __ldrex(v7);
      while ( __strex(v8 | 0x80, v7) );
      __dmb(0xBu);
      if ( v8 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v5);
      while ( 1 )
      {
        result = *v5;
        if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (result & 0x40000000) == 0 )
        {
          do
            v9 = __ldrex(v5);
          while ( v9 == result && __strex(result | 0x40000000, v5) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
  }
  if ( v6 != -1 )
  {
    ++v5[5];
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v5 = 0;
    }
    result = KfLowerIrql((unsigned __int8)v6);
  }
  return result;
}
