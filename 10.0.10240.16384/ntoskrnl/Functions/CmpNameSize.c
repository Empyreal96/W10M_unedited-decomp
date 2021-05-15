// CmpNameSize 
 
unsigned int __fastcall CmpNameSize(unsigned __int16 *a1)
{
  unsigned int result; // r0
  int v3; // r2
  unsigned __int16 *v4; // r1
  unsigned int v5; // t1

  result = *a1;
  v3 = 0;
  if ( result >> 1 )
  {
    v4 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
    while ( 1 )
    {
      v5 = *v4++;
      if ( v5 > 0xFF )
        break;
      if ( ++v3 >= result >> 1 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    result >>= 1;
  }
  return result;
}
