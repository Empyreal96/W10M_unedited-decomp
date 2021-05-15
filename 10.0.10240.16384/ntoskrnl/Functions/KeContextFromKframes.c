// KeContextFromKframes 
 
_BYTE *__fastcall KeContextFromKframes(int a1, _DWORD *a2, int a3)
{
  _BYTE *result; // r0
  _BYTE *v7; // r8
  unsigned int v8; // r3
  unsigned int v9; // r4
  int v10; // r2
  _BYTE *v11; // r0
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3

  result = (_BYTE *)KeGetCurrentIrql(a1);
  v7 = result;
  if ( !result )
    result = (_BYTE *)KfRaiseIrql(1);
  if ( *(_BYTE *)(a1 + 17) )
    return (_BYTE *)sub_547924();
  v8 = *(_DWORD *)a3 & 0xDFFFFFFF;
  *(_DWORD *)a3 = v8;
  v9 = v8;
  if ( (v8 & 0x200001) == 2097153 )
  {
    *(_DWORD *)(a3 + 56) = *(_DWORD *)(a1 + 116);
    *(_DWORD *)(a3 + 60) = *(_DWORD *)(a1 + 120);
    *(_DWORD *)(a3 + 64) = *(_DWORD *)(a1 + 128);
    *(_DWORD *)(a3 + 68) = *(_DWORD *)(a1 + 132);
  }
  if ( (v8 & 0x200002) == 2097154 )
  {
    *(_DWORD *)(a3 + 4) = *(_DWORD *)(a1 + 96);
    *(_DWORD *)(a3 + 8) = *(_DWORD *)(a1 + 100);
    *(_DWORD *)(a3 + 12) = *(_DWORD *)(a1 + 104);
    *(_DWORD *)(a3 + 16) = *(_DWORD *)(a1 + 108);
    *(_DWORD *)(a3 + 48) = *(_DWORD *)(a1 + 124);
    *(_DWORD *)(a3 + 52) = *(_DWORD *)(a1 + 112);
    *(_DWORD *)(a3 + 20) = a2[5];
    *(_DWORD *)(a3 + 24) = a2[6];
    *(_DWORD *)(a3 + 28) = a2[7];
    *(_DWORD *)(a3 + 32) = a2[8];
    *(_DWORD *)(a3 + 36) = a2[9];
    *(_DWORD *)(a3 + 40) = a2[10];
    *(_DWORD *)(a3 + 44) = a2[11];
  }
  if ( (v8 & 0x200004) == 2097156 )
  {
    v10 = KiGetVfpStatePointer(a1);
    v11 = (_BYTE *)(a3 + 80);
    if ( v10 )
    {
      *(_DWORD *)(a3 + 72) = *(_DWORD *)(v10 + 4);
      result = (_BYTE *)memmove((int)v11, v10 + 16, 0x100u);
    }
    else
    {
      *(_DWORD *)(a3 + 72) = 0;
      result = memset(v11, 0, 256);
    }
  }
  if ( (v9 & 0x200008) == 2097160 )
  {
    if ( KiCP14DebugEnabled && *(_BYTE *)(a1 + 18) )
    {
      v13 = *(_DWORD *)(a1 + 28);
      v14 = *(_DWORD *)(a1 + 32);
      v15 = *(_DWORD *)(a1 + 36);
      *(_DWORD *)(a3 + 336) = *(_DWORD *)(a1 + 24);
      *(_DWORD *)(a3 + 340) = v13;
      *(_DWORD *)(a3 + 344) = v14;
      *(_DWORD *)(a3 + 348) = v15;
      v16 = *(_DWORD *)(a1 + 44);
      v17 = *(_DWORD *)(a1 + 48);
      v18 = *(_DWORD *)(a1 + 52);
      *(_DWORD *)(a3 + 352) = *(_DWORD *)(a1 + 40);
      *(_DWORD *)(a3 + 356) = v16;
      *(_DWORD *)(a3 + 360) = v17;
      *(_DWORD *)(a3 + 364) = v18;
      v19 = *(_DWORD *)(a1 + 60);
      v20 = *(_DWORD *)(a1 + 64);
      v21 = *(_DWORD *)(a1 + 68);
      *(_DWORD *)(a3 + 368) = *(_DWORD *)(a1 + 56);
      *(_DWORD *)(a3 + 372) = v19;
      *(_DWORD *)(a3 + 376) = v20;
      *(_DWORD *)(a3 + 380) = v21;
      result = *(_BYTE **)(a1 + 72);
      v22 = *(_DWORD *)(a1 + 76);
      v23 = *(_DWORD *)(a1 + 80);
      v24 = *(_DWORD *)(a1 + 84);
      *(_DWORD *)(a3 + 384) = result;
      *(_DWORD *)(a3 + 388) = v22;
      *(_DWORD *)(a3 + 392) = v23;
      *(_DWORD *)(a3 + 396) = v24;
      *(_DWORD *)(a3 + 400) = *(_DWORD *)(a1 + 88);
      v12 = *(_DWORD *)(a1 + 92);
    }
    else
    {
      memset((_BYTE *)(a3 + 336), 0, 32);
      result = memset((_BYTE *)(a3 + 368), 0, 32);
      v12 = 0;
      *(_DWORD *)(a3 + 400) = 0;
    }
    *(_DWORD *)(a3 + 404) = v12;
  }
  if ( !v7 )
    result = (_BYTE *)KfLowerIrql(0);
  return result;
}
