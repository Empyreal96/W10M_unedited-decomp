// KiClearPriorityFloor 
 
int __fastcall KiClearPriorityFloor(int result, int a2, char a3)
{
  unsigned int *v4; // r5
  unsigned int v5; // r4
  char v6; // r3
  unsigned int v7; // r3
  int v8; // r1
  int v9; // r2

  v4 = (unsigned int *)(result + 44);
  do
    v5 = __ldrex(v4);
  while ( __strex(1u, v4) );
  __dmb(0xBu);
  if ( v5 )
    return sub_50AC68();
  if ( !*(_BYTE *)(a3 + result + 784) )
    KeBugCheckEx(343, result, a3);
  v6 = *(_BYTE *)(a3 + result + 784) - 1;
  *(_BYTE *)(a3 + result + 784) = v6;
  if ( !v6 )
  {
    v7 = *(_DWORD *)(result + 800) ^ (1 << a3);
    *(_DWORD *)(result + 800) = v7;
    if ( v7 < 1 << a3 )
    {
      v8 = *(char *)(result + 123);
      if ( v8 < 16 )
      {
        v9 = (char)(*(_BYTE *)(result + 347) + (*(_BYTE *)(result + 348) & 0xF) + (*(_BYTE *)(result + 348) >> 4));
        if ( v9 < v8 )
          result = KiSetPriorityThread(result, a2, v9);
      }
    }
  }
  __dmb(0xBu);
  *v4 = 0;
  return result;
}
