// EtwpProfileInterrupt 
 
int *__fastcall EtwpProfileInterrupt(int a1)
{
  unsigned int v1; // r1
  int v2; // r2
  unsigned int v3; // r0
  char v4; // r3
  unsigned int v5; // r4
  unsigned int v6; // r3
  int v7; // r1
  int v8; // r3
  char v9; // r3
  int v10; // r1
  unsigned int v11; // r3
  int v13[2]; // [sp+8h] [bp-28h] BYREF
  __int16 v14; // [sp+10h] [bp-20h]
  char v15; // [sp+12h] [bp-1Eh]
  char v16; // [sp+13h] [bp-1Dh]
  int v17[6]; // [sp+18h] [bp-18h] BYREF

  v1 = *(_DWORD *)(a1 + 128);
  v2 = 33610242;
  if ( v1 <= MmHighestUserAddress )
    v2 = 33608194;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13[1] = *(_DWORD *)(v3 + 0x370);
  v15 = 0;
  v4 = *(_BYTE *)(v3 + 0x7B);
  v13[0] = v1;
  v15 = 8 * v4;
  v14 = 1;
  v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v6 = *(unsigned __int8 *)(v5 + 1424);
  if ( v6 != 2 )
  {
    if ( v6 <= 1 )
      goto LABEL_14;
    goto LABEL_12;
  }
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v7 = 0;
  }
  else
  {
    __disable_irq();
    v7 = 1;
  }
  v8 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
  if ( v7 )
    __enable_irq();
  if ( (v8 & 0x10001) == 0 )
  {
LABEL_12:
    v9 = v15 | 2;
    goto LABEL_13;
  }
  v9 = v15 | 1;
LABEL_13:
  v2 &= 0xFFFFBFFF;
  v15 = v9;
LABEL_14:
  v10 = *(_DWORD *)(v3 + 68);
  __dmb(0xBu);
  if ( v10 )
  {
    v11 = *(_DWORD *)(*(_DWORD *)(v5 + 3760) + v10 + 96);
    if ( v11 > 0xFF )
      LOBYTE(v11) = -1;
  }
  else
  {
    LOBYTE(v11) = 0;
  }
  v16 = v11;
  v17[0] = (int)v13;
  v17[1] = 0;
  v17[2] = 12;
  v17[3] = 0;
  return EtwTraceKernelEvent(v17, 1, 0x20000002u, 3886, v2);
}
