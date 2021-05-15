// -NpiRebaseCallback@NP_CONTEXT@@SAJPAX0PAK@Z 
 
int __fastcall NP_CONTEXT::NpiRebaseCallback(void *a1, void *a2, unsigned int *a3)
{
  unsigned int v3; // r0

  if ( !a1 )
  {
    v3 = *a3;
    if ( (*a3 & 1) != 0 && (v3 & 2) == 0 )
    {
      if ( ((v3 >> 2) & 0x3FF) > (unsigned int)a2 )
        *a3 = ((v3 - 4 * (_DWORD)a2) ^ v3) & 0xFFC ^ v3;
      else
        *a3 = v3 & 0xFFFFF003;
    }
  }
  return 0;
}
