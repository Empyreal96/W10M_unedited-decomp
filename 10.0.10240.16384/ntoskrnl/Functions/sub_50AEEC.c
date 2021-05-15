// sub_50AEEC 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_50AEEC(int a1, int a2, int a3, _DWORD *a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  int v13; // r4
  int v14; // r5
  char v15; // r7
  int v16; // r9
  __int64 v17; // [sp-14h] [bp-14h] BYREF
  int v18; // [sp-Ch] [bp-Ch] BYREF

  do
  {
    a4[1] = a4;
    *a4 = v16;
    a4 += 4;
    --a3;
  }
  while ( a3 );
  *(_DWORD *)(v13 + 512) = v16;
  *(_DWORD *)(v14 + 5648) = 0;
  *(_DWORD *)(v14 + 5652) = 0;
  KeQueryPerformanceCounter(&v18, &v17);
  *(_DWORD *)(v14 + 5896) = _rt_sdiv64(1000000i64, 10000 * v17);
  KeInitializeTimerEx((_DWORD *)(v14 + 5792), 0);
  *(_BYTE *)(v14 + 5840) = 19;
  *(_BYTE *)(v14 + 5841) = v15;
  *(_WORD *)(v14 + 5842) = v16;
  *(_DWORD *)(v14 + 5852) = SMKM_STORE_MGR<SM_TRAITS>::SmHighMemPriorityWatchdogDpc;
  *(_DWORD *)(v14 + 5856) = v14;
  *(_DWORD *)(v14 + 5868) = v16;
  *(_DWORD *)(v14 + 5848) = v16;
  *(_DWORD *)(v14 + 5880) = SMKM_STORE_MGR<SM_TRAITS>::SmHighMemPriorityWatchdogWorker;
  *(_DWORD *)(v14 + 5884) = v16;
  *(_DWORD *)(v14 + 5872) = v16;
  __asm { POP.W           {R4-R11,PC} }
}
