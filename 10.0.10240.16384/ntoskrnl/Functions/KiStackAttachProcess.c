// KiStackAttachProcess 
 
int __fastcall KiStackAttachProcess(int result, int a2, int a3)
{
  int v5; // r5
  unsigned int v6; // r4
  int v7; // r2
  int v8; // r3
  int v9; // r0
  unsigned int *v10; // r1
  unsigned int v11; // r2
  int v12; // r3

  v5 = result;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
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
  if ( (v8 & 0x10001) != 0 )
    sub_50CE18();
  if ( *(_DWORD *)(v6 + 116) == result )
  {
    v12 = 1;
    goto LABEL_13;
  }
  v9 = KfRaiseIrql(2);
  v10 = (unsigned int *)(v6 + 44);
  while ( 1 )
  {
    do
      v11 = __ldrex(v10);
    while ( __strex(1u, v10) );
    __dmb(0xBu);
    if ( !v11 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v10 );
  }
  if ( !*(_BYTE *)(v6 + 362) )
  {
    result = KiAttachProcess(v6, v5, v9, a2);
    v12 = 0;
LABEL_13:
    *(_DWORD *)(a3 + 16) = v12;
    return result;
  }
  return KiAttachProcess(v6, v5, v9, a2);
}
