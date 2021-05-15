// PopPepStartActivity 
 
int __fastcall PopPepStartActivity(int a1, int a2, int a3, int a4, unsigned int *a5, int a6)
{
  unsigned int v8; // r6
  int result; // r0

  __dmb(0xBu);
  do
    v8 = __ldrex(a5);
  while ( __strex(v8 - 1, a5) );
  __dmb(0xBu);
  result = (*(int (__fastcall **)(int, int, int))&ActivityAttributes[124 * a4 + 116])(a1, a2, a6);
  **(_DWORD **)(a3 + 4 * a4) &= 0xFFFFFFFD;
  **(_DWORD **)(a3 + 4 * a4) &= 0xFFFFFFF7;
  **(_DWORD **)(a3 + 4 * a4) |= 4u;
  return result;
}
