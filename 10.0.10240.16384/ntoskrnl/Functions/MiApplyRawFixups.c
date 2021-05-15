// MiApplyRawFixups 
 
int __fastcall MiApplyRawFixups(int result, int a2, int a3, int a4)
{
  _DWORD *v4; // r2
  _WORD *v5; // r5
  unsigned int v8; // r7
  int i; // r10
  int v10; // r3
  int v11; // r2

  v4 = (_DWORD *)(a3 & 0xFFFFFFFE);
  v5 = v4 + 2;
  v8 = (unsigned int)(v4[1] - 8) >> 1;
  for ( i = *v4 & 0xFFF; v8; ++v5 )
  {
    --v8;
    v10 = (unsigned __int16)*v5 >> 12;
    v11 = (*v5 & 0xFFF) + i;
    if ( v10 == 3 )
    {
      if ( (((_WORD)v11 + (_WORD)a2) & 0xFFFu) <= 0xFFC )
        *(_DWORD *)(v11 + a2) += a4;
    }
    else if ( v10 )
    {
      if ( v10 != 7 )
        sub_7DCF38(result, 4088, v11);
      if ( (((_WORD)v11 + (_WORD)a2) & 0xFFFu) <= 0xFF8 )
        result = MiApplyMov32Fixup(v11 + a2, a4);
    }
  }
  return result;
}
