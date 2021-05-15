// sub_9683E8 
 
void __fastcall sub_9683E8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, unsigned int a9, int a10)
{
  int v10; // r5
  unsigned int v11; // r6
  int v12; // r7
  int v13; // r10
  int v14; // r1
  int (__fastcall *v15)(int, int, int *); // r3
  int v16; // r0
  int v17; // r9
  int v18; // r1
  unsigned int i; // r8
  int v20; // r1
  int (__fastcall *v21)(int, int, int *); // r3
  int v22; // r1
  unsigned int v23; // r2

  v14 = *(_DWORD *)(v12 + 8);
  v15 = *(int (__fastcall **)(int, int, int *))(v10 + 4);
  a6 = a3;
  a7 = a3;
  a5 = a3;
  v16 = v15(v10, v14, &a7);
  v17 = v16;
  if ( v16 )
  {
    v18 = (*(int (__fastcall **)(int, _DWORD, int *))(v10 + 4))(v10, *(_DWORD *)(v16 + 4), &a6);
    a10 = v18;
    if ( v18 )
    {
      if ( *(_DWORD *)(v12 + 4) <= v11 )
        v11 = *(_DWORD *)(v12 + 4);
      for ( i = 0; i < *(unsigned __int16 *)(v17 + 2); v11 -= 16344 )
      {
        v20 = *(_DWORD *)(v18 + 4 * i);
        v21 = *(int (__fastcall **)(int, int, int *))(v10 + 4);
        a9 = i;
        v22 = v21(v10, v20, &a5);
        if ( !v22 )
          break;
        v23 = v11 <= 0x3FD8 ? v11 : 16344;
        memmove(v13 + 16344 * a9, v22, v23);
        (*(void (__fastcall **)(int, int *))(v10 + 8))(v10, &a5);
        if ( v11 <= 0x3FD8 )
          break;
        i = (unsigned __int16)(i + 1);
        v18 = a10;
      }
      (*(void (__fastcall **)(int, int *))(v10 + 8))(v10, &a6);
    }
    (*(void (__fastcall **)(int, int *))(v10 + 8))(v10, &a7);
    JUMPOUT(0x94F456);
  }
  JUMPOUT(0x94F496);
}
