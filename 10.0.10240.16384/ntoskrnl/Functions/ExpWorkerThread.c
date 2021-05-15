// ExpWorkerThread 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExpWorkerThread(_DWORD *a1)
{
  unsigned int v2; // r4
  int v3; // r5
  int v4; // r10
  int *v5; // lr
  _DWORD *v7; // r9
  int v8; // r0
  int v9; // r7
  int v10; // r1
  int v11; // r2
  unsigned int *v12; // r1
  unsigned int v13; // r2
  void (__fastcall *v14)(int); // r5 OVERLAPPED
  int v15; // r6 OVERLAPPED
  int v16; // r0
  int v17; // r0
  int v18; // r2
  bool v19; // zf
  unsigned int v20; // r2
  unsigned int v21; // r3
  int v22; // r3
  int v23; // r2
  unsigned int *v24; // r0
  unsigned int v25; // r2
  unsigned int *v26; // r6
  unsigned int *v27; // t2
  unsigned int v28; // r0
  unsigned int v29; // r1
  unsigned int v30; // r2
  int v31; // r1
  int v32; // r2
  unsigned int v33; // r2
  int v34; // r2
  int v35; // r0
  int v36; // [sp+0h] [bp-58h]
  int v37; // [sp+4h] [bp-54h]
  int *v38; // [sp+8h] [bp-50h]
  int v39; // [sp+Ch] [bp-4Ch]
  int v40; // [sp+10h] [bp-48h] BYREF
  unsigned int *v41; // [sp+14h] [bp-44h]
  int v42[2]; // [sp+18h] [bp-40h] BYREF
  unsigned int *v43; // [sp+20h] [bp-38h]
  _DWORD v44[12]; // [sp+28h] [bp-30h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v42[1] = 0;
  v3 = 1;
  v4 = a1[103];
  v5 = v42;
  *(_DWORD *)(v2 + 964) |= 1u;
  v38 = v42;
  v39 = 1;
  v42[0] = 0;
  __dmb(0xFu);
  if ( !ExpWorkersCanSwap )
    return sub_53F12C();
  v43 = a1 + 106;
  v41 = a1 + 106;
  v7 = a1 + 2;
  do
  {
LABEL_5:
    while ( 1 )
    {
      v8 = KeRemovePriQueue(a1, 0, 0, v5, v36, v37);
      v9 = v8;
      if ( !v3 )
        break;
      v3 = 0;
      v39 = 0;
      v23 = a1[107] & 0x7FFFFFFF;
      __dmb(0xBu);
      a1[107] = v23;
      __dmb(0xBu);
      v24 = v43;
      do
        v25 = __ldrex(v24);
      while ( __strex(v25 & 0xFFFFBFFF, v24) );
      __dmb(0xBu);
      v5 = 0;
      v38 = 0;
      if ( v9 != 258 )
      {
LABEL_7:
        v10 = a1[108];
        v11 = a1[106];
        __dmb(0xBu);
        if ( v11 < (2 * a1[107]) >> 1
          || v11 < v10 && (_DWORD *)*v7 == v7 && (a1[1] || (v22 = a1[107], __dmb(0xBu), v22 < 0)) )
        {
          KeSetEvent(v4 + 856, 0, 0);
        }
        __dmb(0xBu);
        v12 = a1 + 104;
        do
          v13 = __ldrex(v12);
        while ( __strex(v13 + 1, v12) );
        __dmb(0xBu);
        *(_QWORD *)&v14 = *(_QWORD *)(v9 + 8);
        if ( (dword_682608 & 0x8000000) != 0 )
        {
          EtwTraceThreadWorkItem(v14, 1344);
          v14(v15);
          v16 = EtwTraceThreadWorkItem(v14, 1345);
        }
        else
        {
          v16 = ((int (__fastcall *)(int))v14)(v15);
        }
        if ( *(_DWORD *)(v2 + 476) != v2 + 476 )
          KeBugCheck2(57, v14, v15, v9, 0, 0);
        if ( *(_DWORD *)(v2 + 308) )
          KeBugCheck2(1, v14, *(unsigned __int8 *)(v2 + 362), *(_DWORD *)(v2 + 308), 1, 0);
        v17 = KeGetCurrentIrql(v16);
        if ( v17 )
        {
          v35 = KeGetCurrentIrql(v17);
          KeBugCheck2(225, v14, v35, v15, v9, 0);
        }
        if ( (*(_DWORD *)(v2 + 960) & 8) != 0 )
          KeBugCheck2(223, v14, v15, v9, 0, 0);
        if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
          KeBugCheck2(5, *(_DWORD *)(v2 + 336), *(_DWORD *)(v2 + 116), *(unsigned __int8 *)(v2 + 362), v2, 0);
        v18 = (*(_DWORD *)(v2 + 960) >> 9) & 7;
        if ( (*(_DWORD *)(*(_DWORD *)(v2 + 336) + 192) & 0x100000) != 0 )
        {
          v18 = 0;
        }
        else
        {
          v19 = v18 == 2;
          if ( ((*(_DWORD *)(v2 + 960) >> 9) & 7u) >= 2 )
            goto LABEL_21;
        }
        if ( v2 != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) || !*(_DWORD *)(v2 + 1000) )
        {
          v19 = v18 == 2;
LABEL_21:
          if ( !v19 )
          {
            v34 = (*(_DWORD *)(v2 + 960) >> 9) & 7;
            if ( (*(_DWORD *)(*(_DWORD *)(v2 + 336) + 192) & 0x100000) != 0 )
              v34 = 0;
            if ( v34 < 2 && v2 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
            {
              if ( *(_DWORD *)(v2 + 1000) )
                v34 = 2;
            }
            KeBugCheck2(296, v14, v34, v15, v9, 0);
          }
        }
        v20 = (*(_DWORD *)(v2 + 960) >> 12) & 7;
        if ( (*(_DWORD *)(*(_DWORD *)(v2 + 336) + 192) & 0x100000) != 0 && v20 >= 2 || v20 != 5 )
        {
          v33 = (*(_DWORD *)(v2 + 960) >> 12) & 7;
          if ( (*(_DWORD *)(*(_DWORD *)(v2 + 336) + 192) & 0x100000) != 0 && v33 >= 2 )
            v33 = 2;
          KeBugCheck2(297, v14, v33, v15, v9, 0);
        }
        v21 = *(_DWORD *)(v2 + 968);
        if ( (v21 & 0x100) != 0 )
          KeBugCheck2(347, v14, (v21 >> 9) & 7, v15, v9, 0);
        if ( (*(_DWORD *)(v2 + 76) & 8) != 0 )
        {
          v37 = v9;
          v36 = v15;
          DbgPrintEx(
            0,
            0,
            (int)"EXWORKER: worker exit with system affinity set, worker routine %p, parameter %p, item %p\n",
            (int)v14);
          v44[0] = 0;
          v44[1] = 0;
          v44[2] = 0;
          KeRevertToUserGroupAffinityThread((int)v44, v31, v32, 0);
        }
        if ( *(unsigned __int16 *)(v2 + 344) != *(unsigned __int16 *)(v4 + 264)
          || *(_DWORD *)(v2 + 340) != *(_DWORD *)(v4 + 260) )
        {
          KeQueryNodeActiveAffinity(*(unsigned __int16 *)(v4 + 266), v44, 0);
          KeSetAffinityThread(v2, v44);
        }
        v5 = v38;
        if ( *(_DWORD *)(v2 + 1036) )
        {
          v37 = v9;
          v36 = v15;
          DbgPrintEx(
            0,
            0,
            (int)"EXWORKER: worker exit with activity ID set, worker routine %p, parameter %p, item %p\n",
            (int)v14);
          v40 = 0;
          EtwActivityIdControlKernel(2, &v40);
          v3 = v39;
LABEL_52:
          v5 = v38;
        }
        else
        {
          v3 = v39;
        }
      }
    }
    if ( v8 != 258 )
      goto LABEL_7;
    v5 = v38;
  }
  while ( *(_DWORD *)(v2 + 908) != v2 + 908 );
  v26 = v41;
  v27 = v41;
  __pld(v41);
  v28 = *v27;
  do
  {
    v5 = v38;
    if ( (unsigned __int16)(v28 & 0x3FFF) <= (2 * a1[107]) >> 1 )
      goto LABEL_5;
    v5 = v38;
    if ( (v28 & 0x4000) != 0 )
      goto LABEL_5;
    if ( a1[1] )
      goto LABEL_52;
    v29 = v28 - 1;
    __dmb(0xBu);
    do
      v30 = __ldrex(v26);
    while ( v30 == v28 && __strex(v29, v26) );
    v28 = v30;
    __dmb(0xBu);
  }
  while ( v30 != v29 + 1 );
  *(_DWORD *)(v2 + 964) &= 0xFFFFFFFE;
  return KeSetKernelStackSwapEnable(1);
}
