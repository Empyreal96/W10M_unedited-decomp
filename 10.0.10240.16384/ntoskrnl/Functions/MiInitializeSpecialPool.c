// MiInitializeSpecialPool 
 
int *__fastcall MiInitializeSpecialPool(char a1)
{
  int *v1; // r1
  int v2; // r1
  int *result; // r0
  _DWORD *v4; // r1
  unsigned int v5; // r2

  if ( (a1 & 0x20) != 0 )
  {
    v1 = (int *)dword_63501C;
  }
  else
  {
    v5 = 0x20000000;
    if ( dword_63388C )
      v5 = 0x4000000;
    dword_632AF0 = v5 >> 22;
    v1 = (int *)&unk_634D00;
  }
  InitializeListHeadPte(v1 + 1);
  result = InitializeListHeadPte((int *)(v2 + 16));
  *v4 = 0;
  return result;
}
