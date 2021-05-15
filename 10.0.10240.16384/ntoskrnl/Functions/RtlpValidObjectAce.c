// RtlpValidObjectAce 
 
int __fastcall RtlpValidObjectAce(int a1)
{
  int v1; // r2
  int result; // r0
  unsigned int v3; // r1
  int v4; // r3
  int v5; // r4
  int v6; // r3
  int v7; // r0
  unsigned int v8; // r3

  v1 = 0;
  if ( !a1 )
    goto LABEL_2;
  v3 = *(unsigned __int16 *)(a1 + 2);
  if ( ((v3 + 3) & 0xFFFFFFFC) != v3 || v3 < 0xC )
    goto LABEL_2;
  v4 = *(_DWORD *)(a1 + 8);
  if ( (v4 & 1) != 0 )
    v1 = 16;
  if ( (v4 & 2) != 0 )
    v1 += 16;
  if ( v3 >= v1 + 24
    && ((v4 & 1) == 0 ? (v5 = 0) : (v5 = 16),
        (v4 & 2) == 0 ? (v6 = 0) : (v6 = 16),
        (v7 = a1 + v6 + v5, *(_BYTE *)(v7 + 12) == 1)
     && (v8 = *(unsigned __int8 *)(v7 + 13), v8 <= 0xF)
     && v3 >= v1 + 4 * (v8 + 5)) )
  {
    result = 1;
  }
  else
  {
LABEL_2:
    result = 0;
  }
  return result;
}
