// EtwTraceReadyThread 
 
int *__fastcall EtwTraceReadyThread(int a1, char a2, char a3, char a4)
{
  int v5; // r2
  int v6; // r3
  int v7; // r3
  char v8; // r2
  void (__noreturn *v9)(); // r2
  int v10; // r1
  int v12; // [sp+8h] [bp-28h] BYREF
  char v13; // [sp+Ch] [bp-24h]
  char v14; // [sp+Dh] [bp-23h]
  char v15; // [sp+Eh] [bp-22h]
  char v16; // [sp+Fh] [bp-21h]
  int v17[8]; // [sp+10h] [bp-20h] BYREF

  v12 = *(_DWORD *)(a1 + 880);
  v13 = a2;
  v14 = a3;
  v15 = 0;
  v16 = 0;
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v5 = 0;
  }
  else
  {
    __disable_irq();
    v5 = 1;
  }
  v6 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
  if ( v5 )
    __enable_irq();
  v15 ^= (v15 ^ (v6 ^ v15) & 1 ^ (2 * ((*(_WORD *)(a1 + 82) & 1) == 0))) & 2 ^ (v6 ^ v15) & 1;
  v7 = *(_DWORD *)(*(_DWORD *)(a1 + 116) + 116);
  __dmb(0xBu);
  v8 = v15 ^ (v15 ^ (4 * ((v7 & 7) != 0))) & 4;
  LOBYTE(v7) = (v8 ^ (8 * ((a4 & 1) != 0))) & 8 ^ v8;
  v9 = *(void (__noreturn **)())(a1 + 924);
  v10 = 5249538;
  v15 = v7;
  if ( (a4 & 2) != 0 || v9 == KeSwapProcessOrStack || (char *)v9 == (char *)EtwpLogger )
    v10 = 5245442;
  v17[0] = (int)&v12;
  v17[1] = 0;
  v17[2] = 8;
  v17[3] = 0;
  return EtwTraceKernelEvent(v17, 1, 0x20000200u, 1330, v10);
}
