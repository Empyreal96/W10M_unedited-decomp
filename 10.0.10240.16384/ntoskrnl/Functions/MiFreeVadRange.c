// MiFreeVadRange 
 
unsigned int *__fastcall MiFreeVadRange(int a1, int a2, int a3, int a4)
{
  int v4; // r7
  unsigned int *result; // r0
  int v8; // [sp+8h] [bp-18h]

  v8 = a3;
  v4 = (a4 << 12) | 0xFFF;
  result = (unsigned int *)MiPrepareVadDelete(a1, a2);
  if ( (int)result >= 0 )
  {
    if ( v8 )
    {
      result = (unsigned int *)MiDeletePartialVad(a1, a3 << 12, v4);
      if ( (int)result < 0 )
        return result;
    }
    else
    {
      result = MiDeleteVad(a1, 0);
    }
    if ( (dword_682604 & 0x8000) != 0 )
      result = (unsigned int *)sub_549F4C(result);
    else
      result = 0;
  }
  return result;
}
