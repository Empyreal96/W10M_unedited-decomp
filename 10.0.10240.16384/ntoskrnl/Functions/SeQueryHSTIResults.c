// SeQueryHSTIResults 
 
int __fastcall SeQueryHSTIResults(int a1, unsigned int a2, _DWORD *a3)
{
  unsigned int v3; // r3

  v3 = dword_927904;
  *a3 = dword_927904;
  if ( !v3 )
    return -1073741275;
  if ( a2 < v3 )
    return -1073741820;
  memmove(a1, dword_927900, v3);
  return 0;
}
