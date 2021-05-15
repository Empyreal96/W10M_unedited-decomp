// PL011InitializePort 
 
int *__fastcall PL011InitializePort(int *result, int a2, int a3)
{
  int v3; // r3
  int v4; // r3
  int v5; // r1
  int v6; // r1

  *result = a2;
  result[1] = 0;
  __dsb(0xFu);
  *(_WORD *)(a2 + 48) = 0;
  v3 = *result;
  __dsb(0xFu);
  *(_BYTE *)(v3 + 44) = 112;
  v4 = *result;
  __dsb(0xFu);
  *(_WORD *)(v4 + 56) = 0;
  v5 = *result;
  __dsb(0xFu);
  *(_WORD *)(v5 + 68) = 2047;
  v6 = *result;
  __dsb(0xFu);
  *(_WORD *)(v6 + 48) = 769;
  result[1] = a3;
  return result;
}
