// EtwpTraceStackWalk 
 
int *__fastcall EtwpTraceStackWalk(int a1, unsigned int a2, __int64 a3)
{
  int *result; // r0
  int v5; // r9
  int v6; // r1
  int v7; // r2
  int v8; // r3
  char *v9; // r5
  char *v10; // r4
  int *v11; // r6
  unsigned int v12; // r4
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r6
  unsigned int v16; // r6
  unsigned __int16 v17; // r1
  int v18; // r8
  int v19; // r2
  char v20; // [sp+8h] [bp-370h] BYREF
  int v21; // [sp+300h] [bp-78h]
  int v22; // [sp+308h] [bp-70h]
  __int64 v23; // [sp+30Ch] [bp-6Ch]
  int v24; // [sp+314h] [bp-64h] BYREF
  unsigned int v25; // [sp+318h] [bp-60h] BYREF
  unsigned int v26; // [sp+31Ch] [bp-5Ch] BYREF
  _DWORD v27[6]; // [sp+320h] [bp-58h] BYREF
  int v28[16]; // [sp+338h] [bp-40h] BYREF

  v23 = a3;
  v22 = a1;
  result = (int *)KeQueryCurrentStackInformation(&v24, &v25, &v26, SHIDWORD(a3));
  if ( result && v24 && v24 != 5 )
  {
    v5 = 256;
    result = (int *)RtlpInterlockedPopEntrySList(&EtwpStackLookAsideList);
    if ( result )
    {
      v9 = (char *)(result + 1);
      if ( result != (int *)-4 )
        goto LABEL_9;
    }
    else
    {
      v8 = dword_61ABF8;
    }
    result = KeGetCurrentStackPointer((int)result, v6, v7, v8, v21);
    if ( (unsigned int)result - v25 <= 0x5D8 )
      return result;
    v9 = &v20;
    v5 = 192;
LABEL_9:
    v10 = 0;
    v11 = 0;
    if ( (a2 & 0x800) != 0 )
    {
      v12 = (a2 >> 20) & 0xF;
      v13 = v12 << 8;
      if ( (a2 & 0x2000000) != 0 )
        v13 |= 2u;
      result = (int *)RtlWalkFrameChain((int)v9, v12 + v5, v13);
      if ( (unsigned int)result > v12 )
        v10 = (char *)result - v12;
      else
        v10 = 0;
    }
    if ( (a2 & 0x1000) != 0 )
    {
      v14 = (int)&v9[4 * (_DWORD)v10];
      if ( *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 780) )
      {
        result = (int *)PsPicoWalkUserStack(v14, v5 - (_DWORD)v10);
        v11 = result;
      }
      else
      {
        v15 = HIWORD(a2) & 0xF;
        result = (int *)RtlWalkFrameChain(v14, v15 - (_DWORD)v10 + v5, (v15 << 8) | 1);
        if ( (unsigned int)result > v15 )
          v11 = (int *)((char *)result - v15);
        else
          v11 = 0;
      }
    }
    v16 = (unsigned int)&v10[(_DWORD)v11];
    if ( !v16 )
      goto LABEL_29;
    v17 = v22;
    v18 = a2 & 0xFFFFE602 | 2;
    v27[2] = *(_DWORD *)(v23 + 876);
    v27[3] = *(_DWORD *)(v23 + 880);
    v27[0] = *(_DWORD *)HIDWORD(v23);
    v27[1] = *(_DWORD *)(HIDWORD(v23) + 4);
    v28[0] = (int)v27;
    v28[1] = 0;
    v28[2] = 16;
    v28[3] = 0;
    if ( (v22 & 0x1000000) != 0 && v16 >= 4 )
    {
      v19 = 6182;
      if ( v10 )
        v19 = 6181;
      result = (int *)EtwpTraceStackKey((unsigned __int16)v22, v18, v19, v28, v9, v16);
      if ( result )
        goto LABEL_29;
      v17 = v22;
    }
    v28[4] = (int)v9;
    v28[5] = 0;
    v28[6] = 4 * v16;
    v28[7] = 0;
    result = (int *)EtwpLogKernelEvent(v28, v17, 2, 6176, v18);
LABEL_29:
    if ( v5 == 256 )
      result = (int *)RtlpInterlockedPushEntrySList(&EtwpStackLookAsideList, (_DWORD *)v9 - 1);
  }
  return result;
}
