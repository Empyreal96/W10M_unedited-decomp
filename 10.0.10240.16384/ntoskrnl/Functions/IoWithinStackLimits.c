// IoWithinStackLimits 
 
int __fastcall IoWithinStackLimits(unsigned int a1, int a2)
{
  unsigned int v2; // r7
  _DWORD *v3; // r2
  int v4; // r1
  __int16 v5; // r3
  unsigned int v7; // r1
  unsigned int v8; // r3
  _DWORD *v9; // r2
  unsigned int v10; // [sp+0h] [bp-20h]
  unsigned int v11; // [sp+4h] [bp-1Ch]

  v2 = a1 + a2;
  v3 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v4 = 0;
  }
  else
  {
    __disable_irq();
    v4 = 1;
  }
  v5 = *(_WORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
  if ( v4 )
    __enable_irq();
  if ( (v5 & 1) != 0 )
    return sub_51D37C();
  v7 = v3[10];
  v8 = v3[9];
  v9 = (_DWORD *)v3[8];
  while ( a1 < v8 || v2 > v7 )
  {
    if ( !v9[2] )
      return 0;
    v10 = v9[2];
    v11 = v9[3];
    v9 = (_DWORD *)v9[5];
    v7 = v10;
    v8 = v11;
  }
  return 1;
}
