// -NpiTreeWalkCallback@NP_CONTEXT@@SAJPAX0PAK@Z 
 
int __fastcall NP_CONTEXT::NpiTreeWalkCallback(void *a1, void *a2, unsigned int *a3)
{
  _DWORD *v3; // r3

  if ( (*a3 & 1) != 0 && (*a3 & 2) == 0 )
  {
    v3 = (_DWORD *)*((_DWORD *)a2 + 10);
    if ( !v3 || (*a3 & 0xFFC) < (*v3 & 0xFFCu) )
      *((_DWORD *)a2 + 10) = a3;
  }
  return 0;
}
