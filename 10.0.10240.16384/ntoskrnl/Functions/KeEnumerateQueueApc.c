// KeEnumerateQueueApc 
 
int __fastcall KeEnumerateQueueApc(int a1, void (__fastcall *a2)(_DWORD *, int, int), int a3, char *a4)
{
  int v5; // r4
  int v6; // r7
  unsigned int *v7; // r6
  unsigned int v8; // r2
  int v9; // r5
  _DWORD *v10; // r8
  int v11; // r4
  _DWORD *v15; // [sp+8h] [bp-28h]
  int v16; // [sp+Ch] [bp-24h]

  if ( a4 )
  {
    v5 = *a4;
    v6 = v5;
  }
  else
  {
    v5 = 0;
    v6 = 1;
  }
  v7 = (unsigned int *)(a1 + 44);
  v15 = (_DWORD *)(a1 + 44);
  v16 = KfRaiseIrql(2);
  while ( 1 )
  {
    do
      v8 = __ldrex(v7);
    while ( __strex(1u, v7) );
    __dmb(0xBu);
    if ( !v8 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v7 );
  }
  v9 = v5;
  do
  {
    v10 = *(_DWORD **)(a1 + 8 * v9 + 100);
    v11 = a1 + 8 * v5 + 100;
    while ( v10 != (_DWORD *)v11 )
    {
      a2(v10 - 3, 48, a3);
      v10 = (_DWORD *)*v10;
    }
    v5 = (char)(v9 + 1);
    v9 = v5;
  }
  while ( v5 <= v6 );
  __dmb(0xBu);
  *v15 = 0;
  return KfLowerIrql(v16);
}
