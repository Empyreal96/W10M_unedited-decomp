// EtwTraceAutoBoostSetFloor 
 
int *__fastcall EtwTraceAutoBoostSetFloor(int a1, int a2, char a3, char a4, char a5, char a6, int a7, int a8)
{
  int v8; // r1
  int v9; // r2
  __int16 v10; // r3
  char v11; // r2
  char v12; // r2
  int v14[2]; // [sp+8h] [bp-30h] BYREF
  char v15; // [sp+10h] [bp-28h]
  char v16; // [sp+11h] [bp-27h]
  char v17; // [sp+12h] [bp-26h]
  char v18; // [sp+13h] [bp-25h]
  int v19[8]; // [sp+18h] [bp-20h] BYREF

  v15 = a3;
  v14[0] = a2;
  v8 = *(_DWORD *)(a1 + 880);
  v16 = a5;
  v14[1] = v8;
  v17 = a4 & 0xF | (16 * a6);
  v18 = 0;
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v9 = 0;
  }
  else
  {
    __disable_irq();
    v9 = 1;
  }
  v10 = *(_WORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
  if ( v9 )
    __enable_irq();
  v11 = v18 ^ (((v10 & 1) != 0) ^ v18) & 1;
  v12 = v11 ^ (v11 ^ (2 * (a7 != 0))) & 2;
  v18 = (v12 ^ (4 * (a8 != 0))) & 4 ^ v12;
  v19[0] = (int)v14;
  v19[1] = 0;
  v19[2] = 12;
  v19[3] = 0;
  return EtwTraceKernelEvent(v19, 1, 0x20000200u, 1346, 5245442);
}
