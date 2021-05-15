// IoCsqRemoveIrp 
 
int __fastcall IoCsqRemoveIrp(int a1, int a2, int a3, int a4)
{
  void (__fastcall *v5)(int, int *); // r3
  int v7; // r5
  int v8; // r7
  unsigned int *v9; // r2
  unsigned int v10; // r4
  int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a4;
  v5 = *(void (__fastcall **)(int, int *))(a1 + 16);
  v7 = 0;
  *(_DWORD *)(a1 + 28) = 0;
  v5(a1, v12);
  v8 = *(_DWORD *)(a2 + 4);
  if ( v8 )
  {
    __dmb(0xBu);
    v9 = (unsigned int *)(v8 + 56);
    do
      v10 = __ldrex(v9);
    while ( __strex(0, v9) );
    __dmb(0xBu);
    if ( v10 )
    {
      (*(void (__fastcall **)(int, int))(a1 + 8))(a1, v8);
      *(_DWORD *)(a2 + 4) = 0;
      *(_DWORD *)(v8 + 76) = 0;
      v7 = v8;
    }
  }
  (*(void (__fastcall **)(int, _DWORD))(a1 + 20))(a1, LOBYTE(v12[0]));
  return v7;
}
