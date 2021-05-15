// PopAccumulateNonActivatedCpuTime 
 
__int64 __fastcall PopAccumulateNonActivatedCpuTime(__int64 a1, __int64 a2)
{
  _QWORD *v2; // r9
  _QWORD *v3; // r5
  int v4; // r8
  void *v5; // r0
  unsigned int v6; // r4
  unsigned int v7; // lr
  unsigned int v8; // r6
  unsigned int v9; // r7
  __int64 v11; // [sp+0h] [bp-28h] BYREF
  __int64 v12; // [sp+8h] [bp-20h] BYREF

  v11 = a1;
  v12 = a2;
  v2 = (_QWORD *)a2;
  v3 = (_QWORD *)HIDWORD(a1);
  v4 = a1;
  if ( KeNumberProcessors_0 )
    v5 = KiProcessorBlock;
  else
    v5 = 0;
  PpmParkSnapNodeIdleTime(v5, &v12, &v11);
  v6 = HIDWORD(v11);
  v7 = v12;
  v8 = v11;
  v9 = HIDWORD(v12);
  if ( !v4 )
    *v2 = *v2 - *v3 - v11 + v12;
  *v3 = __PAIR64__(v9, v7) - __PAIR64__(v6, v8);
  return v11;
}
