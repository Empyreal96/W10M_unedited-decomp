// KiSetAffinityThread 
 
int __fastcall KiSetAffinityThread(int result, int a2, int a3)
{
  int v3; // r1
  int *v4; // r6
  int v5; // r5
  unsigned int *v6; // r8
  unsigned int v7; // r4
  int v8; // r9
  int v9; // r7
  int v10; // r3
  int v11; // r4
  int v12; // r2
  int v13; // r0
  __int16 v14; // r3
  _DWORD *v15; // r7
  int v16; // r3
  unsigned int *v17; // r2
  unsigned int v18; // r4
  unsigned int v19; // r3
  int v20; // r0
  int v21; // r2
  int v22; // [sp+8h] [bp-40h] BYREF
  _DWORD *v23; // [sp+Ch] [bp-3Ch] BYREF
  int v24; // [sp+10h] [bp-38h]
  int v25; // [sp+14h] [bp-34h]
  int v26; // [sp+18h] [bp-30h] BYREF
  int v27; // [sp+1Ch] [bp-2Ch]
  int v28; // [sp+20h] [bp-28h]

  v25 = a2;
  v3 = 0;
  v4 = (int *)a3;
  v5 = result;
  v6 = (unsigned int *)(result + 44);
  do
    v7 = __ldrex(v6);
  while ( __strex(1u, v6) );
  __dmb(0xBu);
  if ( v7 )
    return sub_51BB3C();
  *(_WORD *)(result + 344) = *(_WORD *)(a3 + 4);
  *(_DWORD *)(result + 340) = *(_DWORD *)a3;
  v8 = *(_DWORD *)(result + 124);
  v9 = (int)*(&KiProcessorBlock + v8);
  if ( *(unsigned __int8 *)(v9 + 1052) != *(unsigned __int16 *)(a3 + 4) || (*(_DWORD *)(v9 + 1048) & *(_DWORD *)a3) == 0 )
  {
    v20 = KeSelectNodeForAffinity(a3, 0);
    v26 = 0;
    v27 = 0;
    v28 = 0;
    v21 = *(_DWORD *)(v20 + 260);
    v27 = *((unsigned __int16 *)v4 + 2);
    v26 = *v4 & v21;
    result = KeSelectIdealProcessor(v20, &v26, 0);
    *(_DWORD *)(v5 + 124) = result;
    v9 = (int)*(&KiProcessorBlock + result);
    v8 = result;
    v3 = 0;
  }
  v10 = *(_DWORD *)(v5 + 76);
  v11 = 0;
  v12 = 0;
  v22 = 0;
  if ( (v10 & 8) == 0 )
  {
    v13 = KiAcquireThreadStateLock(v5, &v22, &v23);
    v14 = *((_WORD *)v4 + 2);
    v24 = v13;
    *(_WORD *)(v5 + 360) = v14;
    *(_DWORD *)(v5 + 356) = *v4;
    if ( KiComputeThreadAffinity(v5) )
    {
      v4 = &v26;
      LOWORD(v27) = *(_WORD *)(v5 + 360);
      v26 = *(_DWORD *)(v5 + 356);
    }
    else
    {
      *(_DWORD *)(v5 + 364) = v8;
      KiUpdateNodeAffinitizedFlag(v5);
      KiUpdateSharedReadyQueueAffinityThread(v9, v5);
    }
    v11 = v22;
    v15 = v23;
    result = KiRescheduleThreadAfterAffinityChange(v5, v4, v24, v22, v23, v25);
    v3 = result;
    if ( v11 )
    {
      __dmb(0xBu);
      *(_DWORD *)(v11 + 24) = 0;
    }
    if ( v15 )
    {
      __dmb(0xBu);
      *v15 = 0;
    }
    v12 = 0;
  }
  __dmb(0xBu);
  *v6 = 0;
  if ( v3 )
  {
    result = *(_DWORD *)(v11 + 20);
    if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) != result )
    {
      v16 = (int)*(&KiProcessorBlock + result);
      __dmb(0xBu);
      v17 = (unsigned int *)(v16 + 1676);
      do
        v18 = __ldrex(v17);
      while ( __strex(v18 | 2, v17) );
      __dmb(0xBu);
      v19 = (unsigned int)KeGetPcr();
      ++*(_DWORD *)((v19 & 0xFFFFF000) + 0x1414);
      result = HalSendSoftwareInterrupt();
    }
  }
  if ( (dword_682604 & 0x1000) != 0 )
    result = EtwTraceThreadAffinity(v5, v4, v12);
  return result;
}
