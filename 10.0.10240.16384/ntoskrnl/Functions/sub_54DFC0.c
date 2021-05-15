// sub_54DFC0 
 
void __fastcall sub_54DFC0(int a1, _WORD *a2, char a3, int a4)
{
  int v4; // r4
  __int64 v5; // r6
  unsigned int v6; // r3
  unsigned int v7; // r3

  if ( v4 == 1 )
  {
    v6 = v5 + ((unsigned __int16)*a2 << 16);
  }
  else
  {
    if ( v4 == 2 )
    {
      LOWORD(v7) = *a2 + v5;
LABEL_11:
      *a2 = v7;
      goto LABEL_12;
    }
    if ( v4 != 4 )
    {
      if ( v4 == 10 )
        *(_QWORD *)a2 += v5;
LABEL_12:
      JUMPOUT(0x4E52E0);
    }
    if ( (a3 & 2) != 0 )
      goto LABEL_12;
    v6 = *(unsigned __int16 *)(a4 + 2) + ((unsigned __int16)*a2 << 16) + v5 + 0x8000;
  }
  v7 = HIWORD(v6);
  goto LABEL_11;
}
