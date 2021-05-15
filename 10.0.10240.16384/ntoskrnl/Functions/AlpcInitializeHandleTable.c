// AlpcInitializeHandleTable 
 
int __fastcall AlpcInitializeHandleTable(_DWORD *a1)
{
  _BYTE *v2; // r0

  a1[2] = 0;
  a1[3] = 0;
  v2 = (_BYTE *)ExAllocateFromPagedLookasideList((int)&unk_643600);
  *a1 = v2;
  if ( !v2 )
    return -1073741670;
  a1[1] = 16;
  memset(v2, 0, 64);
  return 0;
}
