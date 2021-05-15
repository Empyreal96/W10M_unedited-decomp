// KiHeteroChooseTargetProcessor 
 
int __fastcall KiHeteroChooseTargetProcessor(unsigned int a1, int a2, int *a3, _DWORD *a4)
{
  int v6; // r7
  int v8; // r0
  int v9; // r2
  int v10; // r1
  int v11; // r6
  int *v12; // r8
  int v13; // r0
  int v14; // r2
  int v15; // r4
  int v16; // r3
  int v17; // r1
  int v18; // r3
  int result; // r0
  unsigned int *v20; // r1
  unsigned int v21; // r2
  unsigned int v22; // r2
  char v23; // r3
  int v24; // [sp+8h] [bp-28h] BYREF
  int v25; // [sp+Ch] [bp-24h] BYREF
  int v26; // [sp+10h] [bp-20h]

  v6 = *a3;
  v8 = KiGetHeteroCpuPolicyThread(a2, a1);
  v9 = *(_DWORD *)(a2 + 364);
  v10 = v8;
  v26 = v8;
  v11 = (int)*(&KiProcessorBlock + v9);
  v12 = *(int **)(v11 + 2360);
  while ( 1 )
  {
    v13 = KiGenerateHeteroSets((int)v12, v6, v10, &v25, &v24);
    v14 = *v12;
    v15 = v24;
    if ( (*v12 & v24) != 0 || v13 || (v12[34] & v24) != 0 )
    {
      v16 = v25;
    }
    else
    {
      v15 = v6;
      v24 = v6;
      v25 = v6;
      v16 = v6;
    }
    v17 = v14 & v15;
    if ( (v14 & v15) == 0 )
      break;
    v18 = v16 & v17;
    if ( v18 )
      v17 = v18;
    if ( *(_DWORD *)(a1 + 1048) != *(_DWORD *)(a1 + 3468) && (v12[1] & v17) != 0 )
      v17 &= v12[1];
    result = v11;
    if ( (*(_DWORD *)(v11 + 1048) & v17) == 0 )
    {
      if ( (*(_DWORD *)(v11 + 3468) & v17) != 0 )
        v17 &= *(_DWORD *)(v11 + 3468);
      result = (int)*(&KiProcessorBlock
                    + (((unsigned __int8)__clz(__rbit(__ROR4__(v17, *(_BYTE *)(v11 + 1053)))) + *(_BYTE *)(v11 + 1053)) & 0x1F));
    }
    *a4 = 1;
    v20 = (unsigned int *)(result + 24);
    while ( 1 )
    {
      do
        v21 = __ldrex(v20);
      while ( __strex(1u, v20) );
      __dmb(0xBu);
      if ( !v21 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v20 );
    }
    if ( !*(_BYTE *)(result + 19) )
      return result;
LABEL_34:
    __dmb(0xBu);
    *v20 = 0;
    v10 = v26;
  }
  if ( v16 == v15 )
    v16 = 0;
  result = KiSelectProcessorToPreempt(a2, v11, v15, v16);
  if ( (*(_DWORD *)(result + 1048) & v15) == 0 )
    result = (int)*(&KiProcessorBlock
                  + (((unsigned __int8)__clz(__rbit(__ROR4__(v15, *(_BYTE *)(result + 1053))))
                    + *(_BYTE *)(result + 1053)) & 0x1F));
  v20 = (unsigned int *)(result + 24);
  while ( 1 )
  {
    do
      v22 = __ldrex(v20);
    while ( __strex(1u, v20) );
    __dmb(0xBu);
    if ( !v22 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v20 );
  }
  if ( (*v12 & v15) != 0 )
    goto LABEL_34;
  v23 = *(_BYTE *)(result + 19);
  *a4 = 0;
  if ( (v23 & 2) != 0 )
  {
    __dmb(0xBu);
    *(_DWORD *)(result + 24) = 0;
    result = KiSelectCandidateProcessor();
    if ( (*(_BYTE *)(result + 19) & 1) == 0 )
      *a4 = 1;
  }
  return result;
}
