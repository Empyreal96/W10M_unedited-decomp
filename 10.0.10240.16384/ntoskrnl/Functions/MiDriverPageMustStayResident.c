// MiDriverPageMustStayResident 
 
int __fastcall MiDriverPageMustStayResident(int a1, int a2)
{
  unsigned int *v2; // r4
  unsigned int v3; // r2
  int result; // r0

  v2 = *(unsigned int **)(a1 + 136);
  v3 = (a2 - ((*(_DWORD *)(a1 + 24) >> 10) & 0x3FFFFC) + 0x40000000) >> 2;
  if ( v3 >= *v2 )
    result = 0;
  else
    result = (*(int *)(v2[1] + 4 * (v3 >> 5)) >> (v3 & 0x1F)) & 1;
  return result;
}
