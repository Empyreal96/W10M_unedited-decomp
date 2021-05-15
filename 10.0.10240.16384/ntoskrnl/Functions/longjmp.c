// longjmp 
 
void __fastcall __noreturn longjmp(_DWORD *a1, int a2)
{
  PopPoCoalescinCallback();
  _longjmp_internal(a1, a2);
}
