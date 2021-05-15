// TxtpJustifyRectangle 
 
_DWORD *__fastcall TxtpJustifyRectangle(_DWORD *result, int *a2, unsigned int *a3)
{
  unsigned int v4; // r3
  int v5; // r2
  int v6; // r3
  unsigned int v7; // r2

  a3[1] = 0;
  if ( (result[12] & 4) != 0 )
  {
    v4 = result[13];
  }
  else
  {
    v5 = result[2];
    v6 = *a2;
    if ( (result[12] & 8) != 0 )
    {
      v7 = v5 - v6;
      *a3 = v7;
      v4 = v7 - result[13];
    }
    else
    {
      v4 = (unsigned int)(v5 - v6) >> 1;
    }
  }
  *a3 = v4;
  return result;
}
