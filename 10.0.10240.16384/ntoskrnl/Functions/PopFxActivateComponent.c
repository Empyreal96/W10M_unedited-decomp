// PopFxActivateComponent 
 
int __fastcall PopFxActivateComponent(int result, int a2, char a3, int a4)
{
  int v4; // r4
  unsigned int *v7; // r6
  char *v8; // r4
  unsigned int v9; // r2
  signed int v10; // r2
  unsigned int v11; // r1
  char v12; // [sp+8h] [bp-38h] BYREF

  v4 = *(_DWORD *)(result + 384);
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
  {
    v7 = (unsigned int *)(a2 + 52);
    if ( (a3 & 2) != 0 )
      v8 = 0;
    else
      v8 = &v12;
    __dmb(0xBu);
    do
    {
      v9 = __ldrex(v7);
      v10 = v9 + 1;
    }
    while ( __strex(v10, v7) );
    __dmb(0xBu);
    if ( v10 == 1 )
    {
      __dmb(0xBu);
      do
        v11 = __ldrex(v7);
      while ( __strex(v11 + 1, v7) );
      __dmb(0xBu);
      result = PopFxActivateComponentWorker(result, a2, a4, (int)v8);
      if ( (a3 & 1) != 0 )
        result = KeWaitForSingleObject(a2 + 64, 0, 0, 0, 0);
    }
    else if ( v10 >= 0 )
    {
      result = sub_50F28C();
    }
  }
  return result;
}
