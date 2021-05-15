// __longjmp_internal 
 
void __fastcall __noreturn _longjmp_internal(_DWORD *a1, int a2)
{
  int v2[18]; // [sp+8h] [bp-200h] BYREF
  int v3; // [sp+50h] [bp-1B8h] BYREF

  while ( 1 )
  {
    if ( !a2 )
      a2 = 1;
    v2[5] = (int)a1;
    v2[0] = -2147483610;
    v2[1] = 0;
    v2[2] = 0;
    v2[3] = 0;
    v2[4] = 1;
    a1 = (_DWORD *)RtlUnwindEx(*a1, a1[10], v2, a2, &v3, 0);
  }
}
