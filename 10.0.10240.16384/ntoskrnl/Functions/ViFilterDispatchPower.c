// ViFilterDispatchPower 
 
int __fastcall ViFilterDispatchPower(int a1, int a2, int a3, int a4)
{
  int v4; // r2
  int v6; // r3
  int v7; // r4
  int *v8; // r5
  int *v9; // r6
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r2
  int v19[6]; // [sp+8h] [bp-18h] BYREF

  v19[0] = a3;
  v19[1] = a4;
  v4 = *(_DWORD *)(a1 + 40);
  v19[0] = v4;
  v6 = *(_DWORD *)(v4 + 64);
  __dmb(0xBu);
  while ( (v6 & 1) == 0 )
  {
    __dmb(0xAu);
    __yield();
    v6 = *(_DWORD *)(v4 + 64);
    __dmb(0xBu);
  }
  v7 = IoAcquireRemoveLockEx((_BYTE *)(v19[0] + 16), a2, (int)byte_901D79, 1, 24);
  if ( v7 >= 0 )
  {
    v8 = *(int **)(a2 + 96);
    v9 = v8 - 10;
    v10 = *v8;
    v11 = v8[1];
    v12 = v8[2];
    v13 = v8[3];
    v8 += 4;
    *v9 = v10;
    v9[1] = v11;
    v9[2] = v12;
    v9[3] = v13;
    v14 = v8[1];
    v15 = v8[2];
    v16 = v8[3];
    v9[4] = *v8;
    v9[5] = v14;
    v9[6] = v15;
    v9[7] = v16;
    *((_BYTE *)v9 + 3) = 0;
    v17 = *(_DWORD *)(a2 + 96);
    *(_DWORD *)(v17 - 8) = ViFilterGenericCompletionRoutine;
    *(_DWORD *)(v17 - 4) = v19;
    *(_BYTE *)(v17 - 37) = -32;
    v7 = PoCallDriver(*(_DWORD *)(v19[0] + 4), a2);
  }
  else
  {
    *(_DWORD *)(a2 + 24) = v7;
    IofCompleteRequest(a2, 0);
  }
  return v7;
}
