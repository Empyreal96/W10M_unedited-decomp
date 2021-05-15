// PopFxPepPerfInfoQuery 
 
int __fastcall PopFxPepPerfInfoQuery(int a1, int a2, unsigned int **a3, int a4)
{
  int v6; // r4
  unsigned int *v7; // r6
  unsigned int v8; // r10
  int v9; // r5
  unsigned int *v10; // r0
  unsigned int v11; // r8
  unsigned int *v12; // r5
  unsigned int v13; // r3
  int v14; // r0
  int v15; // r1
  int v16; // r0
  unsigned int v18; // [sp+10h] [bp-28h] BYREF
  unsigned int **v19; // [sp+14h] [bp-24h]

  v19 = a3;
  v6 = 0;
  v7 = 0;
  if ( !PopPluginQueryComponentPerfCapabilities(a1, a2, &v18, a4) )
  {
    v6 = -1073741822;
    goto LABEL_20;
  }
  v8 = v18;
  v9 = 40 * v18;
  v10 = (unsigned int *)ExAllocatePoolWithTag(1, 40 * v18 + 8, 1297630800);
  v7 = v10;
  if ( !v10 )
  {
LABEL_4:
    v6 = -1073741670;
    goto LABEL_20;
  }
  memset(v10, 0, v9 + 8);
  *v7 = v8;
  v11 = 0;
  if ( !v8 )
    goto LABEL_21;
  v12 = v7 + 2;
  while ( 1 )
  {
    PopPluginQueryComponentPerfSet(a1, a2, v11, v12 + 4, v12 + 5, v12 + 6, v12 + 6, v12 + 8);
    if ( !v12[5] )
    {
      v13 = v12[6];
      if ( !v13 )
        PopFxBugCheck(1562, *(_DWORD *)(a1 + 36), a1, a2);
      v6 = RtlULongLongToULong(16 * v13, (unsigned __int64)v13 >> 28, &v18);
      v14 = ExAllocatePoolWithTag(1, v18, 1297630800);
      v12[7] = v14;
      if ( !v14 )
        goto LABEL_4;
      PopPluginQueryComponentPerfStates(a1, a2, v11, v14);
    }
    PopPluginQueryComponentPerfSetName(a1, a2, v11, (__int16 *)v12 + 1, 0);
    v15 = *((unsigned __int16 *)v12 + 1);
    if ( *((_WORD *)v12 + 1) )
      break;
    *(_WORD *)v12 = 0;
    v12[1] = 0;
LABEL_15:
    ++v11;
    v12 += 10;
    if ( v11 >= v8 )
      goto LABEL_19;
  }
  *(_WORD *)v12 = v15 - 2;
  v16 = ExAllocatePoolWithTag(1, v15, 1297630800);
  v12[1] = v16;
  if ( v16 )
  {
    PopPluginQueryComponentPerfSetName(a1, a2, v11, (__int16 *)v12 + 1, v16);
    goto LABEL_15;
  }
  v6 = -1073741670;
LABEL_19:
  if ( v6 >= 0 )
  {
LABEL_21:
    *v19 = v7;
    return v6;
  }
LABEL_20:
  PopFxPepPerfInfoFree(v7);
  return v6;
}
