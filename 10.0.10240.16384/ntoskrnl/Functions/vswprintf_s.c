// vswprintf_s 
 
int __fastcall vswprintf_s(_WORD *a1, int a2, int a3)
{
  int result; // r0

  if ( !a1 || !a2 || !a3 )
    goto LABEL_6;
  result = swoutput_s();
  if ( result >= 0 )
    return result;
  *a1 = 0;
  if ( result == -2 )
LABEL_6:
    PopPoCoalescinCallback();
  return -1;
}
