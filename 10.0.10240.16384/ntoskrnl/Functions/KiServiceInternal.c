// KiServiceInternal 
 
int KiServiceInternal()
{
  int v0; // r12
  int v1; // r0
  unsigned int v2; // r12
  int result; // r0
  unsigned int v4; // r1
  int v5; // [sp+8h] [bp-80h]
  char v6; // [sp+13h] [bp-75h]

  __get_CPSR();
  __enable_irq();
  v1 = v0;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(_BYTE *)(v2 + 346);
  v5 = *(_DWORD *)(v2 + 96);
  *(_BYTE *)(v2 + 346) = 0;
  result = KiSystemService(v1);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v4 + 96) = v5;
  *(_BYTE *)(v4 + 346) = v6;
  return result;
}
