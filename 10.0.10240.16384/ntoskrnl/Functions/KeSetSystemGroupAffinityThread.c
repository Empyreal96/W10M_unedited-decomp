// KeSetSystemGroupAffinityThread 
 
int *__fastcall KeSetSystemGroupAffinityThread(int a1, _DWORD *a2)
{
  unsigned int v3; // r2
  int v5; // r6
  int v6; // r0
  unsigned int v7; // r8
  int v8; // r5
  unsigned int *v9; // r10
  unsigned int v10; // r2
  int *result; // r0
  int v12; // r3
  int v13; // r2
  int v14; // r3
  int v15; // [sp+0h] [bp-30h] BYREF
  int v16; // [sp+4h] [bp-2Ch]
  int v17; // [sp+8h] [bp-28h]
  int v18; // [sp+Ch] [bp-24h]
  int v19; // [sp+10h] [bp-20h]
  int v20; // [sp+14h] [bp-1Ch] BYREF

  v17 = 0;
  v18 = 0;
  v19 = 0;
  v3 = *(unsigned __int16 *)(a1 + 4);
  if ( v3 >= (unsigned __int16)KeActiveProcessors
    || (dword_681D78[v3] & *(_DWORD *)a1) == 0
    || *(unsigned __int16 *)(a1 + 6) | *(unsigned __int16 *)(a1 + 10) | *(unsigned __int16 *)(a1 + 8) )
  {
    v5 = 0;
  }
  else
  {
    v5 = 1;
    *(_DWORD *)a1 &= dword_681D78[*(unsigned __int16 *)(a1 + 4)];
  }
  v6 = KfRaiseIrql(2);
  v16 = v6;
  v7 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v8 = *(_DWORD *)(v7 + 1412);
  v9 = (unsigned int *)(v8 + 44);
  do
    v10 = __ldrex(v9);
  while ( __strex(1u, v9) );
  __dmb(0xBu);
  if ( v10 )
    return (int *)sub_50A848(v6, 1);
  v12 = *(_DWORD *)(v8 + 76);
  if ( (v12 & 8) != 0 )
  {
    LOWORD(v18) = *(_WORD *)(v8 + 360);
    v17 = *(_DWORD *)(v8 + 356);
  }
  else
  {
    *(_DWORD *)(v8 + 76) = v12 | 8;
  }
  v15 = 0;
  if ( v5 )
    ((void (__fastcall *)(unsigned int, int, int, int *))KiSetSystemAffinityThread)(v7 + 1408, a1, 32, &v15);
  __dmb(0xBu);
  *v9 = 0;
  if ( (dword_682604 & 0x1000) != 0 )
    EtwTraceThreadAffinity(v8, a1, v10);
  result = (int *)KiProcessDeferredReadyList(v7 + 1408, &v15, v16);
  if ( a2 )
  {
    v13 = v18;
    v14 = v19;
    result = &v20;
    *a2 = v17;
    a2[1] = v13;
    a2[2] = v14;
  }
  return result;
}
