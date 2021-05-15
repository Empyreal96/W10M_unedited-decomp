// CheckOneBitValidFlag 
 
int __fastcall CheckOneBitValidFlag(int a1, int a2)
{
  int result; // r0
  int v3; // r3

  if ( (a1 & ~a2) != 0 )
    goto LABEL_2;
  v3 = a1 & a2;
  if ( (a1 & a2) == 0 )
    goto LABEL_2;
  while ( (v3 & 1) == 0 )
    v3 >>= 1;
  if ( v3 > 1 )
LABEL_2:
    result = 0;
  else
    result = 1;
  return result;
}
