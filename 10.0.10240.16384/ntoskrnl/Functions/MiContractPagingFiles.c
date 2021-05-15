// MiContractPagingFiles 
 
int __fastcall MiContractPagingFiles(int a1)
{
  int result; // r0
  unsigned int v3; // r4
  unsigned int v4; // r1
  int v5; // r6
  int v6; // r5
  __int16 v7; // r3
  int v8; // r10
  unsigned int v9; // r1
  int v10; // r6
  unsigned int v11; // r0
  _DWORD *v12; // r0
  int v13; // r2

  result = MiOkToShrinkPageFiles(*(_DWORD *)(a1 + 3844), *(_DWORD *)(a1 + 4116));
  if ( result )
  {
    v3 = *(_DWORD *)(a1 + 3596);
    __dmb(0xBu);
    v4 = 0;
    if ( v3 )
    {
      v5 = a1;
      while ( 1 )
      {
        v6 = *(_DWORD *)(v5 + 3600);
        v7 = *(_WORD *)(v6 + 96);
        if ( (v7 & 0x10) == 0 && (v7 & 0x40) == 0 && *(_DWORD *)v6 != *(_DWORD *)(v6 + 8) )
          break;
        ++v4;
        v5 += 4;
        if ( v4 >= v3 )
          goto LABEL_9;
      }
      result = sub_514D54();
    }
    else
    {
LABEL_9:
      if ( v4 != v3 )
      {
        v8 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_632D80);
        }
        else
        {
          do
            v9 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
          while ( __strex(v9 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
          __dmb(0xBu);
          if ( v9 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(&dword_632D80);
          while ( 1 )
          {
            v10 = dword_632D80;
            if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (dword_632D80 & 0x40000000) == 0 )
            {
              do
                v11 = __ldrex((unsigned int *)&dword_632D80);
              while ( v11 == v10 && __strex(v10 | 0x40000000, (unsigned int *)&dword_632D80) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        if ( *(_DWORD *)(a1 + 304) == -1 )
        {
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80);
          }
          else
          {
            __dmb(0xBu);
            dword_632D80 = 0;
          }
          result = KfLowerIrql(v8);
        }
        else
        {
          *(_DWORD *)(a1 + 288) = 0;
          *(_BYTE *)(a1 + 341) = 1;
          *(_DWORD *)(a1 + 300) = a1;
          *(_DWORD *)(a1 + 304) = -1;
          v12 = *(_DWORD **)(a1 + 804);
          v13 = a1 + 292;
          *(_DWORD *)(a1 + 292) = a1 + 800;
          *(_DWORD *)(a1 + 296) = v12;
          if ( *v12 != a1 + 800 )
            __fastfail(3u);
          *v12 = v13;
          *(_DWORD *)(a1 + 804) = v13;
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80);
          }
          else
          {
            __dmb(0xBu);
            dword_632D80 = 0;
          }
          KfLowerIrql(v8);
          result = KeReleaseSemaphoreEx(a1 + 780, 0, 1);
        }
      }
    }
  }
  return result;
}
