// KeBoostPriorityThread 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeBoostPriorityThread(int result, int a2)
{
  void *v2; // r2
  char *v3; // r7
  int v5; // r4
  int v6; // r10
  unsigned int v7; // r3
  unsigned int v8; // r8
  char *v9; // r3
  unsigned int *v10; // r9
  unsigned int v11; // r2
  int v12; // r6
  int v13; // r3
  char *v14; // r1
  unsigned int v15; // r7 OVERLAPPED
  unsigned int v16; // r8 OVERLAPPED
  unsigned __int64 v17; // kr10_8
  unsigned __int64 v18; // r4
  unsigned __int64 *v19; // r3
  unsigned __int64 v20; // kr18_8
  unsigned __int8 *v21; // r3
  unsigned int v22; // r2
  unsigned int v23; // [sp+8h] [bp-48h]
  unsigned int v24; // [sp+Ch] [bp-44h]
  int v25; // [sp+14h] [bp-3Ch]
  int v26; // [sp+18h] [bp-38h] BYREF
  int v27; // [sp+1Ch] [bp-34h]
  int v28; // [sp+20h] [bp-30h]
  int v29; // [sp+24h] [bp-2Ch]
  unsigned int v30; // [sp+28h] [bp-28h]

  v2 = *(void **)(result + 336);
  v3 = (char *)result;
  v27 = result;
  if ( v2 != &KiInitialProcess )
  {
    v26 = 0;
    v5 = 0;
    v6 = KfRaiseIrql(2);
    v29 = v6;
    v7 = (unsigned int)KeGetPcr();
    v8 = (v7 & 0xFFFFF000) + 1408;
    v9 = *(char **)((v7 & 0xFFFFF000) + 0x584);
    v30 = v8;
    if ( v3 == v9 )
    {
      result = sub_510F4C();
    }
    else
    {
      v10 = (unsigned int *)(v3 + 44);
      while ( 1 )
      {
        do
          v11 = __ldrex(v10);
        while ( __strex(1u, v10) );
        __dmb(0xBu);
        if ( !v11 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v10 );
      }
      v12 = v3[123];
      v28 = v12;
      if ( v12 < 16 && !v3[348] )
      {
        v13 = v3[347] + a2;
        v25 = v13;
        if ( v13 > v12 )
        {
          if ( v13 >= 16 )
            v25 = 15;
          v14 = v3 + 48;
          while ( 1 )
          {
            *(_QWORD *)&v15 = *(_QWORD *)v14;
            v23 = *((_DWORD *)v14 + 1);
            v24 = *(_DWORD *)v14;
            do
              v17 = __ldrexd((unsigned __int64 *)v14);
            while ( __PAIR64__(v17, HIDWORD(v17)) == __PAIR64__(v15, v16)
                 && __strexd(__PAIR64__(v16, v15), (unsigned __int64 *)v14) );
            if ( __PAIR64__(v15, v16) == __PAIR64__(v17, HIDWORD(v17)) )
              break;
            __dmb(0xAu);
            __yield();
          }
          v3 = (char *)v27;
          v8 = v30;
          v18 = __PAIR64__(v23, v24) + (unsigned int)*(unsigned __int8 *)(v27 + 403) * KiCyclesPerClockQuantum;
          if ( (*(_DWORD *)(v27 + 80) & 0x10) != 0 )
          {
            __dmb(0xBu);
            v21 = (unsigned __int8 *)(v27 + 80);
            do
              v22 = __ldrex(v21);
            while ( __strex(v22 & 0xEF, v21) );
            __dmb(0xBu);
          }
          __dmb(0xBu);
          v19 = (unsigned __int64 *)(v27 + 24);
          do
            v20 = __ldrexd(v19);
          while ( __strexd(v18, v19) );
          __dmb(0xBu);
          v5 = v25;
          KiSetPriorityThread(v27, &v26, v25);
        }
      }
      __dmb(0xBu);
      *v10 = 0;
      result = KiProcessDeferredReadyList(v8, &v26, v6);
      if ( v5 )
      {
        if ( (dword_682604 & 0x2000) != 0 )
          result = EtwTracePriority(v3, 1328, v12, v5, 0);
      }
    }
  }
  return result;
}
