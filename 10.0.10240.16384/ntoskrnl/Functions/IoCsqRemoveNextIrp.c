// IoCsqRemoveNextIrp 
 
int __fastcall IoCsqRemoveNextIrp(int a1, int a2, int a3, int a4)
{
  void (__fastcall *v5)(int, _DWORD *); // r3
  int v7; // r0
  int v8; // r5
  unsigned int *v10; // r2
  unsigned int v11; // r4
  _DWORD *v12; // r2
  _DWORD v13[8]; // [sp+0h] [bp-20h] BYREF

  v13[0] = a3;
  v13[1] = a4;
  v5 = *(void (__fastcall **)(int, _DWORD *))(a1 + 16);
  *(_DWORD *)(a1 + 28) = 0;
  v5(a1, v13);
  v7 = (*(int (__fastcall **)(int, _DWORD, int))(a1 + 12))(a1, 0, a2);
  v8 = v7;
  if ( !v7 )
  {
    v8 = 0;
LABEL_3:
    (*(void (__fastcall **)(int, _DWORD))(a1 + 20))(a1, LOBYTE(v13[0]));
    return v8;
  }
  __dmb(0xBu);
  v10 = (unsigned int *)(v7 + 56);
  do
    v11 = __ldrex(v10);
  while ( __strex(0, v10) );
  __dmb(0xBu);
  if ( v11 )
  {
    (*(void (__fastcall **)(int, int))(a1 + 8))(a1, v7);
    v12 = *(_DWORD **)(v8 + 76);
    if ( *v12 == 1 )
      v12[1] = 0;
    *(_DWORD *)(v8 + 76) = 0;
    goto LABEL_3;
  }
  return sub_526F0C(a1, v7);
}
