// ExpAllocateTablePagedPool 
 
_BYTE *__fastcall ExpAllocateTablePagedPool(int a1, int a2)
{
  _BYTE *v3; // r0
  _BYTE *v4; // r4

  v3 = (_BYTE *)ExpAllocateTablePagedPoolNoZero();
  v4 = v3;
  if ( v3 )
    memset(v3, 0, a2);
  return v4;
}
