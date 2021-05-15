// ExInterlockedInsertHeadList 
 
int __fastcall ExInterlockedInsertHeadList(int *a1, int *a2, unsigned int *a3)
{
  int v5; // r4
  unsigned int v6; // r2
  int result; // r0
  int v8; // r2

  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v5 = 0;
  }
  else
  {
    __disable_irq();
    v5 = 1;
  }
  do
    v6 = __ldrex(a3);
  while ( __strex(1u, a3) );
  __dmb(0xBu);
  if ( v6 )
    return sub_5271A8(1);
  v8 = a1[1];
  result = *a1;
  *a2 = *a1;
  a2[1] = (int)a1;
  if ( *(int **)(result + 4) != a1 )
    __fastfail(3u);
  *(_DWORD *)(result + 4) = a2;
  *a1 = (int)a2;
  __dmb(0xBu);
  *a3 = 0;
  if ( v5 )
    __enable_irq();
  if ( result == v8 )
    result = 0;
  return result;
}
