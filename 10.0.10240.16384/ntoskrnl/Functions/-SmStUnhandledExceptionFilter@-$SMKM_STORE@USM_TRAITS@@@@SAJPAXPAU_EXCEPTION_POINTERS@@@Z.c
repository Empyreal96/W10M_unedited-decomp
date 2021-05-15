// -SmStUnhandledExceptionFilter@-$SMKM_STORE@USM_TRAITS@@@@SAJPAXPAU_EXCEPTION_POINTERS@@@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStUnhandledExceptionFilter(int a1, int a2)
{
  if ( a2 )
    KeBugCheckEx(340, a1, a2, 0, 0);
  return 0;
}
