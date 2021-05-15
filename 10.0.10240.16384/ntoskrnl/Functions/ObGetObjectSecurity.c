// ObGetObjectSecurity 
 
int __fastcall ObGetObjectSecurity(int a1, int a2, int a3)
{
  return ObpGetObjectSecurity(a1, a2, a3, 0);
}
