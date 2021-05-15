// Template_pqzzzzzzz 
 
int __fastcall Template_pqzzzzzzz(int a1, int a2, int a3, int a4, int a5, int a6, unsigned __int16 *a7, unsigned __int16 *a8, unsigned __int16 *a9, unsigned __int16 *a10, unsigned __int16 *a11, unsigned __int16 *a12, unsigned __int16 *a13)
{
  int varg_r0; // [sp+B8h] [bp+8h]
  int varg_r1; // [sp+BCh] [bp+Ch]
  int varg_r3; // [sp+C4h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  if ( a7 )
    wcslen(a7);
  if ( a8 )
    wcslen(a8);
  if ( a9 )
    wcslen(a9);
  if ( a10 )
    wcslen(a10);
  if ( a11 )
    wcslen(a11);
  if ( a12 )
    wcslen(a12);
  if ( a13 )
    wcslen(a13);
  return EtwWrite(a1, a2, (int)KMPnPEvt_DevQuery_QueryStart, a4);
}
