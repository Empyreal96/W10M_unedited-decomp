// KiSetPriorityFloor 
 
int __fastcall KiSetPriorityFloor(int a1, _DWORD *a2, char a3)
{
  int v3; // r5
  int v4; // r7
  unsigned int *v5; // r6
  unsigned int v6; // r4
  int v7; // r2
  int v8; // r3
  int v9; // r3

  v3 = a3;
  v4 = 0;
  v5 = (unsigned int *)(a1 + 44);
  while ( 1 )
  {
    do
      v6 = __ldrex(v5);
    while ( __strex(1u, v5) );
    __dmb(0xBu);
    if ( !v6 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v5 );
  }
  v7 = a3 + a1;
  v8 = *(unsigned __int8 *)(v3 + a1 + 784);
  if ( v8 == 255 )
    sub_50ECD8();
  *(_BYTE *)(v7 + 784) = v8 + 1;
  *(_DWORD *)(a1 + 800) |= 1 << v3;
  v9 = *(char *)(a1 + 123);
  if ( v9 < v3 )
  {
    KiSetPriorityThread(a1, a2, v3, v9);
    v4 = 1;
  }
  __dmb(0xBu);
  *v5 = 0;
  return v4;
}
