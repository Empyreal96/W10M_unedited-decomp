// MiApplyStraddleFixups 
 
unsigned int __fastcall MiApplyStraddleFixups(unsigned int result, _BYTE *a2, int a3, int a4, int a5, int a6)
{
  int *v6; // r4
  int v9; // r1
  int v10; // r5
  int v11; // r7
  int v12; // r5
  int v13; // r3
  _BYTE *v14; // r6
  int v15; // r7
  int v16; // r5
  char *v17; // r2
  int v18; // [sp+0h] [bp-30h]
  int v19[10]; // [sp+8h] [bp-28h] BYREF

  v6 = *(int **)(result + 8);
  v18 = a3;
  if ( v6 )
  {
    v9 = a6;
    do
    {
      v10 = v6[1];
      result = v10 & 0xFFFFF000;
      if ( (v10 & 0xFFFFF000) == a3 )
      {
        v12 = v10 & 0xFFF;
        if ( v12 )
        {
          v14 = &a2[v12];
          v15 = 4096 - (((_WORD)v12 + (_WORD)a2) & 0xFFF);
          v16 = 0;
          goto LABEL_13;
        }
        v13 = *((unsigned __int16 *)v6 + 6);
        if ( v13 == 3 )
          return sub_5218B8();
        if ( v13 == 7 )
          result = MiApplyMov32Fixup(&a2[(v6[2] & 0xFFF) - 8], a4);
      }
      else
      {
        v11 = v6[2];
        if ( (v11 & 0xFFFFF000) == a3 )
        {
          v16 = 4096 - (v10 & 0xFFF);
          v14 = a2;
          v15 = v11 & 0xFFF;
LABEL_13:
          if ( v14 )
          {
            v19[0] = v6[4];
            v19[1] = v6[5];
            if ( v9 == 1 )
            {
              if ( a5 )
                MiApplyBytestreamFixup(v6, v19, a5);
              result = MiApplyBytestreamFixup(v6, v19, a4);
            }
            if ( v15 )
            {
              v17 = (char *)v19 + v16 - (_DWORD)v14;
              do
              {
                --v15;
                *v14 = v14[(_DWORD)v17];
                ++v14;
              }
              while ( v15 );
            }
          }
          goto LABEL_5;
        }
      }
LABEL_5:
      v6 = (int *)*v6;
      a3 = v18;
      v9 = a6;
    }
    while ( v6 );
  }
  return result;
}
