// PspGetSetContextInternal 
 
int __fastcall PspGetSetContextInternal(int a1)
{
  unsigned int v1; // r4
  int i; // r2

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_BYTE *)(a1 + 48) )
  {
    for ( i = *(_DWORD *)(v1 + 32); (*(_DWORD *)(i + 4) & 1) != 0; i = *(_DWORD *)(i + 20) )
      ;
    JUMPOUT(0x74612C);
  }
  return sub_8035B8();
}
