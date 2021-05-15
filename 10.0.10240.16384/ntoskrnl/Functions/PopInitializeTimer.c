// PopInitializeTimer 
 
int __fastcall PopInitializeTimer(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int result; // r0
  unsigned int *v8; // r1
  unsigned int v9; // r4

  result = KeInitializeTimer2((int)a1, a2, a3, 8);
  __dmb(0xBu);
  v8 = a1 + 26;
  do
    v9 = __ldrex(v8);
  while ( __strex(0, v8) );
  __dmb(0xBu);
  a1[24] = a4;
  a1[25] = a5;
  a1[22] = 0;
  return result;
}
