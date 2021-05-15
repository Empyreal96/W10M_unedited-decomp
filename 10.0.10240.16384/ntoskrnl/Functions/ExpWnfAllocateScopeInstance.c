// ExpWnfAllocateScopeInstance 
 
int __fastcall ExpWnfAllocateScopeInstance(_DWORD *a1, int a2, int a3, unsigned int a4)
{
  _BYTE *v8; // r0
  _BYTE *v9; // r4

  v8 = (_BYTE *)ExAllocatePoolWithTag(1, a4 + 44, 543583831);
  v9 = v8;
  if ( !v8 )
    return -1073741670;
  memset(v8, 0, 44);
  *(_WORD *)v9 = 2306;
  *((_WORD *)v9 + 1) = 44;
  *((_DWORD *)v9 + 1) = 0;
  *((_DWORD *)v9 + 2) = a2;
  *((_DWORD *)v9 + 3) = a4;
  if ( a4 )
  {
    *((_DWORD *)v9 + 4) = v9 + 44;
    memmove((int)(v9 + 44), a3, a4);
  }
  *((_DWORD *)v9 + 7) = 0;
  *((_DWORD *)v9 + 8) = 0;
  *a1 = v9;
  return 0;
}
