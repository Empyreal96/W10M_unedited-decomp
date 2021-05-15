// vsprintf_s 
 
int __fastcall vsprintf_s(_BYTE *a1, int a2, int a3)
{
  int result; // r0

  if ( !a1 || !a2 || !a3 )
    goto LABEL_6;
  result = soutput_s();
  if ( result >= 0 )
    return result;
  *a1 = 0;
  if ( result == -2 )
LABEL_6:
    PopPoCoalescinCallback();
  return -1;
}
