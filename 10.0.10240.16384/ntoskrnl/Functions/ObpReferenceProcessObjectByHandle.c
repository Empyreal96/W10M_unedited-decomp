// ObpReferenceProcessObjectByHandle 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ObpReferenceProcessObjectByHandle(int a1, int a2, int a3, int a4, int a5, int *a6, int a7, _DWORD *a8)
{
  int v9; // r1 OVERLAPPED
  unsigned int v11; // r5
  int v12; // r4
  unsigned int *v13; // r0
  unsigned int *v14; // r6
  unsigned int *v15; // r7
  int v16; // r10
  int *v17; // r0
  int v18; // r1
  unsigned int v19; // r3
  int v20; // r2
  unsigned int v21; // r2
  int v22; // r2
  unsigned int v23; // r1
  __int16 v24; // r3
  int result; // r0
  int v26; // r2
  unsigned int *v27; // r5
  unsigned int v28; // r2
  int v29; // r2
  __int16 v30; // r3
  int v31; // r2
  unsigned int *v32; // r4
  int v33; // r0
  unsigned int v34; // r2
  int v35; // r2

  v9 = 0;
  *a6 = 0;
  a4 = (char)a4;
  v11 = a1;
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( a1 >= 0 )
    goto LABEL_2;
  if ( a1 == -1 )
  {
    v31 = 0x1FFFFF;
    *(_QWORD *)a7 = *(_QWORD *)&v9;
    v32 = (unsigned int *)(a2 - 24);
    v33 = ObpTraceFlags;
    *a8 = 0;
    if ( v33 )
    {
      result = sub_7F75C4();
    }
    else
    {
      do
      {
        v34 = __ldrex(v32);
        v35 = v34 + 1;
      }
      while ( __strex(v35, v32) );
      __dmb(0xBu);
      if ( v35 <= 1 )
        KeBugCheckEx(24, 0, a2, 16, v35);
      *a6 = a2;
      result = 0;
    }
  }
  else
  {
    if ( a1 != -2 )
    {
      if ( a4 )
        return -1073741816;
      v11 = a1 ^ 0x80000000;
      a3 = ObpKernelHandleTable;
LABEL_2:
      --*(_WORD *)(v12 + 308);
      v13 = (unsigned int *)ExMapHandleToPointer(a3, v11);
      v14 = v13;
      if ( v13 )
      {
        v15 = (unsigned int *)(*v13 & 0xFFFFFFF8);
        v16 = v13[1] & 0x1FFFFFF;
        if ( *(_DWORD *)(a3 + 4) )
          v17 = (int *)ExpGetHandleExtraInfo(a3, v11);
        else
          v17 = 0;
        v18 = *v14 & 6;
        v19 = v14[1];
        *(_DWORD *)(a7 + 4) = v16;
        if ( (v19 & 0x4000000) != 0 )
          LOBYTE(v18) = v18 | 8;
        if ( (v19 & 0x2000000) != 0 )
          LOBYTE(v18) = v18 | 1;
        *(_DWORD *)a7 = v18 & 0xF;
        if ( v17 )
          v20 = *v17;
        else
          v20 = 0;
        *a8 = v20;
        do
        {
          v21 = __ldrex(v15);
          v22 = v21 + 1;
        }
        while ( __strex(v22, v15) );
        __dmb(0xBu);
        if ( v22 <= 1 )
          KeBugCheckEx(24, 0, (int)(v15 + 6), 16, v22);
        __dmb(0xBu);
        do
          v23 = __ldrex(v14);
        while ( __strex(v23 + 1, v14) );
        __dmb(0xBu);
        __dmb(0xFu);
        if ( *(_DWORD *)(a3 + 32) )
          v17 = (int *)ExfUnblockPushLock(a3 + 32, 0);
        v24 = *(_WORD *)(v12 + 308) + 1;
        *(_WORD *)(v12 + 308) = v24;
        if ( !v24 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
          KiCheckForKernelApcDelivery((int)v17);
        if ( ObpTraceFlags )
          ObpPushStackInfo((unsigned int)v15, 1, 1u, a5);
        *a6 = (int)(v15 + 6);
        return 0;
      }
      v30 = *(_WORD *)(v12 + 308) + 1;
      *(_WORD *)(v12 + 308) = v30;
      if ( !v30 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
        KiCheckForKernelApcDelivery(0);
      return -1073741816;
    }
    v26 = 0x1FFFFF;
    *(_QWORD *)a7 = *(_QWORD *)&v9;
    v27 = (unsigned int *)(v12 - 24);
    *a8 = 0;
    if ( ObpTraceFlags )
      ObpPushStackInfo(v12 - 24, 1, 1u, a5);
    do
    {
      v28 = __ldrex(v27);
      v29 = v28 + 1;
    }
    while ( __strex(v29, v27) );
    __dmb(0xBu);
    if ( v29 <= 1 )
      KeBugCheckEx(24, 0, v12, 16, v29);
    *a6 = v12;
    result = 0;
  }
  return result;
}
