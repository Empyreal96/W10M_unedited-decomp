// KeSetPriorityBoost 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeSetPriorityBoost(int result, int a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // r4
  unsigned int v6; // r10
  unsigned int v7; // r9
  unsigned __int64 *v8; // r7
  unsigned int v9; // r5 OVERLAPPED
  unsigned int v10; // r6 OVERLAPPED
  unsigned __int64 v11; // kr00_8
  unsigned int *v12; // r7
  unsigned int v13; // r2
  int v14; // r3
  unsigned __int64 v15; // kr08_8
  int v16; // [sp+0h] [bp-28h]
  _DWORD *v17[9]; // [sp+4h] [bp-24h] BYREF

  v17[0] = a3;
  v17[1] = a4;
  v5 = result;
  if ( *(_UNKNOWN **)(result + 336) != &KiInitialProcess )
  {
    v16 = 0;
    v17[0] = 0;
    v6 = KfRaiseIrql(2);
    v7 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    if ( *(char *)(v5 + 123) >= a2 )
      goto LABEL_18;
    v8 = (unsigned __int64 *)(v5 + 48);
    *(_QWORD *)&v9 = *(_QWORD *)(v5 + 48);
    do
      v11 = __ldrexd(v8);
    while ( __PAIR64__(v11, HIDWORD(v11)) == __PAIR64__(v9, v10) && __strexd(__PAIR64__(v10, v9), v8) );
    if ( __PAIR64__(v9, v10) != __PAIR64__(v11, HIDWORD(v11)) )
      return sub_50ECF8();
    v12 = (unsigned int *)(v5 + 44);
    while ( 1 )
    {
      do
        v13 = __ldrex(v12);
      while ( __strex(1u, v12) );
      __dmb(0xBu);
      if ( !v13 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v12 );
    }
    v14 = *(char *)(v5 + 123);
    if ( v14 < a2 )
    {
      v16 = 1;
      *(_BYTE *)(v5 + 348) += 16 * (a2 - v14);
      KiSetPriorityThread(v5, v17, (char)a2, (int)KeGetPcr());
      v15 = *(_QWORD *)(v5 + 24);
      if ( __PAIR64__(v10, v9) > v15 || v15 - __PAIR64__(v10, v9) < (unsigned int)KiLockQuantumTarget )
        *(_QWORD *)(v5 + 24) = __PAIR64__(v10, KiLockQuantumTarget) + v9;
    }
    __dmb(0xBu);
    *v12 = 0;
    if ( v16 )
      result = KiProcessDeferredReadyList(v7 + 1408, v17, v6);
    else
LABEL_18:
      result = KfLowerIrql(v6);
  }
  return result;
}
