// sub_805E7C 
 
void __fastcall sub_805E7C(int a1, int a2, int a3, int a4, char a5, int a6)
{
  int v6; // r4
  int v7; // r6
  int v8; // r9
  int (__fastcall *v9)(int, int, char *); // r3
  int v10; // r0
  int v11; // r5
  int v12; // r1
  int v13; // r8
  int v14; // r2
  unsigned __int16 v15; // r7
  unsigned int v16; // r1

  v9 = *(int (__fastcall **)(int, int, char *))(v6 + 4);
  a6 = v8;
  v10 = v9(v6, v7, &a5);
  v11 = v10;
  if ( v10 )
  {
    v12 = *(_DWORD *)(v10 + 4);
    if ( v12 != v8 )
    {
      v13 = (*(int (__fastcall **)(int, int, int *))(v6 + 4))(v6, v12, &a6);
      if ( !v13 )
      {
        (*(void (__fastcall **)(int, char *))(v6 + 8))(v6, &a5);
        goto LABEL_13;
      }
      v14 = 0;
      if ( *(_WORD *)(v11 + 2) )
      {
        v15 = 0;
        do
        {
          v16 = *(_DWORD *)(v13 + 4 * v14);
          if ( v16 != v8 )
            HvFreeCell(v6, v16);
          v14 = ++v15;
        }
        while ( v15 < (unsigned int)*(unsigned __int16 *)(v11 + 2) );
      }
      (*(void (__fastcall **)(int, int *, int))(v6 + 8))(v6, &a6, v14);
      HvFreeCell(v6, *(_DWORD *)(v11 + 4));
    }
    (*(void (__fastcall **)(int, char *))(v6 + 8))(v6, &a5);
    JUMPOUT(0x7522F8);
  }
LABEL_13:
  JUMPOUT(0x752302);
}
