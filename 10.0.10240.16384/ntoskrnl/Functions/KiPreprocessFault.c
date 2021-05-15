// KiPreprocessFault 
 
int __fastcall KiPreprocessFault(int *a1, int a2, int a3, int a4)
{
  int v5; // r0
  int result; // r0

  v5 = *a1;
  switch ( v5 )
  {
    case 268435458:
      return KiPreprocessInternalInvalidOpcode(a1, a2, a3, a4);
    case 268435460:
      result = KiOpPreprocessAccessViolation(a1, a4);
      if ( result )
        result = 1;
      else
        *a1 = -1073741819;
      break;
    case 268435461:
      result = sub_51BBCC();
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
