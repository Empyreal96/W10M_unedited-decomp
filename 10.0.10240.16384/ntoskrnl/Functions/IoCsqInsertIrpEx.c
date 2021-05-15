// IoCsqInsertIrpEx 
 
int __fastcall IoCsqInsertIrpEx(int a1, int a2, int a3, int a4)
{
  int v4; // r7
  void (__fastcall *v9)(int, int *); // r3
  int (__fastcall *v10)(int, int, int); // r3
  int v11; // r0
  unsigned int *v12; // r0
  unsigned int v13; // r1
  unsigned int v14; // r2
  int v15; // r1
  int v16[8]; // [sp+0h] [bp-20h] BYREF

  v16[0] = a4;
  v4 = 0;
  if ( a3 )
    return sub_525FF0();
  *(_DWORD *)(a2 + 76) = a1;
  v9 = *(void (__fastcall **)(int, int *))(a1 + 16);
  *(_DWORD *)(a1 + 28) = 0;
  v9(a1, v16);
  v10 = *(int (__fastcall **)(int, int, int))(a1 + 4);
  if ( *(_DWORD *)a1 == 3 )
  {
    v4 = v10(a1, a2, a4);
    if ( v4 < 0 )
    {
LABEL_5:
      v11 = a1;
      goto LABEL_6;
    }
  }
  else
  {
    ((void (__fastcall *)(int, int))v10)(a1, a2);
  }
  *(_BYTE *)(*(_DWORD *)(a2 + 96) + 3) |= 1u;
  __dmb(0xBu);
  v12 = (unsigned int *)(a2 + 56);
  do
    v13 = __ldrex(v12);
  while ( __strex((unsigned int)IopCsqCancelRoutine, v12) );
  __dmb(0xBu);
  if ( !*(_BYTE *)(a2 + 36) )
    goto LABEL_5;
  __dmb(0xBu);
  do
    v14 = __ldrex(v12);
  while ( __strex(0, v12) );
  __dmb(0xBu);
  v11 = a1;
  if ( v14 )
  {
    (*(void (__fastcall **)(int, int))(a1 + 8))(a1, a2);
    v15 = LOBYTE(v16[0]);
    *(_DWORD *)(a2 + 76) = 0;
    (*(void (__fastcall **)(int, int))(a1 + 20))(a1, v15);
    (*(void (__fastcall **)(int, int))(a1 + 24))(a1, a2);
    return v4;
  }
LABEL_6:
  (*(void (__fastcall **)(int, _DWORD))(a1 + 20))(v11, LOBYTE(v16[0]));
  return v4;
}
