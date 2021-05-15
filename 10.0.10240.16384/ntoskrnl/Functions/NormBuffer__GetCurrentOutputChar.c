// NormBuffer__GetCurrentOutputChar 
 
int __fastcall NormBuffer__GetCurrentOutputChar(int a1, unsigned __int16 **a2)
{
  unsigned __int16 *v2; // r0
  int v3; // r4

  v2 = *a2;
  v3 = **a2;
  if ( (unsigned int)(v3 - 55296) <= 0x7FF )
  {
    if ( **a2 < 0xDC00u )
      v3 = *++v2 + ((v3 - 55287) << 10);
    else
      v3 += (*--v2 - 55287) << 10;
  }
  *a2 = v2;
  return v3;
}
