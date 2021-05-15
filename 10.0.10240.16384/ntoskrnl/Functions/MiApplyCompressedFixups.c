// MiApplyCompressedFixups 
 
int __fastcall MiApplyCompressedFixups(int a1, int a2, int a3, int a4)
{
  unsigned __int8 *v5; // r1
  unsigned int v6; // r4
  int result; // r0
  unsigned int v8; // r3
  int v9; // r7
  unsigned int v10; // r4
  int v11; // r6
  _BYTE *v12; // r1
  unsigned int v13; // r5
  unsigned int v14; // t1
  unsigned int v15; // r5
  int v16; // [sp+8h] [bp-30h]
  unsigned int v17; // [sp+Ch] [bp-2Ch]

  v5 = (unsigned __int8 *)(a3 & 0xFFFFFFFE);
  v6 = *(unsigned __int8 *)(**(_DWORD **)(a1 + 56) + 32);
  result = 4088;
  v8 = v6 >> 4;
  v9 = v6 & 0xF;
  v17 = v6 >> 4;
  v10 = a2;
  v11 = 4;
  while ( 1 )
  {
    v14 = *v5;
    v12 = v5 + 1;
    v13 = v14;
    v16 = (int)v12;
    if ( (v14 & 0xF0) == 240 )
      break;
    if ( v13 == 239 )
    {
      v15 = (unsigned __int8)*v12;
      if ( v15 <= 4 )
        sub_801810(4088);
      v16 = (int)(v12 + 1);
    }
    else
    {
      if ( v13 < 0xEB )
      {
        v11 = v13;
LABEL_6:
        v15 = 1;
        goto LABEL_7;
      }
      v15 = 239 - v13;
    }
    do
    {
LABEL_7:
      v10 += v11;
      if ( v10 >= a2 + 4096 )
        KeBugCheckEx(26, 49, a1, a2, v16);
      if ( (v10 & 1) != 0 )
      {
        if ( v8 == 7 )
        {
          if ( (((_WORD)v10 - 1) & 0xFFFu) <= 0xFF8 )
          {
            MiApplyMov32Fixup(v10 - 1, a4);
            result = 4088;
          }
        }
        else if ( v8 && v8 == 3 && (((_WORD)v10 - 1) & 0xFFFu) <= 0xFFC )
        {
          *(_DWORD *)(v10 - 1) += a4;
        }
      }
      else if ( v9 == 3 )
      {
        if ( (v10 & 0xFFF) <= 0xFFC )
          *(_DWORD *)v10 += a4;
      }
      else if ( v9 && v9 == 7 && (v10 & 0xFFF) <= 0xFF8 )
      {
        MiApplyMov32Fixup(v10, a4);
        result = 4088;
      }
      v8 = v17;
      --v15;
    }
    while ( v15 );
    v5 = (unsigned __int8 *)v16;
  }
  if ( *v12 )
  {
    v11 = v13 & 0xFF0F | (16 * (unsigned __int8)*v12);
    v8 = v17;
    v16 = (int)(v12 + 1);
    goto LABEL_6;
  }
  return result;
}
