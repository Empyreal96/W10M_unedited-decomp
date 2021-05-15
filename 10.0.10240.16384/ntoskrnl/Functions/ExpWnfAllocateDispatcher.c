// ExpWnfAllocateDispatcher 
 
int ExpWnfAllocateDispatcher()
{
  _BYTE *v0; // r0
  _BYTE *v1; // r4

  v0 = (_BYTE *)ExAllocatePoolWithTag(512, 24, 543583831);
  v1 = v0;
  ExpWnfDispatcher = (int)v0;
  if ( !v0 )
    return 0;
  memset(v0, 0, 24);
  *(_WORD *)v1 = 2312;
  *((_WORD *)v1 + 1) = 24;
  *((_DWORD *)v1 + 3) = ExpWnfWorkItemRoutine;
  *((_DWORD *)v1 + 4) = 0;
  *((_DWORD *)v1 + 1) = 0;
  return 1;
}
