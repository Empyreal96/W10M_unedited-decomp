// KiInitializeContextThread 
 
_BYTE *__fastcall KiInitializeContextThread(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r5
  int v6; // r6
  int v8; // r9
  _BYTE *result; // r0
  int v10; // r10
  int v11; // r5
  int v12; // r7
  _DWORD *v13; // r3
  int v17; // [sp+14h] [bp-1C4h]
  int v18[112]; // [sp+18h] [bp-1C0h] BYREF

  v5 = *(_DWORD *)(a1 + 32);
  v6 = a4;
  v17 = v5 - 272;
  memset((_BYTE *)(v5 - 272), 0, 272);
  v8 = v5 - 296;
  result = memset((_BYTE *)(v5 - 296), 0, 296);
  *(_DWORD *)(v5 - 296) = v5;
  *(_DWORD *)(v5 - 292) = v5 - KeKernelStackSize;
  if ( a5 )
  {
    memmove((int)v18, a5, 0x1A0u);
    v10 = v5 - 704;
    v18[0] = v18[0] & 2 | 0x200001;
    v11 = v18[0];
    v12 = v8 - 496;
    memset((_BYTE *)(v8 - 464), 0, 56);
    memset((_BYTE *)(v8 - 408), 0, 408);
    *(_BYTE *)(v8 - 392) = 1;
    result = (_BYTE *)KeContextToKframes(v8 - 408, (_DWORD *)(v8 - 464), v18, v11, 1);
    *(_DWORD *)(v8 - 480) = a4;
    *(_DWORD *)(v8 - 476) = a3;
    *(_DWORD *)(v8 - 472) = a2;
    *(_DWORD *)(v8 - 412) = KiStartUserThreadReturn;
    *(_DWORD *)(v8 - 484) = KiStartUserThread;
    *(_BYTE *)(a1 + 346) = 1;
  }
  else
  {
    v13 = (_DWORD *)(v5 - 312);
    v12 = v5 - 328;
    *v13 = v6;
    v13[1] = a3;
    v10 = 0;
    v13[2] = a2;
    v13[3] = 0;
    *(_DWORD *)(v5 - 316) = KiStartSystemThread;
    *(_BYTE *)(a1 + 346) = 0;
  }
  *(_BYTE *)v12 = 1;
  *(_DWORD *)(v12 + 8) = v10;
  *(_DWORD *)(a1 + 320) = v17;
  *(_DWORD *)(a1 + 32) = v8;
  *(_DWORD *)(a1 + 64) = v12;
  return result;
}
