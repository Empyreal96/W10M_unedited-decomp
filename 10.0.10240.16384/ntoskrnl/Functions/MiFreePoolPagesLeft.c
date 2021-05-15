// MiFreePoolPagesLeft 
 
unsigned int __fastcall MiFreePoolPagesLeft(int a1)
{
  unsigned int result; // r0
  int *v3; // r2
  unsigned int v4; // r2
  int *v5; // r1
  unsigned int v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r1
  unsigned int v9; // r1

  result = (unsigned int)dword_635310 >> 12;
  if ( a1 == 14 && (unsigned int)dword_633890 >> 12 < result )
    result = (unsigned int)dword_633890 >> 12;
  v3 = &MiState[a1];
  if ( v3[2566] )
    return sub_50EA74();
  v4 = v3[2408] << 10;
  if ( a1 == 5 )
  {
    v6 = dword_632A90;
    __dmb(0xBu);
    v9 = dword_640580;
    __dmb(0xBu);
    if ( v9 < result )
      result = v9;
    v8 = dword_640600;
    __dmb(0xBu);
    if ( v8 >= result )
      goto LABEL_10;
  }
  else
  {
    if ( a1 == 6 )
    {
      v5 = dword_634D34;
    }
    else
    {
      v5 = (int *)&unk_632CF4;
      if ( (unsigned int)dword_633890 >> 12 < result )
        result = (unsigned int)dword_633890 >> 12;
    }
    v6 = v5[6];
    v7 = v5[4];
    if ( v7 <= v4 )
      v8 = 0;
    else
      v8 = v7 - v4;
    if ( v8 >= result )
      goto LABEL_10;
  }
  result = v8;
LABEL_10:
  if ( v4 > v6 )
    result += v4 - v6;
  return result;
}
