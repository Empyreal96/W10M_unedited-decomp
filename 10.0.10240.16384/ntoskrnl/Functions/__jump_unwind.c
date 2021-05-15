// __jump_unwind 
 
void __fastcall __noreturn _jump_unwind(int a1, int a2)
{
  char v2; // [sp+10h] [bp-1A8h] BYREF

  while ( 1 )
    a1 = RtlUnwindEx(a1, a2, 0, 0, &v2, 0);
}
