// KiTimerExpirationDpc 
 
int __fastcall KiTimerExpirationDpc(int a1, int a2, int a3)
{
  int result; // r0
  unsigned int v5; // r4
  int v6; // r2
  int v7; // r3
  unsigned int v8; // r5
  unsigned int v9; // r6
  int *v10; // [sp+0h] [bp-100h]
  int v11[58]; // [sp+18h] [bp-E8h] BYREF

  if ( (dword_682608 & 0x20000) != 0 )
    return sub_553280();
  v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v11[0] = 0;
  while ( 1 )
  {
    v6 = MEMORY[0xFFFF9018];
    __dmb(0xBu);
    v7 = MEMORY[0xFFFF9014];
    v11[3] = v6;
    __dmb(0xBu);
    v11[2] = v7;
    if ( v6 == MEMORY[0xFFFF901C] )
      break;
    __dmb(0xAu);
    __yield();
  }
  __disable_irq();
  while ( 1 )
  {
    v8 = MEMORY[0xFFFF900C];
    __dmb(0xBu);
    v9 = MEMORY[0xFFFF9008];
    __dmb(0xBu);
    if ( v8 == MEMORY[0xFFFF9010] )
      break;
    __dmb(0xAu);
    __yield();
  }
  *(_DWORD *)(v5 + 3168) = (v8 << 14) | (v9 >> 18);
  v10 = v11;
  __enable_irq();
  result = KiTimerExpiration(v5 + 1408, a3, v9, v8, v10);
  __dmb(0xBu);
  *(_DWORD *)(v5 + 3108) = 0;
  if ( *(_BYTE *)(v5 + 1425) )
    result = KiTimer2Expiration(v5 + 1408, __PAIR64__(v8, v9), v11);
  return result;
}
