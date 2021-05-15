// MiUpdatePfnPriorityByPte 
 
int __fastcall MiUpdatePfnPriorityByPte(unsigned int a1, int a2)
{
  unsigned int v3; // r4
  int result; // r0
  int v5; // r4
  int v6; // r6
  unsigned __int8 *v7; // r1
  unsigned int v8; // r2
  unsigned int *v9; // r2
  unsigned int v10; // r0
  int _1C; // [sp+1Ch] [bp+Ch]

  _1C = a2;
  if ( (a1 & 2) != 0 )
  {
    v3 = a1 >> 12;
  }
  else if ( (a1 & 0x400) != 0 || (a1 & 0x800) == 0 )
  {
    v3 = -1;
  }
  else
  {
    v3 = a1 >> 12;
  }
  result = MI_IS_PFN(v3);
  if ( result )
  {
    v5 = MmPfnDatabase + 24 * v3;
    v6 = KfRaiseIrql(2);
    v7 = (unsigned __int8 *)(v5 + 15);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
    __dmb(0xBu);
    if ( v8 >> 7 )
    {
      result = sub_5456A4();
    }
    else
    {
      MiUpdatePfnPriority(v5, a2, 0);
      __dmb(0xBu);
      v9 = (unsigned int *)(v5 + 12);
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 & 0x7FFFFFFF, v9) );
      result = KfLowerIrql(v6);
    }
  }
  return result;
}
