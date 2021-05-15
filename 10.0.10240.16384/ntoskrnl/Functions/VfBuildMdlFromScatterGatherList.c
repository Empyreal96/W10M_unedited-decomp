// VfBuildMdlFromScatterGatherList 
 
int __fastcall VfBuildMdlFromScatterGatherList(int a1, int a2, int a3, int *a4)
{
  int v6; // r9
  int v7; // r6
  int v8; // r0
  int v9; // r7
  _DWORD *v10; // r5
  unsigned int *v11; // r4
  unsigned int v12; // r2
  _DWORD *i; // r3
  int (__fastcall *v14)(int, int, int, int *); // r0
  int v15; // r4
  int v16; // r7
  int v17; // r0
  int v18; // r5
  int v19; // r2
  int v20; // r3
  int v22; // [sp+8h] [bp-28h]
  int vars4; // [sp+34h] [bp+4h]

  v6 = a3;
  v7 = 0;
  v8 = ViGetAdapterInformationInternal(a1, 1);
  v9 = v8;
  if ( v8 )
  {
    if ( *(_DWORD *)(a2 + 4) == -559026163 )
    {
      v10 = (_DWORD *)(v8 + 32);
      if ( *(_DWORD *)(v8 + 32) != v8 + 32 )
      {
        v11 = (unsigned int *)(v8 + 40);
        v22 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented((int)v11);
        }
        else
        {
          do
            v12 = __ldrex(v11);
          while ( __strex(1u, v11) );
          __dmb(0xBu);
          if ( v12 )
            KxWaitForSpinLockAndAcquire(v11);
        }
        for ( i = *(_DWORD **)(v9 + 32); v10 != i; i = (_DWORD *)*i )
        {
          if ( *(i - 1) == a2 )
          {
            v7 = i[3];
            break;
          }
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v11, vars4);
        }
        else
        {
          __dmb(0xBu);
          *v11 = 0;
        }
        KfLowerIrql(v22);
        v6 = a3;
      }
    }
  }
  VF_UNMARK_SCATTER_GATHER_LIST(a2, v7);
  v14 = (int (__fastcall *)(int, int, int, int *))ViGetRealDmaOperation(a1, 60);
  v15 = v14(a1, a2, v6, a4);
  VF_MARK_SCATTER_GATHER_LIST(a2, v7);
  if ( v15 >= 0 && *a4 == v6 && v7 )
  {
    if ( *(_DWORD *)(v7 + 24) )
    {
      v15 = -1073741709;
    }
    else
    {
      v16 = *(_DWORD *)(v7 + 32);
      v17 = IoAllocateMdl(0, *(_DWORD *)(v16 + 20), 0, 0, 0);
      v18 = v17;
      if ( v17 )
      {
        *(_DWORD *)(v7 + 24) = v17;
        memmove(v17 + 28, v16 + 28, 4 * (*(_DWORD *)(v16 + 20) >> 12));
        v19 = *(_DWORD *)(v18 + 24) + *(_DWORD *)(v6 + 24);
        v20 = *(_DWORD *)(v18 + 20);
        *(_DWORD *)(v18 + 24) = v19;
        *(_DWORD *)(v18 + 20) = v20 - v19;
        *(_WORD *)(v18 + 6) |= 2u;
        *a4 = v18;
      }
      else
      {
        v15 = -1073741670;
      }
    }
  }
  return v15;
}
