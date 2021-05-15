// KiDispatchException 
 
int __fastcall KiDispatchException(_DWORD *a1, int a2, _DWORD *a3, char a4, unsigned __int8 a5)
{
  unsigned int *v7; // r5
  unsigned int v8; // r6
  int v9; // r5
  int v10; // r5
  int result; // r0
  int v12; // r4
  int v13; // r3
  int v14; // r0
  _BYTE *v15; // r4
  int v16; // r0
  unsigned int v17; // r1
  int v18; // r3
  int v19; // r1
  int v20; // [sp+8h] [bp-220h]
  int v21; // [sp+Ch] [bp-21Ch]
  _DWORD v22[14]; // [sp+68h] [bp-1C0h] BYREF
  _BYTE *v23; // [sp+A0h] [bp-188h]
  int v24; // [sp+A8h] [bp-180h]

  v20 = a4;
  v21 = a2;
  v7 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3764);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 + 1, v7) );
  v9 = a5;
  if ( a5 && *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 780) )
  {
    v10 = *a1;
    if ( *a1 == 268435458 )
    {
      *a1 = -1073741795;
    }
    else if ( v10 == 268435460 )
    {
      *a1 = -1073741819;
    }
    if ( a4 || *a1 == -1073741819 && a1[6] <= (unsigned int)MmUserProbeAddress )
    {
      result = dword_61D9D0(a1, a2, a3, 0, a4);
      if ( result )
        return result;
      a2 = v21;
    }
    *a1 = v10;
    v9 = a5;
  }
  v22[0] = 2097167;
  KeContextFromKframes(a3, a2);
  v12 = v21;
  if ( KiPreprocessFault(a1, v21, a3, v22, v20) )
    return KeContextToKframes(a3, v21, v22, v22[0]);
  v13 = v20;
  if ( !v20 )
  {
    if ( v9 )
    {
      if ( KiDebugRoutine(a3, v21, a1, v22, 0, 0) || RtlDispatchException(a1, v22) )
        return KeContextToKframes(a3, v21, v22, v22[0]);
      v13 = 0;
      v12 = v21;
    }
    if ( !KiDebugRoutine(a3, v12, a1, v22, v13, 1) )
      KeBugCheck2(30, *a1, a1[3], a1[5], a1[6], 0);
    return KeContextToKframes(a3, v21, v22, v22[0]);
  }
  memset(&a1[a1[4] + 5], 0, -4 * (a1[4] + 5) + 80);
  if ( v9 == 1 )
  {
    v14 = KdIsThisAKdTrap(a1);
    if ( (!*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 340) && !KdIgnoreUmExceptions
       || v14 == 1)
      && KiDebugRoutine(a3, v21, a1, v22, v20, 0) )
    {
      return KeContextToKframes(a3, v21, v22, v22[0]);
    }
    result = DbgkForwardException(a1, 1, 0);
    if ( !result )
    {
      v15 = (_BYTE *)((unsigned int)(v23 - 512) & 0xFFFFFFF8);
      v16 = (int)(v15 + 416);
      v17 = v23 - v15;
      if ( v23 == v15 || v17 >= 0x1000 )
      {
        ProbeForWrite(v15, v17, 8);
        v16 = (int)(v15 + 416);
      }
      else
      {
        if ( (unsigned int)v15 >= MmUserProbeAddress )
          *(_BYTE *)MmUserProbeAddress = 0;
        *v15 = *v15;
        if ( v17 > 8 )
          v15[(v17 - 1) & 0xFFFFFFF8] = v15[(v17 - 1) & 0xFFFFFFF8];
      }
      *(_DWORD *)(v16 + 80) = v23;
      *(_DWORD *)(v16 + 84) = v24;
      memmove(v16, (int)a1, 0x50u);
      result = memmove((int)v15, (int)v22, 0x1A0u);
      __disable_irq();
      a3[29] = v15;
      a3[32] = KeUserExceptionDispatcher;
      v18 = a3[33] | 0x20;
      a3[33] = v18;
      a3[33] = v18 & 0xF9FF03FF;
      v19 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 160);
      if ( v19 && (a3[33] & 0x1F) == 16 && (a3[33] & 0x600FC00) == 0 )
      {
        a3[28] = a3[32];
        a3[32] = v19;
      }
      __enable_irq();
    }
  }
  else
  {
    result = DbgkForwardException(a1, 1, 1);
    if ( !result )
    {
      result = DbgkForwardException(a1, 0, 1);
      if ( !result )
        result = ZwTerminateProcess();
    }
  }
  return result;
}
