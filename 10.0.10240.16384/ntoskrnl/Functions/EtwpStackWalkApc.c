// EtwpStackWalkApc 
 
int __fastcall EtwpStackWalkApc(_DWORD *a1, _DWORD *a2, _DWORD *a3, int *a4, int *a5)
{
  int v8; // r4
  unsigned int v9; // r7
  unsigned int v10; // r6
  int v11; // r4
  int v12; // r5
  unsigned int v13; // r4
  int result; // r0
  unsigned __int8 *v15; // r3
  unsigned int v16; // r2
  unsigned int *v17; // r2
  unsigned int v18; // r1
  _DWORD *v19; // [sp+0h] [bp-28h] BYREF
  _DWORD *v20; // [sp+4h] [bp-24h]
  int *v21; // [sp+8h] [bp-20h]

  v19 = a2;
  v20 = a3;
  v21 = a4;
  v8 = __mrc(15, 0, 13, 0, 3);
  v9 = a1[12];
  v10 = v8 & 0xFFFFFFC0;
  if ( v9 >= KeNumberProcessors_0 )
    v11 = 0;
  else
    v11 = (int)*(&KiProcessorBlock + v9);
  v12 = *(_DWORD *)(v11 + 3596);
  RtlpInterlockedPushEntrySList((unsigned __int64 *)(v12 + 960), a1);
  v13 = *a3;
  if ( (*(_DWORD *)(v10 + 960) & 1) == 0 )
  {
    v19 = (_DWORD *)*a4;
    v20 = (_DWORD *)*a5;
    EtwpTraceStackWalk(v13, 4096, v10, &v19);
  }
  __dmb(0xBu);
  result = 1 << (((BYTE2(v13) & 7) + 24) & 7);
  v15 = (unsigned __int8 *)(v10 + ((int)((HIWORD(v13) & 7) + 24) >> 3) + 80);
  do
    v16 = __ldrex(v15);
  while ( __strex(v16 & ~(_BYTE)result, v15) );
  __dmb(0xBu);
  v17 = (unsigned int *)(v12 + 1592);
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 - 1, v17) );
  __dmb(0xBu);
  *a2 = 0;
  return result;
}
