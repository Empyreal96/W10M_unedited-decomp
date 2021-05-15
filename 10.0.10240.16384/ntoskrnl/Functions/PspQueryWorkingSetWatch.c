// PspQueryWorkingSetWatch 
 
int __fastcall PspQueryWorkingSetWatch(int a1, int a2, _DWORD *a3, unsigned int a4, unsigned int *a5, char a6)
{
  int v8; // r5
  int v9; // r4
  int v10; // r0
  unsigned int *v11; // r8
  int v12; // r6
  unsigned int v13; // r10
  unsigned int v14; // r1
  unsigned int v15; // r2
  unsigned int v16; // r1
  unsigned int v17; // r3
  unsigned int v18; // lr
  unsigned int *v19; // r4
  unsigned int *v20; // r0
  unsigned int v21; // r2
  unsigned int v22; // r3
  unsigned int v23; // r1
  unsigned int *v24; // r2
  unsigned int *v25; // r2
  unsigned int v26; // r4
  unsigned int v27; // r3
  __int16 v28; // r3
  int v30; // [sp+10h] [bp-48h] BYREF
  unsigned int v31; // [sp+14h] [bp-44h]
  unsigned int v32; // [sp+18h] [bp-40h]
  int v33; // [sp+1Ch] [bp-3Ch]
  _DWORD *v34; // [sp+20h] [bp-38h]
  unsigned int v35; // [sp+24h] [bp-34h]
  unsigned int *v36; // [sp+28h] [bp-30h]
  unsigned int v37; // [sp+2Ch] [bp-2Ch]
  int v38; // [sp+30h] [bp-28h]
  unsigned int v39; // [sp+34h] [bp-24h]

  v35 = a4;
  v38 = a2;
  if ( a2 != 42 )
  {
    v9 = 8;
LABEL_6:
    if ( ExIsRestrictedCaller(a6) )
      return -1073741790;
    v10 = ObReferenceObjectByHandleWithTag(a1, 1024, PsProcessType, a6, 2035381072, &v30, 0);
    v8 = v10;
    if ( v10 < 0 )
      return v8;
    v11 = *(unsigned int **)(v30 + 304);
    v36 = v11;
    if ( !v11 )
    {
      v8 = -1073741823;
      v12 = v30;
LABEL_46:
      ObfDereferenceObjectWithTag(v12);
      return v8;
    }
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v37 = v13;
    v8 = 0;
    v33 = 0;
    --*(_WORD *)(v13 + 308);
    __dmb(0xBu);
    do
      v14 = __ldrex(v11);
    while ( __strex(v14 | 1, v11) );
    __dmb(0xBu);
    if ( (v14 & 1) != 0 )
    {
      v8 = -2147483622;
      v12 = v30;
      goto LABEL_42;
    }
    v15 = (unsigned __int16)v14 >> 1;
    v32 = v15;
    if ( (unsigned __int16)v14 >> 1 )
    {
      if ( (v14 & 0x7FFF0000) != 0 )
      {
        v10 = KeWaitForGate((int)(v11 + 2), 0);
        v15 = v32;
      }
      v16 = (v15 + 1) * v9;
      v39 = v16;
      if ( v35 >= v16 )
      {
        v10 = v11[1];
        v35 = v10;
        v33 = v10;
        __dmb(0xBu);
        if ( v38 == 42 )
        {
          v18 = 0;
          v31 = 0;
          while ( v18 < v15 )
          {
            v19 = &a3[4 * v18];
            v20 = &v11[3 * v18 + 6];
            v21 = v20[1];
            v22 = v20[2];
            *v19 = *v20;
            v19[1] = v21;
            v19[2] = v22;
            v19[3] = 0;
            v31 = ++v18;
            v15 = v32;
          }
          a3 += 4 * v18;
          v34 = a3;
          a3[2] = 0;
          a3[3] = 0;
          v10 = v35;
        }
        else
        {
          v34 = a3;
          v23 = 0;
          v31 = 0;
          while ( v23 < v15 )
          {
            v24 = &v11[3 * v23];
            *a3 = v24[6];
            a3[1] = v24[7];
            a3 += 2;
            v34 = a3;
            v31 = ++v23;
            v15 = v32;
          }
        }
        *a3 = 0;
        a3[1] = v10;
        if ( a5 )
          *a5 = v39;
        v17 = v35;
        v12 = v30;
      }
      else
      {
        v8 = -1073741789;
        if ( a5 )
          *a5 = v16;
        v12 = v30;
        v17 = 0;
      }
      if ( v8 >= 0 )
      {
        __dmb(0xBu);
        v10 = -v17;
        v25 = v11 + 1;
        do
          v26 = __ldrex(v25);
        while ( __strex(v26 - v17, v25) );
        __dmb(0xBu);
        *v11 = 0;
LABEL_42:
        v28 = *(_WORD *)(v13 + 308) + 1;
        *(_WORD *)(v13 + 308) = v28;
        if ( !v28 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
          KiCheckForKernelApcDelivery(v10);
        goto LABEL_46;
      }
    }
    else
    {
      v8 = -2147483622;
      v12 = v30;
    }
    __dmb(0xBu);
    do
      v27 = __ldrex((unsigned __int8 *)v11);
    while ( __strex(v27 & 0xFE, (unsigned __int8 *)v11) );
    __dmb(0xBu);
    goto LABEL_42;
  }
  if ( (a4 & 0xF) == 0 )
  {
    v9 = 16;
    goto LABEL_6;
  }
  return -1073741820;
}
