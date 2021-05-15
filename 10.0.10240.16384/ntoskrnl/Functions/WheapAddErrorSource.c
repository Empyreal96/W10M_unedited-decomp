// WheapAddErrorSource 
 
int __fastcall WheapAddErrorSource(int a1, int *a2)
{
  int v3; // r0
  int **v4; // r1
  unsigned int v5; // r1

  v3 = KeWaitForSingleObject(&byte_64193C, 0, 0);
  *(int *)((char *)a2 + 101) = dword_641930;
  v4 = (int **)dword_641938;
  *a2 = (int)&dword_641934;
  a2[1] = (int)v4;
  if ( *v4 != &dword_641934 )
    sub_51E048(v3);
  *v4 = a2;
  dword_641938 = (int)a2;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&dword_641930);
  while ( __strex(v5 + 1, (unsigned int *)&dword_641930) );
  __dmb(0xBu);
  return KeSetEvent(&byte_64193C, 0, 0);
}
